/*5014번 스타트 링크*/
#include <iostream>
#include <queue>
using namespace std;
int F, S, G, U, D;
int Bilding[1000001];
bool visit[1000001];
int dx[2];
queue<int>Q;

void BFS() {
	while (!Q.empty()) {
		int now_floor = Q.front();
		Q.pop();
		for (int d = 0; d < 2; d++) {
			int next_floor = now_floor + dx[d];
			if (!(next_floor <= 0 || next_floor > F)) {
				if (visit[next_floor] == 0) {
					visit[next_floor] = 1;
					Q.push(next_floor);
					Bilding[next_floor] = Bilding[now_floor] + 1;
					if (next_floor == G) return;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> F >> S >> G >> U >> D;
	for (int i = 0; i <= F; i++) {
		Bilding[i] = -1;
	}
	Q.push(S);
	visit[S] = 1;
	Bilding[S] = 0;
	dx[0] = U;
	dx[1] = D * -1;
	BFS();
	if (Bilding[G] == -1) cout << "use the stairs";
	else cout << Bilding[G];
}

/*
조건
1. 최소 이동 횟수를 구함
2. 1차원 이동(상하 이동)
==> BFS를 이용하자

*/