//
//  main.cpp
//  ArduinoCommTest
//
//  Created by James Rees on 10/04/2015.
//  Copyright (c) 2015 James Rees. All rights reserved.
//

#include <iostream>


int main(int argc, const char * argv[]) {
    // insert code here...
        std::cout << "Hello, World!\n";
    
    
   
    

    //const FILE *file;
    FILE* file;
    file = fopen("/dev/cu.usbmodem1411","w");  //Opening device file
    for(int i = 0; i < 10000; i++){
   // std::cout << "The file is: " << file << std::endl;
    
        fprintf(file,"%d", 9); //Writing to the file
        
    }
    fclose(file);
    
}
