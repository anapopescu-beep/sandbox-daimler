from func_timeout import  func_timeout, FunctionTimedOut
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
xCExecutionController = ic.CExecutionController(xCManager)
xCAddressController = ic.CAddressController(xCManager)

# Debugger Function #
def debugger_isCPUStoppedAtBP():
    """
    This function stops the target
    :return: string
    """
    _ret = False
    try:
        xCPUStatus = xCExecutionController.getCPUStatus()
        execPointAddress = xCPUStatus.getExecutionPoint()
        adresses = ic.AddressVector()
        adresses.append(execPointAddress)
        names = ic.StrVector()
        types = ic.IntVector()
        xCAddressController.getFunctionNames(adresses, names, types)
        if xCExecutionController.waitUntilStopped(int(args.timeout), isThrow=True):
            if xCPUStatus.isStopped():
                if xCPUStatus.isStopReasonBP():
                    _ret = "CPU stopped at BP in function " + f"{names[0]}"

    except Exception as e:
        _ret = str(e)
    return str(_ret)

if __name__ == '__main__':
    f = open(args.output, "w")
    f.write(debugger_isCPUStoppedAtBP())
    f.close()
