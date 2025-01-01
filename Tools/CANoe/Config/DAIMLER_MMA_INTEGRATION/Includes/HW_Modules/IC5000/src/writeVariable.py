
import isystem.connect as ic
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-o', '--output', type=str)
parser.add_argument('-t', '--type', type=str)
parser.add_argument('-n', '--name', type=str)
parser.add_argument('-s', '--offset', type=str)
parser.add_argument('-v', '--value', type=str)
args = parser.parse_args()

# Global Variables#

# ISystem Classes #
xCManager = ic.ConnectionMgr()
xCManager.connectMRU('')
xDebug = ic.CDebugFacade(xCManager)
xCAddressController = ic.CAddressController(xCManager)

# Debugger Function #
def debugger_writeVariable():
    _ret = False
    try:
        xCMemAddress = xCAddressController.getVariableAddress(f"{args.name}")
        varMemArea = xCMemAddress.getMemArea()
        varAddress = xCMemAddress.getAddress()
        vType = ic.SType()
        if args.type == "uint8":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 8
            cValue = ic.CValueType(vType, get_hex(args.value))
            xDebug.writeValue(ic.IConnectDebug.fRealTime, varMemArea, varAddress + (1 * int(args.offset)), cValue)
            _ret = "Successfully overwritten variable " + f"{args.name}"+ " offset: "f"{args.offset}"+ " with value 0x" + f"{args.value}"
        elif args.type == "sint8":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 8
            cValue = ic.CValueType(vType, get_hex(args.value))
            xDebug.writeValue(ic.IConnectDebug.fRealTime, varMemArea, varAddress + (1 * int(args.offset)), cValue)
            _ret = "Successfully overwritten variable " + f"{args.name}"+ " offset: "f"{args.offset}"+ " with value 0x" + f"{args.value}"
        elif args.type == "uint16":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 16
            cValue = ic.CValueType(vType, get_hex(args.value))
            xDebug.writeValue(ic.IConnectDebug.fRealTime, varMemArea, varAddress + (2 * int(args.offset)), cValue)
            _ret = "Successfully overwritten variable " + f"{args.name}"+ " offset: "f"{args.offset}"+ " with value 0x" + f"{args.value}"
        elif args.type == "sint16":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 16
            cValue = ic.CValueType(vType, get_hex(args.value))
            xDebug.writeValue(ic.IConnectDebug.fRealTime, varMemArea, varAddress + (2 * int(args.offset)), cValue)
            _ret = "Successfully overwritten variable " + f"{args.name}"+ " offset: "f"{args.offset}"+ " with value 0x" + f"{args.value}"
        elif args.type == "uint32":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 32
            cValue = ic.CValueType(vType, get_hex(args.value))
            xDebug.writeValue(ic.IConnectDebug.fRealTime, varMemArea, varAddress + (4 * int(args.offset)), cValue)
            _ret = "Successfully overwritten variable " + f"{args.name}"+ " offset: "f"{args.offset}"+ " with value 0x" + f"{args.value}"
        elif args.type == "sint32":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 32
            cValue = ic.CValueType(vType, get_hex(args.value))
            xDebug.writeValue(ic.IConnectDebug.fRealTime, varMemArea, varAddress + (4 * int(args.offset)), cValue)
            _ret = "Successfully overwritten variable " + f"{args.name}"+ " offset: "f"{args.offset}"+ " with value 0x" + f"{args.value}"
        elif args.type == "uint64":
            vType.m_byType = ic.SType.tUnsigned
            vType.m_byBitSize = 64
            cValue = ic.CValueType(vType, get_hex(args.value))
            xDebug.writeValue(ic.IConnectDebug.fRealTime, varMemArea, varAddress + (8 * int(args.offset)), cValue)
            _ret = "Successfully overwritten variable " + f"{args.name}"+ " offset: "f"{args.offset}"+ " with value 0x" + f"{args.value}"
        elif args.type == "sint64":
            vType.m_byType = ic.SType.tSigned
            vType.m_byBitSize = 64
            cValue = ic.CValueType(vType, get_hex(args.value))
            xDebug.writeValue(ic.IConnectDebug.fRealTime, varMemArea, varAddress + (8 * int(args.offset)), cValue)
            _ret = "Successfully overwritten variable " + f"{args.name}"+ " offset: "f"{args.offset}"+ " with value 0x" + f"{args.value}"
    except Exception as e:
        _ret = str(e)
    return str(_ret)

def get_hex(value):
    convert_string = int(value, base=16)
    convert_hex = hex(convert_string)
    return convert_hex

if __name__ == '__main__':
    f = open(args.output, "w")
    f.write(debugger_writeVariable())
    f.close()