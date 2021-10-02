#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string str1, str2;
int num1, num2;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> str1 >> str2;
	reverse(str1.begin(), str1.end());
	num1 = stoi(str1);
	reverse(str2.begin(), str2.end());
	num2 = stoi(str2);
	if (num1 > num2) cout << num1;
	else cout << num2;
}
/////////////문자형 배열로 풀이///////////
//#include <iostream>
//#include <string.h>
//using namespace std;
//char str1[4], str2[4], temp[4];
//int num1, num2;ㅇ
//
//int main() {
//	ios::sync_with_stdio(0), cin.tie(0);
//	cin >> str1 >> str2;
//	for (int i = 0; i < 3; i++) {
//		temp[2 - i] = str1[i];
//	}
//	num1 = atoi(temp);
//	for (int i = 0; i < 3; i++) {
//		temp[2 - i] = str2[i];
//	}
//	num2 = atoi(temp);
//	if (num1 > num2) cout << num1;
//	else cout << num2;
//}

