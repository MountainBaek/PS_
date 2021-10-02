/*1920번 수 찾기*/
#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int A[100000],B;

int search(int target) {
	int front = 0;
	int rear = N - 1;
	int mid;
	while (front <= rear) {
		mid = (front + rear) / 2;
		if (A[mid] == target) return 1;
		else {
			if (A[mid] < target) {
				front = mid + 1;
			}
			else{
				rear = mid - 1;
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);
	cin >> M;
	for (int i = 0; i < M; i++){
		cin >> B;
		if (search(B) == 0)
			cout << 0 << '\n';
		else
			cout << 1 << '\n';
	}
}