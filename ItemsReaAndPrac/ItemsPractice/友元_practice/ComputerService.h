//#pragma once
#ifndef _COMPUTERSERVICE_H_
#define _COMPUTERSERVICE_H_

class Computer;

class ComputerService
{
public:
	void upgrade(Computer *computer);
	void clear(Computer *computer);
	void kill(Computer *computer);
};

#endif 