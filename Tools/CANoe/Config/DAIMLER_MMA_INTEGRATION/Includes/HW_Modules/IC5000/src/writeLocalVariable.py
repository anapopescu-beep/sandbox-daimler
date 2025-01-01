
import isystem.connect as ic
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-o', '--output', type=str)
parser.add_argument('-n', '--name', type=str)
parser.add_argument('-v', '--value', type=str)
args = parser.parse_args()

# Global Variables#

# ISystem Classes #
xCManager = ic.ConnectionMgr()
xCManager.connectMRU('')
xCDataController = ic.CDataController(xCManager)

# Debugger Function #
def debugger_writeLocalVariable():
    try:
        _ret = False
        xCDataController.modify(ic.IConnectDebug.fRealTime, f"{args.name}", get_hex(args.value))
        _ret = "Successfully overwritten local variable" + f"{args.name}" + " with value 0x" + f"{args.value}"
    except Exception as e:
        _ret = str(e)
    return str(_ret)

def get_hex(value):
    convert_string = int(value, base=16)
    convert_hex = hex(convert_string)
    return convert_hex

if __name__ == '__main__':
    f = open(args.output, "w")
    f.write(debugger_writeLocalVariable())
    f.close()