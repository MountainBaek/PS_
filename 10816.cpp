/*10816 숫자 카드 2*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>Card;
int N, M, target;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		Card.push_back(input);
	}
	sort(Card.begin(), Card.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> target;
		cout << (upper_bound(Card.begin(), Card.end(), target) - Card.begin()) - (lower_bound(Card.begin(), Card.end(), target) - Card.begin()) << ' ';
	}
}