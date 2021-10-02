/*Union Find 구현*/
#include <iostream>
#define SIZE 10
using namespace std;

int parent[SIZE + 1];

void set_() {
	for (int i = 1; i <= SIZE; i++) parent[i] = i;
}

int find(int target) {
	if (target == parent[target]) return target;
	else return parent[target] = find(parent[target]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) parent[b] = a;
}

void PRINT_() {
	for (int i = 1; i <= SIZE; i++) {
		cout << i << ' ';
	}
	cout << '\n';
	for (int i = 1; i <= SIZE; i++) {
		cout << parent[i] << ' ';
	}
	cout << '\n' << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	set_();
	cout << "초기값" << '\n';
	PRINT_();
	cout << "(1,7 Union)" << '\n'; Union(1, 7);
	PRINT_();
	cout << "(7,2 Union)" << '\n'; Union(7, 2);
	PRINT_();
	cout << "(9,2 Union)" << '\n'; Union(9, 2);
	PRINT_();
	for (int i = 1; i <= SIZE; i++)find(i);
	cout << "헤드 정렬" << '\n';
	PRINT_();
	return 0;
}