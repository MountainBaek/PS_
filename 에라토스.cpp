#include <iostream>
using namespace std;

int num[100000] = {-1,-1,0,}; // 0 : 소수, -1 : 0,1, 합성수 

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int extend_gcd(int xx, int yy) {
	int prev_x, x, prev_y, y, prev_r, r, q, tmp;
	prev_x = 1, prev_y = 0, prev_r = xx;
	x = 0, y = 1, r = yy, q = xx / yy;
	while (1) {
		if (r == 0) return x;
		q = prev_r / r;
		tmp = x;
		x = prev_x - x * q;
		prev_x = tmp;
		tmp = y;
		y = prev_y - y * q;
		prev_y = tmp;
		tmp = r;
		r = prev_r % r;
		prev_r = tmp;
	}
}

int main() {
	/*int N;
	cin >> N;
	for (int i = 2; i*i <= N; i++) {
		for (int j = i * i; j <= N; j++) {
			if (num[j] == -1)continue;
			num[j] = -1;
		}
	}*/
		
	//15x - 17y = 1
	extend_gcd(15, -17);

}