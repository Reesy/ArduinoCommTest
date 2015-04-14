import serial
import time
ser = serial.Serial('/dev/cu.usbmodem1421', 9600)
while(True):
	time.sleep(0.1)
	ser.write('a')
	time.sleep(0.1)
	ser.write('s')
