#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
map<string, int> list;
bool MAP[201][201];
int teamInfo[201];
int K;
int num;
bool ans;

void bfs(int idx) {
	queue<int>Q;
	Q.push(idx);
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int i = 0; i < num; i++) {
			//if (now == i) continue;
			if (MAP[now][i]) {
				if (teamInfo[i] != 0 && teamInfo[i] == teamInfo[now]) {
					ans = false;
					return;
				}
				if (teamInfo[i] == 0) {
					teamInfo[i] = (teamInfo[now] == 1 ? 2 : 1);
					Q.push(i);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> K;
		num = 0;
		ans = true;
		for (int i = 0; i < K; i++) {
			string in1, in2;
			cin >> in1 >> in2;
			if (list.find(in1) == list.end()) {
				list.insert({ in1,num++ });
			}
			if (list.find(in2) == list.end()) {
				list.insert({ in2,num++ });
			}
			
			MAP[list.find(in1)->second][list.find(in2)->second] = true;
			MAP[list.find(in2)->second][list.find(in1)->second] = true;
		}

		//모든 플레이어에 대해 시너지있는 친구가 상대로 갔는지 체크
		for (int i = 0; i < num; i++) {
			if (teamInfo[i] == 0) {
				teamInfo[i] = 1;
				bfs(i);
				if (!ans)break;
			}

		}

		cout << '#' << tc << ' ' << (ans ? "Yes\n" : "No\n");
		memset(teamInfo, 0, sizeof(teamInfo));
		memset(MAP, 0, sizeof(MAP));
		list.clear();
	}
	return 0;
}

/*
시너지 개수 K, 최대 인원 == 2K
기준 정점 시너지는 반대로 보냄
>> 정점이름에 번호를 붙혀?

*/