//
//  arduino-serial-main.cpp
//  ArduinoCommTest
//
//  Created by James Rees on 13/04/2015.
//  Copyright (c) 2015 James Rees. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <unistd.h> 
#include "arduino-serial-lib.h"


int main(int argc, const char * argv[]){
    std::cout << "Test" << std::endl;
    arduinoSerialLib mySerial;
    
   
    int dev = mySerial.serialport_init("/dev/cu.usbmodem1421", 9600);
    //This blinks twice, an initial message needs to be sent to the device to be aware of communications.
    sleep(2);
    mySerial.serialport_write(dev, ">");
    
    for(int i = 0; i < 10; i++){
        usleep(1000);
        std::string s = std::to_string(i);
        std::cout << s << std::endl;
        mySerial.serialport_write(dev, s.c_str());
        
    }
    mySerial.serialport_close(dev);
    return 0;
}