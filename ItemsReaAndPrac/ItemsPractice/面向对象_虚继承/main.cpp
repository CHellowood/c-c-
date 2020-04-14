#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//�绰��
class Tel {
public:
	Tel() {
		this->number = "???";
	}

protected:
	string number;
};

//������
//virtual���õ�ǰ�̳�Ϊ"��̳�", ��ʱ���̳е��౻��Ϊ"�����"
class FixedLine : virtual public Tel {

};

//�ֻ���
//virtual���õ�ǰ�̳�Ϊ"��̳�", ��ʱ���̳е��౻��Ϊ"�����"
class MobilePhone : virtual public Tel {

};

//����������
class WirelessTel : public FixedLine, public MobilePhone {
public:
	//���ú���
	void setNumber(const char* number) {
		//FixedLine���MobilePhone�඼�̳���Tel��,WirelessTel�̳���FixedLine���MobilePhone��,
		//���൱��WirelessTel�̳�������Tel��,�����ָ������һ����̳е�Tel��������ݾ�ֱ�ӷ���,�������ͻᱨ��,       
		//this->FixedLine::number = number;//��//this->MobilePhone::number = number;
		
		//ʹ����̳в����ظ��̳�
		this->number = number;
	}

	//��ȡ����
	string getNumber() {
		return this->number;
	}
};



int main(void) {
	WirelessTel tel;

	tel.setNumber("12345678910");
	cout << tel.getNumber() << "\n";

	system("pause");
	return 0;
}