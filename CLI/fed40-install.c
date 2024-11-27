#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "./putils/colors.h"

enum pack_man {
    dnf = 0,
    apt = 1
};

int main(int argc, char *argv[]) {
    enum pack_man packm;
    bool debugmode = false;
    short int buffer;
    char package_man[2][4] = {{"dnf"}, {"apt"}};

    if(argc == 2 && strcmp(argv[1], "-DEBUG") == 0){
        debugmode = true;
    }

    printf(
        "%s                            _           _        _ _       \n"
        "                           (_)         | |      | | |      \n"
        " _ __  ___ _   _ ___ ______ _ _ __  ___| |_ __ _| | |      \n"
        "| '_ \\/ __| | | / __|______| | '_ \\/ __| __/ _` | | |    \n"
        "| |_) \\__ \\ |_| \\__ \\      | | | | \\__ \\ || (_| | | |\n"
        "| .__/|___/\\__, |___/      |_|_| |_|___/\\__\\__,_|_|_|   \n"
        "| |         __/ |                                          \n"
        "|_|        |___/                                           %s\n\n",
        COLOR_GREEN, COLOR_RESET);

    printf("Wich Package Manager are you using?\nAvailable are: ");
    for (int i = 0; i < sizeof(package_man) / 3; i++) {
        printf("%s (%d) ", package_man[i], i);
    }
    scanf("%hd", &buffer);

    switch (buffer) {
        case 0:
            packm = dnf;
            break;
        case 1:
            packm = apt;
            break;
        default:
            printf("%sCouldnt your package manager!%s\n", COLOR_RED, COLOR_RESET);
    }


  // Todo : how to execute bash commands in c system("ls")
  //        how to export Variables in C from, to Files
  //        Get Terminal width

  /*sudo dnf5 install fastfetch mpv wget git gcc make python3 python3 -
      pip unrar unzip cargo p7zip p7zip - plugins ntfs - 3g htop java - 17 -
      openjdk android -
      tools vlc*/
}
