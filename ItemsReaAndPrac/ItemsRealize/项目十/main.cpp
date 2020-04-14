#include <Windows.h>
#include <iostream>
#include <vector>
#include "Object.h"

void match(vector<Object>& objects) {
	vector<Object> boys;
	vector<Object> girls;
	for (int i = 0; i < objects.size(); i++) {
		if (objects[i].getGender() == "��") {
			boys.push_back(objects[i]);
		}
		else if(objects[i].getGender() == "Ů"){
			girls.push_back(objects[i]);
		}
	}

	for (int i = 0; i < boys.size(); i++) {
		for (int j = 0; j < girls.size(); j++) {
			if (boys[i].satisfied(girls[j].getYanzhi(), girls[j].getWage()) &&
				girls[j].satisfied(boys[i].getYanzhi(), boys[i].getWage())) {
				
				cout << endl << boys[i].getName() << "-��-" << girls[j].getName() << " ��Գɹ�!" << endl;
				cout << endl << boys[i].description() << endl << girls[j].description() << endl;
			}
		}
	}
	cout << endl;
}

int main(void) {
	vector<Object> objects;
	//input(object);
	Object::input(objects);
	
	match(objects);

	system("pause");
	return 0;
}