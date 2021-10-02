#include <iostream>
#include <string>
#define MOD 1'234'567'891
#define R 31
#define ll long long
using namespace std;
ll tmp[50];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int len;
	string a;
	cin >> len >> a;
	ll res = 0;
	tmp[0] = 1;
	for (int i = 1; i < len; i++) 
		tmp[i] = (tmp[i - 1] * R) % MOD;
	
	for (int i = 0; i < len; i++) {
		res += (a[i] - 'a' + 1) * tmp[i] % MOD;
		res %= MOD;
	}
	cout << res % MOD;
	return 0;
}