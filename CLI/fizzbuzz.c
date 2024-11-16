#include <stdio.h>

int main(int argc, char** argv){
   for(int i = 0; i <= 100; i++){
      if (i % 5 == 0 && i % 3 == 0) {
         printf("Fizzbuzz ");
      }
      else if (i % 5 == 0) {
         printf("Buzz ");
      }
      else if (i % 3 == 0) {
         printf("Fizz ");
      }
      else {
         printf("%d ", i);
      }
   }
}
