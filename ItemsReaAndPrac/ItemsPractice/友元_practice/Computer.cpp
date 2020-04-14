#include "Computer.h"

Computer::Computer() {
	this->cpu = "i5";
}

std::string Computer::description() {
	return this->cpu;
}