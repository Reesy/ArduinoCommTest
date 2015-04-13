#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <iostream>

volatile int stop =false;
unsigned char buf[255];
long res;
int myCount=0;
int maxCount=10000;            // Number of cycles to time out serial port
void init_port(int *fd, unsigned int baud)
{
    struct termios options;
    tcgetattr(*fd,&options);
    switch(baud)
    {
        case 9600: cfsetispeed(&options,B9600);
            cfsetospeed(&options,B9600);
            break;
        case 19200: cfsetispeed(&options,B19200);
            cfsetospeed(&options,B19200);
            break;
        case 38400: cfsetispeed(&options,B38400);
            cfsetospeed(&options,B38400);
            break;
        default:cfsetispeed(&options,B9600);
            cfsetospeed(&options,B9600);
            break;
    }
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    tcsetattr(*fd,TCSANOW,&options);
}

int main()
{
    int fd;
    fd = open("/dev/cu.usbmodem1411", O_RDWR | O_NOCTTY | O_NDELAY); // List usbSerial devices using Terminal ls /dev/tty.*
    std::cout << fd << std::endl;
    if(fd == -1) {                        // Check for port errors
        std::cout << fd << std::endl;
        perror("Unable to open serial port\n");
        return (0);
    }
    
    std::cout << "Serial Port is open" << std::endl;
    
    // Write to Serial Port
    init_port(&fd,9600);                  //set serial port to 9600,8,n,1
  // write(fd, "\n", 1);                  // chr(10) start comms
    write(fd, "2", 1);                  // 0 = off 1 = on 2 = ask LED state
    write(fd, "\n", 1);                  // chr(13) terminate comms
    std::cout << "Write to serial port OK" << std::endl;
    std::cout << fd << std::endl;
    // Read from Serial Port
    /*
    while (stop ==false) {
        myCount++;
        res = read(fd,buf,1);
        
        std::cout << res << std::endl;
        buf[res]=0;
      
      
        if (buf[0]==13) {            // Stop reading serial port if value = 13
            stop = true;
        }
        if (buf[0]!=13) {            // If value = 13 then don't display it
            if (buf[0]>0) {            // If received greater than 0, display it
                std::cout << "Led Value is: " << (int)buf[0]<< std::endl;
                myCount=0;      // Byte received so reset timer
            }
        }
        if (myCount>maxCount) {         // Stop reading port if time out
            stop = true;
            myCount=0;
            std::cout << "Serial Port Timed Out" << std::endl;
        }
    }
     */
    for(int i = 0; i < 1000000000; i ++){
         write(fd, "2", 1);                  // 0 = off 1 = on 2 = ask LED state
        
    }
    close(fd);                              // Close the Serial Port
    return (0);                              // End program
}