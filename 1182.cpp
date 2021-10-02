/*1182번 부분수열의 합*/
#include <iostream>
using namespace std;
int N, S, cnt;
int arr[20];

void Search(int index,int sum) {
	int temp = sum + arr[index];
	if (index >= N) return;
	if (temp == S) cnt++;
	Search(index + 1, sum);//현 인덱스의 값을 더하지 않았을 때
	Search(index + 1, temp);//현 인덱스의 값을 더했을 떄
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> arr[i];
	Search(0, 0);
	cout << cnt;
}