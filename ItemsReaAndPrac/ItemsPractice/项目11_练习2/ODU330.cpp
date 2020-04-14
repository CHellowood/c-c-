#include "ODU330.h"
#include <sstream>

ODU330::ODU330(PWR_TYPE pwr, MHZ_TYPE mhz, BW_TYPE bw, BER_TYPE berwl)
	: ODU(pwr, mhz, bw) {
	this->BERWL = berwl;
}

ODU330::~ODU330() {

}

/*查看误码率*/
BER_TYPE ODU330::getBER() {
	return 0.00005;
}

/*查看误码率警告线*/
BER_TYPE ODU330::getBERWL() {
	return BERWL;
}

/*设置误码率警告线*/
void ODU330::setBERWL(BER_TYPE berwl) {
	this->BERWL = berwl;
}

/*设备概述*/
string ODU330::Overview() {
	stringstream ret;
	ret << "PWR:\t" << PWR << "\nMHZ:\t" << MHZ << "\nBW:\t" << BW
		<< "\nBER:\t" << getBER() << "\nBERWL:\t" << BERWL << "\n";
	return ret.str();
}