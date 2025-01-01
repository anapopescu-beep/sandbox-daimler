
import isystem.connect as ic
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-o', '--output', type=str)
parser.add_argument('-n', '--function_name', type=str)
parser.add_argument('-b', '--is_enabled', type=str)
args = parser.parse_args()

# Global Variables#

# ISystem Classes #
xCManager = ic.ConnectionMgr()
xCManager.connectMRU('')
xCExecutionController = ic.CExecutionController(xCManager)
xCBreakPointController = ic.CBreakpointController(xCManager)

# Debugger Function #
def debugger_enableBP():
    """
    This function stops the target
    :return: string
    """
    _ret = False
    try:
        if args.is_enabled == "False":
            xCBreakPointController.setEnabled(False, args.function_name)
            _ret = "False"
        elif args.is_enabled == "True":
            xCBreakPointController.setEnabled(True, args.function_name)
            _ret = "True"
    except Exception as e:
        _ret = str(e)
    return str(_ret)

if __name__ == '__main__':
    f = open(args.output, "w")
    f.write(debugger_enableBP())
    f.close()