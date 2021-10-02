/*20056번 마법사 상어와 파이어볼*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//typedef vector<vector<int>> vii;
struct info { int m, s, d; };
using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vinf = vector<info>;
int dr[] = { -1,-1,0,1,1,1,0,-1 };
int dc[] = { 0,1,1,1,0,-1,-1,-1 };

queue<info> map[51][51];//맵 양끝은 이어져 있음
queue<pii> fire_loc;
// ri,ci - i번 파이어볼 위치
// mi - 파이어볼 질량
// di - 파이어볼 방향
// si - 파이어볼 속력
int N, M, K;//맵크기, 파이어볼 정보 수, 이동명령 수

void fn1(int r, int c) {//move
    int q_size = map[r][c].size();
	for (int j = 0; j < q_size; j++) {
		info elmt = map[r][c].front(); map[r][c].pop();
		int nr = r + dr[elmt.d] * elmt.s; int nc = c + dc[elmt.d] * elmt.s;
		if (nr <= 0)nr += N; if (nr > N) nr -= N; if (nc <= 0)nc += N; if (nc > N) nc -= N;
		map[nr][nc].push(elmt);
	}
	return;
}

void fn2(int r,int c) {//fusion
	//(r,c)는 2개이상 파이어볼 모여있는 위치
	//1. 해당 칸 모든 질량 합, 속력합, (홀+홀 짝, 짝+짝 짝 이용해서할꺼니까) 방향합 구해놓기
	int sum_m = 0, sum_s = 0, sum_d = 0;
	int cnt = map[r][c].size();
	while (!map[r][c].empty()) {
		sum_m += map[r][c].front().m;
		sum_s += map[r][c].front().s;
		sum_d += map[r][c].front().d;
		map[r][c].pop();
	}
	//2. 구한 합들 이용해서 새 파이어볼 4개 넣기
	int new_m = sum_m / 5;
	if (new_m == 0) return;

	int new_s = sum_s / cnt;
	if (sum_d % 2 == 0) for (int d = 0; d < 8; d += 2) map[r][c].push({ new_m,new_s,d });
	else for (int d = 1; d < 8; d += 2) map[r][c].push({ new_m,new_s,d });
	return;
}

int fn3() { //res
	int res = 0;
	for (int r = 1; r <= 50; r++) {
		for (int c = 1; c <= 50; c++) {
			if (map[r][c].size() >= 1) {
				while (!map[r][c].empty()) {
					res += map[r][c].front().m;
					map[r][c].pop();
				}
			}
		}
	}
	return res;
}

void pri(int t) {
	cout << "---------" << t << "-------------\n";
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cout << map[r][c].size() << ' ';
		}
		cout << '\n';
	}
	cout << "-----------------------\n";

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) {
		int ri, ci, mi, si, di;
		cin >> ri >> ci >> mi >> si >> di;
		map[ri][ci].push({ mi,si,di });
		fire_loc.push({ ri,ci });
	}
	while (K--) {
		queue<pii>tmp;
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (!map[r][c].empty()) tmp.push({ r,c });
			}
		}
		while (!tmp.empty()){
			pii p = tmp.front(); tmp.pop();
			fn1(p.first, p.second);
		}
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (map[r][c].size() >= 2) tmp.push({ r,c });
			}
		}
		while (!tmp.empty()) {
			pii p = tmp.front(); tmp.pop();
			fn2(p.first, p.second);
		}
		pri(K);
	}
	
	cout << fn3();

	
	return 0;
}