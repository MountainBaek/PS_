/*»çÅÁ »óÀÚ*/
#include <iostream>
#include <math.h>
#define SIZE 1000002
#define FLAVOR 1000000
#define max(a,b) a>b ? a:b
using namespace std;
typedef long long ll;
ll it[SIZE * 4];
int N, h, size_;

void tree_updata(int idx, ll value) {
	int id = idx + size_ - 1;
	while (id > 0) {
		it[id] += value;
		id /= 2;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	h = (int)ceil(log2(FLAVOR));
	size_ = 1 << h;
	for (int i = 0; i < N; i++) {
		ll cmd, a, b;
		cin >> cmd;
		if (cmd == 1) {
			cin >> a;
			int candy = a;
			int id = 1;
			int updata = id;
			while (id < size_ * 2) {
				if (it[id] >= candy) {
					updata = id;
					id *= 2;
				}
				else {
					candy -= it[id];
					id += 1;
					updata = id;
				}
			}
			cout << updata - size_ + 1 << '\n';
			tree_updata(updata - size_ + 1, -1);
		}
		else {//»çÅÁ ³Ö°í •û°í
			cin >> a >> b;
			tree_updata(a, b);
		}
	}
}