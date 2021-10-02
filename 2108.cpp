#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
struct info {
	int num, fre;
	bool operator<(const info &a) const {
		if (fre > a.fre) return true;
		else if (fre == a.fre)
			return num < a.num;
		return false;
	}
};
info arr1[80002];
int arr2[500000];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	int maxN = -4001;
	int minN = 4001;
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		int in;
		cin >> in;
		arr1[in + 4000].fre++;
		arr2[i] = in;
		sum += in;
		maxN = max(maxN, in);
		minN = min(minN, in);
	}
	for (int i = minN + 4000; i <= maxN + 4000; i++) {
		if (arr1[i].fre != 0)
			arr1[i].num = i - 4000;
	}
	sort(arr1, arr1 + 8001);
	sort(arr2, arr2 + N);
	int fre;
	if (arr1[0].fre == arr1[1].fre) fre = arr1[1].num;
	else fre = arr1[0].num;

	cout << round((double)sum / (double)N) << '\n';
	cout << arr2[N / 2] << '\n';
	cout << fre << '\n';
	cout << maxN - minN << '\n';

	return 0;
}