#include <iostream>

using namespace std;

void hz_nz(char *c, int len, int hzlen) {
	char *ch = c;
	char s[1024];
	char *ch1 = &s[len];
	*ch1 = 0;

	if(hzlen == 3) {
		for(int i=0; i<len/hzlen; i++) {
			*(ch1-1) = *(ch+2);
			*(ch1-2) = *(ch+1);
			*(ch1-3) = *ch;
			ch1 -= 3;
			ch += 3;
		}
	}
	else if(hzlen == 2) {
		for(int i=0; i<len/hzlen; i++) {
			*(ch1-1) = *(ch+1);
			*(ch1-2) = *ch;
			ch1 -= 2;
			ch += 2;
		}
	}
	else {
		for(int i=0; i<len; i++) {
			*(ch1-1) = *ch;
			ch1--;
			ch++;
		}
	}

	for(int i=0; i<len; i++) {
		*(c+i) = s[i];
	}
}

int main1(void) {
	while(1) {
	char c[64] = {NULL};
	char ch1[15];
	char *ch = ch1;

	cin >> c;
	cout << "×Ö·û´®³¤¶È: " << strlen(c) << "c: Ox" << &c << " ch1: Ox" << &ch1 << endl << endl;

	hz_nz(c, strlen(c), strlen("Ð¡"));
/*
	cout << *ch << *(ch+1) << *(ch+2);
	ch = ch+3;
	cout << *ch << *(ch+1) << *(ch+2);
	ch = ch+3;
	cout << *ch << *(ch+1) << *(ch+2);
	ch = ch+3;
	cout << *ch << *(ch+1) << *(ch+2);
	ch = ch+3;
	cout << *ch << *(ch+1) << *(ch+2) << endl;
*/	
	
/*
	cout << c[0] << c[1] << c[2];
	cout << c[3] << c[4] << c[5];
	cout << c[6] << c[7] << c[8];
	cout << c[9] << c[10] << c[11];
	cout << c[12] << c[13] << c[14] << endl;
*/  
	cout << c << endl << endl;
	}
	system("pause");
	return 0;
}