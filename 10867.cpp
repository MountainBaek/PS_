/*10867번 중복 빼고 정렬하기*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,input;
vector<int>v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
}