#pragma once
#include <string>
#include <iostream>

using namespace std;

class Cpu
{
public:
	Cpu();
	Cpu(const string cpuBrand, const string cpuModel);
	~Cpu(void);
	string& callCpuBrand();
	string& callCpuModel();

private:
	string cpuBrand;//Æ·ÅÆ
	string cpuModel;//ÐÍºÅ
};

