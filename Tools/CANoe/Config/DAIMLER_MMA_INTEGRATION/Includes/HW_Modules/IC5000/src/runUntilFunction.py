import isystem.connect
import isystem.connect as ic
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-o', '--output', type=str)
parser.add_argument('-f', '--function', type=str)
parser.add_argument('-t', '--timeout', type=str)

args = parser.parse_args()

# Global Variables#

# ISystem Classes #
xCManager = ic.ConnectionMgr()
xCManager.connectMRU('')
xDebug = ic.CDebugFacade(xCManager)
xCExecutionController = ic.CExecutionController(xCManager)
xCAddressController = ic.CAddressController(xCManager)

# Debugger Function #
def debugger_runUntilFunction():
    _ret = False
    try:
        if args.timeout == "1":
            ltimeout = ic.CExecutionController.TOUT_1s
        elif args.timeout == "10":
            ltimeout = ic.CExecutionController.TOUT_10s
        elif args.timeout == "100":
            ltimeout = ic.CExecutionController.TOUT_100s
        if xDebug.runUntilFunction(args.expression, ltimeout) == isystem.connect.S_OK:
            _ret = "Current location: " + f"{args.expression}" + " reached within a timeout of " + f"{ltimeout}"
    except Exception as e:
        _ret = str(e)
    return str(_ret)

if __name__ == '__main__':
    f = open(args.output, "w")
    f.write(debugger_runUntilFunction())
    f.close()