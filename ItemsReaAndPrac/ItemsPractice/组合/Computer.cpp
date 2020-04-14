#include "Computer.h"


Computer::Computer(const string cpuBrand, const string cpuModel, const int hardDisk, const int memory):cpu(cpuBrand, cpuModel)
{
	this->hardDisk = hardDisk;
	this->memory = memory;

	cout << "����:Computer" << endl;
}


Computer::~Computer(void)
{
	cout << "�ر�:Computer" << endl;
}

Cpu Computer::callCpu() const {
	return cpu;
}

void Computer::callBox(SoundBox *box) {
	this->box = box;
}

int Computer::callHardDisk() const {
	return hardDisk;
}

int Computer::callMemory() const {
	return memory;
}