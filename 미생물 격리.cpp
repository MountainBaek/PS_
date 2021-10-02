#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct info {
	int r, c, d;
};
struct info2 {
	int val, dir;
	bool operator<(const info2 &c)const {
		return val > c.val;
	}
};
int visit[101][101];
int drc[] = { 0,-1,1,0,0,0,0,-1,1 };
int N, M, K, ans;//맵크기, 격리시간, 군집 개수
vector<info2>list[100000];

bool chk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= N || c >= N)) return true;
	else return false;
}

void solve(queue<info>Q) {
	while (M--) {
		int qz = Q.size();
		set<pair<int, int>>tmp;
		while (qz--) {
			info now = Q.front();
			Q.pop();

			int nr = now.r + drc[now.d];
			int nc = now.c + drc[now.d + 4];
			if (!chk(nr, nc))continue;

			//약품구역
			if (nr == 0 || nc == 0||nr==N-1||nc==N-1) {
				visit[nr][nc] = visit[now.r][now.c] / 2;
				visit[now.r][now.c] = 0;
				int d = now.d;
				if (d == 1)
					Q.push({ nr,nc,2 });
				else if (d == 2)
					Q.push({ nr,nc,1 });
				else if (d == 3)
					Q.push({ nr,nc,4 });
				else if (d == 4)
					Q.push({ nr,nc,3 });
			}
			else {
				tmp.insert({ nr,nc });
				list[nr * 100 + nc].push_back({ visit[now.r][now.c],now.d });
				visit[now.r][now.c] = 0;
			}

		}
		for (auto n : tmp) {
			int size = list[n.first * 100 + n.second].size();
			sort(list[n.first * 100 + n.second].begin(), list[n.first * 100 + n.second].end());
			int dir = list[n.first * 100 + n.second][0].dir;
			if (size > 1) {
				for (int i = 0; i < size; i++) {
					visit[n.first][n.second] += list[n.first * 100 + n.second][i].val;
				}
				Q.push({ n.first,n.second,dir });
			}
			else {
				visit[n.first][n.second] = list[n.first * 100 + n.second][0].val;
				Q.push({ n.first,n.second,dir });
			}
			list[n.first * 100 + n.second].clear();
		}
		tmp.clear();
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			ans += visit[r][c];
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	int tc = 1;
	while (T--) {
		ans = 0;
		cin >> N >> M >> K;
		queue<info>Q;
		for (int i = 0; i < K; i++) {
			int r, c, m, d;
			cin >> r >> c >> m >> d;
			visit[r][c] = m;
			Q.push({ r,c,d });
		}
		solve(Q);
		cout << '#' << tc++ << ' ' << ans << '\n';
		memset(visit, 0, sizeof(visit));
	}
	return 0;
}

/*
바이러스 이동 
1) 비었다? : 그냥 이동, 방향유지
2) 안비었다? : 합치고 방향은 수가 많은쪽
3) 가장자리? : 반절, 방향 반대
*약품자리에서 겹칠일 없다(아마)

*/