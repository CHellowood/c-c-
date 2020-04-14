#include <iostream>
#include <Windows.h>
#include "Vector.hpp" //模板的cpp文件写法

//void print(Vector<int>& vec)
//{
//	for (int i = 0; i < vec.getSize(); i++)
//	{
//		std::cout << vec[i] << "\t";
//	}
//
//	std::cout << "\nsize: " << vec.getSize() << std::endl;
//}

class Test 
{
public:
	Test(const char* name = "test", int age = 0) 
	{
		//if (name) 
		{
			int len = strlen(name) + 1;
			this->name = new char[len];
			strcpy_s(this->name, len, name);
		}
		/*else {
			this->name = nullptr;
		}*/
		this->age = age;
	}
	
	bool operator<(const Test& test) const {
		return (this->age < test.age);
	}

	Test& operator=(const Test& test)
	{
		if (this->name)
		{
			delete[] this->name;
			this->name = nullptr;
		}
		int len = strlen(test.name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, test.name);
		this->age = test.age;
		return *this;
	}

	~Test() 
	{
		if (this->name) 
		{
			delete[] this->name;
			this->name = nullptr;
		}
	}

	friend std::ostream& operator<<(std::ostream& os, const Test& test)
	{
		os << test.name << "\t" << test.age;
		return os;
	}

private:
	char* name;
	int age;
};


int main() 
{
	//Vector<int> vec;
	Vector<Test> vec;

	/*for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}*/

	Test t1("Tom", 19);
	Test t2("Jerry", 18);

	vec.push_back(t1);
	vec.push_back(t2);

	//print(vec);
	std::cout << vec;
	std::cout << "第一个元素的值: " << *(vec.begin()->data) << std::endl;

	vec.erase(vec.begin());
	std::cout << "删除第一个元素后: \n";
	//print(vec);
	std::cout << vec;

	vec.erase(vec.begin(), vec.end());
	std::cout << "删除所有元素后: \n";
	//print(vec);
	std::cout << vec;


	system("pause");
	return 0;
}
