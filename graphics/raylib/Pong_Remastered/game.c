#include<stdio.h>
#include<raylib.h>
#include<stdbool.h>
#include"main.h"

void open_game(int window_width, int window_height){
    InitWindow(300, 300, "NEW");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        if(IsKeyDown(KEY_G)){
            CloseWindow();
            main();
        }
        BeginDrawing();
        EndDrawing();
    }
}