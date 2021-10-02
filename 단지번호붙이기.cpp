#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct pnt { int r, c; };
queue<pnt>Q;
int N, idx = 1;
int map[25][25];
int visit[25][25];
int drc[] = { 0,0,-1,1,-1,1,0,0 };
vector<int>tmp;

bool chk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= N || c >= N)) return true;
	else return false;
}

void bfs() {
	int cnt = 1;
	while (!Q.empty()) {
		int r = Q.front().r;
		int c = Q.front().c;
		Q.pop();
		for (int d = 0; d < 4; d++) {
			int nr = r + drc[d];
			int nc = c + drc[d + 4];
			if (chk(nr, nc) && map[nr][nc] == 1 && visit[nr][nc] == 0) {
				visit[nr][nc] = idx;
				Q.push({ nr,nc });
				cnt++;
			}
		}
	}
	tmp.push_back(cnt);
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int r = 0; r < N; r++) {
		string in;
		cin >> in;
		for (int c = 0; c < N; c++) {
			map[r][c] = in[c] - '0';
		}
	}
	
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (map[r][c] == 1 && visit[r][c] == 0) {
				Q.push({ r,c });
				visit[r][c] = idx;
				bfs();
				idx++;
			}
		}
	}
	sort(tmp.begin(), tmp.end());
	cout << tmp.size() << '\n';
	for (int i = 0; i < tmp.size(); i++)
		cout << tmp[i] << '\n';
	return 0;
}