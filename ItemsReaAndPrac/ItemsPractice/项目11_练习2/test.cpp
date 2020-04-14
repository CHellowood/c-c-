#include <iostream>
#include <Windows.h>
#include "ODU.h"
#include "ODU330.h"

using namespace std;

int main(void) {
	ODU odu(45, 1200399, 600);
	//cout << odu.Overview() << "\n";

	cout << "ODU设备:\n";
	cout << "PWR: " << odu.getPWR() << "\nMHZ " << odu.getMHZ()
		 << "\nBW  " << odu.getBW() << "\n\n";

	odu.setPWR(49);
	odu.setMHZ(1094849);
	odu.setBW(500);

	cout << odu.Overview() << "\n\n";

	ODU330 odu330(47, 1998483, 400, 0.00001);

	cout << "ODU330设备:\n";
	cout << "PWR:\t" << odu330.getPWR() << "\nMHZ:\t" << odu330.getMHZ()
		 << "\nBW:\t" << odu330.getBW() << "\nBER:\t" << odu330.getBER()
		 << "\nBERWL:\t" << odu330.getBERWL() << "\n\n";

	odu330.setPWR(49);
	odu330.setMHZ(18938784);
	odu330.setBW(800);
	odu330.setBERWL(0.00002);

	cout << odu330.Overview() << "\n\n";

	system("pause");
	return 0;
}
