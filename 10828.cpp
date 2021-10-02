/*10828¹ø ½ºÅÃ*/
#include <iostream>
#include <string>
using namespace std;
int N, top_pointer;
string command;
int stack_arr[10000];

void push(int n) {
	stack_arr[++top_pointer] = n;
}
void pop() {
	if (top_pointer >= 0) {
		int return_value = stack_arr[top_pointer];
		stack_arr[top_pointer--] = 0;
		cout << return_value << '\n';
	}
	else cout << -1 << '\n';
}
void size() {
	cout << top_pointer + 1 << '\n';
}
void empty() {
	if (top_pointer >= 0) cout << 0 << '\n';
	else cout << 1 << '\n';
}
void top() {
	if (top_pointer >= 0) cout << stack_arr[top_pointer] << '\n';
	else cout << -1 << '\n';
}

int main() { 
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	top_pointer = -1;
	for (int i = 0; i <= N; i++) {
		getline(cin, command);
		if (command.size() == 0) continue;
		if (command[1] == 'u') {
			command.erase(0, 5);
			int put_num = stoi(command);
			push(put_num);
		}
		else if (command == "pop") pop();
		else if (command == "size") size();
		else if (command == "empty") empty();
		else if (command == "top") top();
	}
}