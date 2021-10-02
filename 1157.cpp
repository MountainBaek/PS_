#include <iostream>
#include <string>
using namespace std;

string input;
int cnt[26];
int chk,temp;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		if (input.at(i) >= 'a' && input.at(i) <= 'z')
			chk = input.at(i) - 'a';
		else if (input.at(i) >= 'A' && input.at(i) <= 'Z')
			chk = input.at(i) - 'A';

		cnt[chk]++;
	}
	int max = cnt[0];
	bool overlap = false;
	for (int i = 1; i < 26; i++) {
		if (cnt[i] > max) {
			max = cnt[i];
			temp = i;
			overlap = false;
		}
		else if (cnt[i] == max) {
			overlap = true;
		}
	}
	char output = 'A' + temp;
	if(overlap == false) cout << output;
	else cout << '?' ;
}