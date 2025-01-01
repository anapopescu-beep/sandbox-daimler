import subprocess
import os

# ---------------------------- Configuration section ---------------------------- #

# Paths
buildOutputsPath = "S:/Tools/Build_Env/Workspace/Outputs";

hexViewPath = "S:/Tools/HexView/Installation/HexView-1.13.01/hexview.exe";
hexName = "vHsmUpd_ModularUpdateContainer.hex";
appHeaderName = "vHsmUpd_ContainerHeaderApp.hex";

# ---------------------------- Start of execution area ---------------------------- #

# 1 - Create the container
os.system("CreatevHsmUpdMultipleModuleContainerAndHeader.bat");

# 2 - Prepare the hex files
#   Merge the appheader
subprocess.call(hexViewPath + " " + hexName +" /MO:"+ appHeaderName + " /XI /s -o " + hexName);

print("Merged the App Header");

#   Split the data in 0x8 data and 0xA data
subprocess.call(hexViewPath + " " + hexName +" /AR:0x80000000-0x80FFFFFF /XI /s -o " + hexName + "_0x8");
subprocess.call(hexViewPath + " " + hexName +" /AR:0xA0000000-0xA0FFFFFF /XI /s -o " + hexName + "_0xA");

#   Merge the data into one 0xA file
subprocess.call(hexViewPath + " " + hexName + "_0xA" +" /MO:"+ hexName + "_0x8;0x20000000" + " /XI /s -o " + hexName);

print("Remapped 0x80000000...0x80FFFFFF to 0xA0000000...0xA0FFFFFF");

#   Align the hexfile
subprocess.call(hexViewPath + " " + hexName + " /AD:0x20 /AL:0x20 /XI /s -o " + hexName);

print("Aligned the data for TriCore flashing");

#   Remove temporary files
os.remove(hexName + "_0x8");
os.remove(hexName + "_0xA");

