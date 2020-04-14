#include "ComputerService.h"
#include "Computer.h"
#include <iostream>

void ComputerService::upgrade(Computer* computer) {
	computer->cpu = "i7";
}

void ComputerService::clear(Computer* computer)
{
	std::cout << "[CPU: " << computer->cpu << "]正在清理垃圾...\n";
}

void ComputerService::kill(Computer* computer)
{
	std::cout << "[CPU: " << computer->cpu << "]正在执行杀毒...\n";
}

