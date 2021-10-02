#include <iostream>
#include <deque>
#include <vector>
#define MIN(a,b) a<b?a:b;
#define MAX(a,b) a>b?a:b;
using namespace std;
int Map[50][50];
int visit[50][50];
int chk[2500];
int N, M, ans = 987654321;
struct pnt { int r, c; };
vector<pnt>vir;
pnt drc[4] = { {-1,0},{0,1},{1,0},{0,-1} };
int space_cnt;

int bfs(deque<pnt>Q) {
	int max_t = 0;
	int cnt_ = space_cnt;
	while (!Q.empty()) {
		int r = Q.front().r;
		int c = Q.front().c;
		Q.pop_front();
		for (int d = 0; d < 4; d++) {
			int nr = r + drc[d].r;
			int nc = c + drc[d].c;
			if (!(nr < 0 || nr >= N || nc < 0 || nc >= N)) {
				if (Map[nr][nc] != 1 && visit[nr][nc] == 0) {
					if (Map[nr][nc] == 0) {
						visit[nr][nc] = visit[r][c] + 1;
					}
					else {

					}
					Q.push_back({ nr,nc });
					max_t = MAX(max_t, visit[nr][nc]);
					cnt_--;
				}
			}
		}
	}
	if (cnt_ <= 0)//모든 곳에 다 퍼짐
		return max_t;
	else//다 못퍼짐
		return 987654321;
}

void dfs(int now,int start,deque<pnt>Q) {
	if (now == M) {
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				visit[r][c] = 0;
			}
		}
		int ret = bfs(Q);
		if (ret > 0) {
			ans = MIN(ans, ret);
		}
		
	}
	else {
		for (int s = start; s < vir.size(); s++) {
			if (chk[s] == 0) {
				chk[s] = 1;
				Q.push_back(vir[s]);
				dfs(now + 1, s + 1, Q);
				Q.pop_back();
				chk[s] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> Map[r][c];
			if (Map[r][c] == 2) {
				vir.push_back({ r,c });
			}
			if (Map[r][c] == 0)
				space_cnt++;
		}
	}
	if (space_cnt == 0) {
		cout << 0;
	}
	else {
		deque<pnt>Q;
		dfs(0, 0, Q);
		if (ans == 987654321) {
			cout << -1;
		}
		else {
			cout << ans;
		}
	}
	return 0;
}