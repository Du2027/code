#include <stdio.h>
#include <stdlib.h>
#include "colors.h"

int main(int argc, char** argv){
   char** colorcodes = malloc(6 * sizeof(char*));
   for (int i = 0; i < 5; i++) {
      colorcodes[i] = malloc(10 * sizeof(char));
   }

   colorcodes[0] = COLOR_RED;
   colorcodes[1] = COLOR_GREEN;
   colorcodes[2] = COLOR_YELLOW;
   colorcodes[3] = COLOR_BLUE;
   colorcodes[4] = COLOR_PURPLE;
   colorcodes[5] = COLOR_CYAN;
   char* reset = COLOR_RESET;

   for (int i = 0; i < 6; i++) {
      printf("%sEXAMPLE text ...---???%s\n", colorcodes[i], reset);
   }
}
