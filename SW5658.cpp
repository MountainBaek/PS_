/*5658. [모의 SW 역량테스트] 보물상자 비밀번호*/
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stack>
using namespace std;

int chrtoint(char c) {
	if (c >= 48 && c <= 57) return c - 48;
	else return c - 55;
}

int conv_sort(string *unconv,int N,int k) {
	int len = unconv[0].size();
	int output;
	int converted[28] = { 0 };
	int sorted[28] = { 0 };
	for (int j = 0; j < N; j++) {
		for (int i = len - 1; i >= 0; i--) {
			converted[j] += chrtoint(unconv[j][i])* pow(16, len - 1 - i);
		}
	}
	sort(converted, converted + N);
	stack<int>S;
	S.push(converted[0]);
	for (int i = 1; i < N; i++) {
		if (S.top() != converted[i]) S.push(converted[i]);
	}
	for (int i = 0; i < k - 1; i++) S.pop();
	return S.top();
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T, N, k;
	cin >> T;
	for (int TC = 1; TC < T+1; TC++) {
		string input;
		string rotate_in[7];
		string uncvrt[28];
		int convert[28] = { 0 };
		cin >> N >> k;
		cin >> input;
		int side_n = N / 4;
		int temp_c = 0;
		for (int i = 0; i < side_n; i++) {
			rotate_in[i] = input[N - 1];
			input[N - 1] = NULL;
			rotate_in[i].append(input);
			input = rotate_in[i];
			for (int j = 0; j < 4; j++) {
				for (int k = j * side_n; k < (j + 1)*side_n; k++) {
					uncvrt[temp_c] += rotate_in[i].at(k);
				}
				temp_c++;
			}
		}
		cout << '#' << TC << ' ' << conv_sort(uncvrt, N, k) << endl;
	}
}
