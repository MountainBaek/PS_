#include <iostream>
#include<queue>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;
vvi list(101);
bool visit[101];

int Com;
int connect;

int main() {
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> Com >> connect;
	for (int i = 0; i < connect; i++) {
		int a, b;
		cin >> a >> b;
		list[a].push_back(b);
		list[b].push_back(a);
	}
	int chk = 0;
	queue<int>Q;
	Q.push(1);
	visit[1] = true;
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int i = 0; i < list[now].size();i++) {
			int next = list[now][i];
			if (visit[next] == true) continue;
			visit[next] = true;
			Q.push(next);
			chk++;
		}
	}
	cout << chk;
	return 0;
}