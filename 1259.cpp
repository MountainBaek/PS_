#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (1) {
con:	string in;
		cin >> in;
		if (in == "0") break;
		int size = in.size();
		int f, r;
		if (size % 2 == 0) {
			f = size / 2 - 1;
			r = size / 2;
		}
		else {
			f = size / 2 - 1;
			r = size / 2 + 1;
		}
		while (f >= 0) {
			if (in[f--] != in[r++]) {
				cout << "no" << '\n';
				goto con;
			}
		}
		cout << "yes" << '\n';
	}
	return 0;
}
