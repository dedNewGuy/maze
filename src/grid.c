#include <stdio.h>

#include "grid.h"
#include "minutil.h"

/// CELL STUFF ==================
Wall_T wall_new(Rectangle rec)
{
	Line_T top, right, bottom, left;

	Vector2 top_left  = {rec.x, rec.y};
	Vector2 top_right = {rec.x + rec.width, rec.y};
	Vector2 bot_left  = {rec.x, rec.y + rec.height};
	Vector2 bot_right  = {rec.x + rec.width, rec.y + rec.height};

	top.start_pos = top_left; top.end_pos = top_right;
	right.start_pos = top_right; right.end_pos = bot_right;
	bottom.start_pos = bot_left; bottom.end_pos = bot_right;
	left.start_pos = top_left; left.end_pos = bot_left;

	Wall_T wall = {
		top,
		right,
		bottom,
		left
	};
	return wall;
}

Cell_T cell_new(float x, float y, float cell_w, float cell_h)
{
	Rectangle rec = { x, y, cell_w, cell_h };
	Wall_Flag_T wall_flag = { .top=true, .right=true, .bottom=true, .left=true };
	Wall_T wall = wall_new(rec);
	Cell_T cell = {
		.rec = rec,
		.wall_flag = wall_flag,
		.wall = wall
	};
	return cell;
}

/// GRID STUFF ====================
Grid_T grid_new(int win_w, int win_h, float cell_w, float cell_h)
{
	Grid_T grid = {0};

	int x_offset = GRID_X_OFFSET;
	int y_offset = GRID_Y_OFFSET;
	int grid_w = win_w - (2*x_offset);
	int grid_h = win_h - (2*y_offset);

	int x_cell_count = grid_w / cell_w;
	int y_cell_count = grid_h / cell_h;

	for (int row = 0; row < y_cell_count; ++row) {
		for (int col = 0; col < x_cell_count; ++col) {
			int x = x_offset + col*cell_w;
			int y = y_offset + row*cell_h;
			Cell_T cell = cell_new(x, y, cell_w, cell_h);
			min_da_append(&grid, cell);
		}
	}

	return grid;
}

void grid_render(Grid_T grid)
{

	for (int i = 0; i < grid.count; ++i) {
		Cell_T cell = grid.items[i];
		Wall_T wall = cell.wall;
		if (cell.wall_flag.top)
			DrawLineEx(wall.top.start_pos, wall.top.end_pos, GRID_LINE_THICK, GRID_LINE_COLOR);
		if (cell.wall_flag.right)
			DrawLineEx(wall.right.start_pos, wall.right.end_pos, GRID_LINE_THICK, GRID_LINE_COLOR);
		if (cell.wall_flag.bottom)
			DrawLineEx(wall.bottom.start_pos, wall.bottom.end_pos, GRID_LINE_THICK, GRID_LINE_COLOR);	
		if (cell.wall_flag.left)
			DrawLineEx(wall.left.start_pos, wall.left.end_pos, GRID_LINE_THICK, GRID_LINE_COLOR);
	}
}

void grid_dump(Grid_T grid)
{
	for (int i = 0; i < grid.count; ++i) {
		if (i % 5 == 0) {
			printf("\n");
		}
		Cell_T cell = grid.items[i];
		printf("{%f,%f,%f,%f} ", cell.rec.x, cell.rec.y, cell.rec.width, cell.rec.height);
	}
	printf("\n");
}

void grid_init_start_stop(Grid_T *grid)
{
    grid->items[0].wall_flag.top = false;
    grid->items[grid->count - 1].wall_flag.bottom = false;
}
