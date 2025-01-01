
import isystem.connect as ic
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-o', '--output', type=str)
parser.add_argument('-n', '--file_name', type=str)
parser.add_argument('-l', '--line_number', type=str)
args = parser.parse_args()

# Global Variables#

# ISystem Classes #
xCManager = ic.ConnectionMgr()
xCManager.connectMRU('')
xDebug = ic.CDebugFacade(xCManager)
xCAddressController = ic.CAddressController(xCManager)
xCExecutionController = ic.CExecutionController(xCManager)
xCBreakPointController = ic.CBreakpointController(xCManager)

# Debugger Function #
def debugger_setBreakPointAtLine():
    sfileName = args.file_name
    lineNumber = args.line_number
    _ret = False
    try:
        if xCBreakPointController.setBP(int(lineNumber), sfileName) == 0:
            _ret = "BP set"
        else:
            _ret = "Could not set breakpoint."
    except Exception as e:
        _ret = str(e)
    return str(_ret)

if __name__ == '__main__':
    f = open(args.output, "w")
    f.write(debugger_setBreakPointAtLine())
    f.close()