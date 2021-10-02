/*14502 연구소*/
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
struct pint { int r, c; }temp;
queue<pint>Q;
int Map[8][8];//0:빈공간, 1:벽, 2:바이러스
int visit[8][8];
int drc[] = { -1,1,0,0,0,0,-1,1 };//상하좌우?
int Max_safeArea;
int M, N;

void search_safeA(int(*infection_Map)[8]) {
	int safeArea = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (infection_Map[i][j] == 0) safeArea++;
		}
	}
	if (safeArea > Max_safeArea) Max_safeArea = safeArea;
}

void infection(int(*infection_Map)[8]) {//bfs
	int temp_Map[8][8];
	for (int i = 0; i < 8; i < i++) {
		for (int j = 0; j < 8; j++) {
			temp_Map[i][j] = infection_Map[i][j];
		}
	}
	int temp_visit[8][8];
	memcpy(temp_visit, visit, sizeof(visit));
	queue<pint>QQ;
	QQ = Q;

	while(!QQ.empty()) {
		int rr = QQ.front().r;
		int cc = QQ.front().c;
		QQ.pop();
		for (int d = 0; d < 4; d++) {
			int nr = rr + drc[d];
			int nc = cc + drc[d + 4];
			if (!(nr < 0 || nr >= N || nc < 0 || nc >= M)) {
				if(temp_Map[nr][nc]==0&&temp_visit[nr][nc]==0){
					temp_Map[nr][nc] = 2;
					temp_visit[nr][nc] = 1;
					temp.r = nr;
					temp.c = nc;
					QQ.push(temp);
				}
			}
		}
	}
	search_safeA(temp_Map);
}

void set_wall(int wall_count, int (*infection_Map)[8]) {
	if (wall_count > 3) {
		infection(infection_Map);
		return;
	}
	else { // BP
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (Map[i][j] == 0) {
					Map[i][j] = 1;
					set_wall(wall_count + 1, Map); //벽이 세워진 상태의 Map을 전달
					Map[i][j] = 0;
				}
				
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	memset(Map, -1, sizeof(Map));
	cin >> N >> M; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 2) {
				temp.r = i;
				temp.c = j;
				Q.push(temp);
				visit[i][j] = 1;
			}
		}
	}
	set_wall(1,Map);
	cout << Max_safeArea;
}