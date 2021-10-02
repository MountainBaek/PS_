#include <iostream>
using namespace std;

bool chk[50];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	bool res = 1;
	int prev = 0;
	for(int i = 0; i < 6; i++) {
		int input;
		cin >> input;
		if (prev >= input) {
			res = 0;
			break;
		}
		if (chk[input]) {
			res = 0;
			break;
		}
		if (input < 1 || input >45) {
			res = 0;
			break;
		}
		chk[input] = 1;
		prev = input;
	}
	cout << (res ? "true" : "false");
	return 0;
}