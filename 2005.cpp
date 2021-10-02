#include<iostream>
using namespace std;
long long arr[11][11];

int main() {
	for (int i = 1; i <= 10; i++) {
		arr[i][1] = 1;
		arr[i][i] = 1;
	}
	for (int i = 3; i <= 10; i++) {
		for (int j = 2; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		cout << '#' << tc << '\n';
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= i; j++) {
				cout << arr[i][j]<<' ';
			}
			cout << '\n';
		}
		
	}
	return 0;
}