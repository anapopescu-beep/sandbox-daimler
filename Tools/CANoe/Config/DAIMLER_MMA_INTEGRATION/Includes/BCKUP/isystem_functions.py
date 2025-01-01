###########################
##  PYTHON & CAPL TEST  ###
###########################
from __future__ import print_function
from file import Parser
import isystem.connect as ic
import time

# GLOBALS #
newCommandFlag = False
iSYSInit = False
memory_accessFlag = ic.IConnectDebug.fRealTime
path = "S:\\Tools\\CANoe\\Config\\DAIMLER_MMA_INTEGRATION\\"
fin_name = "isystem_commands.INI"
fin_path = path + fin_name
fout_name = "isystem_response.INI"
fout_path = path + fout_name
parse = Parser(fin_path, fout_path)

xCManager = ic.ConnectionMgr()
xCManager.connectMRU('')
xDebug = ic.CDebugFacade(xCManager)
xLoaderController = ic.CLoaderController(xCManager)
xWorkSpaceController = ic.CWorkspaceController(xCManager)
xCBreakPointController = ic.CBreakpointController(xCManager)
xCExecutionController = ic.CExecutionController(xCManager)
xCDataController = ic.CDataController(xCManager)
xCAddressController = ic.CAddressController(xCManager)


# Debugger initializations #

def ISYSTEM_INIT():
    """
    Initialize all winIDEA objects used by the API
    :return:
    """
    if xCManager and xDebug and xWorkSpaceController and xLoaderController:
        iSYSInit = True
    else:
        iSYSInit = False
    return iSYSInit


# Functions used in CANOE to control the debugger. Input will be the .INI file #
def debugger_run():
    """
    This function runs the target.
    :return: true if successful
    """
    ret = False
    if ISYSTEM_INIT() == True:
        result = xDebug.run()
        ret = True
    return ret


def debugger_reset():
    """
    This function resets the target.
    :return: true if successful
    """
    ret = False
    if ISYSTEM_INIT() == True:
        result = xDebug.reset()
        ret = True
    return ret


def debugger_download():
    """
    This function downloads the files defined in winIDEA on the target.
    :return: true if successful
    """
    ret = False
    if ISYSTEM_INIT() == True:
        result = xDebug.download()
        ret = True
    return ret


def debugger_stop():
    """
    This function stops the target.
    :return: true if successful
    """
    ret = False
    if ISYSTEM_INIT() == True:
        xDebug.stop()
        ret = True
    return ret


def debugger_step():
    """
    This function steps one statement in the source code.
    :return: true if successful
    """
    ret = False
    if ISYSTEM_INIT() == True:
        xDebug.stepHigh()
        ret = True
    return ret


def debugger_stepOver():
    """
    This function steps one statement in the source code, does not enter functions.
    :return: true if successful
    """
    ret = False
    if ISYSTEM_INIT() == True:
        xDebug.stepOverHigh()
        ret = True
    return ret


def debugger_setBreakPointAtLine(lineNumber, sfileName):
    ret = False
    if iSYSInit == False:
        try:
            xCBreakPointController.setBP(lineNumber, sfileName)
            ret = True
        except:
            ret = "Could not set breakpoint at line."
    return ret


def debugger_getAddress(lineNumber, sfileName):
    address = xCAddressController.getAddressOfSourceLine(sfileName, lineNumber)
    return address


def debugger_setRelativeFunctionBpAtLine(functionName, lineOffset):
    ret = False
    if ISYSTEM_INIT() == True:
        ret_add_val = xDebug.getFunctionAddress(functionName)
        if ret_add_val:
            xCLineLocation = xCAddressController.getSourceLineAtAddress(ret_add_val.getAddress())
            functionLineNumber = xCLineLocation.getLineNumber()
            sourceFile = xCLineLocation.getFileName()
            if functionLineNumber and sourceFile:
                abs_line_num = functionLineNumber + int(lineOffset)
                bp_status = debugger_setBreakPointAtLine(abs_line_num, sourceFile)
                if bp_status == True:
                    ret = True
                else:
                    ret = "The breakpoint was not set to following line: " + f"{abs_line_num}" + " (function line: " + f"{functionLineNumber}" + " offset: " + f"{lineOffset}" + ")"
            else:
                ret = "Invalid line number or file name. LN: " + f"{functionLineNumber}" + " FN: " + f"{sourceFile}"
        else:
            ret = "The function address can`t be read. Please check function name!"
    else:
        ret = "The iSYSTEM class is not initialized"
    return ret


def debugger_readVariable(variableType, variableName, offset):
    ret = False
    if iSYSInit == False:
        xCMemAddress = xCAddressController.getVariableAddress(f"{variableName}")
        varMemArea = xCMemAddress.getMemArea()
        varAddress = xCMemAddress.getAddress()
        vType = ic.SType()
        if variableType == "uint8":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 8
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress + (1 * int(offset)), vType)
            ret = hex(xCValueType.getLong())
        elif variableType == "sint8":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 8
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress + (1 * int(offset)), vType)
            ret = hex(xCValueType.getInt())
        elif variableType == "uint16":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 16
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress + (2 * int(offset)), vType)
            ret = hex(xCValueType.getLong())
        elif variableType == "sint16":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 16
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress + (2 * int(offset)), vType)
            ret = hex(xCValueType.getInt())
        elif variableType == "uint32":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 32
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress + (4 * int(offset)), vType)
            ret = xCValueType.getLong()
        elif variableType == "sint32":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 32
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress + (4 * int(offset)), vType)
            ret = hex(xCValueType.getInt())
        elif variableType == "uint64":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 64
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress + (8 * int(offset)), vType)
            ret = hex(xCValueType.getLong())
        elif variableType == "sint64":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 64
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress + (8 * int(offset)), vType)
            ret = hex(xCValueType.getInt())
        elif variableType == "float":
            vType.m_byType = ic.SType.tFloat
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress, vType)
            ret = xCValueType.getFloat()
        elif variableType == "compound":
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress, vType)
            ret = xCValueType.getResult()
        elif variableType == "address":
            vType.m_byType = ic.SType.tAddress
            xCValueType = xDebug.readValue(memory_accessFlag, varMemArea, varAddress, vType)
            ret = xCValueType.getResult()
        else:
            ret = "Incorrect type. Supported types are: uint8/int8, uint16/int16, uint32/int32,float ,address, compound"
    else:
        ret = "The iSYSTEM class is not initialized"
    return ret


def debugger_writeVariable(variableType, variableName, value, offset):
    ret = False
    if iSYSInit == False:
        xCMemAddress = xCAddressController.getVariableAddress(f"{variableName}")
        varMemArea = xCMemAddress.getMemArea()
        varAddress = xCMemAddress.getAddress()
        vType = ic.SType()
        if variableType == "uint8":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 8
            cValue = ic.CValueType(vType, get_hex(value))
            xDebug.writeValue(memory_accessFlag, varMemArea, varAddress + (1 * int(offset)), cValue)
            ret = True
        elif variableType == "sint8":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 8
            cValue = ic.CValueType(vType, value)
            xDebug.writeValue(memory_accessFlag, varMemArea, varAddress + (1 * int(offset)), cValue)
            ret = True
        elif variableType == "uint16":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 16
            cValue = ic.CValueType(vType, value)
            xDebug.writeValue(memory_accessFlag, varMemArea, varAddress + (2 * int(offset)), cValue)
            ret = True
        elif variableType == "sint16":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 16
            cValue = ic.CValueType(vType, value)
            xDebug.writeValue(memory_accessFlag, varMemArea, varAddress + (2 * int(offset)), cValue)
            ret = True
        elif variableType == "uint32":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 32
            cValue = ic.CValueType(vType, value)
            xDebug.writeValue(memory_accessFlag, varMemArea, varAddress + (4 * int(offset)), cValue)
            ret = True
        elif variableType == "sint32":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 32
            cValue = ic.CValueType(vType, value)
            xDebug.writeValue(memory_accessFlag, varMemArea, varAddress + (4 * int(offset)), cValue)
            ret = True
        else:
            ret = "Incorrect type. Supported types are: uint8/int8, uint16/int16, uint32/int32"
    else:
        ret = "The iSYSTEM class is not initialized"
    return ret


def debugger_deleteAllBreakpoints():
    ret = False
    if iSYSInit == False:
        res = xCBreakPointController.deleteAll()
        if res == 1:
            ret = "No breakpoints were deleted because none existed."
        elif res == 0:
            ret = True
    else:
        ret = "The iSYSTEM class is not initialized"
    return ret


def debugger_deleteFunctionBreakpoint(functionName):
    ret = False
    if iSYSInit == False:
        res = xCBreakPointController.deleteBP(f"{functionName}")
        if res == 1:
            ret = "No breakpoints were deleted at this symbol " + functionName
        elif res == 0:
            ret = True
    else:
        ret = "The iSYSTEM class is not initialized "
    return ret


def debugger_getCPUStatus():
    """
    This function checks the status of the CPU.
    :return: CPU Status
    """
    ret = False
    xCPUStatus = xDebug.getCPUStatus()
    if xCPUStatus.isStopped():
        ret = "STOP"
    elif xCPUStatus.isRunning():
        ret = "RUNNING"
    elif xCPUStatus.isReset():
        ret = "RESET"
    elif xCPUStatus.isHalted():
        ret = "HALTED"
    elif xCPUStatus.isWaiting():
        ret = "WAITING"
    elif xCPUStatus.isAttach():
        ret = "SoC ATTACH"
    elif xCPUStatus.isIdle():
        ret = "IDLE"
    return ret


def debugger_isCPUStoppedAtBP():
    """
    This function checks if CPU is stopped at a breakpoint.
    :return: True if stopped.
    """
    ret = False
    xCPUStatus = xDebug.getCPUStatus()
    if xCPUStatus.isStopped():
        if xCPUStatus.isStopReasonBP():
            ret = True
        elif xCPUStatus.isStopReasonExplicit():
            ret = "CPU stopped by user"
        elif xCPUStatus.isStopReasonStep():
            ret = "CPU stopped by step"
        elif xCPUStatus.isStopReasonHW():
            ret = "CPU stopped by HW"
    else:
        ret = "CPU is not stopped"
    return ret


def debugger_readLocalVariable(variableName):
    ret = False
    if ISYSTEM_INIT() == True:
        value = xCDataController.evaluate(memory_accessFlag, variableName)
        if value.isError() == False:
            ret = value.getInt()
        else:
            ret = False
    else:
        ret = "The iSYSTEM class is not initialized"
    return ret


def debugger_writeLocalVariable(variableName, value):
    ret = False
    if ISYSTEM_INIT():
        ret = xCDataController.modify(memory_accessFlag, variableName, value)
    else:
        ret = "The iSYSTEM class is not initialized"
    return ret

def debugger_runUntilReturn(timeout):
    ret = False
    if ISYSTEM_INIT():
        ret = xCExecutionController.runUntilReturn(timeout, False)
        if ret == 0:
            ret = True
    else:
        ret = "The iSYSTEM class is not initialized"

def eraseFile():
    file = Parser(fin_path, fout_path)
    file.fin.truncate(0)
    file.fin.close()

def get_hex(value):
    convert_string = int(value, base=16)
    convert_hex = hex(convert_string)
    return convert_hex


debugger_commands = {
    'run': [debugger_run, []],
    'reset': [debugger_reset, []],
    'download': [debugger_download, []],
    'stop': [debugger_stop, []],
    'step': [debugger_step, []],
    'stepOver': [debugger_stepOver, []],
    'setBreakPointAtLine': [debugger_setBreakPointAtLine, []],
    'getAddress': [debugger_getAddress, []],
    'setRelativeFunctionBpAtLine': [debugger_setRelativeFunctionBpAtLine, []],
    'readVariable': [debugger_readVariable, []],
    'writeVariable': [debugger_writeVariable, []],
    'deleteAllBreakpoints': [debugger_deleteAllBreakpoints, []],
    'deleteFunctionBreakpoint': [debugger_deleteFunctionBreakpoint, []],
    'getCPUStatus': [debugger_getCPUStatus, []],
    'isCPUStoppedAtBP': [debugger_isCPUStoppedAtBP, []],
    'readLocalVariable': [debugger_readLocalVariable, []],
    'writeLocalVariable': [debugger_writeLocalVariable, []],
    'runUntilReturn': [debugger_runUntilReturn, []],
    'eraseFile': [eraseFile, []]
}

#     CHECK HERE    ############
# while True:
#     if len(parse.content) != 0:
parse.debugger_instructions(debugger_commands)
