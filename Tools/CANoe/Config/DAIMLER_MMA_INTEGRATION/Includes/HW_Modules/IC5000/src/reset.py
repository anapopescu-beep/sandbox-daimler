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
xCExecutionController = ic.CExecutionController(xCManager)

# Debugger Function #
def debugger_reset():
    """
    This function resets the target
    :return: string
    """
    _ret = False
    xCExecutionController.reset()
    _ret = 'RESET command successful'
    return str(_ret)

if __name__ == '__main__':
    f = open(args.output, "w")
    f.write(debugger_reset())
    f.close()