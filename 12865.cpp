#include <stdio.h>
#include <algorithm>
using namespace std;
int N, K;
struct info { int weight, value; }item[105];
int DP[100005];

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		int w, v;
		scanf("%d %d", &w, &v);
		item[i] = { w,v };
	}

	for (int I_idx = 1; I_idx <= N; I_idx++) {
		for (int w = K; w >= 1; w--) { // w : ���� ����� �� �ִ� �賶�� ����(����)
			int tmp = DP[w - item[I_idx].weight]; //���� �������� �־��� �� ���� ������ ������ �ִ� ��ġ
			DP[w] = item[I_idx].weight <= w ? max(DP[w], tmp + item[I_idx].value) : DP[w];
		}
	}

	printf("%d", DP[K]);
	return 0;
}