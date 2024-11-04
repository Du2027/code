#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
   int x;
   int y;
} touple;

void print_spaces(int times){
   for(int i = 0; i < times; i++){
      printf(" ");
   }
}

void print_maps(int **arr1, touple size_arr1, int **arr2, touple size_arr2, int spaces){
   int longest;

   if (size_arr1.y > size_arr2.y) {
      longest = size_arr1.y;
   }
   else {
      longest = size_arr2.y;
   }

   for (int i = 0; i < longest; i++) {
      if(i < size_arr1.y){
         for (int n = 0; n < size_arr1.x; n++) {
            printf("%d ",arr1[i][n]);
         }
      }
      if(i < size_arr2.y){
         print_spaces(spaces);
         for (int n = 0; n < size_arr2.x; n++) {
            printf("%d ",arr2[i][n]);
         }
      }
      printf("\n");
   }
}

int main(int argc, char* argv[]){
   int mapsize;
   bool debugmode = false;

   if(argc == 2 && strcmp(argv[1], "-DEBUG") == 0){
      debugmode = true;
   }

   printf("Mapsize : \n");
   scanf("%d", &mapsize);                 // TODO: check for non-numerical input, would take the ascii value as size

   if(debugmode==true){printf("Mapsize: %d\n", mapsize);}

   int **map_p1 = malloc(mapsize * sizeof(int*));
   for(int i = 0; i < mapsize; i++) {
      map_p1[i] = malloc(mapsize * sizeof(int));
   }

   int **map_p2 = malloc(mapsize * sizeof(int*));
   for(int i = 0; i < mapsize; i++) {
      map_p2[i] = malloc(mapsize * sizeof(int));
   }

   for(int i = 0; i < mapsize / 4; i++){
      for(int n=0; n < mapsize / 4; n++){
         map_p1[i][n] = 0;
         map_p2[i][n] = 0;
      }
   }

   touple mapsize_p1 = {mapsize, mapsize};
   touple mapsize_p2 = {mapsize, mapsize};

   print_maps(map_p1, mapsize_p1, map_p2, mapsize_p2, 5);
   return 0;
}