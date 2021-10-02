/*1849¹ø ¼ø¿­*/
#include <iostream>
#include <math.h>
#define SIZE 100002
using namespace std;
int tree[SIZE * 4];
int ans[SIZE];
int N;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	int h = (int)ceil(log2(N));
	int size_ = 1 << h;
	int id = size_ - 1;
	for (int i = size_; i < size_ + N; i++) tree[i] = 1;
	while (id > 0) {
		tree[id] = tree[id * 2] + tree[id * 2 + 1];
		id--;
	}
	for (int i = 1; i <= N; i++) {
		int input;
		cin >> input;
		int loc = input + 1;
		int id = 1, tmp;
		while (id < size_ +N) {
			if (tree[id] >= loc) {
				tmp = id;
				id *= 2;
			}
			else {
				loc -= tree[id];
				id += 1;
				tmp = id;
			}
		}
		ans[tmp - size_+1] = i;
		id = tmp;
		while (id > 0) {
			tree[id] -= 1;
			id /= 2;
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}