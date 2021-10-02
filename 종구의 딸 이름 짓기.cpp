#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;
struct info {
	int r, c;
	char ch;

	bool operator<(const info &cmp)const {
		return ch > cmp.ch;
	}
};
string charset[2000];
bool visit[2000][2000];
int drc[] = { 0,1,1,0 };
int N, M;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	int tc = 1;
	while (T--) {
		cin >> N >> M;
		for (register int r = 0; r < N; r++) {
			cin >> charset[r];
		}
		priority_queue<info, vector<info>, less<info>> Q;
		Q.push({ 0,0,charset[0][0] });
		visit[0][0] = true;
		vector<info>list;

		int cnt = 0;
		cout << '#' << tc++ << ' ';
		while (!Q.empty()) {
			register int qs = Q.size();
			info first = Q.top();
			map<int, string>next;
			while (qs--) {
				cnt++;
				int r = Q.top().r;
				int c = Q.top().c;
				char ch = Q.top().ch;
				Q.pop();

				if (first.ch == ch) {
					for (int d = 0; d < 2; d++) {
						int nr = r + drc[d];
						int nc = c + drc[d + 2];

						if (!(nr >= N || nc >= M) && !visit[nr][nc]) {
							list.push_back({ nr,nc,charset[nr][nc] });
							visit[nr][nc] = true;
						}
					}
				}
				else 
					break;
			}
			while (!Q.empty())
				Q.pop();

			for (auto n : list) {
				Q.push(n);
			}
			list.clear();
			cout << first.ch;
		}
		cout  << '\n';

		memset(visit, 0, sizeof(visit));
		//cout << cnt << '\n';
	}
	
	return 0;
}
