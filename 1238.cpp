#include <iostream>
#include <queue>
#include <vector>
#define min(a,b) a < b ? a : b
#define INF 987654321
struct info {
	int v, d;
	bool operator< (const info& cmp) const {
		return d > cmp.d;
	}
};
using namespace std;
vector<info> map[1001];
int ItoX[1001];
int XtoI[1001];

int N, M, X;
int main() {
	ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
	cin >> N >> M >> X;
	for (int i = 1; i <= N; i++) {
		ItoX[i] = INF;
		XtoI[i] = INF;
	}
	for (int i = 0; i < M; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		map[a].push_back({ b,t });
	}
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		priority_queue<pair<int,info>>PQ;
		ItoX[i] = 0;
		for (auto e : map[i])
			PQ.push({ i,e });

		while (!PQ.empty()) {
			pair<int,info> now = PQ.top();
			PQ.pop();
			ItoX[now.second.v] = min(now.second.d + ItoX[now.first], ItoX[now.second.v]);
			if (now.second.v == X) break;
			for (auto e : map[now.second.v])
				PQ.push({ now.second.v,e });
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << ItoX[i] << ' ';
	}
	return 0;
}