#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#define enter '\n'
#define ll long long
using namespace std;
ll benefit, coin;
int arr[1000002];
int N;

void reset_() {
	benefit = 0;
	coin = 0;
	for (int i = 0; i <= N; i++) arr[i] = 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	queue<ll>Q;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		
		int max_ = 0;
		for (int i = N - 1; i >= 0; i--) {
			if (max_ <= arr[i]) max_ = arr[i];
			else {
				benefit += max_ - arr[i];
			}
		}
		Q.push(benefit);
		cout << '#' << tc << ' ' << benefit << enter;
		reset_();
	}

	return 0;
}