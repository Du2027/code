#include <math.h>
#include <stdio.h>
#include <string.h>
#include "pnumsys.h"
#include <stdbool.h>

int pabs(int value){
    if(value < 0){
        return value * -1;
    }
    else {
        return value;
    }
}

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

int base_to_dez(char *numx, int base, int size_numx, char* result){
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

   sprintf(result, "%d", sum);
}

char* dec_to_bin(char* numx, int size_numx, char* result){
   int sum = 0;
   int stelle = pow(10, size_numx - 1);
   for (int i = 0; i < size_numx; i++) {
      sum = sum + (numx[i] - '0') *  stelle;
      stelle = stelle / 10;
   }

   if(sum == 0){
      result[0] = '0';
      return result;
   }

   int erg = sum;
   int length = get_bin_length(sum) - 1;

   for(int i = 0; erg != 0; i++) {
      result[length - i] = (erg % 2) + '0';
      erg = (erg - (result[length - i] - '0')) / 2;
   }
   return result;
}

char* oct_to_bin(char* numx, int size_numx, char* result){
   char buffer[3];
   short null_counter = 0;

   for (int i = 0; i < size_numx; i++) {
      if(numx[i] == '0'){null_counter++;}
   }

   if(null_counter == size_numx){
      result[0] = '0';
      result[1] = '0';
      result[2] = '0';
      return result;
   }

   for (int i = 0; i < size_numx; i++) {
      memset(buffer, '0', sizeof(buffer));
      int erg = numx[i] - '0';

      for(int n = 0; erg != 0; n++) {
         buffer[2 - n] = (erg % 2) + '0';
         erg = (erg - (buffer[2 - n] - '0')) / 2;

         if (n == 0 && erg == 0) {
            buffer[0] = '0';
            buffer[1] = '0';
         }
         else if(n == 1 && erg == 0){
            buffer[0] = '0';
         }
      }

      printf(",%s", buffer);

      result[0 + 3 * i] = buffer[0];
      result[1 + 3 * i] = buffer[1];
      result[2 + 3 * i] = buffer[2];
   }
   return result;
}

char* hex_to_bin(char* numx, int size_numx, char* result){
   char buffer[4];
   short null_counter = 0;

   for (int i = 0; i < size_numx; i++) {
      if(numx[i] == '0'){null_counter++;}
   }

   if(null_counter == size_numx){
      result[0] = '0';
      result[1] = '0';
      result[2] = '0';
      result[3] = '0';
      return result;
   }

   for (int i = 0; i < size_numx; i++) {
      memset(buffer, '0', sizeof(buffer));
      int erg = numx[i] - '0';

      if(erg > 9){
         erg = erg - 7;
      }

      for(int n = 0; erg != 0; n++) {
         buffer[3 - n] = (erg % 2) + '0';
         erg = (erg - (buffer[3 - n] - '0')) / 2;

         if(n == 0 && erg == 0){
            buffer[0] = '0';
            buffer[1] = '0';
            buffer[2] = '0';
            buffer[3] = '1';
         }
      }

      printf(",%s", buffer);

      result[0 + 4 * i] = buffer[0];
      result[1 + 4 * i] = buffer[1];
      result[2 + 4 * i] = buffer[2];
      result[3 + 4 * i] = buffer[3];
   }
   return result;
}

char* dec_to_oct(char* numx, int size_numx, char* result){
   int sum = 0;
   int stelle = pow(10, size_numx - 1);
   for (int i = 0; i < size_numx; i++) {
      sum = sum + (numx[i] - '0') *  stelle;
      stelle = stelle / 10;
   }

   if(sum == 0){
      result[0] = '0';
      return result;
   }

   int length = get_dez_to_oct_length(sum) -1;
   printf("%d", length);
   int erg = sum;

   for(int i = 0; erg != 0; i++) {
      result[length - i] = (erg % 8) + '0';
      erg = (erg - (result[length - i] - '0')) / 8;
   }
   return result;
}

char* bitzerlegung(char* bin_num, int bits, char* result, short stellen){
   if(stellen > 4 || stellen < 3){
      printf("BITZERL-SYNTAXERR\n");
      return "ERR";
   }

   int times = 0;
   if(bits % stellen != 0){times = bits / stellen +1;}
   else{times = bits / stellen;}

   int sum = 0;
   int cntr = 0;
   char buffer[3];

   for (int i = times; i > 0; i--) {
      if(stellen == 3){
         buffer[0] = bin_num[i]
      }
      else {

      }
   }



   //sum = sum + (buffer) * pow(base1, pos);
   //pos--;

}

char* basex_basey(char basex[3], char* numx, int size_numx, char basey[3], char* result){
   if(size_numx <= 0){
      printf("BASECONVERSION-SIZE0 ERR\n");
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
   else if (strcmp(basey, "hex") == 0 || strcmp(basey, "HEX") == 0) {
      base2 = HEXADEC;
   }
   else {
      printf("BASE2 NOT FOUND\n");
   }

   if(base1 == base2){
      result = numx;
   }

   for (int i = 0; i < size_numx; i++) {
      int buffer = numx[i];
      if(buffer - '0' > 9){
         buffer = buffer - 7;
      }
      if (buffer - '0' >= base1){
         printf("NUM INPUT ERR %d-%d\n", buffer - '0', base1);
         return "ERR";
      }
   }

   if(base2 == DECIMAL){
      base_to_dez(numx, base1, size_numx, result);
   }
   else if (base2 == BINARY) {
      if (base1 == DECIMAL) {
         dec_to_bin(numx, size_numx, result);
      }
      else if (base1 == OCTAL) {
         oct_to_bin(numx, size_numx, result);
      }
      else if (base1 == HEXADEC) {
         hex_to_bin(numx, size_numx, result);
      }
   }
   else if (base2 == OCTAL) {
      if (base1 == DECIMAL) {
         dec_to_oct(numx, size_numx, result);
      }
      else if (base1 == BINARY) {

      }
      else if (base1 == HEXADEC) {

      }
   }

   printf("BASE1:%d|BASE2:%d\n", base1, base2);
   return result;
}

// hex - oct
// hex  & oct -> bin
// bin -> all
// **base x to base y**
