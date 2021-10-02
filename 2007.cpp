#include <iostream>
#include <string>
using namespace std;

string cut_s(string s,int f,int r) {
	string cut_ = "";
	for (int i = f; i < r; i++) {
		cut_ += s[i];
	}
	return cut_;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		string input;
		string tmp = "", word = "";
		cin >> input;
		tmp += input[0];
		tmp += input[1];
		for (int i = 2; i < input.length(); i++) {
			string cut_ = cut_s(input, i, i + tmp.length());
			if (tmp == cut_) {
				if (word == "") {
					word = tmp;
				}
				else {
					int iii = tmp.find(word, 1);
					if (tmp.find(word, 1) != 0)
						break;
					else word = tmp;
				}
			}
			tmp += input[i];
		}

		cout << '#' << tc << ' ' << word.length() << '\n';
	}
	return 0;
}