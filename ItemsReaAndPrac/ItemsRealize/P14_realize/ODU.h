#pragma once

#ifndef _ODU_H_
#define _ODU_H_

#include <string>

#define ODU_TYPE_ODU331 "331"
#define ODU_TYPE_ODU335 "335"

enum class ODU_TYPE {
	ODU_TYPE_331,
	ODU_TYPE_335,
	ODU_TYPE_UNKNOWN
};

class ODU
{
public:
	ODU();

	virtual int getTxFre(); //��ȡ����Ƶ��
	virtual bool setTxFre(int); //���÷���Ƶ��

	virtual int getRxFre(); //��ȡ����Ƶ��
	virtual bool setRxFre(int); //���ý���Ƶ��

	virtual float getTxPower(); //��ȡ���书��
	virtual bool setTxPower(float); //���÷��书��

	virtual float getRxL(); //��ȡ���ܵ�ƽ

	virtual bool heartBeat(); //������

	virtual std::string type_str();
	virtual ODU_TYPE getODUType();

protected:
	int TxFre;    //����Ƶ��
	int RxFre;    //����Ƶ��
	float TxPower;//���书��
	float RxL;    //���յ�ƽ
	ODU_TYPE type;
};

#endif 