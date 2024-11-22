#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./putils/colors.h"
#include "./putils/psort.h"

void print_spaces(short times){
   for(int i = 0; i < times; i++){
      printf(" ");
   }
}

void print_boat_places(int** map1, int size, int cords[], int iteration){
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
         for (int n1 = 0; n1 < iteration; n1++) {
            if (i * size + n + 1 == cords[n1]) {
               printf("%s", COLOR_RED);
            }
         }
         printf("00 %s", COLOR_RESET);
      }
   printf("\n");
   linecount++;
   }
}

void print_maps(int** map1, int** map2, int size, short spaces, const short MODE, int boats){
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
         if(map1[i][n] == 1){
            printf("%s", COLOR_GREEN);
            printf("BB%s ", COLOR_RESET);
         }
         else {
            printf("00 ");
         }
      }

      print_spaces(spaces);

      for (int n = 0; n < size; n++) {
         if(map2[i][n] == 1 && MODE == 1){
            printf("%s", COLOR_RED);
         }
         printf("00%s ", COLOR_RESET);
      }

      printf("\n");
      linecount++;
   }
}

int cord_to_dec(char cord[5], int mapsize){
   int dec_value = 0;
   dec_value = (cord[0] - 65) * mapsize;

   if(cord[1] == '0'){
      dec_value = dec_value + (cord[3] - '0') * 10 + cord[4] - '0';
   }
   else {
      dec_value = dec_value + (cord[2] - '0') * 10 + cord[3] - '0';
   }

   return dec_value;
}

int random_int(int max) {
   return (rand() % max)  + 1;
}

int main(int argc, char **argv){
   srand(time(NULL));
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
      place_phase = false;
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

   int cords_p[boats];
   int cord_buffer = 0;
   char buffer[5];
   bool isvalid = false;
   bool warschon = false;

   while(place_phase){
      for (int i = 0; i < boats; i++) {
         print_boat_places(map_p1, mapsize, cords_p, i);
         while (isvalid == false) {
            printf("\nWhere do you want to place a boat? %sA0:01%s\n", COLOR_BLUE, COLOR_RESET);
            scanf("%s", buffer);
            cord_buffer = cord_to_dec(buffer, mapsize);
            for (int n = 0; n < i; n++) {
               if(cords_p[n] == cord_buffer){
                  warschon = true;
                  if(debugmode){printf("DEBUG:DOUBLE FOUND\n");}
               }
            }

            if(cord_buffer <= (buffer[0] - 65) * mapsize + mapsize && buffer[0] <= 64 + mapsize && cord_buffer >= 0 && warschon == false){
               isvalid = true;
               if(debugmode){printf("DEBUG:ISVAL - CORD:%s - INT:%d\n", buffer, cord_buffer);}
            }
            warschon = false;
         }

         isvalid = false;
         cords_p[i] = cord_buffer;
         cord_buffer = 0;
      }
      place_phase = false;
   }

   bool has_dupes = true;
   int buff;
   int cntr = 0;
   int cords_b[boats];

   for (int i = 0; i < boats; i++) {
      while (has_dupes) {
         cntr = 0;
         buff = random_int(mapsize*mapsize);
         for (int n = 0; n < i; n++) {
            if(buff == cords_b[n]){
               cntr++;
               break;
            }
         }
         if (cntr == 0) {
            cords_b[i] = buff;
            has_dupes = false;
         }
      }
      has_dupes = true;
   }

   if(debugmode){
      has_dupes = true;
      for (int i = 0; i < boats; i++) {
         while (has_dupes) {
            cntr = 0;
            buff = random_int(mapsize*mapsize);
            for (int n = 0; n < i; n++) {
               if(buff == cords_p[n]){
                  cntr++;
                  break;
               }
            }
            if (cntr == 0) {
               cords_p[i] = buff;
               has_dupes = false;
            }
         }
         has_dupes = true;
      }
   }

   bubblesort_int(cords_p, boats);
   bubblesort_int(cords_b, boats);

   if (debugmode) {
      printf("DEBUG: POS's:");
      for (int i = 0; i < boats; i++) {
         printf("%d|%d;", cords_p[i], cords_b[i]);
      }
      printf("\n");
   }

   int zaeler = 0;
   for (int i = 0; i < mapsize; i++) {
      for (int n = 0; n < mapsize; n++) {
         for (int n1 = 0; n1 < boats; n1++) {
            if(zaeler == cords_p[n1] - 1){
               map_p1[i][n] = 1;
               if (zaeler == cords_b[n1] - 1) {
                  map_p2[i][n] = 1;
               }
            }
            else if (zaeler == cords_b[n1] - 1) {
               map_p2[i][n] = 1;
            }
         }
         zaeler++;
      }
   }

   if(debugmode){print_maps(map_p1, map_p2, mapsize, 5, 1, boats);}
   else{print_maps(map_p1, map_p2, mapsize, 5, 0, boats);}

   for (int i = 0; i < mapsize; i++) {
      free(map_p1[i]);
      free(map_p2[i]);
   }
   free(map_p1);
   free(map_p2);

   return 0;
}
