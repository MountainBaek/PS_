/*14501Ήψ Επ»η*/
#include <iostream>
using namespace std;
int N;
int memo[16];
struct input_Arr {
	int T, P;
}input[16];
int Max_pay,sum_pay;

void bf(int n) {
	for (int i = n; i <= N; i++) {
		int c_end = input[i].T - 1 + i;
		if (c_end <= N) {
			sum_pay += input[i].P;
			bf(c_end + 1);
			sum_pay -= input[i].P;
		}
		
	}
	 Max_pay = Max_pay < sum_pay ? sum_pay : Max_pay;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) { cin >> input[i].T >> input[i].P; }
	bf(1);
	cout << Max_pay;
}
/*
4
3 100
2 10
1 15
1 17
*/