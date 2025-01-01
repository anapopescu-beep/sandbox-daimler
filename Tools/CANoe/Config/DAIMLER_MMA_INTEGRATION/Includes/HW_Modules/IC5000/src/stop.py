
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
def debugger_stop():
    """
    This function stops the target
    :return: string
    """
    _ret = False
    try:
        xCExecutionController.stop()
        xCPUStatus = xCExecutionController.getCPUStatus()
        if xCPUStatus.isStopped():
            _ret = 'STOP command successful'
    except Exception as e:
        _ret = str(e)
    return str(_ret)

if __name__ == '__main__':
    f = open(args.output, "w")
    f.write(debugger_stop())
    f.close()