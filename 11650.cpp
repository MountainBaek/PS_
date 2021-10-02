/*11650번 좌표 정렬하기*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
pair<int, int>temp;
vector<pair<int, int>>v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp.first >> temp.second;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}