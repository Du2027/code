#ifndef ASCII_H
#define ASCII_H
   char ascii_at(int value);
#endif

#ifndef COLORS_H
#define COLORS_H
   #define COLOR_RED "\x1b[1;31m"
   #define COLOR_GREEN "\x1b[1;34m"
   #define COLOR_YELLOW "\x1b[1;33m"
   #define COLOR_BLUE "\x1b[1;32m"
   #define COLOR_PURPLE "\x1b[1;35m"
   #define COLOR_CYAN "\x1b[1;36m"
   #define COLOR_RESET "\x1b[0m"
#endif

#ifndef PCOUNT
#define PCOUNT
   int count_dupes(int arr[], int to_count, int size);
   int count_str_dupes(char** arr, char* word_to_count, int size);
#endif

#ifndef PNUMSYS
#define PNUMSYS

   #define BINARY 2
   #define OCTAL 8
   #define DECIMAL 10
   #define HEXADEC 16

   int get_bin_length(int dez_val);
   int get_dez_to_oct_length(int dez_val);
   int base_to_dez(char *numx, int base, int size_numx);
   char* restwert(int numx, int base, char* result);
   char* basex_basey(char basex[3], char* numx, int stellen, char basey[3], char* result);
#endif

#ifndef PSORT
#define PSORT
   int* bubblesort_int(int arr[], int size);
   char* bubblesort_chr(char arr[], int size); // First uppercase then lowercase ABCbx
   char** bubblesort_str(char** arr, int sizex, int sizey);
#endif

#ifndef PSTR
#define PSTR
   int** mk_2d_int(int sizex, int sizey);
   void rm_2d_int(int** arr_2d, int sizey);
#endif
