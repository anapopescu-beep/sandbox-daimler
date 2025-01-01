import isystem.connect
import isystem.connect as ic
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-o', '--output', type=str)
args = parser.parse_args()

# Global Variables#

# ISystem Classes #
xCManager = ic.ConnectionMgr()
xCManager.connectMRU('')
xCBreakPointController = ic.CBreakpointController(xCManager)

# Debugger Function #
def debugger_deleteAllBreakpoints():
    _ret = False
    try:
        if xCBreakPointController.deleteAll() == 0:
            _ret = 'Deleted all breakpoints'
    except Exception as e:
        _ret = str(e)
    return str(_ret)

if __name__ == '__main__':
    f = open(args.output, "w")
    f.write(debugger_deleteAllBreakpoints())
    f.close()