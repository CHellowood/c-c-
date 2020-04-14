#include "ComputerService.h"
#include "Computer.h"
#include <iostream>

void ComputerService::upgrade(Computer* computer) {
	computer->cpu = "i7";
}

void ComputerService::clear(Computer* computer)
{
	std::cout << "[CPU: " << computer->cpu << "]������������...\n";
}

void ComputerService::kill(Computer* computer)
{
	std::cout << "[CPU: " << computer->cpu << "]����ִ��ɱ��...\n";
}

