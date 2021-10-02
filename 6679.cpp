#include <iostream>
using namespace std;
struct base {
	int b;
	int sum;
	int Arr[4];
}B[3]; // B[0]-10, B[1]-12, B[2]-16

int q, r;
int dec_sum, duo_sum, hex_sum;

void cal(int n, int x, int b) {
	q = n;
	while (q != 0)
	{
		int chk = B[b].b;
		q = n / B[b].b;
		r = n % B[b].b;
		B[b].Arr[x] = r;
		x++;
		if (q != 0) cal(q, x, b);
		else break;
	}
}
int main() {
	B[0].b = 10;
	B[1].b = 12;
	B[2].b = 16;

	for (int i = 1000; i < 10000; i++) {
		for (int s = 0; s < 3; s++) {
			B[s].sum = 0;
			for (int a = 0; a < 4; a++) {
				B[s].Arr[a] = 0;
			}
		}
		for (int j = 0; j < 3; j++) {
			cal(i, 0, j);
			for (int k = 0; k < 4; k++) {
				B[j].sum = B[j].sum + B[j].Arr[k];
			}
		}
		if (B[0].sum == B[1].sum && B[0].sum == B[2].sum) cout << i<<'\n';
	}
}