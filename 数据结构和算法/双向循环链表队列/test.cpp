#include <iostream>
#include <Windows.h>
#include "DoubleCycleLinkQueue.h"

using namespace std;

int main(void) {
	EQUEUE* equeue = new EQUEUE;
	DLINK* node = NULL;

	INIT_QUEUE(&equeue->expiredQueue);

	for (int i = 0; i < 5; i++) {
		QUEUE* queue = new QUEUE;
		queue->data = i;
		QUEUE_INSERT_HEAD(&equeue->expiredQueue, &queue->queue);
	}

	for (node = equeue->expiredQueue.naxt; node != &equeue->expiredQueue; node = node->naxt) {
		cout << (CUT_ADDRESS(node, QUEUE, queue))->data << endl;
	}

	while (equeue->expiredQueue.former != &equeue->expiredQueue) {
		node = equeue->expiredQueue.former;
		QUEUE* p = (CUT_ADDRESS(node, QUEUE, queue));
		cout << p->data << endl;
		QUEUE_DELETE(node);
		delete p;
	}


	system("pause");
	return 0;
}

