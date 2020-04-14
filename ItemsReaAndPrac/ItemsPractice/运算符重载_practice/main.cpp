#include <iostream>
#include <Windows.h>
//#include "Money.h"
//#include "Pork.h"
//#include "Beef.h"
#include "Boy.h"
#include "Man.h"

using namespace std;

int main(void) {
	/*//----------双目运算符重载测试----------
	Pork p1(10);
	Pork p2(20);
	Beef b1(10);
	Beef b2(20);

	Money m = p1 + p2;

	cout << m.description() << endl;

	m = p1 + b1;

	cout << m.description() << endl;

	m = b1 + b2;

	cout << m.description() << endl;

	m = b1 + p2;

	cout << m.description() << endl;
	*/
	
	/*//----------赋值运算符重载测试----------
	Boy boy1("侵袭", 18, 4000, 10);
	Boy boy2;

	cout << boy1.description() << endl;
	cout << boy2.description() << endl;

	boy2 = boy1;

	cout << "\n拷贝后:\n";

	cout << boy1.description() << endl;
	cout << boy2.description() << endl;
	*/

	/*//----------关系运算符重载测试----------
	Boy boy3("Tom", 22, 12000, 10);
	Boy boy4("Jerry", 22, 10000, 10);

	if (boy3 > boy4) {
		cout << "选择boy3\n";
	}
	else if (boy3 == boy4) {
		cout << "boy3和boy4一样优秀， 该选哪一个呢？\n";
	}
	else if (boy3 < boy4) {
		cout << "选择boy4\n";
	}
	*/

	////----------下标运算符重载测试----------
	//Boy boy5("while-侵袭", 18, 4000, 10);

	////由于name是字符串，而下标运算符返回的是整数， 所以需要进行强制类型转换
	////cout << "name: " << (char*)boy5[NAME_KEY] << endl;
	//cout << "age: " << boy5[AGE_KEY] << endl;
	//cout << "salary: " << boy5[SALARY_KEY] << endl;
	//cout << "darkHorse: " << boy5[DARK_HORSE_KEY] << endl;

	//cout << endl;

	////cout << "name: " << (char*)boy5[NAME] << endl;
	//cout << "age: " << boy5[AGE] << endl;
	//cout << "salary: " << boy5[SALARY] << endl;
	//cout << "darkHorse: " << boy5[DARK_HORSE] << endl;

	////----------输入输出运算符重载测试----------
	//Boy boy6("while-侵袭", 18, 4000, 10);
	//Boy boy7;

	//////用成员函数实现输出运算符重载 
	//////不推荐使用成员函数来实现输出运算符重载
	////boy6 << cout << endl;
	////boy7 << (boy6 << cout << endl) << endl;

	//////用成员函数实现输入运算符重载 
	//////不推荐使用成员函数来实现输入运算符重载
	////boy7 >> cin;
	//////boy6 >> (boy7 >> cin);

	////boy7 << cout << endl;

	////使用全局友元函数来实现输出运算符重载
	//cout << boy6 << endl << boy7 << endl;

	////使用全局友元函数来实现输入运算符重载
	//cin >> boy7;
	//cout << boy7 << endl;

	////----------普通类型转类类型----------
	//Boy boy8 = 10000;//构造函数Boy(int);
	//
	//cout << boy8 << endl;

	////----------类类型转普通类型(类型运算符重载)----------
	//Boy boy9("七月雪", 18, 4000, 10);

	//int power = boy9;
	//char* name = boy9;

	//cout << power << endl;
	//cout << name << endl;

	////----------类类型转类类型----------
	//Boy boy10("while", 18, 4000, 10);
	//Man man = boy10;//构造函数 Man(Boy&);

	//cout << boy10 << endl;
	//cout << man << endl;

	system("pause");
	return 0;
}