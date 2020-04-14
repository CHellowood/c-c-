#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//电话类
class Tel {
public:
	Tel() {
		this->number = "???";
	}

protected:
	string number;
};

//座机类
//virtual设置当前继承为"虚继承", 此时被继承的类被称为"虚基类"
class FixedLine : virtual public Tel {

};

//手机类
//virtual设置当前继承为"虚继承", 此时被继承的类被称为"虚基类"
class MobilePhone : virtual public Tel {

};

//无线座机类
class WirelessTel : public FixedLine, public MobilePhone {
public:
	//设置号码
	void setNumber(const char* number) {
		//FixedLine类和MobilePhone类都继承了Tel类,WirelessTel继承了FixedLine类和MobilePhone类,
		//就相当于WirelessTel继承了两次Tel类,如果不指定是哪一个类继承的Tel类里的内容就直接访问,编译器就会报错,       
		//this->FixedLine::number = number;//或//this->MobilePhone::number = number;
		
		//使用虚继承不会重复继承
		this->number = number;
	}

	//获取号码
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