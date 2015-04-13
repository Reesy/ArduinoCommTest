//
//  main.cpp
//  ArduinoCommTest
//
//  Created by James Rees on 10/04/2015.
//  Copyright (c) 2015 James Rees. All rights reserved.
//

#include <iostream>
#include <thread>
#include <chrono>



int main(int argc, const char * argv[]) {
    //const FILE *file;
   

    FILE* file;
    file = fopen("/dev/cu.usbmodem1411","w");  //Opening device file
    
    for(int i = 0;i < 3;i++)
    {
        
        fprintf(file,"%d", 'a'); //Writing to the file
       // fprintf(file,"%c",','); //To separate digits
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      
    }
    fclose(file);
    return 0;
}
