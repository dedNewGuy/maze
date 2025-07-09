#include <stdio.h>

#include "raylib.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define WIN_TITLE "MAZE SOLVER"

int main(void)
{
	InitWindow(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);  // Initialize window and OpenGL context
								   
	while (!WindowShouldClose()) {
		BeginDrawing();
		DrawLineEx((Vector2){0, 0}, (Vector2){WIN_WIDTH, WIN_HEIGHT}, 2, WHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
