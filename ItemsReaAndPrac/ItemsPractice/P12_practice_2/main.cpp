/*输入任意多个整数, 把这些数据保存到data.txt文件中,
 *如果在输入的过程中输入错误, 则提示用户重新输入,
 *指导用户结束输入(按ctrl+z), 每行最多保存10个整数
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
	ofstream outfile;
	int data = 0;
	int n = 0;

	outfile.open("data.txt");
	if (!outfile.is_open()) {
		cout << "文件打开失败!\n";
		system("pause");
		exit(1);
	}

	cout << "输入多个整数[ctrl+z结束输入]\n";
	while (true) {
		cout << "请输入一个整数:";
		cin >> data;
	
		while (cin.fail() && !cin.eof()) {
			cin.clear(); //清除错误标志
			//cin.sync();//在VS中无效
			//把输入缓冲区的全部内容都清空掉, 直到遇到换行符结束(换行符也清掉)
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "输入错误, 请重新输入:";
			cin >> data;
		}

		if (cin.eof()) break;

		outfile << data << "\t";
		if (++n % 10 == 0) {
			outfile << "\n";
		}
	}

	outfile.close();
	system("pause");
	return 0;
}