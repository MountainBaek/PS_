#include <iostream>
#include <vector>
#include <algorithm>
#define vi vector<int>  
#define vii vector<vi>
#define viii vector<vii>
using namespace std;
int N, M, K;
int drc[] = { -1,-1,-1,0,1,1,1,0,-1,0,1,1,1,0,-1,-1 };
int energy[11][11], add[11][11], death[11][11];
vector<int> tree[11][11];
//viii tree(11, vii(11));

bool chk(int r, int c) {
	if (!(r<1 || c<1 || r>N || c>N)) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> K;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> add[r][c];
			energy[r][c] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int r, c, a;
		cin >> r >> c >> a;
		tree[r][c].push_back(a);
	}
	while (K--) {
		//봄
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (tree[r][c].size() == 0)continue;
				vector<int>tmp;
				sort(tree[r][c].begin(), tree[r][c].end());
				for(int i=0;i<tree[r][c].size();i++) {
					if (tree[r][c][i] <= energy[r][c]) {
						energy[r][c] -= tree[r][c][i];
						tmp.push_back(tree[r][c][i] + 1);
					}
					else {
						death[r][c] += (tree[r][c][i] / 2);
					}
				}
				tree[r][c].clear();
				for (int i = 0; i < tmp.size(); i++)
					tree[r][c].push_back(tmp[i]);
			}
		}

		//여름
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (death[r][c] == 0)continue;
				energy[r][c] += death[r][c];
				death[r][c] = 0;
			}
		}

		//가을
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (tree[r][c].size() == 0)continue;
				for(int i=0;i<tree[r][c].size();i++) {
					int top = tree[r][c][i];
					if (top % 5 != 0)continue;
					for (int d = 0; d < 8; d++) {
						int nr = r + drc[d];
						int nc = c + drc[d + 8];
						if (!chk(nr, nc))continue;
						tree[nr][nc].push_back(1);
					}
				}
			}
		}
		//겨울
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				energy[r][c] += add[r][c];
			}
		}
	}
	int ans = 0;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (tree[r][c].size() == 0)continue;
			ans += tree[r][c].size();
		}
	}
	cout << ans;
	return 0;
}