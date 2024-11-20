#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
   bool game = true;
   int wahl = -1;
   float money;
   char option[10];
   int coins[] = {0, 0, 0, 0};

   char** menu = malloc(4 * sizeof(char*));
   for (int i = 0; i < 4; i++) {
      menu[i] = malloc(10 * sizeof(char));
   }
   strcpy(menu[0], "Capputcino");
   strcpy(menu[1], "Nespresso");
   strcpy(menu[2], "Latte");
   strcpy(menu[3], "Milk");

   float* prices = malloc(4 * sizeof(float));
   prices[0] = 3.50f;
   prices[1] = 2.25f;
   prices[2] = 2;
   prices[3] = 1;

   while (game) {
      printf(
         "\n"
         "\t     )  (  (         \n"
         "\t   ___)___(__        \t%s\t%.2f€\n"
         "\t  |          |-\\    \t%s\t%.2f€\n"
         "\t  |          | |     \t%s\t\t%.2f€\n"
         "\t   \\        /--/    \t%s\t\t%.2f€\n"
         "\t    \\______/        \n\n"
         "What do would like to drink?  ",
         menu[0], prices[0], menu[1], prices[1], menu[2], prices[2],menu[3], prices[3]
      );

      while(wahl == -1){
         scanf("%s", option);
         switch (option[0]) {
            case '1':
               wahl = 0;
               break;
            case '2':
               wahl = 1;
               break;
            case '3':
               wahl = 2;
               break;
            case '4':
               wahl = 3;
               break;
            case 'C':
               wahl = 0;
               break;
            case 'N':
               wahl = 1;
               break;
            case 'L':
               wahl = 2;
               break;
            case 'M':
               wahl = 3;
               break;
            case 'E':
               game = false;
               for (int i = 0; i < 4; i++) {
                  free(menu[i]);
               }
               free(menu);
               free(prices);
               return 0;
               break;

            default:
               wahl = -1;
         }
      }

      //could implement input validation, coins >= 0
      printf("You choose the %s, it costs %.2f€\n", menu[wahl], prices[wahl]);
      printf("Please insert Coins:\n\n");
      printf("How many quarters?\t (€0.25) ");
      scanf("%d", &coins[0]);
      printf("How many dimes?\t\t (€0.10) ");
      scanf("%d", &coins[1]);
      printf("How many nickles?\t (€0.05) ");
      scanf("%d", &coins[2]);
      printf("How many pennies?\t (€0.01) ");
      scanf("%d", &coins[3]);
      printf("\n");

      money = coins[0] * 0.25 +  coins[1] * 0.10 + coins[2] * 0.05+ coins[3] * 0.01;

      if (money == prices[wahl]) {
         printf("Here you go!\n\n");
      }
      else if (money > prices[wahl]) {
         printf("Here you go!\n");
         printf("And you get %.2f€ back!\n\n", money - prices[wahl]);
      }
      else {
         printf("You dont have enough to buy a coffe!\n");
         printf("You needed to pay %.2f€ and had %.2f€\n\n", prices[wahl], money);
      }

      option[0] = 'X';
      wahl = -1;
      money = 0;
      for (int i = 0; i < sizeof(coins) / sizeof(int); i++) {
         coins[i] = 0;
      }
   }
}
