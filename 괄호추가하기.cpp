#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;
int N, ans = INT_MIN;
string input;
vector<int>oper;
int chk[10];

int cal() {
	int result = 0;
	stack<int>num;
	stack<int>op;
	for (int i = 0; i < input.size(); i++) {
		if (i % 2 == 0) 
			num.push(input[i] - '0');
		else {
			if (op.empty()) op.push(i);
			else if (chk[op.top() / 2] > chk[i / 2]) op.push(i);
			else {
				while (chk[op.top() / 2] <= chk[i / 2]) {
					int tmp1 = num.top();
					num.pop();
					int tmp2 = num.top();
					num.pop();
					switch (input[op.top()]) {
					case '*':
						num.push(tmp1*tmp2);
						break;
					case '+':
						num.push(tmp1 + tmp2);
						break;
					case '-':
						num.push(tmp2 - tmp1);
						break;
					}
					op.pop();
					if (op.empty()) break;
				}
				op.push(i);
			}
		}
	}
	while (!op.empty()) {
		int tmp1 = num.top();
		num.pop();
		int tmp2 = num.top();
		num.pop();
		char c = input[op.top()];
		switch (c) {
		case '*':
			num.push(tmp1*tmp2);
			break;
		case '+':
			num.push(tmp1 + tmp2);
			break;
		case '-':
			num.push(tmp2 - tmp1);
			break;
		}
		op.pop();
	}
	result = num.top();
	return result;
}

void selop(int dep, int cnt,int idx) {
	if (dep == cnt) {
		int res = cal();
		ans = ans < res ? res : ans;
		/*for (int i = 0; i < oper.size(); i++)
			cout << chk[i] << ' ';
		cout << '\n';*/
		return;
	}
	else {
		for (int i = idx; i < oper.size(); i++) {
			if (chk[i] != 100)continue;
			if (dep == 1) {
				chk[i] = dep;
				selop(dep + 1, cnt, i + 1);
				chk[i] = 100;
			}
			else {
				if (chk[i - 1] == 100) {
					chk[i] = dep;
					selop(dep + 1, cnt, i + 1);
					chk[i] = 100;
				}
				else continue;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	cin >> input;
	int priority = 1;
	for (int i = 0; i < input.size(); i++) {
		if (input[i]<'0' || input[i] >'9')
			oper.push_back(priority++);
	}
	for (int i = 0; i < oper.size(); i++)
		chk[i] = 100;
	for (int i = 1; i <= (N + 1) / 2; i++)
		selop(1, i, 0);
	cout << ans;
	return 0;
}