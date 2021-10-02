#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXV 987654321
using namespace std;
struct info {
	int r, c, num;
};
int N;
int map[100][100],numbering[100][100], visit[100][100][2];
int drc[] = { 0,0,-1,1,-1,1,0,0 };
queue<info>Q;

bool chk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= N || c >= N))return true;
	return false;
}

void labeling(vector<info>tmp) {
	int number = 1;
	for (register int i = 0, size = tmp.size(); i < size; i++) {
		info t = tmp[i];
		if (numbering[t.r][t.c] != 0) continue;
		queue<info>q;
		q.push({ t.r,t.c,number });
		Q.push({ t.r,t.c,number });
		numbering[t.r][t.c] = number;
		while (!q.empty()) {
			info now = q.front();
			q.pop();
			for (int d = 0; d < 4; d++) {
				int nr = now.r + drc[d];
				int nc = now.c + drc[d + 4];
				if (chk(nr, nc) && map[nr][nc] == 1 && numbering[nr][nc] == 0) {
					numbering[nr][nc] = number;
					q.push({ nr,nc,number });
					Q.push({ nr,nc,number });
				}
			}
		}
		number++;
	}
}

int bfs() {
	while (!Q.empty()) {
		bool isConn = 0;
		int min_ = MAXV;
		int size = Q.size();
		for (register int i = 0; i < size; i++) {
			info now = Q.front();
			Q.pop();
			for (int d = 0; d < 4; d++) {
				int nr = now.r + drc[d];
				int nc = now.c + drc[d + 4];
				if (!chk(nr, nc)) continue;
				if (map[nr][nc] == 1 && map[now.r][now.c] == 1) continue;

				if (visit[nr][nc][0] == 0) {
					visit[nr][nc][0] = visit[now.r][now.c][0] + 1;
					visit[nr][nc][1] = now.num;
					Q.push({ nr,nc,now.num });
				}
				else {
					if (visit[nr][nc][1] != now.num) {
						isConn = 1;
						min_ = min(visit[nr][nc][0] + visit[now.r][now.c][0], min_);
					}
				}
			}
		}
		if (isConn) return min_;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	vector<info>tmp;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];
			if (map[r][c]) tmp.push_back({ r,c,-1 });
		}
	}

	labeling(tmp);
	cout << bfs();
	
	return 0;
}