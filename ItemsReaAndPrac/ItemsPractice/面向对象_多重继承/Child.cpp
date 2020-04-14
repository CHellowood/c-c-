#include "Child.h"
#include <sstream>

Child::Child() {
	
}

Child::~Child() {
}


void Child::cook() {
	Father::cook();
	Mother::cook();
}