/*问题:
在一次竞赛中, A, B, C, D, E 等五人经过激烈的角逐, 最终取得了各自的名次,
他们的一个好朋友很遗憾没有观看比赛, 在比赛结束后这个朋友询问他们之间的
名次是得知: C不是第一名, D比E低二个名次, 而E不是第二名, A既不是第一名,
也不是最后一名, B比C低一个名次. 编写程序, 计算这五个人各自的名次并输出.
*/

#include <iostream>

using namespace std;

int main(void) {
	for(int A=1; A<=5; A++) {
	  for(int B=1; B<=5; B++) {
		for(int C=1; C<=5; C++) {
		  for(int D=1; D<=5; D++) {
			for(int E=1; E<=5; E++) {
			  if(C != 1 && D-E == 2 && E != 2 && A != 1 && A != 5 && B-C == 1 
				 && A != B && A != C && A!= D && A != E && B != C && B != D 
				 && B != E&& C != D && C != E && D != E)
				cout << "A : " << A << "\tB : " << B << "\tC : " << C << "\tD : " << D << "\tE : " << E << endl;
			}
  		  }
		}
	  }
	}

	system("pause");
	return 0;
}