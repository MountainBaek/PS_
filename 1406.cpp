/*1406번 에디터 (solved by list)*/
#include <iostream>
#include <string>
#include <list>
using namespace std;
string input;
int n;
char command, add_alpha;
list<char>l;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> input;
	cin >> n;
	for (int i = 0; i < input.size(); i++) l.push_back(input[i]);
	list<char>::iterator cursor = l.end(), print_cursor;
	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == 'p') {
			cin >> add_alpha;
			l.insert(cursor, add_alpha);
		}
		else if (command == 'l') {
			if (cursor != l.begin()) cursor--;
		}
		else if (command == 'd') {
			if (cursor != l.end()) cursor++;
		}
		else if (command == 'b') {
			list<char>::iterator erase_cursor = cursor;
			if (cursor != l.begin()) l.erase(--erase_cursor);
		}
	}
	for (print_cursor = l.begin(); print_cursor != l.end(); print_cursor++) cout << *print_cursor;
}
/*1406번 에디터 (solved by stack)*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack<char>L, R, output;
int N;
string input;
char command, add_alpha;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> input;
	for (int i = 0; i < input.size(); i++) L.push(input[i]);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == 'P') {
			cin >> add_alpha;
			L.push(add_alpha);
		}
		else if (command == 'L') {
			if (!L.empty()) {
				R.push(L.top());
				L.pop();
			}
		}
		else if (command == 'D') {
			if (!R.empty()) {
				L.push(R.top());
				R.pop();
			}
		}
		else if (command == 'B') {
			if (!L.empty()) {
				L.pop();
			}
		}
	}
	//좌측 스택 뒤집기
	while (!L.empty()) {
		output.push(L.top());
		L.pop();
	}
	//좌측 스택 출력
	while (!output.empty()) {
		cout << output.top();
		output.pop();
	}
	//우측 스택 출력
	while (!R.empty()) {
		cout << R.top();
		R.pop();
	}
}