/*14620번 꽃길*/
#include <iostream>
using namespace std;
int N;
int Map[10][10];
int visit[10][10];
int drc[] = { 0,0,-1,1,-1,1,0,0 };
int Min_cost = 1e9;

//dfs 탐색 범위 : 0 < r,c < N-1 라서 상하좌우 탐색 할 때 범위 초과 체크는 안해도 됨//
int Add_flower(int r, int c) {
	if (visit[r][c] != 0) return 0; //현위치가 비어있지 않으면 탈출
	else {
		int able[4] = { 0 };
		//상하좌우가 다 비었는지 체크
		for (int d = 0; d < 4; d++) {
			int nr = r + drc[d];
			int nc = c + drc[d + 4];
			if (visit[nr][nc] == 0) {
				able[d] = 1;
			}
		}
		//상하좌우가 다 비었으면 꽃을 심는다.
		if (able[0] == 1 && able[1] == 1 && able[2] == 1 && able[3] == 1) {
			visit[r][c] = 1;
			for (int d = 0; d < 4; d++) {
				int nr = r + drc[d];
				int nc = c + drc[d + 4];
				visit[nr][nc] = 1;
			}
			return 1;
		}
		//아니면 그냥 탈출
		else return 0;
	}
}
void Remove_flower(int r, int c, int flag) {
	if (flag == 1) {
		visit[r][c] = 0;
		for (int d = 0; d < 4; d++) {
			int nr = r + drc[d];
			int nc = c + drc[d + 4];
			visit[nr][nc] = 0;
		}
	}
	else return;
}
void dfs(int flower_cnt) {
	if (flower_cnt > 3) { // 꽃 3개 다 심었을 때
		int min_temp = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (visit[r][c] == 1) {
					min_temp = min_temp + Map[r][c];
				}
			}
		}
		if (Min_cost >= min_temp) {
			Min_cost = min_temp;
		}
		return;
	}
	else {
		for (int rr = 1; rr < N - 1; rr++) {
			for (int cc = 1; cc < N - 1; cc++) {
				int Add_flag = Add_flower(rr, cc);
				if (Add_flag == 1) {
					dfs(flower_cnt + 1);
					Remove_flower(rr, cc, Add_flag);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> Map[r][c];
		}
	}
	
	dfs(1);

	cout << Min_cost;
}