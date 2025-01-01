
import signal
import time
import isystem.connect as ic
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-o', '--output', type=str)
parser.add_argument('-n', '--function_name', type=str)
args = parser.parse_args()

# Global Variables#

# ISystem Classes #
xCManager = ic.ConnectionMgr()
xCManager.connectMRU('')
xCBreakPointController = ic.CBreakpointController(xCManager)

# Debugger Function #
def debugger_deleteFunctionBreakpoint():
    _ret = False
    try:
        if xCBreakPointController.deleteBP(args.function_name) == 0:
            _ret = 'Deleted BP'
    except Exception as e:
        _ret = str(e)
    return str(_ret)

if __name__ == '__main__':
    f = open(args.output, "w")
    f.write(debugger_deleteFunctionBreakpoint())
    f.close()