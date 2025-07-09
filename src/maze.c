#include <stdio.h>

#include "thirdparty/raylib.h"
#include "util.h"
#include "grid.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define WIN_TITLE "MAZE SOLVER"

int main(void)
{
	InitWindow(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE); 

	Grid_T grid = grid_new(WIN_WIDTH, WIN_HEIGHT, 30, 30);

	while (!WindowShouldClose()) {
		BeginDrawing();
		grid_render(grid);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
