/*17135�� ĳ�� ���潺*/
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
1. �ü���ġ ����
2. �� �ü��� ���� ���� �ȿ� ���� �ִ��� Ȯ��
	2.1 ���� ������ ���ݿ��� ���, ���� �ü� �ݺ� ����
3. �ü� ��ġ ���ʺ��� 1�� ���� ��Ž
	3.1 ���� ������ ī��Ʈ ����, ���ݹ��� �� �ʿ��� ����
	3.2 Ž�� ������ �� �ִ��� ī��Ʈ
		3.2.1 ���� ������ ��ü ���� ����
4. �� ������ �ִ� �� �� ����
5. �ü� ���� ����(1�� ������)
6. 2-5 �ݺ�

*/
