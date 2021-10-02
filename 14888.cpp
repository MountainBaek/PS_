/*14888번 연산자 끼워넣기*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int>opr_temp;
int N;
long long cal_temp, Max_v = -1e9, Min_v = 1e9;
int Num[11], opr[4], visit[10];

void make_arr() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < opr[i]; j++)
			opr_temp.push_back(i);
}
long long cal(long long a, int b, int op) {
	if (op == 0) { return a + b; }
	else if (op == 1) { return a - b; }
	else if (op == 2) { return a * b; }
	else { return a / b; }
}

void go(int n) {
	//int num_cnt = n;
	if (n >= N) {
		if (cal_temp > Max_v) Max_v = cal_temp;
		if (cal_temp < Min_v) Min_v = cal_temp;
	}
	else {
		for (int i = 0; i < N - 1; i++) {
			int back_temp = cal_temp;
			if (visit[i] == 0) {
				cal_temp = cal(cal_temp, Num[n], opr_temp.at(i));
				visit[i] = 1;
				go(n + 1);
				visit[i] = 0;
				cal_temp = back_temp;
			}

		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> Num[i];
	for (int i = 0; i < 4; i++)cin >> opr[i];
	make_arr();
	cal_temp = Num[0];
	go(1);
	cout << Max_v << '\n' << Min_v;
}