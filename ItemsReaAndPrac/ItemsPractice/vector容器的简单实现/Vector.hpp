#include "Vector.h"

template<typename DataType, typename Comp>
Vector<DataType, Comp>::Vector()
{
	//this->data = 0;
	//this->next = nullptr;
	/*DataType data;
	this->list.data = data;
	this->list.next = nullptr;*/
	this->list = new List<DataType>;
	this->size = 0;
}

//template<typename DataType>
//Vector<DataType>::Vector(DataType data)
//{
//	//this->data = data;
//	//this->next = nullptr;
//	this->list.data = data;
//	this->list.next = nullptr;
//}

template<typename DataType, typename Comp>
Vector<DataType, Comp>::~Vector()
{
	while (this->list) {
		List<DataType>* p = this->list;
		this->list = p->next;
		delete p;
	}
	this->list = nullptr;
	this->size = 0;
}

//��β�����Ԫ��
template<typename DataType, typename Comp>
void Vector<DataType, Comp>::push_back(const DataType& data)
{
	/*Vector* p = this;
	while (p->next) p = p->next;

	p->next = new Vector(data);*/
	/*if (!this->list) 
	{
		this->list = new List<DataType>;
		this->list->data = data;
		this->list->next = nullptr;
		this->size++;
		return;
	}*/

	List<DataType>* p = this->list;
	Comp comp;

	while (p->next && !comp(data, *(p->next->data))) {
		
		p = p->next; 
	}

	List<DataType>* temp = new List<DataType>;

	*temp = data;
	temp->next = p->next;
	p->next = temp;
	this->size++; //����Ԫ�ؼ�һ
}

//ɾ��ָ��Ԫ�أ���������һ��Ԫ�ص�ָ��
template<typename DataType, typename Comp>
List<DataType>* Vector<DataType, Comp>::erase(List<DataType>* node)
//Vector<DataType>* Vector<DataType>::erase(Vector* node)
{
	if (!node || this->size < 1) return nullptr;

	/*Vector* p = this;
	while (p)
	{
		if (p->next == node) {
			Vector* temp = p->next;
			p->next = temp->next;
			delete temp;
			return p->next;
		}
		p = p->next;
	}
	return nullptr;*/
	/*if (node == this->list) {
		if (this->list->next) 
		{
			this->list = this->list->next;
		}
		else {
			this->list = nullptr;
		}
		this->size--;
		delete node;
		return this->list;
	}*/

	List<DataType>* p = this->list;
	while (p->next && p->next != node) p = p->next;//Ѱ��Ҫɾ����Ԫ��
	
	if (!p->next) return nullptr;   //û���ҵ�Ҫɾ����Ԫ��
	
	List<DataType>* temp = p->next; //�ҵ�Ҫɾ����Ԫ��
	p->next = temp->next;
	delete temp;
	this->size--; //����Ԫ�ؼ�һ

	return p->next;
}

//ɾ��start��end֮�������Ԫ��
template<typename DataType, typename Comp>
void Vector<DataType, Comp>::erase(List<DataType>* start, List<DataType>* end)
//void Vector<DataType>::erase(Vector* start, Vector* end)
{
	if (!start || this->size < 1) return;

	/*if (start == this->list) 
	{
		while (this->list != end) 
		{
			this->erase(this->list);
		}
		return;
	}*/

	//Vector* p = this;
	List<DataType>* p = this->list;
	
	//Ѱ��Ҫɾ���ĵ�һ��Ԫ��
	while (p->next && p->next != start) p = p->next;

	while (p->next && p->next != end) 
	{
		//Vector* temp = p->next;
		List<DataType>* temp = p->next;
		p->next = temp->next;
		delete temp;
		this->size--;
	}
}

//����Ԫ�ظ���
//template<typename DataType>
//int Vector<DataType>::size()
//{
//	Vector* p = this;
//	int ret = 0;
//	while (p->next)
//	{
//		p = p->next;
//		ret++;
//	}
//
//	return ret;
//}

template<typename DataType, typename Comp>
int Vector<DataType, Comp>::getSize()
{
	return this->size;
}

////���ص�һ��Ԫ�ص�ָ��
//template<typename DataType>
//Vector<DataType>* Vector<DataType>::begin() 
//{
//	return this->next;
//}
//
////�������һ��Ԫ�ص�nextָ��
//template<typename DataType>
//Vector<DataType>* Vector<DataType>::end() 
//{
//	return nullptr;//Ϊ�˼������ ��ֱ�ӷ��ؿ���
//}

//���ص�һ��Ԫ�ص�ָ��
template<typename DataType, typename Comp>
List<DataType>* Vector<DataType, Comp>::begin()
{
	return this->list->next;
}

//�������һ��Ԫ�ص�nextָ��
template<typename DataType, typename Comp>
List<DataType>* Vector<DataType, Comp>::end()
{
	return nullptr;//Ϊ�˼������ ��ֱ�ӷ��ؿ���
}

template<typename DataType, typename Comp>
DataType* Vector<DataType, Comp>::operator[](int index) 
{
	if (index < 0) return 0;

	//Vector* p = this->next;
	List<DataType>* p = this->list->next;
	for (int i = 0; i < index && p; i++) {
		p = p->next;
	}

	if (p) return *(p->data);
	return 0;
}

//template<typename DataType>
//DataType Vector<DataType>::num() 
//{
//	return data;
//}

template <typename DataType, typename Comp>
std::ostream& operator<<(std::ostream& os, const Vector<DataType, Comp>& vec)
{
	List<DataType>* p = vec.list->next;
	while (p) {
		os << *(p->data) << "\n";
		p = p->next;
	}
	os << "\nԪ�ظ���: " << vec.size << "\n";
	return os;
}