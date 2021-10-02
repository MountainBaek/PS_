/*2750번 수 정렬하기*/
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[10000000];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);//STL사용

	for (int i = 0; i < N; i++)
		cout << arr[i] << '\n';
}