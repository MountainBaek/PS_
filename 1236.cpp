#include <iostream>
#include <string>
#include <vector>
using namespace std;
string map[50];
bool R[50], C[50];
int N, M, cnt = 1e9;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	int add = 0;
	for (int r = 0; r < N; r++) {
		cin >> map[r];
		for (int c = 0; c < M; c++) {
			if (map[r][c] == 'X') {
				R[r] = true;
				C[c] = true;
			}
		}
	}
	int Rcnt = 0, Ccnt = 0;
	for (int r = 0; r < N; r++) {
		if (!R[r]) {
			R[r] = 1;
			Rcnt++;
		}
	}
	for (int c = 0; c < M; c++) {
		if (!C[c]) {
			C[c] = 1;
			Ccnt++;
		}
	}
	cout << (Rcnt < Ccnt ? Ccnt : Rcnt);
	return 0;
}