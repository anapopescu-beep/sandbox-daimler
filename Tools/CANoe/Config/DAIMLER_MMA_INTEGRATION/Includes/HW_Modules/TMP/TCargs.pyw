import sys
import time
from TCPThermalChamber import *

# define connection parameters
HOST = '10.47.32.10'
PORT = 2049

sTC = TC(HOST,PORT)

try:
        if sys.argv[1] == 'sSetSetpoint':
                data = float(sys.argv[2])
                if data < -40 or data > 180:
                        f = open(filePath, 'w+')
                        f.write("Selected setpoint is out of range!\n")
                        f.close()
                        sys.exit(1)
                else:
                        sSetSetpoint = sTC.ChamberSetSetpoint(data)
                        if sSetSetpoint is None:
                                f = open(filePath, 'w+')
                                f.write('Setpoint changed to ' + str(data) +' degrees Celsius.')
                                f.close()

                        else:
                                f = open(filePath, 'w+')
                                f.write('Setpoint NOT set!')
                                f.close()

        elif sys.argv[1] == 'sReadSetpoint':
                sReadSetpoint = sTC.ChamberReadSetpoint()
                f = open(filePath, 'w+')
                f.write(sReadSetpoint)
                f.close()

        elif sys.argv[1] == 'sReadTemperature':
                sReadTemperature = sTC.ChamberReadTemperature()
                f = open(filePath, 'w+')
                f.write(sReadTemperature)
                f.close()

        elif sys.argv[1] == 'sReadData':
                sReadData = sTC.ChamberReadData()
                f = open(filePath, 'w+')
                f.write(sReadData)
                f.close()

        elif sys.argv[1] == 'sChamberTurnOn':
                sChamberTurnOn = sTC.ChamberTurnOn()
                if sChamberTurnOn is None:
                        f = open(filePath, 'w+')
                        f.write('Thermal chamber is turned ON!')
                        f.close()
                else:
                        f = open(filePath, 'w+')
                        f.write('Thermal chamber is still OFF!')
                        f.close()                        

        elif sys.argv[1] == 'sChamberTurnOff':
                sChamberTurnOff = sTC.ChamberTurnOff()
                if sChamberTurnOff is None:
                        f = open(filePath, 'w+')
                        f.write('Thermal chamber is turned OFF!')
                        f.close()
                else:
                        f = open(filePath, 'w+')
                        f.write('Thermal chamber is still ON [OR] other ERROR is reported!')
                        f.close()
                
except:
        f = open(filePath, 'a')
        f.write('Error occurred!')
        f.close()





 



 


