#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int main (int argc, char* argv[]){
  printf("Wich Package Manager are you using?\n");
  printf("Supported Managers are \tapt(1) || dnf(2)\n");
  
  int option = 0;
  char pmanager[5];

  switch (option) {
    case 1:
      strcpy(pmanager, "dnf");
      break;
    case 2:
      strcpy(pmanager, "apt");
      break;
  }

  // Todo : how to execute bash commands in c
  //        how to export Variables in C from, to Files
  //        Get Terminal width


  sudo dnf5 install fastfetch mpv wget git gcc make python3 python3-pip unrar unzip cargo p7zip p7zip-plugins ntfs-3g htop java-17-openjdk android-tools vlc

  scanf("%d", &option);
  printf("Manager %s", pmanager);
}
