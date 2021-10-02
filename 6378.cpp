#include <iostream>
#include <string>
using namespace std;

string input;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	while (1) {
		cin >> input;
		if (input == "0") return 0;
		while (1) {
			int temp = 0;
			for (int r = 0; r < input.length(); r++) {
				temp = temp + input.at(r) - '0';
			}
			if (temp >= 10) input = to_string(temp);
			else {
				cout << temp << '\n';
				break;
			}
		}
		
	}
}