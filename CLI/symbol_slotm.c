#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "putils/colors.h"
#include <time.h>

char rand_char (char char_arr[], int sizeofarr){
   return char_arr[rand() % (sizeofarr / sizeof(char))];
}

void print_slot(char slot_chars[], int size, char special_char){
   int same = 0;
   for (int i = 0; i < size * 2 + 1; i++) {
      printf("-");
   }
   printf("\n");

   for (int i = 0; i < size; i++) {
      if (slot_chars[i] == special_char) {
         printf("|%s%c%s",COLOR_RED, slot_chars[i],COLOR_RESET);
      }
      else {
         printf("|%c", slot_chars[i]);
      }
   }
   for (int i = 0; i < size; i++) {
      if (slot_chars[i] == special_char) {
         same++;
      }
   }
   if (same == size) {
      printf("%s", COLOR_YELLOW);
   }
   printf("|\n");

   for (int i = 0; i < size * 2 + 1; i++) {
      printf("-");
   }
   printf("\n");
}

bool same_char(char char_arr[], int size){
   int i = 0;
   for (int n = 0; n < size; n++) {
      if (char_arr[n] != char_arr[0]) {
         return false;
      }
   }
   return true;
}

int main(int argc,char** argv){
   int cash = 0;
   int haswon = 0;
   int smallwin_counter = 0;
   int bigwin_counter = 0;
   int nothing_counter = 0;
   int same = 0;
   int bet = 0;
   int iteration = 0;
   int maxit = 0;
   char symbols[] = {'$','&','%','?','!'};
   srand(time(NULL));

   bool endgame = false;
   bool endless = false;
   bool benchmark = false;

   if(argc != 1){
      if(argc == 3 && strcmp(argv[1], "--endless") == 0){endless = true;}
      else if (argc == 3 && strcmp(argv[1], "--benchmark") == 0) {benchmark = true;}

      else {
         printf("what are these args?");
         return -1;
      }
   }

   if (endless) {
      printf("Welcome to P-Slot-Mashine at endless Mode!\n");
      bet = atoi(argv[2]);
   }
   else if (benchmark) {
      printf("Welcome to P-Slot-Mashine at benchmark Mode!\n");
      maxit = atoi(argv[2]);
   }
   else {
      printf("Welcome to P-Slot-Mashine!\n");
   }

   while (cash <= 0 && benchmark == false) {
      printf("With how much cash would you like to start?\n");
      scanf("%d", &cash);
      if (endless == true && cash < bet) {
         cash = 0;
         printf("You wouldnt have enough money!\n");
      }
   }

   char slot_chars[3];
   while (endgame == false) {
      if(endless == false && benchmark == false){
         while (bet <= 0 || bet > cash) {
            printf("How much do you want to bet?\n");
            scanf("%d", &bet);
         }
         printf("\n");
      }

      // checking for wins
      for (int i = 0; i < sizeof(slot_chars) / sizeof(char); i++) {
         slot_chars[i] = rand_char(symbols, sizeof(symbols));
      }
      if (same_char(slot_chars, sizeof(slot_chars) / sizeof(char))) {
         haswon = 1;
         printf("%s", COLOR_YELLOW);
      }
      for (int i = 0; i < sizeof(slot_chars) / sizeof(char); i++) {
         if (slot_chars[i] == symbols[0]) {
            same++;
         }
         else {
            break;
         }
      }
      if (same == sizeof(slot_chars) / sizeof(char)) {
         haswon = 2;
      }

      print_slot(slot_chars, sizeof(slot_chars) / sizeof(char), symbols[0]);
      printf("%s", COLOR_RESET);

      switch (haswon) {
         case 0:
            nothing_counter++;
            if(benchmark){break;}
            printf("You havent won and betted %d. Try again!\n", bet);
            break;
         case 1:
            smallwin_counter++;
            if(benchmark){break;}
            printf("You have won! You betted %d and won %d\n", bet, bet * 10);
            cash = cash + bet * 10;
            break;
         case 2:
            bigwin_counter++;
            if(benchmark){break;}
            printf("YOU WON BIG! You betted %d and won %d\n", bet, bet * 50);
            cash = cash + bet * 50;
            break;
      }

      if (benchmark == false) {
         cash = cash - bet;
         printf("You have %d$ left\n", cash);
      }
      if (endless == false && benchmark == false) {bet = 0;}

      haswon = 0;
      same = 0;
      iteration++;

      if (cash <= 0 && benchmark == false) {
         printf("You have lost :O\n\n");
         endgame = true;
      }
      else if (benchmark && iteration >= maxit ) {endgame = true;}

      if (endgame) {
         if (benchmark||endless) {
            printf("big win %d | small win %d | nothing %d | at %d iterations", bigwin_counter, smallwin_counter, nothing_counter, iteration);
         }
         else{
            printf("You won big %d times and small %d times and nothing %d times.\nYou played for %d iterations", bigwin_counter, smallwin_counter, nothing_counter, iteration);
         }
      }
   }
}
