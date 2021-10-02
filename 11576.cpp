#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int A_B, B_B, R;
int Arr_A[25];
int Arr_B[25];
int temp;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	memset(Arr_B, -1, sizeof(Arr_B));
	cin >> A_B >> B_B;
	cin >> R;
	for (int i = 0; i < R; i++) {
		cin >> Arr_A[i];
	}
	int i = R - 1;
	int j = 0;
	while (1) {
		temp = temp + Arr_A[i] * pow(A_B, j);
		i--;
		j++;
		if (i < 0) break;
	}
	int t = 0;
	while (temp != 0) {
		Arr_B[t] = temp % B_B;
		temp = temp / B_B;
		t++;
	}

	for (int k = 24; k >= 0; k--) {
		if (Arr_B[k] != -1) cout << Arr_B[k]<<' ';
	}

}