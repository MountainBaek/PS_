/*1759번 암호만들기*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int L, C;
char input[16];
bool visit[16];
string pw;

void make_pass(int n, int s) {
	if (n > L) {
		int vow = 0;//모음
		int conso = 0;//자음
		for (int i = 0; i < pw.size(); i++) {
			if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u') vow++;
			else conso++;
		}
		if (vow >= 1 && conso >= 2) cout << pw << endl;
	}
	else {
		for (int i = s; i < C; i++) {
			pw += input[i];
			make_pass(n + 1, i+1);
			pw.pop_back();
		}
	}
}

int main() {
	cin >> L >> C;
	char in;
	for (int i = 0; i < C; i++) {
		cin >> in;
		input[i] = in;
	}
	sort(input, input + C);
	for (int i = 0; i < C; i++) {
		pw += input[i];
		make_pass(2, i+1);
		pw.pop_back();
	}
}