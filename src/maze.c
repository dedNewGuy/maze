#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "thirdparty/raylib.h"
#include "grid.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define WIN_TITLE "MAZE SOLVER"
#define FPS 60

int main(void)
{
	srand(time(NULL));
	InitWindow(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
    SetTargetFPS(FPS);

	int cell_w, cell_h;
	cell_w = cell_h = 30;
	Grid_T grid = grid_new(WIN_WIDTH, WIN_HEIGHT, cell_w, cell_w);

	printf("X Cell Count: %d\n", grid.x_cell_count);

	grid_init_start_stop(&grid);

	int start_cell = 0;
	grid_break_walls(&grid, start_cell);

#ifdef DEBUG
	while (!WindowShouldClose()) {
		BeginDrawing();
		grid_render(grid);
		EndDrawing();
	}
#else
	int i = 0;
	while (!WindowShouldClose()) {
		BeginDrawing();
		grid_render_i(grid, i);
		EndDrawing();
		WaitTime(0.1);
		++i;
	}
#endif // DEBUG

	CloseWindow();
	return 0;
}
