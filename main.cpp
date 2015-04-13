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
    file = fopen("/dev/cu.usbmodem1421","w");  //Opening device file
    
    while(true){
    fprintf(file,"%d", 'a'); //Writing to the file
    fprintf(file,"%c",','); //To separate digits
    fprintf(file,"%c",','); //To separate digits
    }
   // std::cout << file[0] << std::endl;
    
    fclose(file);
    
    return 0;
}
