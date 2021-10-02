#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
struct info { int l, r, s; };
int N, X, M;
vector<info>list;
vector<pair<int,vector<int>>>ans;
int ham[7];
int hamTmp[7];
int max_ans_sum;

bool cmp(const pair<int, vector<int>> &a, const pair<int, vector<int>> &b) {
	if (a.first > b.first) return true;
	else if (a.first == b.first) {
		return a.second < b.second;
	}
	else return false;
}

void set(int idx) {
	if (idx > N) {
		if (hamTmp[N] < max_ans_sum) return;
		bool OK = true;
		for (int i = 0; i < list.size(); i++) {
			if ((hamTmp[list[i].r] - hamTmp[list[i].l - 1]) != list[i].s) {
				OK = false;
				break;
			}
		}
		if (OK) {
			max_ans_sum = max(max_ans_sum, hamTmp[N]);
			vector<int>tmp;
			for (int i = 1; i <= N; i++) {
				tmp.push_back(ham[i]);
			}
			ans.push_back({ hamTmp[N],tmp });
		}
		return;
	}
	else {
		for (int i = X; i >= 0; i--) {
			ham[idx] = i;
			hamTmp[idx] = hamTmp[idx - 1] + i;
			set(idx + 1);
			hamTmp[idx] = 0;
			ham[idx] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> X >> M;
		for (int i = 0; i < M; i++) {
			int l, r, s;
			cin >> l >> r >> s;
			list.push_back({ l,r,s });
		}
		set(1);
		sort(ans.begin(), ans.end(),cmp);
		cout << '#' << tc << ' ';
		if (ans.size() != 0) {
			for (int i = 0; i < N; i++) {
				cout << ans[0].second[i] << ' ';
			}
		}
		else
			cout << -1;
		cout << '\n';
		
		memset(ham, 0, sizeof(ham));
		memset(hamTmp, 0, sizeof(hamTmp));
		list.clear();
		ans.clear();
		max_ans_sum = 0;
	}
	return 0;
}