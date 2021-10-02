#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int sr, sc, er, ec;
		cin >> sr >> sc >> er >> ec;
		int distR = abs(sr - er);
		int distC = abs(sc - ec);
		cout << '#' << tc << ' ' << ((distR + distC) % 2 == 0 ? max(distR, distC) * 2 : max(distR, distC) * 2 - 1) << '\n';
	}
	return 0;
}