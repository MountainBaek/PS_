#include <iostream>
#include <algorithm>
using namespace std;
int perm[100000];
int N, totalCnt;

bool nextPerm() {
	int top = N - 1;

	while (top > 0 && perm[top - 1] > perm[top]) top--;
	if (top == 0) return false;

	int j = N - 1;
	while (perm[top - 1] > perm[j]) j--;

	swap(perm[top - 1], perm[j]);

	int s = top;
	int e = N - 1;
	while (s < e) {
		swap(perm[s], perm[e]);
		s++, e--;
	}
	
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> perm[i];

	if (nextPerm()) {
		for (int i = 0; i < N; i++)
			cout << perm[i] << ' ';
	}
	
	else cout << -1;
	return 0;
}
