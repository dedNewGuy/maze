#ifndef GRID_H_
#define GRID_H_

#include <stdbool.h>
#include "thirdparty/raylib.h"

/// CELL STUFF ==================
typedef struct {
	Vector2 start_pos;
	Vector2 end_pos;
} Line_T;

typedef struct {
	Line_T top;
	Line_T right;
	Line_T bottom;
	Line_T left;
} Wall_T;

typedef struct {
	bool top;
	bool right;
	bool bottom;
	bool left;
} Wall_Flag_T;

typedef struct {
	Wall_T wall;
	Rectangle rec;
	Wall_Flag_T wall_flag;
} Cell_T;

Cell_T cell_new(float x, float y, float cell_w, float cell_h);

/// GRID STUFF ====================
typedef struct {
	Cell_T *items;
	int count;
	int cap;
} Grid_T;

#define GRID_X_OFFSET 10
#define GRID_Y_OFFSET 10
#define GRID_LINE_THICK 1

Grid_T grid_new(int win_w, int win_h, float cell_w, float cell_h);
void grid_render(Grid_T grid);
void grid_dump(Grid_T grid);

#endif // GRID_H_
