#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int max_len = 0;
char ori[5001];
char pt[5001];
void makePI() {
	int size = strlen(pt);
	int pi[5001];
	memset(pi, 0, sizeof(pi));
	int f = 0;
	for (register int r = 1; r < size; r++) {
		while (f > 0 && pt[r] != pt[f]) {
			f = pi[f - 1];
		}
		if (pt[r] == pt[f]) {
			pi[r] = ++f;
			max_len = max_len < pi[r] ? pi[r] : max_len;
		}
	}
	return;
}
inline void substr(int s) {
	int idx = 0;
	for (register int i = s; ori[i] != '\0'; i++) {
		pt[idx++] = ori[i];
	}
	pt[idx] = '\0';
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> ori;
	int size = strlen(ori);
	for (register int i = 0; i < size; i++) {
		substr(i);
		makePI();
	}
	cout << max_len;
	return 0;
}