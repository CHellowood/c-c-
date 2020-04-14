#include "ODU330.h"
#include <sstream>

ODU330::ODU330(PWR_TYPE pwr, MHZ_TYPE mhz, BW_TYPE bw, BER_TYPE berwl)
	: ODU(pwr, mhz, bw) {
	this->BERWL = berwl;
}

ODU330::~ODU330() {

}

/*�鿴������*/
BER_TYPE ODU330::getBER() {
	return 0.00005;
}

/*�鿴�����ʾ�����*/
BER_TYPE ODU330::getBERWL() {
	return BERWL;
}

/*���������ʾ�����*/
void ODU330::setBERWL(BER_TYPE berwl) {
	this->BERWL = berwl;
}

/*�豸����*/
string ODU330::Overview() {
	stringstream ret;
	ret << "PWR:\t" << PWR << "\nMHZ:\t" << MHZ << "\nBW:\t" << BW
		<< "\nBER:\t" << getBER() << "\nBERWL:\t" << BERWL << "\n";
	return ret.str();
}