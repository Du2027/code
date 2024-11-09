#include "psort.h"

int* psort_int(int arr[], int size){
   int sorted_arr[size];
   int i;
   int buffer = arr[0];
   int pos;

   for (i = 0; i < size; i++) {
      sorted_arr[i] = arr[i];
      arr[i] = 0;
   }

   for(i = 0; i < size; i++){
      if (arr[i] < buffer) {
         buffer = arr[i];
         i = 0;
      }
   }
   return arr;
}

int* bubblesort_int(int arr[], int size){
   int buffer;
   for (int i = 0; i < size - 1; i++) {
      for (int n = 0; n < size - 1; n++) {
         if (arr[n] > arr[n+1]) {
            buffer = arr[n];
            arr[n] = arr[n+1];
            arr[n+1] = buffer;
         }
      }
   }
   return arr;
}
