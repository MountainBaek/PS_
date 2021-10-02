#include <iostream>
#include <queue>
using namespace std;
int T, N, M, R, C, L;
int Map[50][50];
int visit[50][50];
int cnt;
int drc[] = { 0,0,-1,1,1,-1,0,0 };

void reset_() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			Map[r][c] = 0;
			visit[r][c] = 0;
			cnt = 0;
		}
	}
}

void BFS() {
	queue<pair<int, int> >Q;
	Q.push({ R,C });
	cnt++;
	int visit_cnt = 1;
	visit[R][C] = 1;
	while (!Q.empty()) {
		if (visit_cnt > L) {
			return;
		}
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		if (Map[r][c] == 1) {
			if ((r - 1) >= 0 && visit[r - 1][c] == 0) {
				if (Map[r - 1][c] == 1 || Map[r - 1][c] == 2 || Map[r - 1][c] == 5 || Map[r - 1][c] == 6) {
					Q.push({ r - 1,c });
					cnt++;
					visit[r - 1][c] = visit[r][c] + 1;
				}
			}
			if ((c + 1) < M && visit[r][c + 1] == 0) {
				if (Map[r][c + 1] == 1 || Map[r][c + 1] == 3 || Map[r][c + 1] == 6 || Map[r][c + 1] == 7) {
					Q.push({ r,c + 1 });
					cnt++;
					visit[r][c + 1] = visit[r][c] + 1;
				}
			}
			if ((r + 1) < N && visit[r + 1][c] == 0) {
				if (Map[r + 1][c] == 1 || Map[r + 1][c] == 2 || Map[r + 1][c] == 4 || Map[r + 1][c] == 7) {
					Q.push({ r + 1,c });
					cnt++;
					visit[r + 1][c] = visit[r][c] + 1;
				}
			}
			if ((c - 1) >= 0 && visit[r][c - 1] == 0) {
				if (Map[r][c - 1] == 1 || Map[r][c - 1] == 3 || Map[r][c - 1] == 4 || Map[r][c - 1] == 5) {
					Q.push({ r,c - 1 });
					cnt++;
					visit[r][c - 1] = visit[r][c] + 1;
				}
			}
		}
		else if (Map[r][c] == 2) {
			if ((r - 1) >= 0 && visit[r - 1][c] == 0) {
				if (Map[r - 1][c] == 1 || Map[r - 1][c] == 2 || Map[r - 1][c] == 5 || Map[r - 1][c] == 6) {
					Q.push({ r - 1,c });
					cnt++;
					visit[r - 1][c] = visit[r][c] + 1;
				}
			}
			if ((r + 1) < N && visit[r + 1][c] == 0) {
				if (Map[r + 1][c] == 1 || Map[r + 1][c] == 2 || Map[r + 1][c] == 4 || Map[r + 1][c] == 7) {
					Q.push({ r + 1,c });
					cnt++;
					visit[r + 1][c] = visit[r][c] + 1;
				}
			}
		}
		else if (Map[r][c] == 3) {
			if ((c - 1) >= 0 && visit[r][c - 1] == 0) {
				if (Map[r][c - 1] == 1 || Map[r][c - 1] == 3 || Map[r][c - 1] == 4 || Map[r][c - 1] == 5) {
					Q.push({ r,c - 1 });
					cnt++;
					visit[r][c - 1] = visit[r][c] + 1;
				}
			}
			if ((c + 1) < M && visit[r][c + 1] == 0) {
				if (Map[r][c + 1] == 1 || Map[r][c + 1] == 3 || Map[r][c + 1] == 6 || Map[r][c + 1] == 7) {
					Q.push({ r,c + 1 });
					cnt++;
					visit[r][c + 1] = visit[r][c] + 1;
				}
			}
		}
		else if (Map[r][c] == 4) {
			if ((r - 1) >= 0 && visit[r - 1][c] == 0) {
				if (Map[r - 1][c] == 1 || Map[r - 1][c] == 2 || Map[r - 1][c] == 5 || Map[r - 1][c] == 6) {
					Q.push({ r - 1,c });
					cnt++;
					visit[r - 1][c] = visit[r][c] + 1;
				}
			}
			if ((c + 1) < M && visit[r][c + 1] == 0) {
				if (Map[r][c + 1] == 1 || Map[r][c + 1] == 3 || Map[r][c + 1] == 6 || Map[r][c + 1] == 7) {
					Q.push({ r,c + 1 });
					cnt++;
					visit[r][c + 1] = visit[r][c] + 1;
				}
			}
		}
		else if (Map[r][c] == 5) {
			if ((r + 1) < N && visit[r + 1][c] == 0) {
				if (Map[r + 1][c] == 1 || Map[r + 1][c] == 2 || Map[r + 1][c] == 4 || Map[r + 1][c] == 7) {
					Q.push({ r + 1,c });
					cnt++;
					visit[r + 1][c] = visit[r][c] + 1;
				}
			}
			if ((c + 1) < M && visit[r][c + 1] == 0) {
				if (Map[r][c + 1] == 1 || Map[r][c + 1] == 3 || Map[r][c + 1] == 6 || Map[r][c + 1] == 7) {
					Q.push({ r,c + 1 });
					cnt++;
					visit[r][c + 1] = visit[r][c] + 1;
				}
			}
		}
		else if (Map[r][c] == 6) {
			if ((c - 1) >= 0 && visit[r][c - 1] == 0) {
				if (Map[r][c - 1] == 1 || Map[r][c - 1] == 3 || Map[r][c - 1] == 4 || Map[r][c - 1] == 5) {
					Q.push({ r,c - 1 });
					cnt++;
					visit[r][c - 1] = visit[r][c] + 1;
				}
			}
			if ((r + 1) < N && visit[r + 1][c] == 0) {
				if (Map[r + 1][c] == 1 || Map[r + 1][c] == 2 || Map[r + 1][c] == 4 || Map[r + 1][c] == 7) {
					Q.push({ r + 1,c });
					cnt++;
					visit[r + 1][c] = visit[r][c] + 1;
				}
			}
		}
		else if (Map[r][c] == 7) {
			if ((r - 1) >= 0 && visit[r - 1][c] == 0) {
				if (Map[r - 1][c] == 1 || Map[r - 1][c] == 2 || Map[r - 1][c] == 5 || Map[r - 1][c] == 6) {
					Q.push({ r - 1,c });
					cnt++;
					visit[r - 1][c] = visit[r][c] + 1;
				}
			}
			if ((c - 1) >= 0 && visit[r][c - 1] == 0) {
				if (Map[r][c - 1] == 1 || Map[r][c - 1] == 3 || Map[r][c - 1] == 4 || Map[r][c - 1] == 5) {
					Q.push({ r,c - 1 });
					cnt++;
					visit[r][c - 1] = visit[r][c] + 1;
				}
			}
		}
		visit_cnt = visit[r][c] + 1;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> R >> C >> L;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				cin >> Map[r][c];
			}
		}

		BFS();
		int cc = 0;
		cout << endl;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (0 < visit[r][c] && visit[r][c] <= L) {
					cout << visit[r][c] << ' ';
					cc++;
				}
				else
					cout << "0 ";
			}
			cout << endl;
		}
		cout << '#' << t << ' ' << cc << '\n';
		reset_();
	}
}