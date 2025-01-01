
import isystem.connect as ic
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-o', '--output', type=str)
parser.add_argument('-n', '--function_name', type=str)
parser.add_argument('-l', '--line_offset', type=str)
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
def debugger_deleteRelativeFunctionBpAtLine():
    _ret = False
    try:
        ret_add_val = xDebug.getFunctionAddress(args.function_name)
        if ret_add_val:
            xCLineLocation = xCAddressController.getSourceLineAtAddress(ret_add_val.getAddress())
            functionLineNumber = xCLineLocation.getLineNumber()
            sourceFile = xCLineLocation.getFileName()
            if functionLineNumber and sourceFile:
                abs_line_num = functionLineNumber + int(args.line_offset)
                bp_status = debugger_deleteBreakPointAtLine(sourceFile, abs_line_num)
                if bp_status == True:
                    _ret = "BP deleted at line " + f"{abs_line_num}" + " (function line: " + f"{functionLineNumber}" + " offset: " + f"{args.line_offset}" + ")"
                else:
                    _ret = "BP deleted at line " + f"{abs_line_num}" + " (function line: " + f"{functionLineNumber}" + " offset: " + f"{args.line_offset}" + ")"
            else:
                _ret = "Invalid line number or file name. LN: " + f"{functionLineNumber}" + " FN: " + f"{sourceFile}"
        else:
            _ret = "The function address can`t be read. Please check function name!"
    except Exception as e:
        _ret = str(e)
    return str(_ret)

def debugger_deleteBreakPointAtLine(lineNumber, sfileName):
    _ret = False
    try:
        if xCBreakPointController.deleteBP(lineNumber, sfileName) == 0:
            _ret = True
        else:
            _ret = "Could not delete breakpoint."
    except Exception as e:
        _ret = str(e)
    return _ret

if __name__ == '__main__':
    f = open(args.output, "w")
    f.write(debugger_deleteRelativeFunctionBpAtLine())
    f.close()