import xml.etree.ElementTree as et
import subprocess
import shutil
import pathlib
import os

# ---------------------------- Configuration section ---------------------------- #

# --------------- Versions --------------- #

# Release number and version for App
newAppPartNumber = "1749025500"
newAppReleaseVer = "233100"
newAppDiagVer = "209"

# Release number and version for FBL
newFblPartNumber = "1749041800"
newFblReleaseVer = "233100"
newFblDiagVer = "010205"

# Release number and version for HSM
newHsmPartNumber = "1749025500"
newHsmReleaseVer = "233503"

# --------------- Paths --------------- #

buildOutputsPath = "S:/Tools/Build_Env/Workspace/Outputs"

odxPath = "S:/Tools/Odx/Workspace/Daimler_1608/"
odxOutPath = "S:/Tools/Odx/Workspace/Daimler_1608/Out/."
trafoPath = "C:/Program Files/Softing/DTS_Trafo/9.02.015/bin/TrafoCoApp.exe"
odxPathSupplier = "S:/Tools/Odx/Workspace/Daimler_1608/Supplier/"

hexViewPath = "S:/Tools/HexView/Installation/HexView-1.15.03/hexview.exe"

daimlerSecurityPluginPath = "S:\Tools\Odx\Workspace\Daimler_1608\DaimlerSecurityPlugin\DaimlerSecurityConsoleApp.exe"

# App Paths
appPath = buildOutputsPath + "/app/Out/"

appHexName = "app.hex"
appComprEncrHexName = "app_lzma_enc.hex"

appPPAddressSpace = "0xA00FFF80-0xA00FFFFF"

# FBL Updater Paths
fblPath = buildOutputsPath + "/fbl_upd/Out/"
fblHexName = "fbl_upd.hex"
fblComprEncrHexName = "fbl_upd_lzma_enc.hex"

# HSM Updater Paths
hsmUpdPath = buildOutputsPath + "/hsm/Out/"
hsmUpdHexName = "hsm_upd_container.hex"

hsmScriptPath = "S:/Tools/Vector_configuration/Workspace/hsmupdater/Appl/"
hsmContainerName = "vHsmUpd_ModularUpdateContainer.hex"
hsmMainScript = "CreatevHsmUpdMultipleModuleContainerAndHeader.bat"
appHeaderName = "vHsmUpd_ContainerHeaderApp.hex"
hsmHeaderName = 'vHsmUpd_Header.hex'

# Release tags
newAppReleaseTag = newAppPartNumber + "_001_" + newAppReleaseVer
newFblReleaseTag = newFblPartNumber + "_001_" + newFblReleaseVer
newHsmReleaseTag = newHsmPartNumber + "_001_" + newHsmReleaseVer

# ---------------------------- Classes ---------------------------- #
class Segment:
    startAddress = 0
    endAddress = 0
    size = 0
    compressedSize = 0

    def __init__(self, startAddress=0, endAddress=0, size=0, compressedSize=0):
        self.startAddress = startAddress
        self.endAddress = endAddress
        self.size = size
        self.compressedSize = compressedSize

# ---------------------------- Function to delete temporary files ---------------------------- #
def cleanupDagSwDlFiles(appType):
    try:
        os.remove(appType + ".hex")
        os.remove(appType + ".xml")
        os.remove(appType + ".crc")
        os.remove(appType + "_cccv2.sig")
        os.remove(appType + "_enc.hex")
        os.remove(appType + "_enc_cccv2.sig")
        os.remove(appType + "_lz77.hex")
        os.remove(appType + "_lz77_cccv2.sig")
        os.remove(appType + "_lz77_enc.hex")
        os.remove(appType + "_lz77_enc_cccv2.sig")
        os.remove(appType + "_lzma_cccv2.sig")
        os.remove(appType + "_lzma_enc_cccv2.sig")
        os.remove(appType + "_lzma.hex")
        os.remove(appType + "_lzma_enc.xml")
        os.remove(appType + "_lzma_enc.hex")
    except Exception as e:
        print(e)

# ---------------------------- Function to replace a line in a file ---------------------------- #
def replaceLine(fileName, lineNum, text):
    lines = open(fileName, 'r').readlines()
    lines[lineNum-1] = text + '\n'
    out = open(fileName, 'w')
    out.writelines(lines)
    out.close()

# ---------------------------- Function to apply the new release tag to ODX-F file ---------------------------- #
def getCurrentVersions(odxName):

    newAppName = odxPathSupplier + odxName + ".odx-f"

    # Start parsing the XML
    xmlTree = et.parse(newAppName)
    rootElement = xmlTree.getroot()

    # Traverse the whole XML to find our elements and write the data
    for elem in traverse(rootElement):
        if elem.tag == "ECU-MEM":
            currentTag = elem.attrib['ID'][-21:]
            currentVersion = currentTag[-6:]

    return currentTag, currentVersion

# ---------------------------- Function to apply the new diag version to ODX-F file ---------------------------- #
def applyDiagVer(odxName, diagVer):

    newAppName = odxPathSupplier + odxName + ".odx-f"

    # Start parsing the XML
    xmlTree = et.parse(newAppName)
    rootElement = xmlTree.getroot()

    # Traverse the whole XML to find our elements and write the data
    for elem in traverse(rootElement):
        if elem.tag == "OWN-IDENTS":
            elemDiag = elem[0]
            elemDiag[2].text = str(int(diagVer, 16))

    # Write the modified xml file
    xmlTree.write(newAppName, encoding="UTF-8", xml_declaration=True)

    print("Diag version set to " + diagVer)

# ---------------------------- Function to apply the new release tag to ODX-F file ---------------------------- #
def applyTagToOdx(odxName, oldTag, newTag):
    # Input-output files for App
    oldAppName = odxPathSupplier + odxName + ".odx-f"
    newAppName = odxPathSupplier + odxName + "_temp.odx-f"

    fin = open(oldAppName, "rt")

    # Output file to write the result to
    fout = open(newAppName, "wt")

    # For each line in the input file
    for line in fin:
	    # Read replace the string and write to output file
	    fout.write(line.replace(oldTag, newTag))
    
    # Close input and output files
    fin.close()
    fout.close()

    # Remove the temporary file
    os.remove(oldAppName)
    os.rename(newAppName, oldAppName)

    print("Release tag changed to: "+ newTag + " for: " + oldAppName)

# ---------------------------- Function to apply CRC and CCCv2 to the ODX-F file ---------------------------- #
def applyChecksumAndSigToOdx (odxName, checksum, signature):

    newAppName = odxPathSupplier + odxName + ".odx-f"

    # Start parsing the XML
    xmlTree = et.parse(newAppName)
    rootElement = xmlTree.getroot()

    # Traverse the whole XML to find our elements and write the data
    for elem in traverse(rootElement):
        if elem.tag == "FW-SIGNATURE":
            elem.text = signature
        if elem.tag == "FW-CHECKSUM":
            elem.text = checksum

    # Write the modified xml file
    xmlTree.write(newAppName, encoding="UTF-8", xml_declaration=True)

    print("CCCv2 and CRC have been added to: " + newAppName)

# ---------------------------- Function to apply the block segments to the ODX-F file ---------------------------- #
def applySegmentsToOdx (odxName, appSegments):

    newAppName = odxPathSupplier + odxName + ".odx-f"

    # Start parsing the XML
    xmlTree = et.parse(newAppName)
    rootElement = xmlTree.getroot()

    segmentTextTemplate = ''

    # Traverse the whole XML
    for elem in traverse(rootElement):
        if elem.tag == "SEGMENTS":

            # Get segment tag
            segmentTextTemplate = elem[0].attrib['ID']
            segmentTextTemplate = segmentTextTemplate[:-8]

            # Remove all existing segments
            for child in list(elem):
                elem.remove(child)

            # Add the new segments
            for segment in appSegments:
                newSegment = et.Element("SEGMENT")
                address = hex(segment.startAddress)[2:].upper()
                newSegment.attrib['ID'] = segmentTextTemplate + address
                shortName = et.SubElement(newSegment, "SHORT-NAME")
                shortName.text = address
                longName = et.SubElement(newSegment, "LONG-NAME")
                longName.text = address
                source = et.SubElement(newSegment, "SOURCE-START-ADDRESS")
                source.text = address
                compressedSize = et.SubElement(newSegment, "COMPRESSED-SIZE")
                compressedSize.text = str(segment.compressedSize)
                size = et.SubElement(newSegment, "UNCOMPRESSED-SIZE")
                size.text = str(segment.size)

                elem.append(newSegment)

            # Indent the document for better readability
            et.indent(rootElement)

            # Write the changes to the file
            xmlTree.write(newAppName, encoding="UTF-8", xml_declaration=True)

        # if elem.tag == "SEGMENTS":

# ---------------------------- Function to generate SMR-F files with Trafo from our new ODX-F file ---------------------------- #
def generateSmrf(odxName, appName):

    newAppName = odxPathSupplier + odxName + ".odx-f"

    # COpy files to supplier path to call the Trafo tool
    shutil.copyfile(appName, odxPathSupplier + appName)

    trafoCmd = "\"" + trafoPath + "\"" + " /fsplit " + "\"" + newAppName + "\"" + " /outdir " + "\"" + odxOutPath + "\"" + " /log /resultUI"
    subprocess.call(trafoCmd)

    # Remove the file from the supplier folder to avoid confusions
    os.remove(odxPathSupplier + appName)

# ---------------------------- Function to traverse a tree ---------------------------- #
def traverse(elem):
    yield elem

    for child in elem:
        yield from traverse(child)

# ---------------------------- Function that exports the block information from a hex file (GM FBL Data) ---------------------------- #
def exportBlockInformation(appName):
    subprocess.call(hexViewPath + " " + appName + " /XGMFBL /CS7 /s")
    print("Exported block data for " + appName)

# ---------------------------- Function that  parses the GM FBL Data and populates a class with this information ---------------------------- #
def getBlockSegments(appName, appComprEncName):
    appRawData = appName.replace(".hex", ".xml")
    appComprEncrData = appComprEncName.replace(".hex", ".xml")
    appSegments = []
    
    # Get RAW data
    ## Start parsing the XML
    xmlTree = et.parse(appRawData)
    rootElement = xmlTree.getroot()

    ## Get the Raw Address and size (length) and add them to the segment list
    for elem in traverse(rootElement):
        if elem.tag == "Address":
            address = (int(elem.attrib['Value']) & 0xFFFFFFFF)
        if elem.tag == "Length":
            size = int(elem.attrib['Value'])
            endAddress = address + (size -1)
            appSegments.append(Segment(address, endAddress, size))

    # Get compressed size
    ## Start parsing the XML
    xmlTree = et.parse(appComprEncrData)
    rootElement = xmlTree.getroot()

    i = 0

    ## Get the Compressed size and update the segment list
    for elem in traverse(rootElement):
        if elem.tag == "Length":
            comprSize = int(elem.attrib['Value'])
            appSegments[i].compressedSize = comprSize
            i = i+1
    
    return appSegments

# ---------------------------- Function that calls the DaimlerSecurityPlugin ---------------------------- #
def daimlerSecurityPlugin(appSegments, appName, appComprEncName):

    # Segment components
    segmentInfoStart = '<SecurityPluginSegmentInfo xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" version=\"2.0\"> <SecurityPluginSegments> '
    segmentInfoEnd = ' </SecurityPluginSegments> </SecurityPluginSegmentInfo>'
    segments = ""
    
    # Populate the segments
    for segment in appSegments:
        segments = segments + ("<SecurityPluginSegment> <StartAddress>"+ str(segment.startAddress) +"</StartAddress> "
        + "<CompressedSize>"+ str(segment.compressedSize) +"</CompressedSize> "
	    + "<TargetAddress>"+ str(segment.startAddress) +"</TargetAddress> "
	    + "<UncompressedSize>"+ str(segment.size) +"</UncompressedSize> </SecurityPluginSegment> ")
        print("Found block with start address: " + hex(segment.startAddress) + ", end address: " + hex(segment.endAddress) + ", size: "+ hex(segment.size) + ", compressed size: " + hex(segment.compressedSize))

    # Write all the info to the SegmentInfo.xml
    segmentFile = open("SegmentInfo.xml", "w")
    segmentFile.write(segmentInfoStart + segments + segmentInfoEnd)
    segmentFile.close()
    print("SegmentInfo.xml has been overwritten with the information for " + appName + " and " + appComprEncName)

    # Call the DaimlerSecurityPlugin
    pluginOutput = subprocess.check_output("DaimlerSecurityPlugin\DaimlerSecurityConsoleApp.exe" + ' /f INTEL-HEX /c CCCv2 /i DaimlerSecurityPlugin\DaimlerSecurityPlugin.ini /n EdDSAKey01 /s SegmentInfo.xml ' + appComprEncName)

    split = pluginOutput.split()

    # Get the signature from the output of the plugin
    # checksum = split[1].decode('utf-8')
    signature = split[3].decode('utf-8')

    # Get the CRC from the unencrypted file generated by DAG SWDL script
    appCrcPath = appName[:-4] + ".crc"

    # Read whole file to a string and tidy up the file - the space/comma order is important
    appCrc = open(appCrcPath, "r").read().replace("0x", "").replace(", ", "")

    print("This is the checksum: " + appCrc + " and this is the signature: " + signature)

    return appCrc, signature

# ---------------------------- Start of execution area ---------------------------- #

# 1 - Apply the new release tag to ODX-F files. containers and revision labels
oldAppReleaseTag, oldAppReleaseVer = getCurrentVersions("application")
applyTagToOdx("application", oldAppReleaseTag, newAppReleaseTag)
applyTagToOdx("application", oldAppReleaseVer, newAppReleaseVer)
applyTagToOdx("application", oldAppReleaseVer[:2] + "." + oldAppReleaseVer[2:4] + "." + oldAppReleaseVer[4:6], newAppReleaseVer[:2] + "." + newAppReleaseVer[2:4] + "." + newAppReleaseVer[4:6])
applyDiagVer("application", newAppDiagVer)

oldFblReleaseTag, oldFblReleaseVer = getCurrentVersions("fbl")
applyTagToOdx("fbl", oldFblReleaseTag, newFblReleaseTag)
applyTagToOdx("fbl", oldFblReleaseVer, newFblReleaseVer)
applyTagToOdx("fbl", oldFblReleaseVer[:2] + "." + oldFblReleaseVer[2:4] + "." + oldFblReleaseVer[4:6], newFblReleaseVer[:2] + "." + newFblReleaseVer[2:4] + "." + newFblReleaseVer[4:6])
applyDiagVer("fbl", newFblDiagVer)

oldHsmReleaseTag, oldHsmReleaseVer = getCurrentVersions("HSM_Updater")
applyTagToOdx("HSM_Updater", oldHsmReleaseTag, newHsmReleaseTag)
applyTagToOdx("HSM_Updater", oldHsmReleaseVer, newHsmReleaseVer)
applyTagToOdx("HSM_Updater", oldHsmReleaseVer[:2] + "." + oldHsmReleaseVer[2:4] + "." + oldHsmReleaseVer[4:6], newHsmReleaseVer[:2] + "." + newHsmReleaseVer[2:4] + "." + newHsmReleaseVer[4:6])

# 2 - Prepare the hex files

#----------- App Area
#   Copy App to our local folder from the outputs folder
shutil.copyfile(appPath + appHexName, str(pathlib.Path(__file__).parent.absolute()) + "/" + appHexName)

print("Copied latest built "+ appHexName + " from "+ appPath)

#   Split the data in 0x8 data and 0xA data
subprocess.call(hexViewPath + " " + appHexName +" /AR:0x80000000-0x80FFFFFF /XI /s -o " + appHexName + "_0x8")
subprocess.call(hexViewPath + " " + appHexName +" /AR:0xA0000000-0xA0FFFFFF /XI /s -o " + appHexName + "_0xA")

#   Merge the data into one 0xA file
subprocess.call(hexViewPath + " " + appHexName + "_0xA" +" /MO:"+ appHexName + "_0x8;0x20000000" + " /XI /s -o " + appHexName)

print("Remapped 0x80000000...0x80FFFFFF to 0xA0000000...0xA0FFFFFF")

#   Align the hexfile
subprocess.call(hexViewPath + " " + appHexName + " /AD:0x20 /AL:0x20 /XI /s -o " + appHexName)

print("Aligned the data for TriCore flashing")

#   Remove everything from this address space to get rid of the PP
subprocess.call(hexViewPath + " " + appHexName + " /S /CR:"+ appPPAddressSpace +" /XI /s -o " + appHexName)

print("Removed data from "+ appPPAddressSpace)

#   Fill first 2000h
subprocess.call(hexViewPath + " " + appHexName + " /FR:0xA006C000,0x5000 /FP:0xFF /XI /s -o " + appHexName)
print("Filled first 5000h to lower block count")

#   Remove temporary files
os.remove(appHexName + "_0x8")
os.remove(appHexName + "_0xA")

#   Generate the CCCv2 and CRC files
os.system("dag_swdl_files_create.py -i " + appHexName)

#   Export the block information from the hex files to xml files
exportBlockInformation(appHexName)
exportBlockInformation(appComprEncrHexName)

# Get the block information out of the hex files
appSegments = getBlockSegments(appHexName, appComprEncrHexName)

# Compute the checksum and the signature using the Daimler Security Plugin
checksum, signature = daimlerSecurityPlugin(appSegments, appHexName, appComprEncrHexName)

# Apply the segments to the ODX file
applySegmentsToOdx("application", appSegments)

# Apply the checksum and the signature to the ODX file
applyChecksumAndSigToOdx ("application", checksum, signature)

# Generate the final file
generateSmrf("application", appComprEncrHexName)

#----------- FBL Area
#   Copy FBL updater to our local folder from the outputs folder, no additional processing needed here
shutil.copyfile(fblPath + fblHexName, str(pathlib.Path(__file__).parent.absolute()) + "/" + fblHexName)

print("Copied latest built " + fblHexName + " from "+ fblPath)

#   Generate the CCCv2 and CRC files
os.system("dag_swdl_files_create.py -i " + fblHexName)

#   Export the block information from the hex files to xml files
exportBlockInformation(fblHexName)
exportBlockInformation(fblComprEncrHexName)

# Get the block information out of the hex files
fblSegments = getBlockSegments(fblHexName, fblComprEncrHexName)

checksum, signature = daimlerSecurityPlugin(fblSegments, fblHexName, fblComprEncrHexName)

# Apply the segments to the ODX file
applySegmentsToOdx("fbl", fblSegments)

# Apply the checksum and the signature to the ODX file
applyChecksumAndSigToOdx ("fbl", checksum, signature)

# Generate the final file
generateSmrf("fbl", fblComprEncrHexName)

#------------ HSM Area
# Change HSM version in the main script
replaceLine(hsmScriptPath + hsmMainScript, 70, "set UPDATE_VERSION=00" + newHsmReleaseVer)
print("Changed HSM version in script " + hsmMainScript + " to "+ newHsmReleaseVer)

# 1 - Create the container
subprocess.call([ hsmScriptPath + hsmMainScript ], shell=True, cwd=hsmScriptPath)

# 2 - Prepare the hex files
#   Merge the appheader
subprocess.call(hexViewPath + " "+ hsmScriptPath + hsmContainerName +" /MO:"+ hsmScriptPath + appHeaderName + " /XI /s -o " + hsmScriptPath + hsmContainerName)

print("Merged the App Header")

#   Split the data in 0x8 data and 0xA data
subprocess.call(hexViewPath + " " + hsmScriptPath + hsmContainerName +" /AR:0x80000000-0x80FFFFFF /XI /s -o " + hsmScriptPath + hsmContainerName + "_0x8")
subprocess.call(hexViewPath + " " + hsmScriptPath + hsmContainerName +" /AR:0xA0000000-0xA0FFFFFF /XI /s -o " + hsmScriptPath + hsmContainerName + "_0xA")

#   Merge the data into one 0xA file
subprocess.call(hexViewPath + " " + hsmScriptPath + hsmContainerName + "_0xA" +" /MO:" + hsmScriptPath + hsmContainerName + "_0x8;0x20000000" + " /XI /s -o "+ hsmScriptPath + hsmContainerName)

print("Remapped 0x80000000...0x80FFFFFF to 0xA0000000...0xA0FFFFFF")

#   Align the hexfile
subprocess.call(hexViewPath + " " + hsmScriptPath + hsmContainerName + " /AD:0x20 /AL:0x20 /XI /s -o " + hsmScriptPath + hsmContainerName)

print("Aligned the data for TriCore flashing")

#   Remove temporary files
os.remove(hsmScriptPath + hsmContainerName + "_0x8")
os.remove(hsmScriptPath + hsmContainerName + "_0xA")

# Copy HSM updater to our local folder from the outputs folder, no additional processing needed here
shutil.copyfile(hsmScriptPath + hsmContainerName, str(pathlib.Path(__file__).parent.absolute()) + "/" + hsmUpdHexName)

# Remove temporary files
os.remove(hsmContainerName)
os.remove(hsmHeaderName)

# Generate the final file
generateSmrf("HSM_Updater", hsmUpdHexName)

# Copy all the files to the supplier path, where they remain to be checked in
shutil.copyfile( str(pathlib.Path(__file__).parent.absolute()) + "/" + appHexName,  odxPathSupplier + appHexName)
shutil.copyfile( str(pathlib.Path(__file__).parent.absolute()) + "/" + appComprEncrHexName,  odxPathSupplier + appComprEncrHexName)
shutil.copyfile( str(pathlib.Path(__file__).parent.absolute()) + "/" + fblHexName,  odxPathSupplier + fblHexName)
shutil.copyfile( str(pathlib.Path(__file__).parent.absolute()) + "/" + fblComprEncrHexName,  odxPathSupplier + fblComprEncrHexName)
shutil.copyfile( str(pathlib.Path(__file__).parent.absolute()) + "/" + hsmUpdHexName,  odxPathSupplier + hsmUpdHexName)
print("Copied the release files to the Supplier path")

# Cleanup DAG SwDl files
cleanupDagSwDlFiles("app")
cleanupDagSwDlFiles("fbl_upd")
cleanupDagSwDlFiles("hsm_upd_container")
print("Cleaned up all the temporary files")