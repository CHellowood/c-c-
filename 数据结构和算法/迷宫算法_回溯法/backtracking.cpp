#include "backtracking.h"
#include "LinkStack.h"
#include <graphics.h>

#define link_data            \
	link->data.x = role.x;   \
	link->data.y = role.y;   \
	enterStack(stack, link)

/*******************************************
*回溯法寻路:
*输入:   map地图首地址, map_line地图高度(行数), map_col地图宽度(列数),
         road表示路的数据(数字), Walk_by_road把走过的路设为Walk_by_road,
		 role_x人物的x坐标(列数), role_y人物的y坐标(行数).
*返回值: 无
********************************************/
void pathfinding(int* map, int map_line, int map_col, int road, int walk_by_road, int role_x, int role_y) {
	if (!map) return;

	Stack stack;
	initStack(stack);

	Pos role = {role_x, role_y};

	IMAGE daoju[2];
	loadimage(&daoju[0], _T("daoju4.bmp"), 40, 40, true);
	loadimage(&daoju[1], _T("daoju2.bmp"), 40, 40, true);

	while (true) {
		putimage(role.x * 40, role.y * 40, &daoju[1]);
		Link* link = new Link;

		if (role.x - 1 >= 0 && map[role.y * map_col + (role.x - 1)] == road) {
			link_data;
			map[role.y * map_col + role.x--] = walk_by_road;
		}
		else if (role.y - 1 >= 0 && map[(role.y - 1) * map_col + role.x] == road) {
			link_data;
			map[role.y-- * map_col + role.x] = walk_by_road;
		}
		else if (role.x + 1 < map_col && map[role.y * map_col + (role.x + 1)] == road) {
			link_data;
			map[role.y * map_col + role.x++] = walk_by_road;
		}
		else if (role.y + 1 < map_line && map[(role.y + 1) * map_col + role.x] == road) {
			link_data;
			map[role.y++ * map_col + role.x] = walk_by_road;
		}
		else {
			map[role.y * map_col + role.x] = walk_by_road;
			role.x = stack.top->data.x;
			role.y = stack.top->data.y;
			outStack(stack);
		}

		putimage(role.x*40, role.y*40, &daoju[0]);

		Sleep(500);

		if (stack.tail == stack.top) break;
	}
	destroyStack(stack);
}