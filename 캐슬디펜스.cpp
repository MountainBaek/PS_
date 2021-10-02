/*17135번 캐슬 디펜스*/
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int N, M, D, ans, map1[17][17], map2[17][17];
vector<int>ArcLoc;
bool chk(int r, int c) {
	if (!(r<1 || c<1 || r>N || c>M))
		return true;
	return false;
}
void GameGo() {
	int tmp = 0, m1[17][17], m2[17][17];
	memcpy(m1, map1, sizeof(m1)); memcpy(m2, map2, sizeof(m2));
	for (int ArcR = N + 1; ArcR > 1; ArcR--) {
		for (int idx = 0; idx < 3; idx++) {
			int ArcC = ArcLoc[idx];
			for (int nowDist = 1; nowDist <= D; nowDist++) {
				bool kill = false;
				for (int d = 1; d <= nowDist; d++) {
					int nr = ArcR - d, nc = ArcC - (nowDist - d);
					if (chk(nr, nc) && m1[nr][nc] == 1) {
						m2[nr][nc]++;
						kill = true;
						break;
					}
				}
				if (kill == true) break;
				for (int d = nowDist - 1; d > 0; d--) {
					int nr = ArcR - d, nc = ArcC + (nowDist - d);
					if (chk(nr, nc) && m1[nr][nc] == 1) {
						m2[nr][nc]++;
						kill = true;
						break;
					}
				}
				if (kill == true) break;
			}
		}
		int Ecnt = 0;
		for (int r = ArcR - 1; r > 0; r--) {
			for (int c = 1; c <= M; c++) {
				if (m1[r][c] == 1)
					Ecnt++;
				if (m2[r][c] != 0) {
					tmp++;
					m1[r][c] = m2[r][c] = 0;
				}
			}
		}
		if (Ecnt == 0) break;
	}
	ans = ans < tmp ? tmp : ans;
}
void setArc(int Acnt, int idx) {
	if (Acnt == 3)
		GameGo();
	else {
		for (int i = idx; i <= M; i++) {
			ArcLoc.push_back(i);
			setArc(Acnt + 1, i + 1);
			ArcLoc.pop_back();
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> D;
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= M; c++)
			cin >> map1[r][c];
	setArc(0, 1);
	cout << ans;
	return 0;
}

/*
1. 궁수위치 선택
2. 각 궁수들 공격 범위 안에 적이 있는지 확인
	2.1 적이 있으면 공격여부 기록, 현재 궁수 반복 종료
3. 궁수 위치 위쪽부터 1번 까지 완탐
	3.1 공격 받은적 카운트 증가, 공격받은 적 맵에서 삭제
	3.2 탐색 범위내 적 있는지 카운트
		3.2.1 적이 없으면 전체 루프 종료
4. 답 변수와 최대 비교 후 저장
5. 궁수 위로 전진(1번 전까지)
6. 2-5 반복

*/
