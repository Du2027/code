#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pnums.h"

int main(int argc, char** argv){
   char andwort[20] = {48};

   basex_basey("dec", "69", 2, "oct", andwort);    // err with 69

   printf("-%s-\n", andwort);
   for (int i = 0; i < 20; i++) {
      printf("%d\n", andwort[i]);
   }
}
