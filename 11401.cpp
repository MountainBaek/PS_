#include <iostream>
#include <algorithm>
#include <math.h>
#define MOD 1'000'000'007
using namespace std;
long long factor[4000001];

long long powerMOD(int N, int x) {
	if (x == 1) {
		return N % MOD;
	}
	else {
		if (x % 2 == 1) {
			long long tmp = powerMOD(N, (x - 1) / 2);
			return tmp * tmp % MOD * N % MOD;
		}
		else {
			long long tmp = powerMOD(N, x / 2);
			return tmp * tmp % MOD;
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, K;
	cin >> N >> K;
	if (K == 0 || K == N) {
		cout << 1;
		return 0;
	}
	factor[1] = 1;
	for (int i = 2; i <= N; i++) {
		factor[i] = (factor[i - 1] * i) % MOD;
	}

	long long A = factor[N] % MOD;
	long long B = powerMOD(factor[K], MOD - 2) * powerMOD(factor[N - K], MOD - 2) % MOD;
	long long res = A * B % MOD;
	cout << res;
	return 0;
}