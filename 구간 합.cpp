#include <iostream>
#include <string>
#include <string.h>
#define LL long long
using namespace std;
LL numChk[10];

void cal(LL num, LL pnt) {
	while (num > 0) {
		string s = to_string(num);
		int tmp = s[s.length() - 1] - '0';
		numChk[tmp] += pnt;
		num /= 10;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	int tc = 1;
	while (T--) {
		LL A, B, ans,pnt = 1;
		cin >> A >> B;
		while (A <= B) {
			while (B % 10 != 9 && A <= B) {
				cal(B, pnt);
				B--;
			}
			if (B < A) break;
			while (A % 10 != 0 && A <= B) {
				cal(A, pnt);
				A++;
			}
			A /= 10;
			B /= 10;
			for (int i = 0; i < 10; i++) {
				numChk[i] += (B - A + 1)*pnt;
			}
			pnt *= 10;
		}
		ans = 0;
		for (int i = 0; i < 10; i++) {
			ans += (numChk[i] * i);
		}
		cout << '#' << tc++ << ' ' << ans << '\n';
		memset(numChk, 0, sizeof(numChk));
	}
	return 0;
}