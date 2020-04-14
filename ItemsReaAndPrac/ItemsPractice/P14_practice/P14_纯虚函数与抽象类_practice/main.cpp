#include <iostream>
#include <Windows.h>

//ӵ�д��麯�����౻��֮Ϊ������
class Shape {//��״
public:
	Shape(const char* color = "blue"){
		int len = strlen(color) + 1;
		this->color = new char[len];
		strcpy_s(this->color, len, color);
	}

	//������������ӵ��ָ���Ա�� �����Ѹ����������������Ϊ�麯��
	virtual ~Shape() { delete[] color; }

	//���麯��
	virtual int area() = 0;

private:
	char* color;
};


class Square : public Shape{//������
public:
	Square(int row = 0, const char* color = "blue") 
		: Shape(color), row(row){}

	//�̳г��������Ҫ�Գ�����Ĵ��麯��������д��ʵ��
	//�����������д����ô����Ҳ�ǳ�����
	int area() { return row * row; }

private:
	int row;
};

int main() {
	//�������޷����ɶ���
	//���磺
	Shape s;


}