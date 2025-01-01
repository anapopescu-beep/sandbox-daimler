import isystem.connect
import isystem.connect as ic
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-o', '--output', type=str)
parser.add_argument('-t', '--timeout', type=str)
args = parser.parse_args()

# Global Variables#

# ISystem Classes #
xCManager = ic.ConnectionMgr()
xCManager.connectMRU('')
xDebug = ic.CDebugFacade(xCManager)
xCExecutionController = ic.CExecutionController(xCManager)

# Debugger Function #
def debugger_runUntilReturn():
    _ret = False
    try:
        if args.timeout == "1":
            ltimeout = ic.CExecutionController.TOUT_1s
        elif args.timeout == "10":
            ltimeout = ic.CExecutionController.TOUT_10s
        elif args.timeout == "100":
            ltimeout = ic.CExecutionController.TOUT_100s
        if xCExecutionController.runUntilReturn(ltimeout, True) == isystem.connect.S_OK:
            _ret = 'runUntilReturn executed'
    except Exception as e:
        _ret = str(e)
    return str(_ret)

if __name__ == '__main__':
    f = open(args.output, "w")
    f.write(debugger_runUntilReturn())
    f.close()