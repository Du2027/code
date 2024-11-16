#include <string.h>
#include "pcount.h"

int count_dupes(int arr[], int to_count, int size){
   if(size <= 0){
      return 0;
   }

   int dupecount = 0;
   for (int i = 0; i < size; i++) {
      if(arr[i] == to_count){
         dupecount++;
      }
   }
   return dupecount;
}

int count_str_dupes(char** arr, char* word_to_count, int size){
   if(size <= 0){
      return 0;
   }

   int dupecount = 0;
   for (int i = 0; i < size; i++) {
      if(strcmp(word_to_count, arr[i]) == 0){
         dupecount++;
      }
   }
   return dupecount;
}
