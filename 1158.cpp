/*1158번 조세퍼스 문제*/
#include <iostream>
#include <vector>
using namespace std;
vector<int>V;
int N, M;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) V.push_back(i);
	int curr = M - 1;
	cout << '<';
	while (V.size() > 1) {
		cout << V[curr] << ", ";
		V.erase(V.begin() + curr);
		if (V.size() == 0) break;
		curr = (curr + M - 1) % V.size();//다음 위치 구하기
	}
	cout << V[0] << '>';
}
