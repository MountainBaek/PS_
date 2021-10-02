#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct PNT { int r, c; };
struct INFO { PNT pnt; int dir; };
int map[14][14];
queue<int> Q[14][14];
INFO unit[11];
int N, K;

bool range_chk(int r, int c) { return (1 <= r && r <= N && 1 <= c && c <= N) ? true : false; };

bool red(int num, int nr, int nc) {
	PNT now = unit[num].pnt;
	//우선 반대로 뒤집고
	stack<int>move;
	queue<int>wait;
	while (!Q[now.r][now.c].empty()) {
		if (Q[now.r][now.c].front() == num) {
			while (!Q[now.r][now.c].empty()) {
				move.push(Q[now.r][now.c].front());
				Q[now.r][now.c].pop();
			}
		}
		else {
			wait.push(Q[now.r][now.c].front());
			Q[now.r][now.c].pop();
		}
	}
	//이동해서 쌓는다.
	while (!move.empty()) {
		unit[move.top()].pnt = { nr,nc };
		Q[nr][nc].push(move.top());
		move.pop();
		if (Q[nr][nc].size() >= 4) return true;
	}

	while(!wait.empty()) {
		Q[now.r][now.c].push(wait.front());
		wait.pop();
	}

	return false;
}

bool white(int num,int nr,int nc){
	queue<int> wait, move;
	PNT now = unit[num].pnt;
	while (!Q[now.r][now.c].empty()) {
		if (Q[now.r][now.c].front() == num) {
			while (!Q[now.r][now.c].empty()) {
				move.push(Q[now.r][now.c].front());
				Q[now.r][now.c].pop();
			}
		}
		else {
			wait.push(Q[now.r][now.c].front());
			Q[now.r][now.c].pop();
		}
	}

	while (!wait.empty()) {
		Q[now.r][now.c].push(wait.front());
		wait.pop();
	}

	while (!move.empty()) {
		unit[move.front()].pnt = { nr,nc };
		Q[nr][nc].push(move.front());
		move.pop();
		if (Q[nr][nc].size() >= 4) return true;
	}
	return false;
}

bool blue(int num) {
	//맨 아래 것만 방향전환?
	PNT now = unit[num].pnt;
	int dir = unit[num].dir;
	switch (dir) {
	case 1:	dir = 2; break;
	case 2:	dir = 1; break;
	case 3:	dir = 4; break;
	case 4:	dir = 3; break;
	}
	unit[num].dir = dir;
	int nr = now.r + ("91102"[dir] - '1');
	int nc = now.c + ("92011"[dir] - '1');
	if (range_chk(nr, nc)) { // 한칸 전진 했을때
		if (map[nr][nc] == 0) { if (white(num, nr, nc))return true; }
		else if (map[nr][nc] == 1) { if(red(num, nr, nc))return true; }
	}
	return false;
}

int play() {
	int turn = 1;
	while (turn <= 1005) {
		for (int i = 1; i <= K; i++) {
			PNT now = unit[i].pnt;
			int now_dir = unit[i].dir;
			int nr = now.r + ("91102"[now_dir] - '1');
			int nc = now.c + ("92011"[now_dir] - '1');
			if (range_chk(nr, nc)) {
				if (map[nr][nc] == 1) { if (red(i, nr, nc)) return turn > 1000 ? -1 : turn; }		//다음칸 빨강
				else if (map[nr][nc] == 2) { if (blue(i)) return turn > 1000 ? -1 : turn; }			//파랑
				else if (map[nr][nc] == 0) { if (white(i, nr, nc)) return turn > 1000 ? -1 : turn;} //흰칸
			}
			else blue(i);
		}
		turn++;
	}
	return turn > 1000 ? -1 : turn;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K;
	for (int r = 1; r <= N; r++) for (int c = 1; c <= N; c++) cin >> map[r][c];
	for (int i = 1; i <= K; i++) {
		int r, c, d;
		cin >> r >> c >> d;
		Q[r][c].push(i);
		unit[i] = { {r,c},d };
	}
	cout << play();
	return 0;
}