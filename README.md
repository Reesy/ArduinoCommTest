# ArduinoCommunicationC++

OOP wrapper for the C code found at https://github.com/todbot/arduino-serial/ This is a library that allows you to communicate via serial port with an arduino. 

Instructions for use: The blink_test.ino file is a script that needs to be loaded onto an arduino, 
this script will wait for communication via serial port. To engage communication write '>' to the arduino. 
After communication has begun sending the arduino the numbers 0 - 9 will make an LED on port 9 shine to varying degrees.

arduino-serial-main: running this will engage communication with arduino and loop through 0-9 on brightness.
blinkTest.py: running this will engage communication with arduino and loop through 0-9 on brightness.

It is important to note that you will need to write down your own serial port where you see '/dev/cu.usbmodem1421'
9600 is the default baud-rate but you should modify this as and when required. 

