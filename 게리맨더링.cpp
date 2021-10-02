#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#define vi vector<int> 
#define vvi vector<vi>
using namespace std;
int N, M;
//vvi connect(11); vvi tmp(11);
vi A, B;
int value[11], arr[11];
int connect[11][11], tmp[11][11];
int _union_[11];
int cnt, ans = 1e9;

void set() {
	for (int i = 1; i <= N; i++)
		_union_[i] = i;
}

int _find_(int tar) {
	if (tar == _union_[tar]) return tar;
	else return _union_[tar] = _find_(_union_[tar]);
}

void uni(int a, int b) {
	a = _find_(a);
	b = _find_(b);
	if (a != b) _union_[b] = a;
}

void disconnect(vi team) {
	for (int i = 0; i < team.size(); i++) {
		int j = 0;
		int now = team[i];
		for (int j = 1; j <= N; j++) {
			if (tmp[now][j] == 1 && !binary_search(team.begin(), team.end(), j))
				tmp[now][j] = tmp[j][now] = 0;
		}
	}
}

bool chk(vi team) {
	for (int i = 1; i < team.size(); i++) {
		if (_union_[team[0]] != _union_[team[i]]) {
			return false;
		}
	}
	return true;
}

void bfs(int s) {
	queue<int>Q;
	int visit[11];
	memcpy(visit, arr, sizeof(visit));
	Q.push(s);
	visit[s] = 1;
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int i = 1; i <= N; i++) {
			if (tmp[now][i] == 1 && visit[i] == 0) {
				visit[i] = 1;
				Q.push(i);
				uni(now, i);
			}
		}
	}

}

void setTeam(int tar, int dep, int idx) {
	if (tar == dep) {
		set();
		for (int i = 1; i <= N; i++)
			if (!binary_search(A.begin(), A.end(), i))
				B.push_back(i);
		memcpy(tmp, connect, sizeof(tmp));
		disconnect(A);
		disconnect(B);

		if (A.size() > 1)bfs(A[0]);
		if (B.size() > 1)bfs(B[0]);

		if (chk(A) && chk(B)) {
			int Asum = 0, Bsum = 0;
			for (int i = 0; i < A.size(); i++)
				Asum += value[A[i]];
			for (int i = 0; i < B.size(); i++)
				Bsum += value[B[i]];
			ans = min(abs(Asum - Bsum), ans);
		}
	
		B.clear();
		return;
	}
	else {
		for (int i = idx; i <= N; i++) {
			A.push_back(i);
			setTeam(tar, dep + 1, i + 1);
			A.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> value[i];
		_union_[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		cin >> M;
		for (int j = 0; j < M; j++) {
			int in;
			cin >> in;
			connect[i][in] = 1;
		}
	}

	for (int i = 1; i <= N; i++)
		setTeam(i, 0, 1);

	if (ans == 1e9) ans = -1;
	cout << ans;
	return 0;
}