#include <stdio.h>

#include "thirdparty/raylib.h"
#include "grid.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define WIN_TITLE "MAZE SOLVER"
#define FPS 60

int main(void)
{
	InitWindow(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
    SetTargetFPS(FPS);

	int cell_w, cell_h;
	cell_w = cell_h = 30;
	Grid_T grid = grid_new(WIN_WIDTH, WIN_HEIGHT, cell_w, cell_w);

	grid_init_start_stop(&grid);

	int i = 0;
	while (!WindowShouldClose()) {
		BeginDrawing();
		grid_render_i(grid, i);
		EndDrawing();
		WaitTime(0.01);
		++i;
	}

	CloseWindow();
	return 0;
}
