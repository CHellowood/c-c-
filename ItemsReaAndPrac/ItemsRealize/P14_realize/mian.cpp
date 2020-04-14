#include <iostream>
#include <Windows.h>
#include "ODU.h"
#include "ODU335.h"

void test(ODU* odu) {
	while (true) {
		if (!odu->heartBeat()) {
			switch(odu->getODUType()) {
			case ODU_TYPE::ODU_TYPE_331:
				delete odu;
				odu = new ODU335;
				break;
			case ODU_TYPE::ODU_TYPE_335:
				delete odu;
				odu = new ODU;
				break;
			default:
				odu = NULL;
				return;
			}
		}
		Sleep(1000);
	}
}


int main() {
	ODU* odu = new ODU;

	test(odu);

	system("pause");
	return 0;
}
