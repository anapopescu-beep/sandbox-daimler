import xml.etree.ElementTree as ET
import subprocess
import shutil
import pathlib
import os

# ---------------------------- Configuration section ---------------------------- #

# Release numbers and versions for App
oldAppPartNumber = "1749025500";
newAppPartNumber = "1749025500";

oldAppReleaseVer = "231800";
newAppReleaseVer = "232121";

oldAppReleaseTag = oldAppPartNumber + "_001_" + oldAppReleaseVer;
newAppReleaseTag = newAppPartNumber + "_001_" + newAppReleaseVer;

# Release numbers and versions for FBL
oldFblPartNumber = "1749041800";
newFblPartNumber = "1749041800";

oldFblReleaseVer = "231100";
newFblReleaseVer = "231800";

oldFblReleaseTag = oldFblPartNumber + "_001_" + oldFblReleaseVer;
newFblReleaseTag = newFblPartNumber + "_001_" + newFblReleaseVer;

# Release numbers and versions for HSM
oldHsmPartNumber = "1749041900";
newHsmPartNumber = "1749041900";

oldHsmReleaseVer = "224400";
newHsmReleaseVer = "230500";

oldHsmReleaseTag = oldHsmPartNumber + "_001_" + oldHsmReleaseVer;
newHsmReleaseTag = newHsmPartNumber + "_001_" + newHsmReleaseVer;

# Paths
buildOutputsPath = "S:/Tools/Build_Env/Workspace/Outputs";

odxPath = "S:/Tools/Odx/Workspace/Daimler_1608/Supplier/";
odxOutPath = "S:/Tools/Odx/Workspace/Daimler_1608/Out/.";
trafoPath = "S:/Tools/DTS_Trafo/Installation/Trafo-9.02.015/bin/TrafoCoApp.exe";

hexViewPath = "S:/Tools/HexView/Installation/HexView-1.13.01/hexview.exe";

# App Paths
appPath = buildOutputsPath + "/app/Out/";

appHexName = "app.hex";

appPPAddressSpace = "0xA00FFF80-0xA00FFFFF";

# FBL Updater Paths
fblPath = buildOutputsPath + "/fbl_upd/Out/";
fblHexName = "fbl_upd.hex";

# ---------------------------- Function to apply the new release tag to ODX-F file ---------------------------- #

def applyTagToOdx(odxName, oldTag, newTag):
    # Input-output files for App
    oldAppName = odxPath + odxName + ".odx-f";
    newAppName = odxPath + odxName + "_temp.odx-f";

    fin = open(oldAppName, "rt");

    # Output file to write the result to
    fout = open(newAppName, "wt");

    # For each line in the input file
    for line in fin:
	    # Read replace the string and write to output file
	    fout.write(line.replace(oldTag, newTag));
    
    # Close input and output files
    fin.close();
    fout.close();

    # Remove the temporary file
    os.remove(oldAppName);
    os.rename(newAppName, oldAppName);

    print("Release tag changed to: "+ newTag + " for: " + oldAppName);

# ---------------------------- Function to apply CRC and CCCv2 to the ODX-F file ---------------------------- #

def applyChecksumAndSigToOdx (appType, odxName):

    newAppName = odxPath + odxName + ".odx-f";

    appCrcPath = appType + ".crc";
    appCccv2Path = appType + "_cccv2.sig";

    # Read whole file to a string and tidy up the file - the space/comma order is important
    appCrc = open(appCrcPath, "r").read().replace("0x", "").replace(", ", "");
    appCccv2 = open(appCccv2Path, "r").read().replace("0x", "").replace(" ,", "");

    # Start parsing the XML
    xmlTree = ET.parse(newAppName);
    rootElement = xmlTree.getroot();

    # Function to traverse the tree
    def traverse(elem, level=0):
        yield elem, level

        for child in elem:
            yield from traverse(child, level + 1)

    # Traverse the whole XML to find our elements and write the data
    for elem, level in traverse(rootElement):
        if elem.tag == "FW-SIGNATURE":
            elem.text = appCccv2;
        if elem.tag == "FW-CHECKSUM":
            elem.text = appCrc;

    # Write the modified xml file
    xmlTree.write(newAppName, encoding="UTF-8", xml_declaration=True);

    print("CCCv2 and CRC have been added to: " + newAppName);

# ---------------------------- Function to generate SMR-F files with Trafo from our new ODX-F file ---------------------------- #

def generateSmrf(odxName):

    newAppName = odxPath + odxName + ".odx-f";

    trafoCmd = "\"" + trafoPath + "\"" + " /fsplit " + "\"" + newAppName + "\"" + " /outdir " + "\"" + odxOutPath + "\"" + " /log /resultUI";
    subprocess.call(trafoCmd);

# ---------------------------- Start of execution area ---------------------------- #

# 1 - Apply the new release tag to ODX-F files
applyTagToOdx("application", oldAppReleaseTag, newAppReleaseTag);
applyTagToOdx("fbl", oldFblReleaseTag, newFblReleaseTag);
applyTagToOdx("HSM_Updater", oldHsmReleaseTag, newHsmReleaseTag);


# Replace the version of the containers as well
applyTagToOdx("application", oldAppReleaseVer, newAppReleaseVer);
applyTagToOdx("fbl", oldFblReleaseVer, newFblReleaseVer);
applyTagToOdx("HSM_Updater", oldHsmReleaseVer, newHsmReleaseVer);

# Replace the revision label
applyTagToOdx("application", oldAppReleaseVer[:2] + "." + oldAppReleaseVer[2:4] + "." + oldAppReleaseVer[4:6], newAppReleaseVer[:2] + "." + newAppReleaseVer[2:4] + "." + newAppReleaseVer[4:6]);
applyTagToOdx("fbl", oldFblReleaseVer[:2] + "." + oldFblReleaseVer[2:4] + "." + oldFblReleaseVer[4:6], newFblReleaseVer[:2] + "." + newFblReleaseVer[2:4] + "." + newFblReleaseVer[4:6]);
applyTagToOdx("HSM_Updater", oldHsmReleaseVer[:2] + "." + oldHsmReleaseVer[2:4] + "." + oldHsmReleaseVer[4:6], newHsmReleaseVer[:2] + "." + newHsmReleaseVer[2:4] + "." + newHsmReleaseVer[4:6]);

# 2 - Prepare the hex files

#   Copy App to our local folder from the outputs folder
#shutil.copyfile(appPath + appHexName, str(pathlib.Path(__file__).parent.absolute()) + "/" + appHexName);

#print("Copied latest built "+ appHexName + " from "+ appPath);

#   Split the data in 0x8 data and 0xA data
#subprocess.call(hexViewPath + " " + appHexName +" /AR:0x80000000-0x80FFFFFF /XI /s -o " + appHexName + "_0x8");
#subprocess.call(hexViewPath + " " + appHexName +" /AR:0xA0000000-0xA0FFFFFF /XI /s -o " + appHexName + "_0xA");

#   Merge the data into one 0xA file
#subprocess.call(hexViewPath + " " + appHexName + "_0xA" +" /MO:"+ appHexName + "_0x8;0x20000000" + " /XI /s -o " + appHexName);

print("Remapped 0x80000000...0x80FFFFFF to 0xA0000000...0xA0FFFFFF");

#   Align the hexfile
#subprocess.call(hexViewPath + " " + appHexName + " /AD:0x20 /AL:0x20 /XI /s -o " + appHexName);

print("Aligned the data for TriCore flashing");

#   Remove everything from this address space to get rid of the PP
#subprocess.call(hexViewPath + " " + appHexName + " /S /CR:"+ appPPAddressSpace +" /XI /s -o " + appHexName);

#print("Removed data from "+ appPPAddressSpace);

#   Fill first 1000h
#subprocess.call(hexViewPath + " " + appHexName + " /FR:0xA0068000,0x1000 /FP:0xFF /XI /s -o " + appHexName);
print("Filled first 1000h to lower block count");


#   Remove temporary files
#os.remove(appHexName + "_0x8");
#os.remove(appHexName + "_0xA");

#   Generate the CCCv2 and CRC files
#os.system("dag_swdl_files_create.py -i " + appHexName);

#   Copy FBL updater to our local folder from the outputs folder, no additional processing needed here
#shutil.copyfile(fblPath + fblHexName, str(pathlib.Path(__file__).parent.absolute()) + "/" + fblHexName);

print("Copied latest built " + fblHexName + " from "+ fblPath);

#   Generate the CCCv2 and CRC files
#os.system("dag_swdl_files_create.py -i " + fblHexName);

# 3 - Apply CRC and CCCv2 information to ODX
#applyChecksumAndSigToOdx ("app", "application");
#applyChecksumAndSigToOdx ("fbl_upd", "FBL");

# 4 - Generate SMR-F files
#generateSmrf("application");
#generateSmrf("fbl");

# 5 - Cleanup DAG SwDl files
#def cleanupDagSwDlFiles(appType):
#    os.remove(appType + ".crc");
#    os.remove(appType + "_cccv2.sig");
#    os.remove(appType + "_enc.hex");
#    os.remove(appType + "_enc_cccv2.sig");
#    os.remove(appType + "_lz77.hex");
#    os.remove(appType + "_lz77_cccv2.sig");
#    os.remove(appType + "_lz77_enc.hex");
#    os.remove(appType + "_lz77_enc_cccv2.sig");

#cleanupDagSwDlFiles("app");
#cleanupDagSwDlFiles("fbl_upd");

print("Cleaned up DAG SWDL files");