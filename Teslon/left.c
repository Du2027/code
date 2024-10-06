#include<stdio.h>
#include<pigpio.h>

int main(){
        if(gpioInitialise() < 0){
                printf("Setup failed\n");
                return -1;
        }

        gpioSetMode(22, PI_OUTPUT);

        gpioWrite(22, 1);

        return 0;
}
