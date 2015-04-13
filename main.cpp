//
//  main.cpp
//  ArduinoCommTest
//
//  Created by James Rees on 10/04/2015.
//  Copyright (c) 2015 James Rees. All rights reserved.
//
#include <chrono>
#include <thread>
#include <iostream>
//#include "cArduino.h"



int main(int argc, const char * argv[]) {
    
  //  cArduino arduino(ArduinoBaundRate::B9600bps);
       //const FILE *file;
   
  
  
    FILE* file;
    file = fopen("/dev/cu.usbmodem1411","w");  //Opening device file
    
    while(true)
    {
        file = fopen("/dev/cu.usbmodem1411","w");  //Opening device file
        fprintf(file,"%d", 'a'); //Writing to the file
        fprintf(file,"%c",','); //To separate digits
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
  
        
      
    }
    fclose(file);
    
    return 0;
}
