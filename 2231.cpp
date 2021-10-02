#include <iostream>
#include <string>
using namespace std;
char temp[1000000];
int value;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int input;
	cin >> input;
	for (int i = 1; i <= input; i++) {
		int t = i;
		while (t) {
			value = value + t % 10;
			t = t / 10;
		}
		if (i + value == input) {
			cout << i;
			return 0;
		}
		value = 0;
	}
	cout << "0";
}