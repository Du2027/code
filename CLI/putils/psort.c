#include "psort.h"
#include <string.h>
#include <strings.h>

int* bubblesort_int(int arr[], int size){
   int buffer;
   for (int i = 0; i < size - 1; i++) {
      for (int n = 0; n < size - 1 - i; n++) {
         if (arr[n] > arr[n+1]) {
            buffer = arr[n];
            arr[n] = arr[n+1];
            arr[n+1] = buffer;
         }
      }
   }
   return arr;
}

char* bubblesort_chr(char arr[], int size){
      int buffer;
      for (int n = 0; n < size - 1; n++) {
         for (int i = 0; i < size - 1 - n; i++) {
            if (arr[i] > arr[i+1]) {
               buffer = arr[i];
               arr[i] = arr[i+1];
               arr[i+1] = buffer;
            }
         }
      }
      return arr;
}

char** bubblesort_str(char** arr, int sizex, int sizey){
   char* buffer;
   for (int n = 0; n < sizey - 1; n++) {
      for(int i = 0; i < sizey - 1 - n; i++){
         if (strcmp(arr[i], arr[i+1]) > 0) {
            buffer = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = buffer;
         }
      }
   }
   return arr;
}
