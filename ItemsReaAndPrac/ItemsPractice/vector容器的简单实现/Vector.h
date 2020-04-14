#pragma once

#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

/*
* 修改日期: 2019.03.15
* 修改内容: 增加了链表，链表元素个数， 
*           以及修改了Vector类与链表相关的内容
*/

template <typename DataType>
struct List{ //链表
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

//比较: 小于
template <typename DataType>
struct less {
	bool operator()(const DataType& left, const DataType& right) const {
		return (left < right);
	}
};

//比较: 大于
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

	void    push_back(const DataType& data); //在尾部添加元素
	//Vector* erase(Vector* node); //删除指定元素，并返回下一个元素的指针
	//void    erase(Vector* start, Vector* end);//删除start与end之间的所有元素
	List<DataType>* erase(List<DataType>* node);
	void erase(List<DataType>* start, List<DataType>* end);

	//int     size(); //计算元素个数
	int getSize();
	//Vector* begin(); //返回第一个元素的指针
	//Vector* end();   //返回最后一个元素的next指针
	List<DataType>* begin();
	List<DataType>* end();

	DataType* operator[](int index);

	template <typename DataType, typename Comp>
	friend std::ostream& operator<<(std::ostream& os,
		const Vector<DataType, Comp>& vec);

	//为了方便测试， 特地写的函数
	//返回当前元素的data
	//DataType num();

private:
	//Vector(DataType data);
	
	//DataType data;
	//Vector* next;  //下一个元素
	List<DataType>* list;
	int size; //链表的元素个数
};


#endif 


