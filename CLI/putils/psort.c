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
