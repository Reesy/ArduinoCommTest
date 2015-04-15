import serial
import time
ser = serial.Serial('/dev/cu.usbmodem1421', 9600)



time.sleep(2);
ser.write('>');

for x in range(49, 57):
	time.sleep(1)
	ser.write(chr(x));
	print x
