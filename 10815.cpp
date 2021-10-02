/*10815번 숫자카드*/
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, target;
int Card[500000];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Card[i];
	sort(Card, Card + N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> target;
		if (binary_search(Card, Card + N, target) == 0) cout << 0 << ' ';
		else cout << 1 << ' ';
	}
}