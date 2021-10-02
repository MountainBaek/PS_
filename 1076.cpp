#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string temp[10] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };
/*곱은 10^(색의 배열 번호)*/
string in1, in2, in3;
char A[2];
int flag;
long long mult, convert;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> in1 >> in2 >> in3;
	int i = 0;
	while (flag < 3) {
		if (in1 == temp[i]) {
			A[0] = '0' + i;
			flag++;
		}
		if (in2 == temp[i]) {
			A[1] = '0' + i;
			flag++;
		}
		if (in3 == temp[i]) {
			mult = pow(10, i);
			flag++;
		}
		i++;
	}
	convert = atoi(A);
	long long num = convert * mult;
	cout << num;
}