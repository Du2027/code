#include <stdlib.h>
#include "pstr.h"

int** mk_2d_int(int sizex, int sizey){
   int** arr_2d = malloc(sizey * sizeof(int*));
   for(int i = 0; i < sizey; i++){
      arr_2d[i] = malloc(sizex * sizeof(int));
   }
   return arr_2d;
}

// num to string

void rm_2d_int(int** arr_2d, int sizey){
   for (int i = 0; i < sizey; i++) {
      free(arr_2d[i]);
   }
   free(arr_2d);
}
