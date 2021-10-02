/*6549번 히스토그램에서 가장큰 직사각형*/
#include <iostream>
#include <math.h>
#include <algorithm>
#define SIZE 100000
using namespace std;

int tree[SIZE * 4];
int N, max_;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	while (1) {
		cin >> N;
		int h = (int)ceil(log2(N));
		int size = 1 << h;
		int id = size - 1;
		if (N == 0)break;
		for (int i = size; i < size + N; i++) 
			cin >> tree[i];
		while (id > 0) {
			if (tree[id * 2] == 0 && tree[id * 2 + 1] != 0) 
				tree[id] = tree[id * 2 + 1];
			else if (tree[id * 2] != 0 && tree[id * 2 + 1] == 0) 
				tree[id] = tree[id * 2];
			else 
				tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
			id--;
		}
		for (int i = 1; i < size * 2; i++) {
			int tmp = h - log2(i);
			int width = 1 << tmp;
			max_ = max(tree[i] * width, max_);
		}
		cout << max_ << '\n';
	}
	return 0;
}