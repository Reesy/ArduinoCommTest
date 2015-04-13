//
//  arduino-serial-main.cpp
//  ArduinoCommTest
//
//  Created by James Rees on 13/04/2015.
//  Copyright (c) 2015 James Rees. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "arduino-serial-lib.h"




int main(int argc, const char * argv[]){
    
    char const* file = "/dev/cu.usbmodem1421";
    
    int dev = serialport_init(file, 9600);
    
    
    return 0;
}