#include<stdio.h>
#include<pigpio.h>
#include<string.h>


int main(int argc, char* argv[]){
        if(gpioInitialise() < 0){
                printf("Setup failed\n");
                return -1;
        }
        if(argc != 2){
                printf("Argument-count error\n");
                return -1;
        }

        int Pin = atoi(argv[1]);
        printf("Trying Pin %d\n", Pin);

        gpioSetMode(Pin, PI_OUTPUT);
        gpioWrite(Pin, 1);
        printf("LOW\n");
        gpioSleep(PI_TIME_RELATIVE, 3, 0);
        gpioWrite(Pin, 0);
        printf("HIGH\n");
        gpioSleep(PI_TIME_RELATIVE, 5, 0);
        gpioWrite(Pin, 1);

        return 0;
}
