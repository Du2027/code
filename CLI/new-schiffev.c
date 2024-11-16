#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "./putils/colors.h"

void print_spaces(short times){
   for(int i = 0; i < times; i++){
      printf(" ");
   }
}

void print_boat_places(int** map1, int size, char** cords, int iteration){
   int linecount = 65;
   int uebertrag = 0;

   print_spaces(3);
   for (int n = 1; n < size + 1; n++) {
      if(n < 10){
         printf("%s0%d %s", COLOR_BLUE, n, COLOR_RESET);
      }
      else{
         printf("%s%d %s", COLOR_BLUE, n, COLOR_RESET);
      }
   }
   printf("\n");

   for (int i = 0; i < size; i++) {
      if (linecount > 90) {
         linecount = 65;
         uebertrag++;
      }

      printf("%s%c%d%s ", COLOR_BLUE, linecount, uebertrag, COLOR_RESET);
      for (int n = 0; n < size; n++) {
         printf("%02d ", map1[i][n]);
      }
   printf("\n");
   linecount++;
   }
}

void print_maps(int** map1, int** map2, int size, short spaces){
   int linecount = 65;
   int uebertrag = 0;

   print_spaces(3);
   for (int i = 0; i < 2; i++) {
      for (int n = 1; n < size + 1; n++) {
         if(n < 10){
            printf("%s0%d %s", COLOR_BLUE, n, COLOR_RESET);
         }
         else{
            printf("%s%d %s", COLOR_BLUE, n, COLOR_RESET);
         }
      }

      print_spaces(spaces);
   }

   printf("\n");

   for (int i = 0; i < size; i++) {
      if (linecount > 90) {
         linecount = 65;
         uebertrag++;
      }

      printf("%s%c%d%s ", COLOR_BLUE, linecount, uebertrag, COLOR_RESET);
      for (int n = 0; n < size; n++) {
         printf("%02d ", map1[i][n]);
      }

      print_spaces(spaces);

      for (int n = 0; n < size; n++) {
         printf("%02d ", map2[i][n]);
      }

      printf("\n");
      linecount++;
   }
}

int main(int argc, char **argv){
   int mapsize = 0;
   int boats = 0;
   int beginner = 0;          //0 Uninitialized 1 Me 2 Bot
   bool debugmode = false;
   bool place_phase = true;

   if(argc == 2 && strcmp(argv[1], "-DEBUG") == 0){
      mapsize = 10;
      boats = 10;
      beginner = 1;
      debugmode = true;
   }

   while (mapsize == 0 || mapsize < 1 || mapsize > 50) {
      printf("How big should the map be?\n");
      scanf("%d", &mapsize);
   }

   while (boats <= 0 || boats > 200 || boats >= mapsize * mapsize) {
      printf("How many boats should be there?\n");
      scanf("%d", &boats);
   }

   while (beginner == 0){
      char answer[100];
      printf("Who should beginn (M)e / (B)ot\n");
      scanf("%s", answer);
      if (answer[0] == 'M' || answer[0] == 'm') {
         beginner = 1;
      }
      else if (answer[0] == 'B' || answer[0] == 'b') {
         beginner = 2;
      }
   }

   if (debugmode == false) {
      switch (beginner) {
         case 1:
            printf("Conclusion: %d² map, %d boats, You as the beginner\n", mapsize, boats);
            break;
         case 2:
            printf("Conclusion: %d² map, %d boats, Bot as the beginner\n", mapsize, boats);
            break;
         default:
            printf("%sSOMETHING WENT WRONG, BEGINNER SWITCH ERR%s\n", COLOR_RED, COLOR_RESET);
      }
   }

   int **map_p1 = malloc(mapsize * sizeof(int*));
   for(int i = 0; i < mapsize; i++) {
      map_p1[i] = malloc(mapsize * sizeof(int));
   }

   int **map_p2 = malloc(mapsize * sizeof(int*));
   for(int i = 0; i < mapsize; i++) {
      map_p2[i] = malloc(mapsize * sizeof(int));
   }

   char** player_cords = malloc(boats * sizeof(char*));
   for(int i = 0; i < boats; i++) {
      player_cords[i] = malloc(5 * sizeof(char));
   }

   while(place_phase){
      for (int i = 0; i < boats; i++) {
         print_boat_places(map_p1, mapsize, player_cords, i);
         printf("\nWhere do you want to place a boat? %sXX:XX%s\n", COLOR_BLUE, COLOR_RESET);
         scanf("%s", player_cords[i]);
      }

      place_phase = false;
   }

   for (int i = 0; i < boats; i++) {
      free(player_cords[i]);
   }
   free(player_cords);

   for (int i = 0; i < mapsize; i++) {
      free(map_p1[i]);
      free(map_p2[i]);
   }
   free(map_p1);
   free(map_p2);

   return 0;
}
