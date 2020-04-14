#include <iostream>
#include <Windows.h>
#include "Computer.h"
#include "SoundBox.h"

void Test(SoundBox &box) {
	Computer test("intel", "i9", 1000, 32);
	test.callBox(&box);
	//cout << "cpu品牌:" << test.callCpu().callCpuBrand() << endl;
	//cout << "cpu型号:" << test.callCpu().callCpuModel() << endl;
	//cout << "电脑硬盘大小:" << test.callHardDisk() << endl;
	//cout << "电脑内存大小:" << test.callMemory() << endl;
}

int main() {
	SoundBox box;
	Test(box);

	system("pause");
}