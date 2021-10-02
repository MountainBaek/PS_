#include <iostream>
#define ll unsigned long long
using namespace std;
ll arr[40];
ll A, B, C;
ll pow(ll idx) {
	if (idx == 1) {
		return A % C;
	}
	else {
		if (idx % 2 == 1) {
			ll tmp = pow((idx - 1) / 2);
			ll tmptmp = ((tmp%C)*(tmp%C)) % C;
			return (tmptmp*(A%C)) % C;
		}
		else {
			ll tmp = pow(idx / 2);
			return ((tmp % C)*(tmp % C)) % C;
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> A >> B >> C;
	cout <<pow(B);
	return 0;
}