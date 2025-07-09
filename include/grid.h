#ifndef GRID_H_
#define GRID_H_

#include "thirdparty/raylib.h"

typedef struct {
	int x;
	int y;
	int width;
	int height;
} Cell_T;

Cell_T cell_new(int x, int y, int cell_w, int cell_h)
{
	Cell_T cell = {
		.x = x,
		.y = y,
		.width = cell_w, 
		.height = cell_h,
	};
	return cell;
}

typedef struct {
	Cell_T *items;
	int count;
	int cap;
} Grid_T;

#define GRID_X_OFFSET 10
#define GRID_Y_OFFSET 10
#define GRID_LINE_THICK 1

Grid_T grid_new(int win_w, int win_h, int cell_w, int cell_h)
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

	int line_thick = GRID_LINE_THICK;
	for (int i = 0; i < grid.count; ++i) {
		Cell_T cell = grid.items[i];
		Rectangle rec = {
			cell.x, cell.y,
			cell.width, cell.height
		};
		DrawRectangleLinesEx(rec, line_thick, WHITE);
	}
}

void grid_dump(Grid_T grid)
{
	for (int i = 0; i < grid.count; ++i) {
		if (i % 5 == 0) {
			printf("\n");
		}
		Cell_T cell = grid.items[i];
		printf("{%d,%d,%d,%d} ", cell.x, cell.y, cell.width, cell.height);
	}
	printf("\n");
}

#endif // GRID_H_
