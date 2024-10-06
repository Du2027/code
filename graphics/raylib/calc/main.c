#include<stdio.h>
#include<raylib.h>
#include<stdbool.h>
#include<string.h>

int main(void){

	SetConfigFlags(FLAG_WINDOW_UNDECORATED);

	Vector2 Monitor_size = (Vector2){GetMonitorWidth(0), GetMonitorHeight(0)};

	Color BG_COLOR = {0, 0, 0, 255};
	Color BUTTON_BACKGROUND_COLOR = {20, 20, 20 ,255};
	Color BUTTON_COLOR = {30, 30, 30, 255};
	Color ORANGE_ACCENT = {250, 133, 0, 255};

	const int window_size[] = {600, 750}; // maybe a little smaller
	const float roundness = 0.09f;
	const int quit_offset = 20;
	const int button_offset = 30;
	//char second_num[];
	int operator;
	//char show_num[]; 
	bool quit = false;

	InitWindow(window_size[0], window_size[1], "P'Calc"); // width, heitght, title
	SetTargetFPS(140);

	Vector2 Button_size = (Vector2){(window_size[0] - button_offset * 5) / 4, (window_size[1] - window_size[1] / 2.5 - button_offset * 5) / 5};

	Rectangle Quitbutton = {window_size[0] - (window_size[0] / 16) - quit_offset, quit_offset, window_size[0] / 16, window_size[0] / 16};
	Rectangle Overlay = {0, (window_size[1] / 2.5) - button_offset, window_size[0], window_size[1]};
	Rectangle Button_k = {button_offset, window_size[1] - (button_offset + Button_size.y), Button_size.x, Button_size.y };
	Rectangle Button_0 = {button_offset * 2 + Button_size.x * 1, window_size[1] - (button_offset + Button_size.y), Button_size.x, Button_size.y };
	Rectangle Button_i = {button_offset * 3 + Button_size.x * 2, window_size[1] - (button_offset + Button_size.y), Button_size.x * 2 + button_offset,Button_size.y};

	Rectangle Button_1 = {button_offset, window_size[1] - (button_offset * 2 + Button_size.y * 2), Button_size.x, Button_size.y };
	Rectangle Button_2 = {button_offset * 2 + Button_size.x * 1, window_size[1] - (button_offset * 2 + Button_size.y * 2), Button_size.x, Button_size.y };
	Rectangle Button_3 = {button_offset * 3 + Button_size.x * 2, window_size[1] - (button_offset * 2 + Button_size.y * 2), Button_size.x, Button_size.y };
	Rectangle Button_p = {button_offset * 4 + Button_size.x * 3, window_size[1] - (button_offset * 2 + Button_size.y * 2), Button_size.x, Button_size.y };

	Rectangle Button_4 = {button_offset, window_size[1] - (button_offset * 3 + Button_size.y * 3), Button_size.x, Button_size.y };
	Rectangle Button_5 = {button_offset * 2 + Button_size.x * 1, window_size[1] - (button_offset * 3 + Button_size.y * 3), Button_size.x, Button_size.y };
	Rectangle Button_6 = {button_offset * 3 + Button_size.x * 2, window_size[1] - (button_offset * 3 + Button_size.y * 3), Button_size.x, Button_size.y };
	Rectangle Button_m = {button_offset * 4 + Button_size.x * 3, window_size[1] - (button_offset * 3 + Button_size.y * 3), Button_size.x, Button_size.y };

	Rectangle Button_7 = {button_offset, window_size[1] - (button_offset * 4 + Button_size.y * 4), Button_size.x, Button_size.y };
	Rectangle Button_8 = {button_offset * 2 + Button_size.x * 1, window_size[1] - (button_offset * 4 + Button_size.y * 4), Button_size.x, Button_size.y };
	Rectangle Button_9 = {button_offset * 3 + Button_size.x * 2, window_size[1] - (button_offset * 4 + Button_size.y * 4), Button_size.x, Button_size.y };
	Rectangle Button_x = {button_offset * 4 + Button_size.x * 3, window_size[1] - (button_offset * 4 + Button_size.y * 4), Button_size.x, Button_size.y };

	Rectangle Button_s = {button_offset, window_size[1] - (button_offset * 5 + Button_size.y * 5), Button_size.x, Button_size.y };
	Rectangle Button_C = {button_offset * 2 + Button_size.x * 1, window_size[1] - (button_offset * 5 + Button_size.y * 5), Button_size.x, Button_size.y };
	Rectangle Button_b = {button_offset * 3 + Button_size.x * 2, window_size[1] - (button_offset * 5 + Button_size.y * 5), Button_size.x * 2 + button_offset,Button_size.y};

	Vector2 Mousepos = {0.0f, 0.0f};

	while(!WindowShouldClose()){
		Mousepos = GetMousePosition();

		if (CheckCollisionPointRec(Mousepos, Quitbutton))
		{
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) quit = true;
		}
		else quit = false;
		
		if (quit)
		{
			CloseWindow();
		}
		
		BeginDrawing();
		ClearBackground(BG_COLOR);

		//DrawRectangleRec(Quitbutton, ORANGE);
		DrawText("X", window_size[0] - (window_size[0] / 16) - quit_offset, quit_offset - 7, 60, WHITE); // maybe rewrite
		
		DrawRectangleRounded(Overlay,  roundness, 80, BUTTON_BACKGROUND_COLOR);

		DrawRectangleRounded(Button_k, roundness, 20, BUTTON_COLOR);
		DrawRectangleRounded(Button_0, roundness, 20, BUTTON_COLOR);
		DrawRectangleRounded(Button_i, roundness, 20, ORANGE);

		DrawRectangleRounded(Button_1, roundness, 20, BUTTON_COLOR);
		DrawRectangleRounded(Button_2, roundness, 20, BUTTON_COLOR);
		DrawRectangleRounded(Button_3, roundness, 20, BUTTON_COLOR);
		DrawRectangleRounded(Button_p, roundness, 20, BUTTON_COLOR);

		DrawRectangleRounded(Button_4, roundness, 20, BUTTON_COLOR);
		DrawRectangleRounded(Button_5, roundness, 20, BUTTON_COLOR);
		DrawRectangleRounded(Button_6, roundness, 20, BUTTON_COLOR);
		DrawRectangleRounded(Button_m, roundness, 20, BUTTON_COLOR);

		DrawRectangleRounded(Button_7, roundness, 20, BUTTON_COLOR);
		DrawRectangleRounded(Button_8, roundness, 20, BUTTON_COLOR);
		DrawRectangleRounded(Button_9, roundness, 20, BUTTON_COLOR);
		DrawRectangleRounded(Button_x, roundness, 20, BUTTON_COLOR);

		DrawRectangleRounded(Button_s, roundness, 20, BUTTON_COLOR);
		DrawRectangleRounded(Button_C, roundness, 20, BUTTON_COLOR);
		DrawRectangleRounded(Button_b, roundness, 20, ORANGE);


		DrawText(".", button_offset + Button_size.x / 2.05f, window_size[1] - (button_offset + Button_size.y), 60, WHITE);
		DrawText("0", button_offset * 2 + Button_size.x + Button_size.x / 2.5, window_size[1] - (button_offset + Button_size.y) + 5, 53, WHITE);
		DrawText("=", button_offset * 3 + Button_size.x * 3, window_size[1] - (button_offset + Button_size.y) + 5, 55, WHITE);

		DrawText("1", button_offset + Button_size.x / 2.2f, window_size[1] - (button_offset * 2 + Button_size.y * 2) + 5, 55, WHITE);
		DrawText("2", button_offset * 2 + Button_size.x + Button_size.x / 2.5, window_size[1] - (button_offset * 2 + Button_size.y * 2) + 5, 53, WHITE);
		DrawText("3", button_offset * 3 + Button_size.x * 2 + Button_size.x / 2.5, window_size[1] - (button_offset * 2 + Button_size.y * 2) + 5, 53, WHITE);
		DrawText("+", button_offset * 4 + Button_size.x * 3 + Button_size.x / 2.5, window_size[1] - (button_offset * 2 + Button_size.y * 2) + 5, 53, ORANGE_ACCENT);

		DrawText("4", button_offset + Button_size.x / 2.2f, window_size[1] - (button_offset * 3 + Button_size.y * 3) + 5, 55, WHITE);
		DrawText("5", button_offset * 2 + Button_size.x + Button_size.x / 2.5, window_size[1] - (button_offset * 3 + Button_size.y * 3) + 5, 53, WHITE);
		DrawText("6", button_offset * 3 + Button_size.x * 2 + Button_size.x / 2.5, window_size[1] - (button_offset * 3 + Button_size.y * 3) + 5, 53, WHITE);
		DrawText("-", button_offset * 4 + Button_size.x * 3 + Button_size.x / 2.5, window_size[1] - (button_offset * 3 + Button_size.y * 3) + 5, 53, ORANGE_ACCENT);

		DrawText("7", button_offset + Button_size.x / 2.2f, window_size[1] - (button_offset * 4 + Button_size.y * 4) + 5, 55, WHITE);
		DrawText("8", button_offset * 2 + Button_size.x + Button_size.x / 2.5, window_size[1] - (button_offset * 4 + Button_size.y * 4) + 5, 53, WHITE);
		DrawText("9", button_offset * 3 + Button_size.x * 2 + Button_size.x / 2.5, window_size[1] - (button_offset * 4 + Button_size.y * 4) + 5, 53, WHITE);
		DrawText("*", button_offset * 4 + Button_size.x * 3 + Button_size.x / 2.5, window_size[1] - (button_offset * 4 + Button_size.y * 4) + 5, 53, ORANGE_ACCENT);

		DrawText("/", button_offset + Button_size.x / 2.2f, window_size[1] - (button_offset * 5 + Button_size.y * 5) + 5, 55, WHITE);
		DrawText("C", button_offset * 2 + Button_size.x + Button_size.x / 2.5, window_size[1] - (button_offset * 5 + Button_size.y * 5) + 5, 53, WHITE);
		DrawText("<=", button_offset * 3 + Button_size.x * 3, window_size[1] - (button_offset * 5 + Button_size.y * 5) + 5, 55, WHITE);
		

		EndDrawing();
	}
	CloseWindow();

	return 0;
}