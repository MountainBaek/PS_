#include <iostream>
using namespace std;
int N, M;
int visit[9];

void go(int now,int s) {
	if (now == M) {
		for (int i = 1; i < 10; i++) {
			if (visit[i] == 1) cout << i << ' ';
		}
		cout << endl;
		return;
	}
	else {
		for (int i = s; i <= N; i++) {
			if (visit[i] == 0) {
				visit[i] = 1;
				go(now + 1,i);
				visit[i] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;

	go(0,1);
}