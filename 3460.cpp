#include <iostream>
using namespace std;
int bit[21];
int q, r;
void bitcal(int n, int x) {
	q = n;
	while (q != 0) {
		q = n / 2;
		r = n % 2;
		bit[x] = r;
		x++;
		if (q != 0) bitcal(q, x);
		else break;
	}
}
int main() {
	int T, input;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> input;
		bitcal(input, 0);
		for (int i = 0; i < 21; i++) {
			if (bit[i] == 1) cout << i << ' ';
		}
		for (int i = 0; i < 21; i++) bit[i] = 0;
	}
}