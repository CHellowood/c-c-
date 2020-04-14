#include <Windows.h>
#include <iostream>
#include <vector>
#include "Object.h"
#include "Database.h"



int main(void) {
/*	
	vector<Boy> boys;
	vector<Girl> girls;
	//input(object);
	Object::input(boys, girls);
	
	Database data(boys, girls);

	data.save();
*/

	Database data1;
	Boy boy;
	Girl girl;

	data1.init();
	data1.print();
	data1.autoMatch();
	data1.autoMatchBest();
	//Boy::inputBoy(boy);
	//data1.addOne(boy);

	//Girl::inputGirl(girl);
	//data1.addOne(girl);

	system("pause");
	return 0;
}