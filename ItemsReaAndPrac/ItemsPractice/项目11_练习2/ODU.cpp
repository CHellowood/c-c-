#include "ODU.h"
#include <sstream>

ODU::ODU(PWR_TYPE pwr, MHZ_TYPE mhz, BW_TYPE bw) {
	this->PWR = pwr;
	this->MHZ = mhz;
	this->BW  = bw;
}

ODU::~ODU() {

}

/*�鿴���书��*/
PWR_TYPE ODU::getPWR() {
	return PWR;
}

/*�鿴����Ƶ��*/
MHZ_TYPE ODU::getMHZ() {
	return MHZ;
}

/*�鿴����*/
BW_TYPE ODU::getBW() {
	return BW;
}

/*���÷��书��*/
void ODU::setPWR(PWR_TYPE pwr) {
	this->PWR = pwr;
}

/*���÷���Ƶ��*/
void ODU::setMHZ(MHZ_TYPE mhz) {
	this->MHZ = mhz;
}

/*�޸Ĵ���*/
void ODU::setBW(BW_TYPE bw) {
	this->BW = bw;
}


string ODU::Overview() {
	stringstream ret;
	ret << "PWR:\t" << PWR << "\nMHZ:\t" << MHZ << "\nBW:\t" << BW << "\n";
	return ret.str();
}