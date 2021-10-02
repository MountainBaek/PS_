#include <iostream>
using namespace std;

int p1[20];
int p2[20];
int r[20];
int N = 10;

void init() {
	for (int i = 0; i < N; i++) {
		p1[i] = i;
		p2[i] = i;
	}
}

int f(int x,int *p) {
	if (x == p[x]) return x;
	else return p[x] = f(p[x],p);
}

void u1(int a, int b,int* p) {
	int aa = f(a, p);
	int bb = f(b, p);
	if (aa != bb) p[bb] = aa;
}

void u2(int a, int b, int* p) {
	int aa = f(a, p);
	int bb = f(b, p);
	if (r[aa] < r[bb]) {
		p[aa] = bb;
	}
	else {
		p[bb] = aa;
		if (r[aa] == r[bb])
			r[aa]++;
	}
}

void pr(int* p) {
	for (int i = 0; i < N; i++)
		cout << p[i] << ' ';
	cout << endl;
}
int main() {
	init();
	pr(p1);
	pr(p2);
	u1(9, 8, p1);
	u1(8, 7, p1);
	u1(7, 6, p1);
	u1(6, 5, p1);
	u1(0, 1, p1);
	u1(1, 2, p1);
	u1(2, 3, p1);
	u1(3, 4, p1);
	u1(5, 4, p1);
	pr(p1);

	u2(0, 1, p2);
	u2(1, 2, p2);
	u2(2, 3, p2);
	u2(3, 4, p2);
	u2(9, 8, p2);
	u2(8, 7, p2);
	u2(7, 6, p2);
	u2(6, 5, p2);
	u2(5, 4, p2);
	pr(p2);
}