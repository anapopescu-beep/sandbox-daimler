import isystem.connect
import isystem.connect as ic
import argparse
from ast import literal_eval

parser = argparse.ArgumentParser()
parser.add_argument('-o', '--output', type=str)
args = parser.parse_args()

# Global Variables#

# ISystem Classes #
xCManager = ic.ConnectionMgr()
xCManager.connectMRU('')
xDebug = ic.CDebugFacade(xCManager)
xCAddressController = ic.CAddressController(xCManager)
xCExecutionController = ic.CExecutionController(xCManager)

# Debugger Function #
def debugger_stepIn():
    _ret = False
    # try:
    xDebug.stepHigh() == isystem.connect.S_OK
    cpuStatus = xCExecutionController.getCPUStatus()
    execPointAddress = cpuStatus.getExecutionPoint()
    adresses = ic.AddressVector()
    adresses.append(execPointAddress)
    names = ic.StrVector()
    types = ic.IntVector()
    xCAddressController.getFunctionNames(adresses, names, types)
    _ret = "Stepped in function " + f"{names[0]}"


    # except Exception as e:
    #     _ret = str(e)
    return str(_ret)


if __name__ == '__main__':
    f = open(args.output, "w")
    f.write(debugger_stepIn())
    f.close()