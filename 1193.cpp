#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int input = 0;
	cin >> input;
	if (input == 1) { cout << "1/1"; return 0; }
	int cnt = 0;
	int res = 0;
	while (1) {
		cnt++;
		int tmp = res;
		res = (cnt * cnt - cnt + 2) / 2;
		if (res > input) { cnt--; res = tmp; break; }
	}
	int line = cnt + 1;
	int top, bottom, loc = input - res;
	if (cnt % 2 != 0) {
		top = cnt - loc;
		bottom = 1 + loc;
	}
	else {
		top = 1 + loc;
		bottom = cnt - loc;
	}
	cout << top << '/' << bottom;
	return 0;
}
/*
계차수열 공식
1+ {(n-1)*n/2 }
*/