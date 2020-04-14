#include "Database.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

#define BOYS_FILE  "boys.txt"
#define GIRLS_FILE "girls.txt"

Database::Database() {
	
}

/*
Database::Database(vector<Boy>& boys, vector<Girl>& girls) {
	this->boys = boys;
	this->girls = girls;
}
*/

Database::~Database() {

}

/*获取文件的大小（单位：字节）*/
long long Database::fileSize(const char* file) {
	ifstream infile;
	infile.open(file);
	if (!infile.is_open()) {
		//cout << "fileSize: 文件打开失败！\n";
		return -1;
	}

	infile.seekg(0, infile.end);
	long long ret = infile.tellg();

	infile.close();
	return ret;
}

/*从文件里读取数据，来初始化成员*/
void Database::init() {
	initBoys();
	initGirls();
}

/*从文件里读取数据，来初始化boys的信息*/
void Database::initBoys() {
	ifstream infile;
	infile.open(BOYS_FILE);
	
	/*文件打开失败， 文件不存在*/
	if (!infile.is_open()) {
		cout << "--【男嘉宾信息】--\n";

		/*输入信息*/
		Boy::inputBoys(boys);
		
		/*把输入的信息保存到文件中*/
		saveBoys();
		return;
	}

	/*循环读取*/
	while (true) {
		string stream;

		/*从文件里读一行数据*/
		getline(infile, stream);

		/*是否读到文件结束符*/
		if (infile.eof()) break;

		char name[16];     //名字
		int age;         //年龄
		int yanzhi;      //颜值
		int wage;        //工资

	/*
		infile >> name >> gender >> age >> yanzhi >> wage;
	*/

		/*从读取出来的一行字符串中读取数据*/
		int ret = sscanf_s(stream.c_str(), "名字:%s 性别:男 年龄:%d 颜值:%d 薪资:%d\n", name, sizeof(name), &age, &yanzhi, &wage);
		
		/*数据读取失败*/
		if (ret < 0) {
			cout << "boys数据库格式匹配失败！\n";
			system("pause");
			exit(1);
		}

		/*把读到的数据加入boys里*/
		boys.push_back(Boy(string(name), age, yanzhi, wage));

	}
	/*关闭文件*/
	infile.close();
	return;
}

/*从文件里读取数据，来初始化girls的信息*/
void Database::initGirls() {
	ifstream infile;
	infile.open(GIRLS_FILE);

	/*文件打开失败， 文件不存在*/
	if (!infile.is_open()) {
		cout << "--【女嘉宾信息】--\n";

		/*输入信息*/
		Girl::inputGirls(girls);
		
		/*把输入的信息保存到文件中*/
		saveGirls();
		return;
	}

	/*循环读取*/
	while (true) {
		string stream;

		/*从文件里读一行数据*/
		getline(infile, stream);

		/*是否读到文件结束符*/
		if (infile.eof()) break;

		char name[16];     //名字
		int age;         //年龄
		int yanzhi;      //颜值
		int wage;        //工资

		/*从文件中读取数据*/
	/*
		infile >> name >> gender >> age >> yanzhi >> wage;
	*/

		/*从读取出来的一行字符串中读取数据*/
		int ret = sscanf_s(stream.c_str(), "名字:%s 性别:女 年龄:%d 颜值:%d 薪资:%d\n", name, sizeof(name), &age, &yanzhi, &wage);
		
		/*数据读取失败*/
		if (ret < 0) {
			cout << "girls数据库格式匹配失败！\n";
			system("pause");
			exit(1);
		}


		girls.push_back(Girl(string(name), age, yanzhi, wage));
	}
	/*关闭文件*/
	infile.close();
	return;
}

/*匹配对象*/
bool Database::match() {
	/*当boys或girls为空时匹配失败！*/
	if (boys.size() < 1 || girls.size() < 1) {
		cout << "boys或girls为空!\n";
		return false;
	}

	/*用line表示100个 - 号*/
	string line(100, '-');
	
	cout << line << "\n";

	for (int i = 0; i < boys.size(); i++) {
		for (int j = 0; j < girls.size(); j++) {
			if (boys[i].satisfied(girls[j]) && girls[j].satisfied(boys[i])) {

				cout << boys[i].getName() << "-和-" << girls[j].getName() << " 匹配成功!" << "\n";
				cout << endl << boys[i].description() << "\n" << girls[j].description() << "\n";
				cout << line << "\n";
			}
		}
	}
	return true;
}

/*把boys的数据保存到文件中*/
void Database::saveBoys() {
	ofstream outfile;
	outfile.open(BOYS_FILE);
	
	if (!outfile.is_open()) {
		cout << BOYS_FILE << "写入失败！";
		system("pause");
		exit(-1);
	}

	for (vector<Boy>::iterator iter = boys.begin(); iter != boys.end(); iter++) {
	/*
		outfile << iter->getName() << "\t" << iter->getGender() << "\t"
			<< iter->getAge() << "\t" << iter->getYanzhi() << "\t"
			<< iter->getWage() << "\n";
	*/

		outfile << iter->description() << "\n";
	}

	outfile.close();
	return ;
} 

/*把girls的数据保存到文件中*/
void Database::saveGirls() {
	ofstream outfile;
	outfile.open(GIRLS_FILE);

	if (!outfile.is_open()) {
		cout << GIRLS_FILE << "写入失败！";
		system("pause");
		exit(-1);
	}

	for (vector<Girl>::iterator iter = girls.begin(); iter != girls.end(); iter++) {
	/*
		outfile << iter->getName() << "\t" << iter->getGender() << "\t"
			<< iter->getAge() << "\t" << iter->getYanzhi() << "\t"
			<< iter->getWage()<< "\n";
	*/

		outfile << iter->description() << "\n";
	}

	outfile.close();
	return;
}


void Database::print() {
	if (boys.size() < 1 && girls.size() < 1) {
		cout << "暂无数据！\n";
		return;
	}

	cout << "男嘉宾数据: \n\n";
	for (vector<Boy>::iterator iter = boys.begin(); iter != boys.end(); iter++) {
	/*
		cout << iter->getName() << "\t" << iter->getGender() << "\t"
			<< iter->getAge() << "\t" << iter->getYanzhi() << "\t"
			<< iter->getWage() << "\t" << iter->getDemandYanzhi() << "\t"
			<< iter->getDemandWage() << "\n";
	*/

		cout << iter->description() << "\n";
	}

	cout << "\n女嘉宾数据: \n\n";
	for (vector<Girl>::iterator iter = girls.begin(); iter != girls.end(); iter++) {
	/*
		cout << iter->getName() << "\t" << iter->getGender() << "\t"
			<< iter->getAge() << "\t" << iter->getYanzhi() << "\t"
			<< iter->getWage() << "\n";
	*/

		cout << iter->description() << "\n";
	}
}

void Database::addOne(Boy &boy) {
	boys.push_back(boy);
	
	//把boys保存到文件中
	saveBoys();

	/*当boys或girls为空时匹配失败！*/
	if (girls.size() < 1) {
		cout << "girls为空!\n";
		return ;
	}

	/*用line表示100个 - 号*/
	string line(100, '-');

	cout << line << "\n";

	//匹配与该boy符合的girl
	for (int i = 0; i < girls.size(); i++) {
		if (boy.satisfied(girls[i]) && girls[i].satisfied(boy)) {

			cout << boy.getName() << "-和-" << girls[i].getName() << " 匹配成功!" << "\n";
			cout << endl << boy.description() << "\n" << girls[i].description() << "\n";
			cout << line << "\n";
		}
	}
}

void Database::addOne(Girl& girl) {
	girls.push_back(girl);
	
	//把girls保存到文件中
	saveGirls();

	/*当boys或girls为空时匹配失败！*/
	if (boys.size() < 1) {
		cout << "girls为空!\n";
		return;
	}

	/*用line表示100个 - 号*/
	string line(100, '-');

	cout << line << "\n";

	//匹配与该boy符合的girl
	for (int i = 0; i < boys.size(); i++) {
		if (girl.satisfied(boys[i]) && boys[i].satisfied(girl)) {

			cout << girl.getName() << "-和-" << boys[i].getName() << " 匹配成功!" << "\n";
			cout << endl << girl.description() << "\n" << boys[i].description() << "\n";
			cout << line << "\n";
		}
	}
}