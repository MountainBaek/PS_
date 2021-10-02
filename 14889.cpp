/*14889번 스타트와 링크*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>v, S_T, L_T;
int N, Map[20][20], ST[10], LT[10], valance = 1e9,diff;
int ST_sum, LT_sum;
int Comb_m[20][20];

void go() {
	for (int i = 0; i < N / 2; i++) {
		for (int j = i + 1; j < N / 2; j++) {
			ST_sum = ST_sum + Map[S_T[i]][S_T[j]] + Map[S_T[j]][S_T[i]];
			LT_sum = LT_sum + Map[L_T[i]][L_T[j]] + Map[L_T[j]][L_T[i]];
		}
	}
}

int comb(int n, int k) {
	if (n == k) return 1;
	else if (k == 0) return 0;
	else if (n > k > 0) {
		return comb(n - 1, k - 1) + comb(n - 1, k);
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
	for (int i = 0; i < N / 2; i++) { v.push_back(0); v.push_back(1); }
	sort(v.begin(), v.end());

	do {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 0) S_T.push_back(i);
			else L_T.push_back(i);
		}
		go();
		
		if (ST_sum - LT_sum > 0) diff = ST_sum - LT_sum;
		else diff = LT_sum - ST_sum;

		if (diff < valance) valance = diff;
		
		ST_sum = LT_sum = 0;
		S_T.clear();
		L_T.clear();
	} while (next_permutation(v.begin(), v.end()));

	for (int i = 1; i < N; i++) {
		Comb_m[i][i] = 1;
	}
	comb(2,1);
	cout << valance;
}