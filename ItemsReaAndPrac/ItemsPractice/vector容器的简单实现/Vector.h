#pragma once

#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

/*
* �޸�����: 2019.03.15
* �޸�����: ��������������Ԫ�ظ����� 
*           �Լ��޸���Vector����������ص�����
*/

template <typename DataType>
struct List{ //����
	List() {
		this->data = nullptr;
		this->next = nullptr;
	}

	DataType& operator=(const DataType& data) {
		if (!this->data) this->data = new DataType;
			
		*(this->data) = data;
		return *(this->data);
	}

	~List() {
		if (data) delete data;
	}
	
	DataType* data;
	List* next;
};

//�Ƚ�: С��
template <typename DataType>
struct less {
	bool operator()(const DataType& left, const DataType& right) const {
		return (left < right);
	}
};

//�Ƚ�: ����
template <typename DataType>
struct greater {
	bool operator()(const DataType& left, const DataType& right) const {
		return (left > right);
	}
};

template <typename DataType, typename Comp = less<DataType>>
class Vector
{
public:
	Vector();
	~Vector();

	void    push_back(const DataType& data); //��β�����Ԫ��
	//Vector* erase(Vector* node); //ɾ��ָ��Ԫ�أ���������һ��Ԫ�ص�ָ��
	//void    erase(Vector* start, Vector* end);//ɾ��start��end֮�������Ԫ��
	List<DataType>* erase(List<DataType>* node);
	void erase(List<DataType>* start, List<DataType>* end);

	//int     size(); //����Ԫ�ظ���
	int getSize();
	//Vector* begin(); //���ص�һ��Ԫ�ص�ָ��
	//Vector* end();   //�������һ��Ԫ�ص�nextָ��
	List<DataType>* begin();
	List<DataType>* end();

	DataType* operator[](int index);

	template <typename DataType, typename Comp>
	friend std::ostream& operator<<(std::ostream& os,
		const Vector<DataType, Comp>& vec);

	//Ϊ�˷�����ԣ� �ص�д�ĺ���
	//���ص�ǰԪ�ص�data
	//DataType num();

private:
	//Vector(DataType data);
	
	//DataType data;
	//Vector* next;  //��һ��Ԫ��
	List<DataType>* list;
	int size; //�����Ԫ�ظ���
};


#endif 


