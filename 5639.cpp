/*5639번 이진 검색 트리*/
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;
int tree[40000];
int size_;
void post(int idx) {
	if (idx >= size_) return;
	post(idx * 2);
	post(idx * 2 + 1);
	if (tree[idx] != 0) cout << tree[idx] << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	string input;
	ifstream in("input.txt");
	int h = 0, max_ = 0;
	while (getline(in,input)) {
		int idx = 1;
		int trans = stoi(input);
		while (1) {
			if (tree[idx]==0) {
				tree[idx] = trans;
				break;
			}
			if (trans < tree[idx]) idx *= 2;
			else idx = idx * 2 + 1;
		}
		max_ = max_ < idx ? idx : max_;
	}
	h = (int)ceil(log2(max_));
	size_ = 1 << h;
	int id = 1;
	post(id);
}