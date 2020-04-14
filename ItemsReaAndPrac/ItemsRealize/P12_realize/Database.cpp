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

/*��ȡ�ļ��Ĵ�С����λ���ֽڣ�*/
long long Database::fileSize(const char* file) {
	ifstream infile;
	infile.open(file);
	if (!infile.is_open()) {
		//cout << "fileSize: �ļ���ʧ�ܣ�\n";
		return -1;
	}

	infile.seekg(0, infile.end);
	long long ret = infile.tellg();

	infile.close();
	return ret;
}

/*���ļ����ȡ���ݣ�����ʼ����Ա*/
void Database::init() {
	initBoys();
	initGirls();
}

/*���ļ����ȡ���ݣ�����ʼ��boys����Ϣ*/
void Database::initBoys() {
	ifstream infile;
	infile.open(BOYS_FILE);
	
	/*�ļ���ʧ�ܣ� �ļ�������*/
	if (!infile.is_open()) {
		cout << "--���мα���Ϣ��--\n";

		/*������Ϣ*/
		Boy::inputBoys(boys);
		
		/*���������Ϣ���浽�ļ���*/
		saveBoys();
		return;
	}

	/*ѭ����ȡ*/
	while (true) {
		string stream;

		/*���ļ����һ������*/
		getline(infile, stream);

		/*�Ƿ�����ļ�������*/
		if (infile.eof()) break;

		char name[16];     //����
		int age;         //����
		int yanzhi;      //��ֵ
		int wage;        //����

	/*
		infile >> name >> gender >> age >> yanzhi >> wage;
	*/

		/*�Ӷ�ȡ������һ���ַ����ж�ȡ����*/
		int ret = sscanf_s(stream.c_str(), "����:%s �Ա�:�� ����:%d ��ֵ:%d н��:%d\n", name, sizeof(name), &age, &yanzhi, &wage);
		
		/*���ݶ�ȡʧ��*/
		if (ret < 0) {
			cout << "boys���ݿ��ʽƥ��ʧ�ܣ�\n";
			system("pause");
			exit(1);
		}

		/*�Ѷ��������ݼ���boys��*/
		boys.push_back(Boy(string(name), age, yanzhi, wage));

	}
	/*�ر��ļ�*/
	infile.close();
	return;
}

/*���ļ����ȡ���ݣ�����ʼ��girls����Ϣ*/
void Database::initGirls() {
	ifstream infile;
	infile.open(GIRLS_FILE);

	/*�ļ���ʧ�ܣ� �ļ�������*/
	if (!infile.is_open()) {
		cout << "--��Ů�α���Ϣ��--\n";

		/*������Ϣ*/
		Girl::inputGirls(girls);
		
		/*���������Ϣ���浽�ļ���*/
		saveGirls();
		return;
	}

	/*ѭ����ȡ*/
	while (true) {
		string stream;

		/*���ļ����һ������*/
		getline(infile, stream);

		/*�Ƿ�����ļ�������*/
		if (infile.eof()) break;

		char name[16];     //����
		int age;         //����
		int yanzhi;      //��ֵ
		int wage;        //����

		/*���ļ��ж�ȡ����*/
	/*
		infile >> name >> gender >> age >> yanzhi >> wage;
	*/

		/*�Ӷ�ȡ������һ���ַ����ж�ȡ����*/
		int ret = sscanf_s(stream.c_str(), "����:%s �Ա�:Ů ����:%d ��ֵ:%d н��:%d\n", name, sizeof(name), &age, &yanzhi, &wage);
		
		/*���ݶ�ȡʧ��*/
		if (ret < 0) {
			cout << "girls���ݿ��ʽƥ��ʧ�ܣ�\n";
			system("pause");
			exit(1);
		}


		girls.push_back(Girl(string(name), age, yanzhi, wage));
	}
	/*�ر��ļ�*/
	infile.close();
	return;
}

/*ƥ�����*/
bool Database::match() {
	/*��boys��girlsΪ��ʱƥ��ʧ�ܣ�*/
	if (boys.size() < 1 || girls.size() < 1) {
		cout << "boys��girlsΪ��!\n";
		return false;
	}

	/*��line��ʾ100�� - ��*/
	string line(100, '-');
	
	cout << line << "\n";

	for (int i = 0; i < boys.size(); i++) {
		for (int j = 0; j < girls.size(); j++) {
			if (boys[i].satisfied(girls[j]) && girls[j].satisfied(boys[i])) {

				cout << boys[i].getName() << "-��-" << girls[j].getName() << " ƥ��ɹ�!" << "\n";
				cout << endl << boys[i].description() << "\n" << girls[j].description() << "\n";
				cout << line << "\n";
			}
		}
	}
	return true;
}

/*��boys�����ݱ��浽�ļ���*/
void Database::saveBoys() {
	ofstream outfile;
	outfile.open(BOYS_FILE);
	
	if (!outfile.is_open()) {
		cout << BOYS_FILE << "д��ʧ�ܣ�";
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

/*��girls�����ݱ��浽�ļ���*/
void Database::saveGirls() {
	ofstream outfile;
	outfile.open(GIRLS_FILE);

	if (!outfile.is_open()) {
		cout << GIRLS_FILE << "д��ʧ�ܣ�";
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
		cout << "�������ݣ�\n";
		return;
	}

	cout << "�мα�����: \n\n";
	for (vector<Boy>::iterator iter = boys.begin(); iter != boys.end(); iter++) {
	/*
		cout << iter->getName() << "\t" << iter->getGender() << "\t"
			<< iter->getAge() << "\t" << iter->getYanzhi() << "\t"
			<< iter->getWage() << "\t" << iter->getDemandYanzhi() << "\t"
			<< iter->getDemandWage() << "\n";
	*/

		cout << iter->description() << "\n";
	}

	cout << "\nŮ�α�����: \n\n";
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
	
	//��boys���浽�ļ���
	saveBoys();

	/*��boys��girlsΪ��ʱƥ��ʧ�ܣ�*/
	if (girls.size() < 1) {
		cout << "girlsΪ��!\n";
		return ;
	}

	/*��line��ʾ100�� - ��*/
	string line(100, '-');

	cout << line << "\n";

	//ƥ�����boy���ϵ�girl
	for (int i = 0; i < girls.size(); i++) {
		if (boy.satisfied(girls[i]) && girls[i].satisfied(boy)) {

			cout << boy.getName() << "-��-" << girls[i].getName() << " ƥ��ɹ�!" << "\n";
			cout << endl << boy.description() << "\n" << girls[i].description() << "\n";
			cout << line << "\n";
		}
	}
}

void Database::addOne(Girl& girl) {
	girls.push_back(girl);
	
	//��girls���浽�ļ���
	saveGirls();

	/*��boys��girlsΪ��ʱƥ��ʧ�ܣ�*/
	if (boys.size() < 1) {
		cout << "girlsΪ��!\n";
		return;
	}

	/*��line��ʾ100�� - ��*/
	string line(100, '-');

	cout << line << "\n";

	//ƥ�����boy���ϵ�girl
	for (int i = 0; i < boys.size(); i++) {
		if (girl.satisfied(boys[i]) && boys[i].satisfied(girl)) {

			cout << girl.getName() << "-��-" << boys[i].getName() << " ƥ��ɹ�!" << "\n";
			cout << endl << girl.description() << "\n" << boys[i].description() << "\n";
			cout << line << "\n";
		}
	}
}