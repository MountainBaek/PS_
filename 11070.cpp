#include <iostream>
#define MIN(a,b) a<b?a:b;
#define MAX(a,b) a>b?a:b;
using namespace std;

int T, n, m;
struct info {
	double S;
	double A;
	double W;
}team[1002];

void init() {
	for (int i = 1; i <= n; i++) {
		team[i] = { 0,0,0 };
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			int a, b, p, q;//p == aÆÀ µæÁ¡ == bÆÀ ½ÇÁ¡ // q == bÆÀ µæÁ¡ == aÆÀ ½ÇÁ¡
			cin >> a >> b >> p >> q;
			team[a].S += p;
			team[a].A += q;
			team[b].S += q;
			team[b].A += p;
		}
		double min_ = 987654321, max_ = -987654321;
		for (int idx = 1; idx <= n; idx++) {
			if (team[idx].S == 0 && team[idx].A == 0) {
				team[idx].W = 0;
			}
			else {
				team[idx].W = (team[idx].S * team[idx].S) / ((team[idx].S * team[idx].S) + (team[idx].A * team[idx].A));//W=S^2/(S^2 + A^2)
			}
			min_ = MIN(min_, team[idx].W);
			max_ = MAX(max_, team[idx].W);
		}
		cout << (int)(max_*1000) << '\n' << (int)(min_*1000) << '\n';
		init();
	}
	return 0;
}