#include <iostream>
#include <queue>
using namespace std;
struct Point {
	int r, c;
}temp;
int T, N, M;//테스트 케이스, 맵크기, 추가 신호등 주기
int Map[10][10];
int visit[10][10];
int dxy[] = { 0,0,-1,1,-1,1,0,0 };

void bfs(int rr, int cc) {
	queue<Point>Q;
	temp.r = rr;
	temp.c = cc;
	Q.push(temp);
	visit[rr][cc] = 0;
	while (!Q.empty()) {
		int r = Q.front().r;
		int c = Q.front().c;
		Q.pop();
		for (int d = 0; d < 4; d++) {
			int nr = r + dxy[d];
			int nc = c + dxy[d + 4];
			if (!(nr < 0||nr>=N||nc<0||nc>=N)&&visit)
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				visit[i][j] = -1;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> Map[i][j];
			}
		}
		bfs(0, 0);

	}
}