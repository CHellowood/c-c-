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

	void init(); /*从文件里读取数据， 来初始化成员*/

	bool autoMatch();        /*自动匹配对象*/
	bool autoMatchBest();    /*自动匹配最佳对象*/
	bool autoMatchBestBoy(const Girl& girl); /*自动匹配最佳男孩*/
	bool autoMatchBestGirl(const Boy& boy);/*自动匹配最佳女孩*/

	void print();/*打印boys和girls的信息*/

	/*添加用户*/
	void addOne(Boy &boy);
	void addOne(Girl &girl);

private:
	/*获取文件大小*/
	long long fileSize(const char* file);
	
	void initBoys();    /*从文件里读取数据， 来初始化boys*/
	void initGirls();   /*从文件里读取数据， 来初始化girls*/
	void saveBoys();    /*把boys的数据保存到文件中*/
	void saveGirls();   /*把girls数据保存到文件中*/

	vector<Boy> boys;   /*单身男信息*/
	vector<Girl> girls; /*单身女信息*/
};

#endif 