#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct pnt { int r, c; };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<pnt>list;
		for (int i = 0; i < N+2; i++) {
			int r, c;
			cin >> r >> c;
			list.push_back({ r,c });
		}

		vector<vector<int>> map(N+2, vector<int>(N+2));
		vector<bool>visit(N+2);

		for (int r = 0; r < N+2; r++) {
			for (int c = 0; c < N+2; c++) {
				map[r][c] = abs(list[r].r - list[c].r) + abs(list[r].c - list[c].c);
			}
		}
		
		queue<int>Q;
		Q.push(0);
		visit[0] = true;
		while (!Q.empty()) {
			int now = Q.front();
			Q.pop();
			for (int i = 0; i < N+2; i++) {
				if (map[now][i] <= 1000 && !visit[i]) {
					visit[i] = true;
					Q.push(i);
				}
			}
		}

		cout << (visit[N + 1] ? "happy" : "sad") << '\n';
	}
	return 0;
}