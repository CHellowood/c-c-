#pragma once
#include "Cpu.h"

class SoundBox;

class Computer
{
public:
	Computer(const string cpuBrand, const string cpuModel, const int hardDisk, const int memory);
	~Computer(void);

	Cpu callCpu() const;
	int callHardDisk() const;
	int callMemory() const;
	void callBox(SoundBox *box);

private:
	Cpu cpu;
	SoundBox *box;
	int hardDisk;//硬盘 单位:G
	int memory;  //内存 单位:G
};

