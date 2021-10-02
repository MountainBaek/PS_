#include <iostream>
using namespace std;
//일반
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}
//확장
long long gcd_exps(long long x, long long y) {
	long long r, q, tmpA = x, t, t1 = 0, t2 = 1;
	while (y != 0) {
		q = x / y;
		r = x % y;
		t = t1 - q * t2;
		x = y;
		y = r;
		t1 = t2;
		t2 = t;
	}
	while (t1 < 0) t1 += tmpA;
	return t1;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, c = 1;
		cin >> a >> b;
		if (b == 1) {
			if (a + 1 > 1e9) {
				cout << "IMPOSSIBLE" << '\n';
				continue;
			}
			else {
				cout << a + 1 << '\n';
				continue;
			}
		}
		if (a == 1) {
			cout << 1 << '\n';
			continue;
		}
		int gcd_ans = a > b ? gcd(a, b) : gcd(b, a);
		if (gcd_ans != 1) {
			cout << "IMPOSSIBLE" << '\n';
		}
		else {
			long long ans = gcd_exps(a, b);
			if (ans > 1e9) cout << "IMPOSSIBLE" << '\n';
			else cout << ans << '\n';
		}
	}
}