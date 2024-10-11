#include <stdio.h>
#include <string.h>

/*
argv[0] == ./file
argv[1] == arg1
*/

//howtouse command

void help() {
  printf("Available Commands are  -h/-help\t|displaying commands\n\t\t\t-l/-list\t|listing todo's\n");
}

void list() { 
  printf("listing...\n"); 
}

int main(int argc, char *argv[]) {
  int command = 0;

  char beginn_red[] = "\x1b[1;31m";
  char beginn_green[] = "\x1b[1;32m";
  char beginn_yellow[] = "\x1b[1;33m";
  char beginn_blue[] = "\x1b[1;34m";
  char beginn_purple[] = "\x1b[1;35m";
  char beginn_cyan[] = "\x1b[1;36m";
  char end_color[] = "\x1b[0m";

  FILE *DATA = fopen("~/.todos", "r");

  if (DATA == NULL) {
    char ans;
    printf("Todo file not found, wish to create one? [y/n]");
    scanf("%c", &ans);
    if (ans == 'y') {
      DATA = fopen("~/.todos", "w");
      printf("%screated .todos file in ~ directory%s\n", beginn_green, end_color);
    } 
    else {
      printf("%sno file created%s\n", beginn_red, end_color);
    }
  }

  if (argc == 1) {
    printf("No argument given, use -h for help\n");
    return -1;
  }

  if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0) {
    help();
  }

  if (strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "-list") == 0) {
    list();
  }
}
