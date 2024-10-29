#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char* argv[]){
   int mapsize;
   bool debugmode = false;

   if(argc == 2 && strcmp(argv[1], "-DEBUG") == 0){
      debugmode = true;
   }

   printf("Mapsize : \n");
   scanf("%d", &mapsize);                 // TODO: check for non-numerical input, would take the ascii value as size
   if(debugmode==true){printf("Mapsize: %d\n", mapsize);}

   int map_p1[mapsize][mapsize];    // sizeof returns 400(10*10*sizeof(int))
   int map_p2[mapsize][mapsize];
   int i;
   int n;

   for(i = 0; i < sizeof(map_p1[0]) / 4; i++){
      for (n=0; n < sizeof(map_p1[0]) / 4; n++) {
         map_p1[i][n] = 0;
         printf("%d", map_p1[i][n]);
      }
      printf("\n");
   }

   return 0;
}
