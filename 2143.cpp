#include <iostream>
#include <algorithm>
#include <map>
#define ll long long 
using namespace std;
int A[1001];
int B[1001];
map<ll, ll>Asum;
map<ll, ll>Bsum;
int T, N, M;

void makeSum(map<ll, ll>& tmp, int* arr, int n) {
	for (register int i = 1; i <= n; i++) {
		int sum = arr[i];
		auto it = tmp.find(sum);
		if (it == tmp.end()) tmp.insert({ sum,1 });
		else it->second++;
		for (register int j = i + 1; j <= n; j++) {
			sum += arr[j];
			auto it = tmp.find(sum);
			if (it == tmp.end()) tmp.insert({ sum,1 });
			else it->second++;
		}
	}
}

inline void init() {
	cin >> T;
	cin >> N;
	for (register int i = 1; i <= N; i++)
		cin >> A[i];

	cin >> M;
	for (register int i = 1; i <= M; i++)
		cin >> B[i];

	makeSum(Asum, A, N);
	makeSum(Bsum, B, M);

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	init();
	ll ans = 0;
	for (auto m : Asum) {
		auto it = Bsum.find(T - m.first);
		if (it == Bsum.end()) continue;
		ans += (m.second * it->second);
	}
	cout << ans;
	return 0;
}
