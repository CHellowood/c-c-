#include <iostream>
#include <Windows.h>
#include "Computer.h"
#include "SoundBox.h"

void Test(SoundBox &box) {
	Computer test("intel", "i9", 1000, 32);
	test.callBox(&box);
	//cout << "cpuƷ��:" << test.callCpu().callCpuBrand() << endl;
	//cout << "cpu�ͺ�:" << test.callCpu().callCpuModel() << endl;
	//cout << "����Ӳ�̴�С:" << test.callHardDisk() << endl;
	//cout << "�����ڴ��С:" << test.callMemory() << endl;
}

int main() {
	SoundBox box;
	Test(box);

	system("pause");
}