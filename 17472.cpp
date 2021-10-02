#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#define piii pair<int,pair<int,int>>
#define node1 second.first
#define node2 second.second
#define len first
using namespace std;
struct pnt { int r, c; };

int drc[] = { 0,0,-1,1,1,-1,0,0 };
int map[10][10];
int visit[10][10];
vector<pnt> island[7];
int N, M, islandIdx = 1;
priority_queue<piii>PQ;
int prt[7], rank[7];

bool chk(int r, int c) {
	if (!(r < 0 || c < 0 || r >= N || c >= M)) return true;
	return false;
}

int FIND(int tar) {
	if (tar == prt[tar]) return tar;
	else return prt[tar] = FIND(prt[tar]);
}

void UNI(int a, int b) {
	int aa = FIND(a);
	int bb = FIND(b);
	if (aa != bb)
		prt[bb] = aa;
}

void setIsland(vector<pnt>tmp) {
	queue<pnt>Q;
	for (int i = 0; i < tmp.size(); i++) {
		if (visit[tmp[i].r][tmp[i].c] != 0) continue;
		Q.push(tmp[i]);
		visit[tmp[i].r][tmp[i].c] = islandIdx;
		island[islandIdx].push_back(tmp[i]);
		while (!Q.empty()) {
			int r = Q.front().r;
			int c = Q.front().c;
			Q.pop();
			for (int d = 0; d < 4; d++) {
				int nr = r + drc[d];
				int nc = c + drc[d + 4];
				if (chk(nr, nc) && map[nr][nc] == 1 && visit[nr][nc] == 0) {
					visit[nr][nc] = islandIdx;
					Q.push({ nr,nc });
					island[islandIdx].push_back({ nr,nc });
				}
			}
		}
		islandIdx++;
	}
}

void calLen() {
	for (int num = 1; num < islandIdx; num++) {
		for (int idx = 0; idx < island[num].size(); idx++) {
			int r = island[num][idx].r;
			int c = island[num][idx].c;
			for (int d = 0; d < 4; d++) {
				int lenTmp = 1;
				while (1) {
					int nr = r + drc[d] * lenTmp;
					int nc = c + drc[d + 4] * lenTmp;
					if (!chk(nr, nc))break;
					if (visit[nr][nc] == num)break;
					if (visit[nr][nc] != 0) {
						if (lenTmp - 1 >= 2) {
							PQ.push({ (lenTmp - 1)*-1,{num,visit[nr][nc]} });
							break;
						}
						else break;
					}
					lenTmp++;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	vector<pnt>tmp;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> map[r][c];
			if (map[r][c] == 1)tmp.push_back({ r,c });
		}
	}

	setIsland(tmp);
	calLen();

	for (int i = 0; i < islandIdx; i++)
		prt[i] = i;

	int ans = 0;
	while (!PQ.empty()) {
		piii now = PQ.top();
		PQ.pop();
		if (prt[now.node1] == prt[now.node2]) continue;
		ans += (now.len*-1);
		UNI(now.node1, now.node2);
		for (int i = 1; i < islandIdx; i++)
			FIND(i);

		bool isEnd = true;
		for (int i = 2; i < islandIdx; i++) {
			if (prt[i - 1] != prt[i]) {
				isEnd = false;
				break;
			}
		}
		if (isEnd)break;
	}
	
	int cnt = 0;
	int AnsOK = true;
	for (int i = 1; i < islandIdx; i++) {
		if (prt[i] == i)cnt++;
		if (cnt > 1) {
			AnsOK = false;
			break;
		}
	}
	cout << (AnsOK ? ans : -1);
	return 0;
}