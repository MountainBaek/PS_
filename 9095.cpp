///*9095번 1,2,3 더하기*/
//#include <iostream>
//using namespace std;
//int T, input, result;
//
//void go(int sum) {
//	if (sum > input) return;
//	else if (sum == input) result++;
//	else {
//		for (int i = 1; i <= 3; i++) {
//			int temp = sum;
//			temp += i;
//			go(temp);
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	cin >> T;
//	while (T--) {
//		cin >> input;
//		go(0);
//		cout << result << '\n';
//		result = 0;
//	}
//}
/*9095번 1,2,3 더하기 (DP)*/
#include <iostream>
using namespace std;
int T, input;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		int Memo[12] = {};
		Memo[0] = 1;
		cin >> input;
		for (int i = 1; i <= input; i++) {
			if (i - 1 >= 0)	Memo[i] += Memo[i - 1];
			if (i - 2 >= 0)	Memo[i] += Memo[i - 2];
			if (i - 3 >= 0)	Memo[i] += Memo[i - 3];
		}
		cout << Memo[input] << '\n';
	}
}