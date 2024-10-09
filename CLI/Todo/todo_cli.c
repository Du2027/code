#include <stdio.h>
#include <string.h>

/*
argv[0] == ./file
argv[1] == arg1
*/

void help() {
  printf("Availabel Commands are : -h/-help\t|displaying commands");
}

int main(int argc, char *argv[]) {
  int command = 0;

  if (argc == 1) {
    printf("No argument given, use -h for help");
    return -1;
  }

  if (strcmp(argv[1], "-h") == 0) {
    help();
  }

  

      printf(argv[2]);
}
