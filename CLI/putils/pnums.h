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
