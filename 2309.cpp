#include <iostream>
using namespace std;
int tall[100];
int visit[100];
int sum, r, flag;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for (int i = 0; i < 9; i++) {
		int input;
		cin >> input;
		tall[input]++;
	}
	for (int i = 0; i < 100; i++) {
		if(tall[i] == 1) sum = sum + i;
	}
	r = sum - 100;
	for (int i = 0; i < 100; i++) {
		if (tall[i] == 1) {
			visit[i] = 1;
			for (int j = 0; j < 100; j++) {
				if (tall[j]==1&&visit[j] == 0) {
					if (i + j == r) {
						tall[i] = 0;
						tall[j] = 0;
						flag = 1;
						break;
					}
				}
			}
			visit[i] = 0;
		}
		if (flag == 1) break;
	}
	for (int i = 0; i < 100; i++) {
		if (tall[i] == 1) cout << i << '\n';
	}
}