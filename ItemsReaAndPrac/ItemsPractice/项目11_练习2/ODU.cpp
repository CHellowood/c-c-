#include "ODU.h"
#include <sstream>

ODU::ODU(PWR_TYPE pwr, MHZ_TYPE mhz, BW_TYPE bw) {
	this->PWR = pwr;
	this->MHZ = mhz;
	this->BW  = bw;
}

ODU::~ODU() {

}

/*查看发射功率*/
PWR_TYPE ODU::getPWR() {
	return PWR;
}

/*查看发射频率*/
MHZ_TYPE ODU::getMHZ() {
	return MHZ;
}

/*查看带宽*/
BW_TYPE ODU::getBW() {
	return BW;
}

/*设置发射功率*/
void ODU::setPWR(PWR_TYPE pwr) {
	this->PWR = pwr;
}

/*设置发射频率*/
void ODU::setMHZ(MHZ_TYPE mhz) {
	this->MHZ = mhz;
}

/*修改带宽*/
void ODU::setBW(BW_TYPE bw) {
	this->BW = bw;
}


string ODU::Overview() {
	stringstream ret;
	ret << "PWR:\t" << PWR << "\nMHZ:\t" << MHZ << "\nBW:\t" << BW << "\n";
	return ret.str();
}