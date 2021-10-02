#include <iostream>
#define SIZE 1'000'000
using namespace std;

int res[SIZE + 1];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	res[4] = 1;
	res[5] = 2;

	for (int i = 6; i <= N; i++) {
		res[i] = res[(i + 1) / 2] + 2;
	}
	cout << res[N];
	return 0;

}