#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
int N;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	int tc = 1;
	while (T--) {
		set<pair<int, string>>list;
		cin >> N;
		for (int i = 0; i < N; i++) {
			string in;
			cin >> in;
			list.insert({ in.length(),in });
		}

		cout << '#' << tc-- << '\n';
		for (auto n : list)
			cout << n.second << '\n';
	}
	return 0;
}