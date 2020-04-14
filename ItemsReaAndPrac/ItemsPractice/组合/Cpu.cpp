#include "Cpu.h"

Cpu::Cpu() {
	cout << "调用手动定义的默认构造函数!" << endl;
}

Cpu::Cpu(const string cpuBrand, const string cpuModel)
{
	this->cpuBrand = cpuBrand;
	this->cpuModel = cpuModel;

	cout << "启动:Cpu" << endl;
}


Cpu::~Cpu(void)
{
	cout << "关闭:Cpu" << endl;
}

string& Cpu::callCpuBrand() {
	return cpuBrand;
}

string& Cpu::callCpuModel() {
	return cpuModel;
}