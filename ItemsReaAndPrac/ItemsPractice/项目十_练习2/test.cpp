#include <iostream>
#include "Person.h"

int main(void) {
	Person lhc("�����", 28, Man);
	Person ryy("��ӯӯ", 27, Woman);
	Person tbg("�ﲮ��", 26, Man);
	Person yls("����ɺ", 20, Woman);
	Person cx("�������", 55, Man);

	lhc.getMarried(ryy);
	cout << lhc.getName() << "�Ķ�����:" << lhc.getObject()->getName() << endl;
	cout << ryy.getName() << "�Ķ�����:" << ryy.getObject()->getName() << endl;

	lhc.divorce();
	
	if (lhc.getObject() == NULL) {
		cout << lhc.getName() << "�ǵ���!" << endl;
	}
	else {
		cout << "���ʧ��!" << endl;
	}

	lhc.addFriend(tbg);
	lhc.addFriend(cx);
	
	for (int i = 0; i < lhc.getFriends().size(); i++) {
		cout << lhc.getFriends().at(i)->description() << endl;
	}

	lhc.breakFriend(tbg);

	for (int i = 0; i < lhc.getFriends().size(); i++) {
		cout << lhc.getFriends().at(i)->description() << endl;
	}

	system("pause");
	return 0;
}