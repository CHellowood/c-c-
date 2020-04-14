/*#pragma once*/
#ifndef _ODU330_h_
#define _ODU330_H_

#include "ODU.h"

#define BER   BitErrorRate             /*������*/
#define BERWL BitErrorRateWarnintLine  /*�����ʾ�����*/

#define BER_TYPE float    /*�����ʵ���������*/ 

class ODU330 : public ODU {
public:
	ODU330(PWR_TYPE pwr, MHZ_TYPE mhz, BW_TYPE bw, BER_TYPE berwl);
	~ODU330();

	BER_TYPE getBER();      /*�鿴������*/
	BER_TYPE getBERWL();    /*�鿴�����ʾ�����*/
	void     setBERWL(BER_TYPE berwl);    /*���������ʾ�����*/
	string   Overview();    /*�豸����*/

private:
	BER_TYPE BERWL;    /*�����ʾ�����*/
};

#endif 