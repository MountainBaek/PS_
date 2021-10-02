#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (1) {
		string tmp;
		getline(cin, tmp);
		if (tmp == ".") break;
		string in = "";
		for (int i = 0; tmp[i] != '.';i++) {
			if (tmp[i] == '(' || tmp[i] == ')' || tmp[i] == '[' || tmp[i] == ']')
				in += tmp[i];
		}
		stack<char>S;
		bool isOK = true;
		for (int i = 0, size = in.size(); i < size; i++) {
			if (in[i] == '(' || in[i] == '[') S.push(in[i]);
			else if (in[i] == ')' || in[i] == ']') {
				if (S.empty()) {
					isOK = false;
					break;
				}
				if (in[i] == ')' && S.top() == '[') {
					isOK = false;
					break;
				}
				else if (in[i] == ']' && S.top() == '(') {
					isOK = false;
					break;
				}
				else if (in[i] == ')' && S.top() == '(') S.pop();
				else if (in[i] == ']' && S.top() == '[') S.pop();
			}
		}
		cout << (S.empty()&&isOK ? "yes" : "no") << '\n';
	}
	return 0;
}