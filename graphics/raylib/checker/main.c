#include<raylib.h>
#define RAYGUI_IMPLEMENTATION
#include"raygui.h"


#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int main (void){

    Vector2 Window_size = (Vector2){800,750};
    Vector2 Obj_size = (Vector2){200.0f, 200.0f};
    Vector2 Slider_size = (Vector2){100, 20};
    Vector4 rgba = (Vector4){250, 133, 0, 255};
    Color MENU_COLOR = {30, 30, 30, 255};
    Rectangle Menu_Background = {Window_size.x / 4 * 3, 0, Window_size.x / 4, Window_size.y};

    bool quit = false;
    int obj_offset = 50;
    float roundness = 0.0f;
    float segments = 0.0f;

    InitWindow(Window_size.x, Window_size.y, "Checker");

    while (!WindowShouldClose() && quit == false)
    {
        if(IsKeyDown(KEY_ESCAPE)){
            quit = true;
        }   

        BeginDrawing();
            ClearBackground(BLACK);
            DrawRectangleRounded((Rectangle){(Window_size.x / 4 * 3) / 2 - Obj_size.x / 2, Window_size.y / 2 - Obj_size.y / 2, Obj_size.x, Obj_size.y}, roundness, segments, (Color){rgba.x, rgba.y, rgba.z, rgba.w});
           
            DrawRectangleRec(Menu_Background, MENU_COLOR);
            DrawText("Menu", Window_size.x / 5 * 4 + 20, 20, 30, GRAY);

            char buffer_w[100];
            gcvt(Obj_size.x, 6, buffer_w);
            GuiSliderBar((Rectangle){ Window_size.x / 5 * 4 + 10, 100, Slider_size.x, Slider_size.y}, "width", buffer_w, &Obj_size.x, 1.0f, 550.0f);
            char buffer_h[100];
            gcvt(Obj_size.y, 6, buffer_h);
            GuiSliderBar((Rectangle){ Window_size.x / 5 * 4 + 10, 150, Slider_size.x, Slider_size.y}, "height", buffer_h, &Obj_size.y, 1.0f, 700.0f);

            char buffer_r[100];
            gcvt(roundness, 6, buffer_r);
            GuiSliderBar((Rectangle){ Window_size.x / 5 * 4 + 10, 250, Slider_size.x, Slider_size.y}, "round", buffer_r, &roundness, 0, 1.0f);
            char buffer_s[100];
            gcvt(segments, 6, buffer_s);
            GuiSliderBar((Rectangle){ Window_size.x / 5 * 4 + 10, 300, Slider_size.x, Slider_size.y}, "seg's", buffer_s, &segments, 0, 10.0f);

            char buffer_red[100];
            gcvt(rgba.x, 6, buffer_red);
            GuiSliderBar((Rectangle){ Window_size.x / 5 * 4 + 10, 400, Slider_size.x, Slider_size.y}, "red", buffer_red, &rgba.x, 0, 255.0f);
            char buffer_g[100];
            gcvt(rgba.y, 6, buffer_g);
            GuiSliderBar((Rectangle){ Window_size.x / 5 * 4 + 10, 450, Slider_size.x, Slider_size.y}, "green", buffer_g, &rgba.y, 0, 255.0f);
            char buffer_b[100];
            gcvt(rgba.z, 6, buffer_b);
            GuiSliderBar((Rectangle){ Window_size.x / 5 * 4 + 10, 500, Slider_size.x, Slider_size.y}, "blue", buffer_b, &rgba.z, 0, 255.0f);
            char buffer_a[100];
            gcvt(rgba.w, 6, buffer_a);
            GuiSliderBar((Rectangle){ Window_size.x / 5 * 4 + 10, 550, Slider_size.x, Slider_size.y}, "alpha", buffer_a, &rgba.w, 0, 255.0f);

        EndDrawing();
    }
    CloseWindow();
}