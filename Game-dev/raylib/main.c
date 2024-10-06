#include<stdio.h>
#include<raylib.h>
#include<stdbool.h>

int main(void){

    const int window_size[] = {800, 1000};
    bool wandcollide = false;
    int speed = 7;
    int ballpos[] = {400, 400};
    Color bg_color = {34, 135, 139, 1};

    InitWindow(window_size[0], window_size[1], "Title"); // width, heitght, title
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        if(IsKeyDown(KEY_RIGHT) && ballpos[0] <= 0){
            ballpos[0] = ballpos[0] + 1 * speed;
        }
        else if(IsKeyDown(KEY_UP) && ballpos[1] <= 0){
            ballpos[1] = ballpos[1] - 1 * speed;
        }
        else if(IsKeyDown(KEY_DOWN) && ballpos[1] >= window_size[1]){
            ballpos[1] = ballpos[1] + 1 * speed;
        }
        else if(IsKeyDown(KEY_LEFT) && ballpos[0] >= window_size[0]){
            ballpos[0] = ballpos[0] - 1 * speed;
        }

        BeginDrawing();
        ClearBackground(bg_color);
        DrawCircle(ballpos[0], ballpos[1], 20, WHITE);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}