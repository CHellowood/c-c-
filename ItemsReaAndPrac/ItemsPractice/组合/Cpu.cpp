#include "Cpu.h"

Cpu::Cpu() {
	cout << "�����ֶ������Ĭ�Ϲ��캯��!" << endl;
}

Cpu::Cpu(const string cpuBrand, const string cpuModel)
{
	this->cpuBrand = cpuBrand;
	this->cpuModel = cpuModel;

	cout << "����:Cpu" << endl;
}


Cpu::~Cpu(void)
{
	cout << "�ر�:Cpu" << endl;
}

string& Cpu::callCpuBrand() {
	return cpuBrand;
}

string& Cpu::callCpuModel() {
	return cpuModel;
}