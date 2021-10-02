#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> pipii;

int p[100001];
int r[100001];
pipii edge[100001];
int V, E;

void init() {
	for (int i = 1; i <= V; i++)
		p[i] = i;
}

int f(int tar) {
	if (tar == p[tar]) return tar;
	else return p[tar] = f(p[tar]);
}

void uni(int a, int b) {
	int aa = f(a);
	int bb = f(b);
	//if (aa != bb) p[bb] = aa;

	if (r[aa] > r[bb]) {
		p[bb] = aa;
	}
	else {
		p[aa] = bb;
		if (r[aa] == r[bb])
			r[bb]++;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> V >> E;
	init();
	for (int i = 0; i < E; i++) {
		int v1, v2, val;
		cin >> v1 >> v2 >> val;
		edge[i] = { val,{v1,v2} };
	}
	sort(edge, edge + E);

	int cnt = 0;
	int res = 0;
	for (int i = 0; i < E; i++) {
		int v1 = edge[i].second.first;
		int v2 = edge[i].second.second;
		int val = edge[i].first;

		if (f(v1) != f(v2)) {
			uni(v1, v2);
			cnt++;
			res += val;
		}
		if (cnt == V - 1) break;
	}

	cout << res;
	return 0;
}