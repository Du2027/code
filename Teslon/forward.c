#include<stdio.h>
#include<pigpio.h>

int main(){
        if(gpioInitialise() < 0){
                printf("Setup failed\n");
                return -1;
        }

        gpioSetMode(23, PI_OUTPUT);
        gpioSetMode(27, PI_OUTPUT);

        gpioWrite(23, 1);
        gpioWrite(27, 1);

        return 0;
}
