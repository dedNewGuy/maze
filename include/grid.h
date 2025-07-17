#ifndef GRID_H_
#define GRID_H_

#include <stdbool.h>
#include "thirdparty/raylib.h"

/// CELL STUFF ==================
#define WALL_TOP "top"
#define WALL_BOTTOM "bottom"
#define WALL_RIGHT "right"
#define WALL_LEFT "left"

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
	bool visited;
} Cell_T;

Cell_T cell_new(float x, float y, float cell_w, float cell_h);

/// GRID STUFF ====================
typedef struct {
	Cell_T *items;
	int count;
	int cap;
	int x_cell_count;
	int y_cell_count;
} Grid_T;

#define GRID_X_OFFSET 10
#define GRID_Y_OFFSET 10
#define GRID_LINE_THICK 1
#define GRID_LINE_COLOR WHITE

Grid_T grid_new(int win_w, int win_h, float cell_w, float cell_h);
void grid_render(Grid_T grid);
void grid_render_i(Grid_T grid, int i);
void grid_dump(Grid_T grid);
void grid_init_start_stop(Grid_T *grid);
void grid_break_walls(Grid_T *grid, int i);
	
#endif // GRID_H_
