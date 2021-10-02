/*15686번 치킨배달*/
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
struct pnt { int r, c; }house[100], bbq[13];
queue<int>min_Q;
vector<int>combv;
int N, M, Map[50][50];
int house_cnt, bbq_cnt, Min_dis = 1e9;

void cal_min(vector<pnt>alive) {
	int min_temp, temp_dis = 0;
	for (int h = 0; h < house_cnt; h++) {
		min_temp = abs(house[h].r - alive[0].r) + abs(house[h].c - alive[0].c);
		for (int j = 1; j < M; j++) {
			if (min_temp > abs(house[h].r - alive[j].r) + abs(house[h].c - alive[j].c)) {
				min_temp = abs(house[h].r - alive[j].r) + abs(house[h].c - alive[j].c);
			}
		}
		min_Q.push(min_temp);
	}
	while (!min_Q.empty()) {
		temp_dis += min_Q.front();
		min_Q.pop();
	}
	if (Min_dis > temp_dis) {
		Min_dis = temp_dis;
	}
	
}

void comb(int n, int k) {
	
	do {
		vector<pnt>alive;
		for (int i = 0; i < combv.size(); i++) {
			if (combv[i] == 1) {
				alive.push_back(bbq[i]);
			}
		}
		cal_min(alive);
	} while (next_permutation(combv.begin(), combv.end()));
	
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> Map[r][c];
			if (Map[r][c] == 1) {
				house[house_cnt].r = r;
				house[house_cnt].c = c;
				house_cnt++;
			}
			if (Map[r][c] == 2) {
				bbq[bbq_cnt].r = r;
				bbq[bbq_cnt].c = c;
				bbq_cnt++;
			}
		}
	}
	for (int i = 0; i < bbq_cnt - M; i++)combv.push_back(0);
	for (int i = 0; i < M; i++) combv.push_back(1);
	
	comb(bbq_cnt, M);
	cout << Min_dis;
}