/*10866¹ø µ¦*/
#include <iostream>
#include <deque>
#include <string>
using namespace std;
int N;
string command;
deque<int>D;
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> N;
	for (int i = 0; i <= N; i++) {
		getline(cin, command);
		if (command[0] == '\0') continue;
		if(command[1]=='u'){
			if (command[5] == 'f') {
				command.erase(0, 11);
				int input = stoi(command);
				D.push_front(input);
			}
			else if (command[5] == 'b') {
				command.erase(0, 10);
				int input = stoi(command);
				D.push_back(input);
			}
		}
		else if (command[4] == 'f') {
			if (D.empty()) cout << -1 << '\n';
			else {
				cout << D.front() << '\n';
				D.pop_front();
			}
		}
		else if (command[4] == 'b') {
			if (D.empty()) cout << -1 << '\n';
			else {
				cout << D.back() << '\n';
				D.pop_back();
			}
		}
		else if (command[0] == 's') cout << D.size() << '\n';
		else if (command[0] == 'e') {
			if (D.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (command[0] == 'f') {
			if (D.empty()) cout << -1 << '\n';
			else {
				cout << D.front() << '\n';
			}
		}
		else if (command[0] == 'b') {
			if (D.empty()) cout << -1 << '\n';
			else {
				cout << D.back() << '\n';
			}
		}
	}
}