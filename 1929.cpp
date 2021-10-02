/*1929번 소수 구하기*/
#include <iostream>
using namespace std;
int M, N;
int num[1000001] = {0,-1,};//0 : 소수, -1 : 1 또는 합성수

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> M >> N;

	for (int i = 2; i*i <= N; i++) { //체크 범위를 √N 까지로 둔다.
		for (int j = i * i; j <= N; j += i) {//i의 배수 부분을 다 합성수로 체크한다.
			if (num[j] == -1) continue;//만약 이전에 처리가 되었다면 바로 다음으로 넘어간다.
			num[j] = -1;
		}
	}
	for (int i = M; i <= N; i++) {
		if (num[i] == 0) cout << i << '\n';
	}
}