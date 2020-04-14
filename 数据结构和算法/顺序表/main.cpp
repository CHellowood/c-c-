#include <iostream>
#include <Windows.h>

using namespace std;

#define SEQUENCE_SIZE 10

typedef struct {
	int* sequence; //˳�����ʼ��ַ
	int lenght;    //�Ѵ����Ԫ�ظ���
	int size;      //˳����ܴ�С
}Sequence;

//��ʼ��˳���
bool initSequence(Sequence *seq) {
	seq->sequence = new int[SEQUENCE_SIZE];

	if (!seq->sequence) return false;
	
	seq->lenght = 0;
	seq->size = SEQUENCE_SIZE;

	return true;
}

//���Ԫ��
bool addLenght(Sequence *seq, int n) {
	if (seq->lenght == seq->size) return false;

	seq->sequence[seq->lenght] = n;
	seq->lenght++;

	return true;
}

//����Ԫ��
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

//ɾ��Ԫ��
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

//��ӡԪ��
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
		cout << "˳����ʼ���ɹ�!" << endl;
	}
	else {
		cout << "˳����ʼ��ʧ��!" << endl;
		system("pause");
		return 0;
	}

	printLenght(&seq);

	cout << "----------���Ԫ��----------" << endl;
	cout << "������Ҫ��ӵ�Ԫ�ظ���:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		cout << "������Ҫ��ӵĵ�" << j+1 << "��Ԫ��:";
		cin >> n;
		addLenght(&seq, n);
	}

	printLenght(&seq);

	cout << "----------����Ԫ��----------" << endl;
	cout << "������Ҫ�����λ��(�±�)��Ԫ��:";
	cin >> i >> n;

	if (insertLenght(&seq, i, n)) {
		cout << "����ɹ�!" << endl;
	}
	else {
		cout << "����ʧ��!" << endl;
	}

	printLenght(&seq);

	cout << "----------ɾ��Ԫ��----------" << endl;
	cout << "������Ҫɾ����Ԫ�ص�λ��(�±�):";
	cin >> i;

	if (deleteLenght(&seq, i)) {
		cout << "ɾ���ɹ�!" << endl;
	}
	else {
		cout << "ɾ��ʧ��!" << endl;
	}

	printLenght(&seq);

	cout << "----------ɾ��˳���----------" << endl;

	killSequence(&seq);

	system("pause");
	return 0;
}