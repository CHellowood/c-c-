#include "backtracking.h"
#include "LinkStack.h"
#include <graphics.h>

#define link_data            \
	link->data.x = role.x;   \
	link->data.y = role.y;   \
	enterStack(stack, link)

/*******************************************
*���ݷ�Ѱ·:
*����:   map��ͼ�׵�ַ, map_line��ͼ�߶�(����), map_col��ͼ���(����),
         road��ʾ·������(����), Walk_by_road���߹���·��ΪWalk_by_road,
		 role_x�����x����(����), role_y�����y����(����).
*����ֵ: ��
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