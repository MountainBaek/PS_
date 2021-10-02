#include <iostream>
#include <string>
#include <string.h>
#include <map>
#define SIZE 200'005
using namespace std;
int T, N;
int relation[SIZE];
int parent[SIZE];
map<string, int> fr;

int findSet(int tar) {
	if (tar == parent[tar]) return tar;
	else {
		parent[tar] = findSet(parent[tar]);
		relation[tar] = relation[parent[tar]];
		return parent[tar];
	}
}

void unionSet(int a, int b) {
	int x = findSet(a);
	int y = findSet(b);
	if (x != y) {
		parent[y] = x;
		relation[y] += relation[x];
		relation[x] = relation[y];
	}
}

void init() {
	cin >> N;
	for (register int i = 0; i < SIZE; i++) {
		relation[i] = 1;
		parent[i] = i;
	}
	fr.clear();
	int num = 1;
	for (register int i = 0; i < N; i++) {
		string a, b;
		cin >> a >> b;
		int aNum, bNum;
		auto it = fr.find(a);
		if (it == fr.end()) {
			aNum = num;
			fr.insert({ a,num++ });
		}
		else aNum = it->second;

		it = fr.find(b);
		if (it == fr.end()) {
			bNum = num;
			fr.insert({ b,num++ });
		}
		else bNum = it->second;

		unionSet(aNum, bNum);
		
		findSet(aNum);
		findSet(bNum);


		cout << relation[aNum]<<'\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	for (register int t = 0; t < T; t++) {
		init();
	}
	return 0;
}
