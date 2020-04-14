//#pragma once
#ifndef _BACKTRACKING_H_
#define _BACKTRACKING_H_

typedef struct _pos {
	int x;
	int y;
}Pos;

void pathfinding(int* map, int map_line, int map_col, int road, int walk_by_road, int role_x, int role_y);

#endif 