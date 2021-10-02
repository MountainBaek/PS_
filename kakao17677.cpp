#include <iostream>
#include <string>
#include <regex>
#include <queue>
#include <algorithm>
using namespace std;
regex comp("[a-zA-Z]+");
string a[1000], b[1000];
queue<string>itsc, unio;
int a_idx = 0, b_idx = 0;

int solution(string str1, string str2) {
	int answer = 0;
	string temp;
	transform(str1.begin(), str1.end(), str1.begin(), toupper);
	transform(str2.begin(), str2.end(), str2.begin(), toupper);
	for (int i = 0; i < str1.length() - 1; i++) {
		temp = str1.substr(i, 2);
		if (regex_match(temp, comp)) {
			a[a_idx++] = temp;
		}
	}
	for (int i = 0; i < str2.length() - 1; i++) {
		temp = str2.substr(i, 2);
		if (regex_match(temp, comp)) {
			b[b_idx++] = temp;
		}
	}

	for (int i = 0; i < str1.length() - 1; i++) {
		for (int j = 0; j < str2.length() - 1; j++) {
			if (a[i] != "\0"&&a[i] == b[j]) {
				itsc.push(b[j]);
				unio.push(b[j]);
				a[i] = b[j] = "\0";
				break;
			}
		}
	}
	for (int i = 0; i < str1.length() - 1; i++) {
		if (a[i] != "\0") unio.push(a[i]);
	}
	for (int i = 0; i < str2.length() - 1; i++) {
		if (b[i] != "\0") unio.push(b[i]);
	}
	double x = itsc.size();
	double y = unio.size();
	if (y == 0)answer = 65536;
	else answer = (double)(x / y) * 65536;
	
	return answer;
}

int main() {
	int out;
	out = solution("e=m*c^2", "e=m*c^2");

	cout << out;
}