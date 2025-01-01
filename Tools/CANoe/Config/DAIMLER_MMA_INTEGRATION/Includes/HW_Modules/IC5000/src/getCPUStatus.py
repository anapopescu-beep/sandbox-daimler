
import isystem.connect as ic
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-o', '--output', type=str)
args = parser.parse_args()

# Global Variables#

# ISystem Classes #
xCManager = ic.ConnectionMgr()
xCManager.connectMRU('')
xDebug = ic.CDebugFacade(xCManager)

# Debugger Function #
def debugger_getCPUStatus():
    _ret = False
    try:
        xCPUStatus = xDebug.getCPUStatus()
        if xCPUStatus.isStopped():
            _ret = 'CPU is Stopped'
        elif xCPUStatus.isRunning():
            _ret = 'CPU is Running'
        elif xCPUStatus.isReset():
            _ret = 'CPU is Resetting'
        elif xCPUStatus.isHalted():
            _ret = 'CPU is Halted'
        elif xCPUStatus.isWaiting():
            _ret = 'CPU is Waiting'
        elif xCPUStatus.isIdle():
            _ret = 'CPU is Idle'
    except Exception as e:
        _ret = str(e)
    return str(_ret)

if __name__ == '__main__':
    f = open(args.output, "w")
    f.write(debugger_getCPUStatus())
    f.close()