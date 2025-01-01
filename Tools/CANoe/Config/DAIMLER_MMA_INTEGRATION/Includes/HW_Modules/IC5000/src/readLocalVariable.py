
import isystem.connect as ic
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-o', '--output', type=str)
parser.add_argument('-n', '--name', type=str)
args = parser.parse_args()

# Global Variables#

# ISystem Classes #
xCManager = ic.ConnectionMgr()
xCManager.connectMRU('')
xCDataController = ic.CDataController(xCManager)

# Debugger Function #
def debugger_readLocalVariable():
    _ret = False
    try:
        value = xCDataController.evaluate(ic.IConnectDebug.fRealTime, f"{args.name}")
        if value.isError() == False:
            _ret = f"{hex(value.getLong())}"
    except Exception as e:
        _ret = str(e)
    return str(_ret)

if __name__ == '__main__':
    f = open(args.output, "w")
    f.write(debugger_readLocalVariable())
    f.close()