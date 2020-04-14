//#pragma once
#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <vector>
#include "Boy.h"
#include "Girl.h"

using namespace std;

class Database {
public:
	Database();
	//Database(vector<Boy>& boys, vector<Girl>& girls);
	~Database();

	void init(); /*���ļ����ȡ���ݣ� ����ʼ����Ա*/
	bool match();/*ƥ�����*/
	void print();/*��ӡboys��girls����Ϣ*/

	/*����û�*/
	void addOne(Boy &boy);
	void addOne(Girl &girl);

private:
	/*��ȡ�ļ���С*/
	long long fileSize(const char* file);
	
	void initBoys();    /*���ļ����ȡ���ݣ� ����ʼ��boys*/
	void initGirls();   /*���ļ����ȡ���ݣ� ����ʼ��girls*/
	void saveBoys();    /*��boys�����ݱ��浽�ļ���*/
	void saveGirls();   /*��girls���ݱ��浽�ļ���*/

	vector<Boy> boys;   /*��������Ϣ*/
	vector<Girl> girls; /*����Ů��Ϣ*/
};

#endif 