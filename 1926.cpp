#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int num = i;
		bool flag = true;
		int clap_cnt = 0;
		while (num != 0) {
			if (num % 10 == 3 || num % 10 == 6|| num % 10 == 9) {
				clap_cnt++;
				flag = false;
			}
			num /= 10;
		}
		if (flag == true) cout << i << ' ';
		else {
			while (clap_cnt--) {
				cout << '-';
			}
			cout << ' ';
		}
	}
	return 0;
}