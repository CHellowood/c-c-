#include <iostream>
#include <Windows.h>

using namespace std;

#define SEQUENCE_SIZE 10

typedef struct {
	int* sequence; //顺序表起始地址
	int lenght;    //已储存的元素个数
	int size;      //顺序表总大小
}Sequence;

//初始化顺序表
bool initSequence(Sequence *seq) {
	seq->sequence = new int[SEQUENCE_SIZE];

	if (!seq->sequence) return false;
	
	seq->lenght = 0;
	seq->size = SEQUENCE_SIZE;

	return true;
}

//添加元素
bool addLenght(Sequence *seq, int n) {
	if (seq->lenght == seq->size) return false;

	seq->sequence[seq->lenght] = n;
	seq->lenght++;

	return true;
}

//插入元素
bool insertLenght(Sequence *seq, int i, int n) {
	if (seq->lenght == seq->size)return false;
	if (i < 0 || i > seq->lenght)  return false;
	
	for (int j = seq->lenght; j > i; j--) {
		seq->sequence[j] = seq->sequence[j - 1];
	}
	seq->sequence[i] = n;
	seq->lenght++;

	return true;
}

//删除元素
bool deleteLenght(Sequence *seq, int i) {
	if (i < 0 || i >= seq->lenght) return false;

	if (i == seq->lenght-1) {
		seq->lenght--;
		return true;
	}

	for (int j = i; j < seq->lenght; j++) {
		seq->sequence[j] = seq->sequence[j + 1];
	}
	seq->lenght--;

	return true;
}

void killSequence(Sequence *seq) {
	if (seq->sequence) delete[] seq->sequence;
	seq->lenght = 0;
	seq->size = 0;
}

//打印元素
void printLenght(Sequence *seq) {
	for (int i = 0; i < seq->lenght; i++) {
		cout << seq->sequence[i] << "  ";
	}
	cout << endl;
}

int main(void) {
	Sequence seq;
	int i=0, n=0;
	
	if (initSequence(&seq)) {
		cout << "顺序表初始化成功!" << endl;
	}
	else {
		cout << "顺序表初始化失败!" << endl;
		system("pause");
		return 0;
	}

	printLenght(&seq);

	cout << "----------添加元素----------" << endl;
	cout << "请输入要添加的元素个数:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		cout << "请输入要添加的第" << j+1 << "个元素:";
		cin >> n;
		addLenght(&seq, n);
	}

	printLenght(&seq);

	cout << "----------插入元素----------" << endl;
	cout << "请输入要插入的位置(下标)和元素:";
	cin >> i >> n;

	if (insertLenght(&seq, i, n)) {
		cout << "插入成功!" << endl;
	}
	else {
		cout << "插入失败!" << endl;
	}

	printLenght(&seq);

	cout << "----------删除元素----------" << endl;
	cout << "请输入要删除的元素的位置(下标):";
	cin >> i;

	if (deleteLenght(&seq, i)) {
		cout << "删除成功!" << endl;
	}
	else {
		cout << "删除失败!" << endl;
	}

	printLenght(&seq);

	cout << "----------删除顺序表----------" << endl;

	killSequence(&seq);

	system("pause");
	return 0;
}