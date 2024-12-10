// This is a combination of all putils

#include "all.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// ascii
char ascii_at(int value){
   if (value < 33 || value >= 127) {
      return 0;
   }
   else {
      return (char) value;
   }
}

// pcount
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

// pnums
int get_bin_length(int dez_val){
   if(dez_val == 0){return 1;}

   int size_needed = 0;
   while (pow(2, size_needed) <= dez_val) {
      size_needed++;
   }
   return size_needed;
}

int get_dez_to_oct_length(int dez_val){
   if(dez_val == 0){return 1;}

   int size_needed = 0;
   while (pow(8, size_needed) <= dez_val) {
      size_needed++;
   }
   return size_needed;
}

int base_to_dez(char *numx, int base, int size_numx){
   int pos = size_numx - 1;
   int sum = 0;
   char buffer;

   for (int i = 0; i < size_numx; i++) {
      if(numx[i] - '0' > 10){
         buffer = numx[i] - '0' - 7;
      } else {
         buffer = numx[i] - '0';
      }

      sum = sum + (buffer) * pow(base, pos);
      pos--;
   }
   return sum;
}

char* restwert(int numx, int base, char* result){
   int sum = numx;
   short int max_pos;
   short int it = 0;

   if(sum == 1){
      result[0] = '1';
      return result;
   }

   switch (base) {
      case BINARY:
         max_pos = get_bin_length(numx);
         break;
      case OCTAL:
         max_pos = get_dez_to_oct_length(numx) - 1;
         break;
      case HEXADEC:
         for (max_pos = 0; pow(10, max_pos) < numx; max_pos++) {};
         max_pos = max_pos - 1;
         break;
   }

   while(sum != 0){
      if(sum % base >= 10){
         result[max_pos - it] = sum % base + 55;
      }
      else {
         result[max_pos - it] = sum % base + 48;
      }
      sum = (sum - (sum % base)) / base;
      it++;
   }
   return result;
}

char* basex_basey(char basex[3], char* numx, int stellen, char basey[3], char* result){
   if(stellen <= 0){
      printf("BASECONVERSION-SIZE0 ERR\n");
      result = "ERR";
      return "ERR";
   }

   short base1;
   short base2;

   if(strcmp(basex, "bin") == 0 || strcmp(basex, "BIN") == 0){
      base1 = BINARY;
   }
   else if (strcmp(basex, "oct") == 0 || strcmp(basex, "OCT") == 0) {
      base1 = OCTAL;
   }
   else if (strcmp(basex, "dec") == 0 || strcmp(basex, "DEC") == 0) {
      base1 = DECIMAL;
   }
   else if (strcmp(basex, "dez") == 0 || strcmp(basex, "DEZ") == 0) {
      base1 = DECIMAL;
   }
   else if (strcmp(basex, "hex") == 0 || strcmp(basex, "HEX") == 0) {
      base1 = HEXADEC;
   }
   else {
      printf("BASE1 NOT FOUND\n");
   }

   if(strcmp(basey, "bin") == 0 || strcmp(basey, "BIN") == 0){
      base2 = BINARY;
   }
   else if (strcmp(basey, "oct") == 0 || strcmp(basey, "OCT") == 0) {
      base2 = OCTAL;
   }
   else if (strcmp(basey, "dec") == 0 || strcmp(basey, "DEC") == 0) {
      base2 = DECIMAL;
   }
   else if (strcmp(basey, "dez") == 0 || strcmp(basey, "DEZ") == 0) {
      base2 = DECIMAL;
   }
   else if (strcmp(basey, "hex") == 0 || strcmp(basey, "HEX") == 0) {
      base2 = HEXADEC;
   }
   else {
      printf("BASE2 NOT FOUND\n");
   }

   // Input validation
   for (int i = 0; i < stellen; i++) {
      int buffer = numx[i];
      if(buffer - '0' > 9){
         buffer = buffer - 7;
      }
      if (buffer - '0' >= base1){
         printf("NUM INPUT ERR %d-%d\n", buffer - '0', base1);
         return "ERR";
      }
   }

   int dezvalue;
   switch (base1) {
      case DECIMAL:
         dezvalue = atoi(numx);
         break;
      case HEXADEC:
         dezvalue = base_to_dez(numx, HEXADEC, stellen);
         break;
      case OCTAL:
         dezvalue = base_to_dez(numx, OCTAL, stellen);
         break;
      case BINARY:
         dezvalue = base_to_dez(numx, BINARY, stellen);
         break;
   }

   switch (base2) {
      case DECIMAL:
         sprintf(result, "%d", dezvalue);
         break;
      case HEXADEC:
         result = restwert(dezvalue, HEXADEC, result);
         break;
      case OCTAL:
         result = restwert(dezvalue, OCTAL, result);  // prob
         break;
      case BINARY:
         result = restwert(dezvalue, BINARY, result);
         break;
   }

   short int iteration = 0;
   if(result[0] == '0' && stellen > 1){
      char result_buff[stellen];
      while(result[iteration + 1] >= '0' && result[iteration + 1] <= '9' || result[iteration + 1] >= 'A' && result[iteration + 1] <= 'F' || result[iteration + 1] == 0){
         result_buff[iteration] = result[iteration + 1];
         iteration++;
      }
      strcpy(result, result_buff);
      return result;
   }
   return result;
}

// psort
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

// pstr
int** mk_2d_int(int sizex, int sizey){
   int** arr_2d = malloc(sizey * sizeof(int*));
   for(int i = 0; i < sizey; i++){
      arr_2d[i] = malloc(sizex * sizeof(int));
   }
   return arr_2d;
}

// num to string

void rm_2d_int(int** arr_2d, int sizey){
   for (int i = 0; i < sizey; i++) {
      free(arr_2d[i]);
   }
   free(arr_2d);
}
