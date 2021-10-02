#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#define ll long long
#define MOD 1'000'000
#define MAXIUM 1'000'000'000'000'000'000
using namespace std;

struct matrix {
	ll arr[2][2];
	matrix() { memset(arr, 0, sizeof(arr)); }
	matrix(int t) {
		if (t == 0) {		// | 1 0 |
			arr[0][0] = 1;	// | 0 1 |
			arr[0][1] = 0;
			arr[1][0] = 0;
			arr[1][1] = 1;
		}
		else if (t == 1) {	// | 1 1 |
			arr[0][0] = 1;	// | 1 0 |
			arr[0][1] = 1;
			arr[1][0] = 1;
			arr[1][1] = 0;
		}
	}
};
		
matrix mult(matrix a, matrix b) {
	matrix res;
	res.arr[0][0] = (a.arr[0][0] * b.arr[0][0] + a.arr[0][1] * b.arr[1][0]) % MOD;
	res.arr[0][1] = (a.arr[0][0] * b.arr[0][1] + a.arr[0][1] * b.arr[1][1]) % MOD;
	res.arr[1][0] = (a.arr[1][0] * b.arr[0][0] + a.arr[1][1] * b.arr[1][0]) % MOD;
	res.arr[1][1] = (a.arr[1][0] * b.arr[0][1] + a.arr[1][1] * b.arr[1][1]) % MOD;
	return res;
}

matrix pow(ll n) {
	if (n == 1) return matrix(1);
	else {
		if (n % 2 == 1) {
			matrix tmp = pow(n / 2);
			matrix res = mult(tmp, tmp);
			return mult(res, matrix(1));
		}
		else {
			matrix tmp = pow(n / 2);
			matrix res = mult(tmp, tmp);
			return res;
		}
	}
}

void printmatrix(matrix res,int n) {
	cout << res.arr[0][0] << ' ' << res.arr[0][1] << '\n';
	cout << res.arr[1][0] << ' ' << res.arr[1][1] << '\n';
	cout << "fibo(" << n + 1 << ") : " << res.arr[0][0] << '\n';
	cout << "fibo(" << n << ") : " << res.arr[1][0] << '\n';
	cout << "fibo(" << n - 1 << ") : " << res.arr[1][1] << "\n\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N;
	cin >> N;
	ll tmp = N;

	//matrix res(0);// 단위행렬
	//matrix a(1); // 1,1,1,0
	//while (tmp > 0) {
	//	if (tmp % 2 == 1) {
	//		res = mult(res, a);
	//	}
	//	a = mult(a, a);
	//	tmp /= 2;
	//}
	//cout << res.arr[1][0] % MOD << '\n';

	matrix res2 = pow(N);
	cout << res2.arr[1][0]%MOD << '\n';
	
	return 0;

}