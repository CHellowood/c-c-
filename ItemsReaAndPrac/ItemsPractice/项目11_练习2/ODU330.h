/*#pragma once*/
#ifndef _ODU330_h_
#define _ODU330_H_

#include "ODU.h"

#define BER   BitErrorRate             /*误码率*/
#define BERWL BitErrorRateWarnintLine  /*误码率警告线*/

#define BER_TYPE float    /*误码率的数据类型*/ 

class ODU330 : public ODU {
public:
	ODU330(PWR_TYPE pwr, MHZ_TYPE mhz, BW_TYPE bw, BER_TYPE berwl);
	~ODU330();

	BER_TYPE getBER();      /*查看误码率*/
	BER_TYPE getBERWL();    /*查看误码率警告线*/
	void     setBERWL(BER_TYPE berwl);    /*设置误码率警告线*/
	string   Overview();    /*设备概述*/

private:
	BER_TYPE BERWL;    /*误码率警告线*/
};

#endif 