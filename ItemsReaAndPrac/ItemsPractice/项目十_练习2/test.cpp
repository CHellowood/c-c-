#include <iostream>
#include "Person.h"

int main(void) {
	Person lhc("令狐冲", 28, Man);
	Person ryy("任盈盈", 27, Woman);
	Person tbg("田伯光", 26, Man);
	Person yls("岳灵珊", 20, Woman);
	Person cx("冲虚道长", 55, Man);

	lhc.getMarried(ryy);
	cout << lhc.getName() << "的对象是:" << lhc.getObject()->getName() << endl;
	cout << ryy.getName() << "的对象是:" << ryy.getObject()->getName() << endl;

	lhc.divorce();
	
	if (lhc.getObject() == NULL) {
		cout << lhc.getName() << "是单身!" << endl;
	}
	else {
		cout << "离婚失败!" << endl;
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