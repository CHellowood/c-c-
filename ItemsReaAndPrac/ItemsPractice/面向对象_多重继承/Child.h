#pragma once
#include "Father.h"
#include "Mother.h"


class Child : public Father, public Mother{
public:
	Child();
	~Child();

	void cook();
};

