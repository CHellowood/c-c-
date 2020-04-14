#include <iostream>
#include <Windows.h>
#include <time.h>
#include "TimeoutList.h"

using namespace std;

void timeout(CONTIOUT& list, time_t now) {
	for (int i = 0; i < list.lenght; i++) {
		if (list.connection[i].connectionTime > now) {
			continue;
		}
		cout << "fd=" << list.connection[i].fd << ":连接超时,已断开连接!" << endl;
		deleteConnection(list, i);
		i--;
		return;
	}
	cout << "正在连接..." << endl;
}

int main() {
	CONTIOUT list;
	time_t start, end, last_time;

	initList(list);

	time(&start);
	end = start + 60;
	last_time = start;

	for (int i = 0; i < LIST_MAX; i++) {
		CONNECTION n;
		n.connectionTime = start + 5 + 2 * i;
		n.fd = i;

		addConnection(list, n);
	}
	printList(list);

	while (end > start) {
		if (start > last_time + 0.999) {
			last_time = start;
			timeout(list, start);
		}
		Sleep(10);
		time(&start);
	}
	destroyList(list);

	system("pause");
	return 0;
}