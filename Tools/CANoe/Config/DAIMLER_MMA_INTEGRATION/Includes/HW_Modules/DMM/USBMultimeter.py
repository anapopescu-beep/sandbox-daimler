import pyvisa
import time

csReadVoltAC = "MEASure:VOLTage:AC?";
csReadCurrAC = "MEASure:CURRent:AC?";
csReadPeriod = "MEASure:PERiod?";
csReadResistor = "MEASure:RESistance?";
csReadFResistor = "MEASure:FRESistance?";
csReadFrequency = "MEASure:FREQuency?";
csReadDiode = "MEASure:DIODe?";
csReadVoltDC = "MEASure:VOLTage:DC?";
csReadCurrDC = "MEASure:CURRent:DC?";
csCloseChannels = "ROUTe:CLOSe";
csQueryClosedChannels = "ROUTe:CLOSe?";
csOpenMultipleChannels = "ROUTe:OPEN";
csScannerCardState = "ROUTe:STATe?";
csSetCardReadingFunction = "ROUTe:SCAN:FUNCtion ";
csSetMultipleReadVoltDC = "VOLT:DC";
csSetMultipleReadVoltAC = "VOLT:AC";
csSetMultipleReadFrequency = "FREQuency";
csSetMultipleReadResistance = "RESistance";
csSetMultipleReadFResistance = "FRESistance";
csSetMultipleReadPeriod = "PERiod";
csSetMultipleReadDiode = "DIODe";
csSetMultipleReadCurrentAC = "CURR:AC";
csSetMultipleReadCurrentDC = "CURR:DC";
csDisableChannel = "NONE";
csChannelState = "ROUTe:SCAN:FUNC?";
csReadScanInterval = "ROUTe:SCAN:TIMER?";
csSetScanInterval = "ROUTe:SCAN:TIMER";
csReadNbOfScans = "ROUTe:SCAN:COUNT?";
csSetNbOfScans = "ROUTe:SCAN:COUNT";
csScanState = "ROUTe:SCAN:STATe?";
csRunScanMode = "ROUTe:SCAN:SCAN";
csRunStepMode = "ROUTe:SCAN:STEP";
csTrigCardReading = "rout:scan";
csFetchData = "fetch?";
csSetTempUnit = "UNIT Cel";
csSetTCOupleType = "TCOuple:TYPE K,";
csReadTerminalsPos = "ROUTe:TERMinals?";
csReadTemp = "MEASure:TCOuple?";

class DMM:
        def __init__(self, _sMultimeter):
                self.rm = pyvisa.ResourceManager()
                self.inst = self.rm.open_resource(_sMultimeter)

        def SingleReadCurrentDC(self):
                currentDC = self.inst.query(csReadCurrDC)
                return currentDC

        def SingleReadVoltageDC(self):
                voltageDC = self.inst.query(csReadVoltDC)
                return voltageDC
        
        def SingleReadCurrentAC(self):
                currentAC = self.inst.query(csReadCurrAC)
                return currentAC

        def SingleReadVoltageAC(self):
                voltageAC = self.inst.query(csReadVoltAC)
                return voltageAC

        def SingleReadTemperature(self):
                singleTemp = self.inst.query(csReadTemp)
                return singleTemp
        
        def ReadMultipleThermocouples(self):
                for i in range(1,11):
                        csSetTCOupleType                = "TCOuple:TYPE K,@" + str(i)
                        csSetCardReadingFunction        = "ROUTe:SCAN:FUNCtion " + str(i) + ', "TCOuple"'
                        
                        setCardFunc     = self.inst.write(csSetCardReadingFunction)
                        setTCOupleType  = self.inst.write(csSetTCOupleType)
                        
                setTempUnit = self.inst.write(csSetTempUnit)
                scanMode = self.inst.write(csRunScanMode)
                time.sleep(5)
                multipleTemperatures = self.inst.query(csFetchData)
                return multipleTemperatures

        def ReadTerminalPos(self):
                terminalPos = self.inst.query(csReadTerminalsPos)
                return terminalPos
                
