#include <stdio.h>

#include "raylib.h"

int main(void)
{
	InitWindow(800, 600, "Maze");  // Initialize window and OpenGL context
								   
	while (!WindowShouldClose()) {
		BeginDrawing();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
