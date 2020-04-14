#include <iostream>
#include <Windows.h>

using namespace std;

#define DATA_SIZE 11

typedef struct _Priority {
	int priority;
}Priority;

typedef Priority DataType;

typedef struct PriorityQueue {
	DataType* data; //数据
	int size;       //当前已储存的元素个数
	int limit;      //元素个数上限
}PQueue;

bool initQueue(PQueue& queue, int* data, int len);
bool insertQueue(PQueue& queue, int n);
bool outQueue(PQueue& queue, int& n);
void destroyQueue(PQueue& queue);

static bool adjust(PQueue& queue, int i);
static bool insert_adjust(PQueue& queue, int i);
bool initQueue(PQueue& queue, int* data, int len) {
	int limit = DATA_SIZE > len ? DATA_SIZE : len;

	queue.data = new Priority[limit];
	if (!queue.data) return false;

	queue.size = 0;
	queue.limit = limit;
	
	if (len > 0) {
		for (queue.size = 0; queue.size < len;) {
			queue.data[queue.size++].priority = data[queue.size];
			if (!insert_adjust(queue, queue.size - 1)) return false;
		}
	}
	return true;
}

bool insertQueue(PQueue& queue, int n) {
	if (!queue.data || queue.size >= queue.limit) return false;

	queue.data[queue.size++].priority = n;
	if (!insert_adjust(queue, queue.size - 1)) return false;

	return true;
}

bool outQueue(PQueue& queue, int& n) {
	if (!queue.data) return false;

	n = queue.data[0].priority;
	queue.data[0].priority = queue.data[--queue.size].priority;

	for (int i = (queue.size - 1) / 2; i >= 0; i--) {
		if (!adjust(queue, i)) return false;
	}

	return true;
}

bool adjust(PQueue& queue, int i) {
	if (!queue.data || i < 0 || i >= queue.size) return false;

	int node = queue.data[i].priority;
	while ((i * 2 + 1) < queue.size) {
		int son = i * 2 + 1;

		if (son + 1 < queue.size && queue.data[son + 1].priority > queue.data[son].priority) {
			son++;
		}

		if (queue.data[son].priority <= queue.data[i].priority) {
			break;
		}

		queue.data[i].priority = queue.data[son].priority;
		queue.data[son].priority = node;

		i = son;
	}
	return true;
}

bool insert_adjust(PQueue& queue, int i) {
	if (i < 0 || i >= queue.size) return false;

	while (i > 0) {
		int father = (i - 1) / 2;

		if (queue.data[father].priority >= queue.data[i].priority) {
			break;
		}

		int num = queue.data[father].priority;
		queue.data[father].priority = queue.data[i].priority;
		queue.data[i].priority = num;

		i = father;
	}
	return true;
}

void destroyQueue(PQueue& queue) {
	if (!queue.data) {
		cout << "队列不存在!" << endl;
		return;
	}

	delete[] queue.data;
}

int main(void) {
	PQueue queue;
	int data[] = {2, 4, 5, 8, 0, 1, 3, 6, 7, 9};

	if (!initQueue(queue, data, sizeof(data) / sizeof(data[0]))) {
		cout << "初始化优先队列失败!" << endl;
		system("pause");
		exit(-1);
	}
	cout << "初始化优先队列成功!" << endl;

	for (int i = 0; i < queue.size; i++) {
		cout << " " << queue.data[i].priority;
	}
	cout << endl;

	if (!insertQueue(queue, 66)) {
		cout << "插入失败!" << endl;
	}
	else {
		cout << "插入成功!" << endl;
	}

	for (int i = 0; i < queue.size; i++) {
		cout << " " << queue.data[i].priority;
	}
	cout << endl;

	int n = 0;
	cout << "出队:";
	for (int i = 0; i < queue.size;) {
		outQueue(queue, n);
		cout << " " << n;
	}
	cout << endl;

	destroyQueue(queue);

	system("pause");
	return 0;
}