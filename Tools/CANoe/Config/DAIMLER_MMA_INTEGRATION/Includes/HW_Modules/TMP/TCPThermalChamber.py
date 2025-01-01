import sys
import time
import socket

#output file path
filePath = r'C:\MKS\DAIMLER_MMA\Includes\sTCMeasureFile.txt'

#commands
sendDataCMD = '$01E '
readDataCMD = b'$01I\r'

cmdStart    = '01000000000000000000000000000000\r'
cmdStop     = '00000000000000000000000000000000\r'

class TC:
    def __init__(self, HOST, PORT):
        self.server = (HOST, PORT)
        self.socket = socket.socket(family=socket.AF_INET, type=socket.SOCK_STREAM)
        try:
            self.socket.connect(self.server)
        except socket.error as err:
            f = open(filePath, 'w+')
            f.write("Connection error: %s" % err)
            f.close()
            sys.exit(1)

        self.sData = bytearray()
        self.rData = bytearray()

    def ChamberSendCommand(self, data):
        self.socket.send(data)

    def ChamberReadData(self):
        for char in bytearray(readDataCMD):
            self.rData.append(char)
        self.socket.send(self.rData)
        time.sleep(1)
        self.dataFromThermalChamber = self.socket.recv(1024)
        return str(self.dataFromThermalChamber.decode())
        
    def ChamberSetSetpoint(self, data):
        self.sendDataCMD = sendDataCMD + "{:06.1f}".format(data)+ " 0025.0 0000.0 " + cmdStop
        for char in bytearray(bytes(self.sendDataCMD.encode())):
            self.sData.append(char)
        self.socket.send(self.sData)

    def ChamberReadSetpoint(self):
        return str(float(self.ChamberReadData().split(' ')[0]))

    def ChamberReadTemperature(self):
        return str(float(self.ChamberReadData().split(' ')[1]))

    def ChamberTurnOn(self):
        currentSetpoint = float(self.ChamberReadSetpoint())
        if currentSetpoint < -40 or currentSetpoint > 180:
            f = open(filePath, 'w+')
            f.write("Selected setpoint is out of range!\n")
            f.close()
            sys.exit(1)
        else:
            self.sendDataCMD = sendDataCMD + "{:06.1f}".format(currentSetpoint)+ " 0025.0 0000.0 " + cmdStart
            for char in bytearray(bytes(self.sendDataCMD.encode())):
                self.sData.append(char)
            self.socket.send(self.sData)

    def ChamberTurnOff(self):
        currentSetpoint = float(self.ChamberReadSetpoint())
        if currentSetpoint < -40 or currentSetpoint > 180:
            f = open(filePath, 'w+')
            f.write("Selected setpoint is out of range!\n")
            f.close()
            sys.exit(1)
        else:
            self.sendDataCMD = sendDataCMD + "{:06.1f}".format(currentSetpoint)+ " 0025.0 0000.0 " + cmdStop
            for char in bytearray(bytes(self.sendDataCMD.encode())):
                self.sData.append(char)
            self.socket.send(self.sData)
