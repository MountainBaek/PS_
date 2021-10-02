#include <iostream>
using namespace std;
int arr[50002];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	int tc = 1;
	cin >> T;
	while (T--) {
		int ans = 0;
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		int front = 1, rear = 1, top = 1;
		int prev = 0;
		while (1) {
			if (rear > N) {
				ans += ((top - front) * (rear - top - 1));
				break;
			}
			if (prev < arr[rear] && top == rear) {
				prev = arr[rear];
				rear++;
				if (arr[top] < arr[rear]) top = rear;
			}
			else if (prev < arr[rear] && top != rear) {
				prev = arr[rear];
				ans += ((top - front) * (rear - top - 1));
				top = rear;
				front = rear - 1;
				rear++;
				if (arr[top] < arr[rear]) top = rear;
			}
			else if(prev >= arr[rear]) {
				prev = arr[rear];
				rear++;
			}
		}
		
		cout << '#' << tc++ << ' ' << ans << '\n';
	}
	return 0;
}