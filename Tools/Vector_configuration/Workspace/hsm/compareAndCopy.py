import shutil
import os
import os.path
from os import path

sourceFolder1 = 'S:\\Tools\\Vector_configuration\\Workspace\\HSM\\Appl\\GenData\\Components\\'
sourceFolder2 = 'S:\\Tools\\Vector_configuration\\Workspace\\HSM\\Appl\\GenData\\src\\'
sourceFolder3 = 'S:\\Tools\\Vector_configuration\\Workspace\\HSM\\Appl\\GenData\\inc\\'
sourceFolder4 = 'S:\\Tools\\Vector_configuration\\Workspace\\HSM\\Appl\\GenData\\'
sourceFolderVector ={sourceFolder1,sourceFolder2,sourceFolder3,sourceFolder4}

destinationFolder = 'S:\\Components\\HSM\\Supplier\\DaVinci_generated\\'

CONST_STRING_GENERATED_AT_MCAL = "DATE, TIME"
CONST_STRING_GENERATION_TIME = "Generation Time:"
CONST_STRING_GENERATED_AT = "Generated at:"

copiedFiles = open ("S:\\Tools\\Vector_configuration\\Workspace\\HSM\\CopiedFiles.txt", "w")
copiedFiles.write("The following files have been copied: \n")

for index, sourceFolderName in enumerate(sourceFolderVector):
    if(path.exists(sourceFolderName)):
        for filename in os.listdir(sourceFolderName):
            if filename.endswith(".c") or filename.endswith(".h"): 

                destinationFileName = destinationFolder+filename
                SourceFileName = sourceFolderName+filename

                #Check if destination folder contains file
                if os.path.exists(destinationFileName):
                
                    # Open file for readin in text mode (default mdoe)
                    f1 = open(SourceFileName)
                    f2 = open(destinationFileName)

                    #read the first line from the files
                    f1_line = f1.readline()
                    f2_line = f2.readline()
                    #Variable to store if difference found
                    foundDifference = 0

                    #Loop if either file1 or file2 has not reacehed EOFError
                    while ((f1_line != '' or f2_line != '') and foundDifference < 1):
                        if((CONST_STRING_GENERATION_TIME not in f1_line) and (CONST_STRING_GENERATED_AT not in f1_line) and (CONST_STRING_GENERATED_AT_MCAL not in f1_line)):

                            #strip the leading whitespaces
                            f1_line = f1_line.rstrip()
                            f2_line = f2_line.rstrip()
                            
                            #compare the lines from both file
                            if (f1_line != f2_line):
                                
                                #increment line counter
                                foundDifference += 1

                        #read the next line from the file
                        f1_line = f1.readline()
                        f2_line = f2.readline()

                    #close the files
                    f1.close()
                    f2.close()
                
                    if(foundDifference == 1):
                        shutil.copy(SourceFileName,destinationFolder)
                        print(SourceFileName+"\n")
                        copiedFiles.write(SourceFileName)
                        copiedFiles.write("\n")

                    continue
                else:
                    shutil.copy(SourceFileName,destinationFolder)
                    print(SourceFileName+"\n")
                    copiedFiles.write(SourceFileName)
                    copiedFiles.write("\n")
                    
            else:
                continue
        print("\n")
        copiedFiles.write("\n")
        
copiedFiles.close()