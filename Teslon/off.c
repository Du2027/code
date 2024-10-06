#include<stdio.h>
#include<pigpio.h>

int main(){
        if(gpioInitialise() < 0){
                printf("Setup failed\n");
                return -1;
        }

        gpioSetMode(23, PI_OUTPUT);
        gpioSetMode(27, PI_OUTPUT);
        gpioSetMode(22, PI_OUTPUT);
        gpioSetMode(24, PI_OUTPUT);

        gpioWrite(23, 0);
        gpioWrite(27, 0);
        gpioWrite(22, 0);
        gpioWrite(24, 0);

        return 0;
}
