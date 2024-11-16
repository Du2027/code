#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "./putils/colors.h"

typedef struct{
   int x;
   int y;
} touple;

typedef struct{
   int value;
   bool is_declared;
} integer;

void print_spaces(int times){
   for(int i = 0; i < times; i++){
      printf(" ");
   }
}

integer declare(integer var, int value){
   var.value = value;
   var.is_declared = true;
   return var;
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
   integer mapsize;
   integer boats;
   int beginner = 0;
   bool debugmode = false;

   if(argc == 2 && strcmp(argv[1], "-DEBUG") == 0){
      mapsize = declare(mapsize, 15);
      boats = declare(boats, 10);
      beginner = 1;
   }

   if(mapsize.is_declared == false){
      printf("How big should the map be?\n");
      scanf("%d", &mapsize.value);                 // TODO: check for non-numerical input, would take the ascii value as size; Maybe Rectangular Maps
   }

   int **map_p1 = malloc(mapsize.value * sizeof(int*));
   for(int i = 0; i < mapsize.value; i++) {
      map_p1[i] = malloc(mapsize.value * sizeof(int));
   }

   int **map_p2 = malloc(mapsize.value * sizeof(int*));
   for(int i = 0; i < mapsize.value; i++) {
      map_p2[i] = malloc(mapsize.value * sizeof(int));
   }

   for(int i = 0; i < mapsize.value / 4; i++){
      for(int n=0; n < mapsize.value / 4; n++){
         map_p1[i][n] = 0;
         map_p2[i][n] = 0;
      }
   }

   touple mapsize_p1 = {mapsize.value, mapsize.value};
   touple mapsize_p2 = {mapsize.value, mapsize.value};

   if(beginner == 0){
      char answer;
      while(answer != 'M' && answer != 'm' && answer != 'B' && answer != 'b'){
         printf("Who is the beginner?((M)e/(B)ot)\n");
         scanf("%s", &answer);
      }
      if(answer == 'M' || answer == 'm'){
         beginner = 1;
         }
      else {
         beginner = -1;
      }
   }
   if (boats.is_declared == false) {
      printf("With how many boats are we playing?\n");
      scanf("%d", &boats.value);
   }

   if (beginner == 1) {
      printf("Conclusion: %d boats on a %d² map and you as a beginner\n", boats.value,mapsize.value);
   }
   else {
      printf("Conclusion: %d boats on a %d² map and not you as a beginner\n", boats.value,mapsize.value);
   }

   bool endgame = false;
   int boatsl_p1 = boats.value;
   int boatsl_p2 = boats.value;
   char boatpos_p1[boats.value][3];

   for (int i = 0; i < boats.value; i++) {
      printf("Where do you want to place a boat? -h or --h for help\n");
      scanf("%s",boatpos_p1[i]);

      int line = 0;
      int spalt = 65;
      bool place = false;

      for (int n = 0; n < mapsize.value; n++) {
         if (boatpos_p1[i][0] == (char) spalt && (boatpos_p1[i][1] - '0') * 10 + (boatpos_p1[i][2] - '0') == line) {
            place = true;
         }

         for (int n1 = 0; n1 < mapsize.value; n1++) {
            if (place == true) {
               printf("%s%d%s",COLOR_RED,map_p1[n][n1],COLOR_RESET);
               printf("case");
               place = false;
            }
            else {
               printf("%d",map_p1[n][n1]);
            }
            spalt++;
         }
         line++;
         printf("\n");
      }
   }

   /*
   while (endgame == false) {
      print_maps(map_p1, mapsize_p1, map_p2, mapsize_p2, 5);
   }
   */

   for(int i = 0; i < mapsize.value; i++) {
      free(map_p1[i]);
      free(map_p2[i]);
   }
   free(map_p1);
   free(map_p2);

   return 0;
}
