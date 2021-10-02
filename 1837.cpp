#include <iostream>
#include <string>
using namespace std;
const int MAX = 1e6 + 1;
int prime[MAX] = { 0,-1, };
void eratos() {
	for (int i = 2; i*i <= MAX; i++) {
		for (int j = i * i; j <= MAX; j += i) {
			if (prime[j] == 1) continue;
			prime[j] = 1;
		}
	}
}

string P, int K;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	eratos();
	cin >> P >> K;
	return 0;
}