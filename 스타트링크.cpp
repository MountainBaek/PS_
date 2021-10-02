#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int N, ans = 987654321;
int map[21][21];
vector<int> A;

void dfs(int dep,int idx) {
	if (dep == N / 2) {
		vector<int>B;
		sort(A.begin(), A.end());
		for (int i = 1; i <= N; i++) {
			if (!binary_search(A.begin(), A.end(), i))
				B.push_back(i);
		}
		int Asum = 0, Bsum = 0;
		for (register int i = 0; i < A.size(); i++) {
			for (register int j = i + 1; j < A.size(); j++) {
				Asum += map[A[i]][A[j]];
				Asum += map[A[j]][A[i]];
				Bsum += map[B[i]][B[j]];
				Bsum += map[B[j]][B[i]];
			}
		}
		int cha = abs(Asum - Bsum);
		ans = cha < ans ? cha : ans;
		return;
	}
	else {
		for (register int i = idx; i <= N; i++) {
			A.push_back(i);
			dfs(dep + 1, i + 1);
			A.pop_back();
		 }
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (register int r = 1; r <= N; r++)
		for (register int c = 1; c <= N; c++)
			cin >> map[r][c];
	dfs(0,1);
	
	cout << ans;
	return 0;
}