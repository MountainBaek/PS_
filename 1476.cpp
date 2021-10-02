#include <iostream>
using namespace std;
int E=1, S=1, M=1 ,output = 1;
int e, s, m;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> e >> s >> m;
	while (1) {
		if (E == e && S == s && M == m) {
			cout << output;
			break;
		}
		else{
			output++;
			E++;
			if (E == 16) E = 1;
			S++;
			if (S == 29) S = 1;
			M++;
			if (M == 20) M = 1;
		}
	}
}