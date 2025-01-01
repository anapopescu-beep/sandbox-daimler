
import isystem.connect as ic
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-o', '--output', type=str)
parser.add_argument('-t', '--type', type=str)
parser.add_argument('-n', '--name', type=str)
parser.add_argument('-s', '--offset', type=str)
args = parser.parse_args()

# Global Variables#

# ISystem Classes #
xCManager = ic.ConnectionMgr()
xCManager.connectMRU('')
xDebug = ic.CDebugFacade(xCManager)
xCAddressController = ic.CAddressController(xCManager)

# Debugger Function #
def debugger_readVariable():
    _ret = False
    try:
        xCMemAddress = xCAddressController.getVariableAddress(f"{args.name}")
        varMemArea = xCMemAddress.getMemArea()
        varAddress = xCMemAddress.getAddress()
        vType = ic.SType()
        if args.type == "uint8":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 8
            xCValueType = xDebug.readValue(ic.IConnectDebug.fRealTime, varMemArea, varAddress + (1 * int(args.offset)), vType)
            _ret = f"{hex(xCValueType.getLong())}"
        elif args.type == "sint8":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 8
            xCValueType = xDebug.readValue(ic.IConnectDebug.fRealTime, varMemArea, varAddress + (1 * int(args.offset)), vType)
            _ret = f"{hex(xCValueType.getInt())}"
        elif args.type == "uint16":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 16
            xCValueType = xDebug.readValue(ic.IConnectDebug.fRealTime, varMemArea, varAddress + (2 * int(args.offset)), vType)
            _ret = "Variable " + f"{args.name}" + " is equal to " + f"{hex(xCValueType.getLong())}"
        elif args.type == "sint16":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 16
            xCValueType = xDebug.readValue(ic.IConnectDebug.fRealTime, varMemArea, varAddress + (2 * int(args.offset)), vType)
            _ret = f"{hex(xCValueType.getInt())}"
        elif args.type == "uint32":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 32
            xCValueType = xDebug.readValue(ic.IConnectDebug.fRealTime, varMemArea, varAddress + (4 * int(args.offset)), vType)
            _ret = f"{hex(xCValueType.getLong())}"
        elif args.type == "sint32":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 32
            xCValueType = xDebug.readValue(ic.IConnectDebug.fRealTime, varMemArea, varAddress + (4 * int(args.offset)), vType)
            _ret = f"{hex(xCValueType.getInt())}"
        elif args.type == "uint64":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 64
            xCValueType = xDebug.readValue(ic.IConnectDebug.fRealTime, varMemArea, varAddress + (8 * int(args.offset)), vType)
            _ret = f"{hex(xCValueType.getLong())}"
        elif args.type == "sint64":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 64
            xCValueType = xDebug.readValue(ic.IConnectDebug.fRealTime, varMemArea, varAddress + (8 * int(args.offset)), vType)
            _ret = f"{hex(xCValueType.getInt())}"
        elif args.type == "float":
            vType.m_byType = ic.SType.tFloat
            xCValueType = xDebug.readValue(ic.IConnectDebug.fRealTime, varMemArea, varAddress, vType)
            _ret = f"{hex(xCValueType.getFloat())}"
    except Exception as e:
        _ret = str(e)
    return str(_ret)

if __name__ == '__main__':
    f = open(args.output, "w")
    f.write(debugger_readVariable())
    f.close()