#include<stdio.h>

int main(int argc, char* charv[]){
   short i = 0;
   short cntr = -1;

   printf("Usage:\t-x\t displaying numbers in different numberformats\n\t d\t numbers in decimal format\n\t o\t numbers in octagonal format\n\t h\t numbers in hexagonal format\n");

   printf("\n\t/////////////////////////////////ascii table/////////////////////////////////\n\t");
   for(i = 33; i < 127; i++){
      if(cntr == 9){
         printf("\n\t");
         cntr = 0;
      } else{
         cntr++;
      }

      if(i == 123){
         printf("\t\t\t");
      }

      printf("%d", i);

      if(i > 99){
         printf(" ");
      }
      else{
         printf("  ");
      }

      printf("%c\t", i);
   }
   printf("\n");
}
