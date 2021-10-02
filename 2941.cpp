#include <iostream>
#include <string>
using namespace std;
string input;
int cnt;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> input;
	cnt = input.length();
	for (int i = 0; i < input.length(); i++) {
		if (input.at(i) == '=') {
			if (input.at(i - 1) == 'c') cnt--;
			else if (input.at(i - 1) == 's') cnt--;
			else if (input.at(i - 1) == 'z') {
				if (input.at(i - 2) == 'd') cnt = cnt - 2;
				else cnt--;
			}
		}
		else if (input.at(i) == '-') {
			if (input.at(i - 1) == 'c') cnt--;
			else if (input.at(i - 1) == 'd') cnt--;
		}
		else if (input.at(i) == 'j') {
			if (input.at(i - 1) == 'l') cnt--;
			else if (input.at(i - 1) == 'n') cnt--;
		}
	}
	cout << cnt;
}