#include <iostream>
#include <vector>
#include <math.h>
#define min(a,b) a<b?a:b
using namespace std;
struct pnt { int R; int C; };
pnt arr[10];
bool visit[10];
int N, ans = 987654321;
int CalDist(vector<int>v) {
	int sum = 0;
	for (int i = 0; i < N - 1; i++) {
		sum += (abs(arr[i].R - arr[i + 1].R) + abs(arr[i].C - arr[i + 1].C));
	}
	return sum;
}

void dfs(int dep,vector<int>v) {
	if (dep == N) {
		ans = min(ans, CalDist(v));
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (visit[i] == false) {
				visit[i] = true;
				v.push_back(i);
				dfs(dep + 1,v);
				v.pop_back();
				visit[i] = false;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		vector<int>v; 
		ans = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int R, C;
			cin >> R >> C;
			arr[i] = { R,C };
		}
		dfs(0, v);
		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}