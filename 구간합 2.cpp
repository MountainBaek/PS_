#include <iostream>
#include <math.h>
#define ll long long
#define SIZE 4000001
using namespace std;
struct info {
	ll val;
	ll lazy;
};
info Tree[SIZE];
ll arr[SIZE];
int N, M, K;

ll init(int node, int left, int right) {
	if (left == right)
		return Tree[node].val = arr[left];
	else
		return Tree[node].val = init(node * 2, left, (left + right) / 2) + init(node * 2 + 1, (left + right) / 2 + 1, right);
}

int RangeChk(int node_l,int node_r,int tar_l,int tar_r) {
	if (tar_l > tar_r)return 0;
	else if (node_l == tar_l && tar_r == node_r) return 1;
	else if (node_l <= tar_l && tar_r <= node_r) return 2;
	return 0;
}

void updata_parent(int node) {
	while (node > 0) {
		Tree[node].val = Tree[node * 2].val + Tree[node * 2 + 1].val;
		node /= 2;
	}
}

void updata_lazy(int node, int node_left, int node_right, int tar_left, int tar_right, ll add) {
	if (Tree[node].lazy != 0) {
		Tree[node].val = Tree[node].val + (node_right - node_left + 1)*Tree[node].lazy;
		if (node_left != node_right) {
			Tree[node * 2].lazy += Tree[node].lazy;
			Tree[node * 2 + 1].lazy += Tree[node].lazy;
		}
		Tree[node].lazy = 0;
		updata_parent(node / 2);
	}
	int chk = RangeChk(node_left, node_right, tar_left, tar_right);
	if (chk == 1) {
		Tree[node].val += (node_right - node_left + 1)*add;
		if (node_left != node_right) {
			Tree[node * 2].lazy += add;
			Tree[node * 2 + 1].lazy += add;
		}
		updata_parent(node / 2);
	}
	else if (chk == 2) {
		if ((node_left + node_right) / 2 < tar_right)
			updata_lazy(node * 2, node_left, (node_left + node_right) / 2, tar_left, (node_left + node_right) / 2, add);
		else
			updata_lazy(node * 2, node_left, (node_left + node_right) / 2, tar_left, tar_right, add);
		
		if (tar_left < (node_left + node_right) / 2 + 1)
			updata_lazy(node * 2 + 1, (node_left + node_right) / 2 + 1, node_right, (node_left + node_right) / 2 + 1, tar_right, add);
		else
			updata_lazy(node * 2 + 1, (node_left + node_right) / 2 + 1, node_right, tar_left, tar_right, add);
	}
}

ll sum_result;
void rangeSum(int node,int node_left,int node_right,int tar_left,int tar_right) {
	if (Tree[node].lazy != 0) {
		Tree[node].val = Tree[node].val + (node_right - node_left + 1)*Tree[node].lazy;
		if (node_left != node_right) {
			Tree[node * 2].lazy += Tree[node].lazy;
			Tree[node * 2 + 1].lazy += Tree[node].lazy;
		}
		Tree[node].lazy = 0;
		updata_parent(node / 2);
	}
	int chk = RangeChk(node_left, node_right, tar_left, tar_right);
	if (chk == 1)
		sum_result += Tree[node].val;
	else if (chk == 2) {
		if ((node_left + node_right) / 2 < tar_right)
			rangeSum(node * 2, node_left, (node_left + node_right) / 2, tar_left, (node_left + node_right) / 2);
		else
			rangeSum(node * 2, node_left, (node_left + node_right) / 2, tar_left, tar_right);

		if (tar_left < (node_left + node_right) / 2 + 1)
			rangeSum(node * 2 + 1, (node_left + node_right) / 2 + 1, node_right, (node_left + node_right) / 2 + 1, tar_right);
		else
			rangeSum(node * 2 + 1, (node_left + node_right) / 2 + 1, node_right, tar_left, tar_right);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	init(1, 1, N);
	for (int i = 0; i < K + M; i++) {
		int comd;
		cin >> comd;
		if (comd == 1) {
			int l, r, add;
			cin >> l >> r >> add;
			updata_lazy(1, 1, N, l, r, add);
		}
		else {
			int l, r;
			cin >> l >> r;
			sum_result = 0;
			rangeSum(1, 1, N, l, r);
			cout << sum_result << '\n';
		}
	}
	return 0;
}