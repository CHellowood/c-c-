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

	virtual int getTxFre(); //获取发射频率
	virtual bool setTxFre(int); //设置发射频率

	virtual int getRxFre(); //获取接收频率
	virtual bool setRxFre(int); //设置接收频率

	virtual float getTxPower(); //获取发射功率
	virtual bool setTxPower(float); //设置发射功率

	virtual float getRxL(); //获取接受电平

	virtual bool heartBeat(); //心跳包

	virtual std::string type_str();
	virtual ODU_TYPE getODUType();

protected:
	int TxFre;    //发射频率
	int RxFre;    //接收频率
	float TxPower;//发射功率
	float RxL;    //接收电平
	ODU_TYPE type;
};

#endif 