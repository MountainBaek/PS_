#include <iostream>
#include <algorithm>
#include <map>
#define pii pair<int,int>
using namespace std;

int N;
/* key : 식별번호, value : 위치 */
map<int, int> before;

/* first : 값, second : 식별번호 */
pii arr[500001];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	int label = 1;
	
	for (int i = 1; i <= N; i++) {
		int input;
		cin >> input;
		arr[i] = { input, label };
		before.insert({ label, i });
		label++;
	}

	sort(arr + 1, arr + N + 1);
	
	int res = 0;
	for (int i = 1; i <= N; i++) {
		int beforeIdx = before.find(arr[i].second)->second;
		int afterIdx = i;
		int moveDist = beforeIdx - afterIdx;

		res = res < moveDist ? moveDist : res;
	}

	cout << res + 1;
	return 0;
}