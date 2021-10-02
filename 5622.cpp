#include <iostream>
#include <string>
using namespace std;
string input;
int cnt;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> input;
	for (int s = 0; s < input.length(); s++) {
		if (input.at(s) == 'A' || input.at(s) == 'B' || input.at(s) == 'C') cnt = cnt + 2;
		else if (input.at(s) == 'D' || input.at(s) == 'E' || input.at(s) == 'F') cnt = cnt + 3;
		else if (input.at(s) == 'G' || input.at(s) == 'H' || input.at(s) == 'I') cnt = cnt + 4;
		else if (input.at(s) == 'J' || input.at(s) == 'K' || input.at(s) == 'L') cnt = cnt + 5;
		else if (input.at(s) == 'M' || input.at(s) == 'N' || input.at(s) == 'O') cnt = cnt + 6;
		else if (input.at(s) == 'P' || input.at(s) == 'Q' || input.at(s) == 'R' || input.at(s) == 'S') cnt = cnt + 7;
		else if (input.at(s) == 'T' || input.at(s) == 'U' || input.at(s) == 'V') cnt = cnt + 8;
		else if (input.at(s) == 'W' || input.at(s) == 'X' || input.at(s) == 'Y' || input.at(s) == 'Z') cnt = cnt + 9;
	}
	cout << cnt + input.length();
}