#include <iostream>
#include <math.h>
#include <algorithm>
#define MAX 100002
#define px(i) p[i].first
#define py(i) p[i].second
#define pa(i) p[i].angle
using namespace std;
typedef long long ll;
struct P { ll first, second; double angle; };

int N;
P p[MAX];
P ST[MAX];
ll A = 1LL;

ll ccw(P A, P B, P C) {
	ll tmp1 = A.first*B.second + B.first*C.second + C.first*A.second;
	ll tmp2 = B.first*A.second + C.first*B.second + A.first* C.second;
	if (tmp1 - tmp2 < 0)return -1;
	else if (tmp1 - tmp2 > 0)return 1;
	else return 0;
}

bool comp1(const P &A, const P &B) {
	if (A.first < B.first) return true;
	else if (A.first == B.first) return A.second < B.second;
	else return false;
}

bool comp2(const P &A, const P &B) {
	if (A.angle < B.angle) return true;
	else if (A.angle == B.angle) {
		if(A.first == B.first) return A.second < B.second;
		else return A.first < B.first;
	}
	else return false;
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> px(i) >> py(i);
	}
	sort(p+1, p + N+1, comp1);
	P origin = p[1];
	for (int i = 1; i <= N; i++) {
		px(i) -= origin.first;
		py(i) -= origin.second;
		pa(i) = atan2(py(i), px(i));
	}
	
	sort(p + 2, p + N+1, comp2);

	int nn_p = 1;
	int top = 0;
	while (nn_p <= N) {
		while (top > 1 && ccw(ST[top - 1], ST[top], p[nn_p]) <= 0) 
			top--;
		ST[++top] = p[nn_p++];
	}
	cout << top;
	return 0;
}
