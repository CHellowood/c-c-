/*#pragma once*/
#ifndef _ODU_H_
#define _ODU_H_

#include <string>

using namespace std;

#define PWR Power        /*发射功率*/
#define MHZ MegaHertz    /*发射频率*/
#define BW  BandWidth    /*带宽*/

#define PWR_TYPE float   /*发射功率的数据类型*/
#define MHZ_TYPE int     /*发射频率的数据类型*/
#define BW_TYPE  float   /*带宽的数据类型*/

class ODU {
public:
	ODU(PWR_TYPE pwr, MHZ_TYPE mhz, BW_TYPE bw);
	~ODU();

	PWR_TYPE getPWR();    /*查看发射功率*/
	MHZ_TYPE getMHZ();    /*查看发射频率*/
	BW_TYPE  getBW();     /*查看带宽*/
	void     setPWR(PWR_TYPE pwr);    /*设置发射功率*/
	void     setMHZ(MHZ_TYPE mhz);    /*设置发射频率*/
	void     setBW(BW_TYPE bw);       /*修改带宽*/

	string   Overview();    /*设备概述*/

protected:
	PWR_TYPE PWR;    /*发射功率*/
	MHZ_TYPE MHZ;    /*发射频率*/
	BW_TYPE  BW;     /*带宽*/
};

#endif 