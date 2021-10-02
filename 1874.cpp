/*1874번 스택 수열*/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
stack<int>S;
queue<char>Q;
int N, Arr_pointer = 0, push_num = 1;
int Arr[100000];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> Arr[i];
	while (Arr_pointer < N) {
		if (S.empty()) {
			S.push(push_num++);
			Q.push('+');
		}
		else {
			if (S.top() == Arr[Arr_pointer]) {
				S.pop();
				Arr_pointer++;
				Q.push('-');
			}
			else {
				if (S.top() > Arr[Arr_pointer]) {
					cout << "NO";
					return 0;
				}
				else {
					S.push(push_num++);
					Q.push('+');
				}
			}
		}
	}
	while (!Q.empty()) {
		cout << Q.front() << '\n';
		Q.pop();
	}
}