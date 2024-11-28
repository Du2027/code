#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "./putils/colors.h"

enum pack_man{
    dnf = 0,
    apt = 1
};

enum brows{
    brave = 1,
    firefox = 2,
    zen = 3
};

int main(int argc, char *argv[]) {
    enum pack_man packm;
    enum brows browser;
    bool debugmode = false;
    short int buffer;
    char package_man[2][4] = {{"dnf"}, {"apt"}};
    char webbrowser[3][14] = {{"brave-browser"}, {"firefox"}, {"zen-browser"}};

    if(argc == 2 && strcmp(argv[1], "-DEBUG") == 0){
        debugmode = true;
    }

    printf(
        "%s                            _           _        _ _     \n"
        "                           (_)         | |      | | |      \n"
        " _ __  ___ _   _ ___ ______ _ _ __  ___| |_ __ _| | |      \n"
        "| '_ \\/ __| | | / __|______| | '_ \\/ __| __/ _` | | |    \n"
        "| |_) \\__ \\ |_| \\__ \\      | | | | \\__ \\ || (_| | | |\n"
        "| .__/|___/\\__, |___/      |_|_| |_|___/\\__\\__,_|_|_|   \n"
        "| |         __/ |                                          \n"
        "|_|        |___/                                           %s\n\n",
        COLOR_GREEN, COLOR_RESET);

    printf("Wich Package Manager are you using?\n%s", COLOR_BLUE);
    for (int i = 0; i < sizeof(package_man) / 3; i++) {
        printf("%s (%d) ", package_man[i], i);
    }
    printf("%s\n", COLOR_RESET);
    scanf("%hd", &buffer);

    switch (buffer) {
        case 0:
            packm = dnf;    // dnf5?
            break;
        case 1:
            packm = apt;
            break;
        default:
            printf("%sCouldnt find your package manager!%s\n", COLOR_RED, COLOR_RESET);
            return -1;
    }

    buffer = 0;
    printf("What Browser would you want to use? Use -1 for nothing.\n%s", COLOR_BLUE);
    for (int i = 0; i < sizeof(webbrowser) / 14; i++) {
        printf("%s (%d) ", webbrowser[i], i);
    }
    printf("%s\n", COLOR_RESET);
    scanf("%hd", &buffer);

    switch (buffer) {
        case -1:
            browser = 0;
            break;
        case 0:
            browser = brave;
            break;
        case 1:
            browser = firefox;
            break;
        case 2:
            browser = zen;
            break;
        default:
            printf("%sCouldnt find your Browser!%s\n", COLOR_RED, COLOR_RESET);
            return -2;
    }

    switch (browser) {
        case 0:
            printf("%sNo Browser selected, skipping...%s\n", COLOR_PURPLE, COLOR_RESET);
            break;
        case brave:
            if (packm == dnf) {
                /*system(
                    "sudo dnf config-manager --add-repo https://brave-browser-rpm-release.s3.brave.com/brave-browser.repo"
                    "sudo rpm --import https://brave-browser-rpm-release.s3.brave.com/brave-core.asc"
                    "sudo dnf install brave-browser"
                );*/
            }
            break;
        case firefox:
            if (packm == dnf) {
                //system("sudo dnf install firefox");
            }
            break;
        case zen:
            break;
        default:
            break;
    }

    printf("Would you like to install nvidia-drivers?\n");
    //WIP
    printf("Would you like to install additional packages?\n");
    //WIP
}
