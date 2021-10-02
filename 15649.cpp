#include <iostream>
using namespace std;
int N, M;
int out[9], chk[9];

void perm(int n) {
	int now = n;
	if (now == M) {
		for (int i = 0; i < M; i++) cout << out[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (chk[i] != 0) continue;
		chk[i] = 1;
		out[now] = i;
		perm(now + 1);
		chk[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	perm(0);
}
