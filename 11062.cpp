#include <iostream>
#define MAX(a,b) a>b?a:b;
using namespace std;

int T, N;
int card[1005];
int D[1005][1005][2];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int n = 1; n <= N; n++) {
			cin >> card[n];
		}
		for (int d = 0; d <= N - 1; d++) {
			for (int i = 1; i <= N - d; i++) {
				D[i][i + d][0] = MAX(D[i + 1][i + d][1] + card[i], D[i][i + d - 1][1] + card[i + d]);
				if (D[i + 1][i + d][1] + card[i] > D[i][i + d - 1][1] + card[i + d]) {
					D[i][i + d][1] = D[i + 1][i + d][0];
				}
				else {
					D[i][i + d][1] = D[i][i + d - 1][0];
				}
			}
		}
		cout << D[1][N][0] << '\n';
	}
	return 0;
}