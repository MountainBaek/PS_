#include <iostream>
#include <queue>
using namespace std;
int T;
int Map[12][12];
bool visit[12][12]; /*초기화 필요*/
struct Point {
	int r, c;
}temp;
queue<Point>Q;		/*초기화 필요*/
int dxy[] = { 0,0,-1,1,-1,1,0,0 };
int cable = 1e9;

int N;
int cable_temp = 0;	/*초기화 필요*/

void dfs() {
	int r = Q.front().r;
	int c = Q.front().c;
	Q.pop();
	for (int d = 0; d < 4; d++) {
		int nr = r + dxy[d];
		int nc = c + dxy[d + 4];
		if (!(nr < 0 || nr >= N || nc < 0 || nc >= N) && visit[nr][nc] == 0) {
			cable_temp++;
			dfs();
		}
	}

}
void dfs() {
	
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for (int t = 1; t <= T; t++) {
		
		cin >> N;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				cin >> Map[r][c];
				if (Map[r][c] == 1) {
					temp.r = r;
					temp.c = c;
					Q.push(temp);
				}
			}
		}
		link();
	}
}