#include <iostream>
using namespace std;
bool T[500501];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 1; i <= 1000; i++)
		T[i*(i + 1) / 2] = true;
	int tc;
	cin >> tc;
	while (1) {
	RE:
		tc--;
		if (tc < 0) break;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n - i; j++) {
				if (T[i] && T[j] && T[n - i - j]) {
					cout << "1\n";
					goto RE;
				}
			}
		}
		cout << "0\n";
	}
	return 0;
}