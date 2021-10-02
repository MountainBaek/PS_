#include <iostream>
#include <string>
using namespace std;
int T, grp;
char input[100];


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		int chr;
		bool TorF = true;
		int chk[26] = { 0 };
		cin >> input;
		for (int c = 0; input[c]; c++) {
			int now = input[c] - 'a';
			if (chk[now] != 0 && input[c] != input[c - 1]) TorF = false;
			chk[now]++;
		}
		if (TorF == true) grp++;
	}
	cout << grp;
}