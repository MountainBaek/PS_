/*1026¹ø º¸¹°*/
#include <iostream>
#include <algorithm>
using namespace std;
int A[50], B[50];
int N, result;

bool desc(int a, int b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	sort(A, A + N);
	sort(B, B + N, desc);
	for (int i = 0; i < N; i++) {
		result += A[i] * B[i];
	}
	cout << result;
}