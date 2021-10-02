/*10845¹ø Å¥*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;
queue<int>Q;
int N;
string command;
char com[15];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i <= N;i++) {
		getline(cin, command);
		if (command.size()==0) continue;
		if (command[1] == 'u') {
			command.erase(0, 5);
			int input_num = stoi(command);
			Q.push(input_num);
		}
		else if (command == "pop") {
			if (Q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << Q.front() << '\n';
				Q.pop();
			}
		}
		else if (command == "size") {
			cout << Q.size() << '\n';
		}
		else if (command == "empty") {
			if (Q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (command == "front") {
			if (!Q.empty()) cout << Q.front() << '\n';
			else cout << -1 << '\n';
		}
		else if (command == "back") {
			if (!Q.empty()) cout << Q.back() << '\n';
			else cout << -1 << '\n';
		}
	}

}