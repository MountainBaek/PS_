#include <iostream>
#include <string>
#define SIZE 1000001
using namespace std;

int pi[SIZE];

int ans = 0;

void makePI(string pt) {
	int f = 0;
	int size = pt.size();
	for (int r = 1; r < size; r++) {
		while (f > 0 && pt[f] != pt[r]) {
			f = pi[f - 1];
		}
		if (pt[f] == pt[r]) {
			pi[r] = ++f;
		}
	}
}

void KMP(string ori, string pt) {
	makePI(pt);

	int oriSize = ori.size();
	int ptSize = pt.size();
	int f = 0;

	for (int r = 0; r < oriSize; r++) {
		while (f > 0 && ori[r] != pt[f]) {
			f = pi[f - 1];
		}
		if (ori[r] == pt[f]) {
			if (f == ptSize - 1) {
				ans = 1;
				return;
				f = pi[f];
			}
			else {
				f++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string ori, pt;
	cin >> ori >> pt;
	KMP(ori, pt);
	
	cout << ans;

	return 0;
}