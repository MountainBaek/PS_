#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
using namespace std;
struct pnt { int r, c; };
struct info { pnt p; bool d; };
int visit[2][205][205];
int moveVert[] = { -1,1,0,0 };
int moveHorz[] = { 0,0,-1,1 };
pnt start, fin;
int Rsize;
int Csize;
bool chk(int r, int c) {
	if (!(r < 0 || c < 0 || r>Rsize || c>Csize)) return true;
	else return false;
}

void Vprint() {
	cout << "vert\n";
	for (int r = 0; r <= Rsize; r++) {
		for (int c = 0; c <= Csize; c++) {
			cout << visit[0][r][c] << ' ';
		}
		cout << '\n';
	}
	cout << "horz\n";
	for (int r = 0; r <= Rsize; r++) {
		for (int c = 0; c <= Csize; c++) {
			cout << visit[1][r][c] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int sr, sc, er, ec;
		cin >> sr >> sc >> er >> ec;
		Rsize = abs(sr - er) + 1;
		Csize = abs(sc - ec) + 1;
		start = { sr - sr,sc - sc };
		fin = { er - sr,ec - sc };
		queue<info>Q;
		Q.push({ start,0 });
		visit[0][start.r][start.c] = 1;
		Q.push({ start,1 });
		visit[1][start.r][start.c] = 1;
		bool horzFin = false;
		bool vertFin = false;
		while (!Q.empty()) {
			//Vprint();
 			int r = Q.front().p.r;
			int c = Q.front().p.c;
			bool dir = Q.front().d;
			Q.pop();
			if (r == fin.r &&c == fin.c) {
				if (dir) vertFin = true;
				else horzFin = true;
				if (vertFin && horzFin) break;
				continue;
			}
			for (int d = 0; d < 2; d++) {
				int nr, nc;
				if (dir) {//1
					nr = r + moveVert[d];
					nc = c + moveVert[d + 2];
				}
				else {
					nr = r + moveHorz[d];
					nc = c + moveHorz[d + 2];
				}

				if (!chk(nr, nc))continue;
				if (visit[(dir + 1) % 2][nr][nc] != 0) continue;
				visit[(dir + 1) % 2][nr][nc] = visit[dir][r][c] + 1;
				Q.push({ {nr,nc},(bool)((dir + 1) % 2) });
			}
		}
		int ans = visit[0][fin.r][fin.c] < visit[1][fin.r][fin.c] ? visit[0][fin.r][fin.c] : visit[1][fin.r][fin.c];
		cout << '#' << tc << ' ' << (ans - 1) << '\n';
		memset(visit, 0, sizeof(visit));
	}
	return 0;
}