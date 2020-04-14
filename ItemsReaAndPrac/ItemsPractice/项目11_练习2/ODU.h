/*#pragma once*/
#ifndef _ODU_H_
#define _ODU_H_

#include <string>

using namespace std;

#define PWR Power        /*���书��*/
#define MHZ MegaHertz    /*����Ƶ��*/
#define BW  BandWidth    /*����*/

#define PWR_TYPE float   /*���书�ʵ���������*/
#define MHZ_TYPE int     /*����Ƶ�ʵ���������*/
#define BW_TYPE  float   /*�������������*/

class ODU {
public:
	ODU(PWR_TYPE pwr, MHZ_TYPE mhz, BW_TYPE bw);
	~ODU();

	PWR_TYPE getPWR();    /*�鿴���书��*/
	MHZ_TYPE getMHZ();    /*�鿴����Ƶ��*/
	BW_TYPE  getBW();     /*�鿴����*/
	void     setPWR(PWR_TYPE pwr);    /*���÷��书��*/
	void     setMHZ(MHZ_TYPE mhz);    /*���÷���Ƶ��*/
	void     setBW(BW_TYPE bw);       /*�޸Ĵ���*/

	string   Overview();    /*�豸����*/

protected:
	PWR_TYPE PWR;    /*���书��*/
	MHZ_TYPE MHZ;    /*����Ƶ��*/
	BW_TYPE  BW;     /*����*/
};

#endif 