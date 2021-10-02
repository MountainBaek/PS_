/*6603¹ø ·Î¶Ç*/
#include <iostream>
using namespace std;
int N, input, Arr[13], visit[13];

void Comb(int n,int s) {
	if (n > 5) {
		for (int i = 0; i < N; i++) {
			if (visit[i] == 1) cout << Arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	else {
		for (int i = s; i < N; i++) {
			if (visit[i] == 0) {
				visit[i] = 1;
				Comb(n + 1,i);
				visit[i] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while(true) {
		cin >> N;
		if (N == 0)break;
		for (int i = 0; i < N; i++) cin >> Arr[i];
		Comb(0,0);
		cout << '\n';
	}
}
