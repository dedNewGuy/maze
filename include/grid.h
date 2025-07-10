#ifndef GRID_H_
#define GRID_H_

#include "thirdparty/raylib.h"

/// CELL STUFF ==================
typedef struct {
	int x;
	int y;
	int width;
	int height;
} Cell_T;

Cell_T cell_new(int x, int y, int cell_w, int cell_h);

/// GRID STUFF ====================
typedef struct {
	Cell_T *items;
	int count;
	int cap;
} Grid_T;

#define GRID_X_OFFSET 10
#define GRID_Y_OFFSET 10
#define GRID_LINE_THICK 1

Grid_T grid_new(int win_w, int win_h, int cell_w, int cell_h);
void grid_render(Grid_T grid);
void grid_dump(Grid_T grid);

#endif // GRID_H_
