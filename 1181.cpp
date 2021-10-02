/*1181번 단어 정렬*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int N;
string in;
vector<string>v;
vector<pair<int,string>>out;
pair<int, string>temp;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> in;
		v.push_back(in);
	}
	sort(v.begin(), v.end());//입력 받은것을 정렬해서
	v.erase(unique(v.begin(), v.end()),v.end());//중복 제거
	//단어의 길이와 단어를 저장하는 벡터에 넣어줌
	for (int i = 0; i < v.size(); i++) {
		temp = { v[i].size(),v[i] };
		out.push_back(temp);
	}
	sort(out.begin(), out.end());//pair를 정렬하면 first 기준으로 정렬되고, 다음으로 second기준으로 정렬이 된다.
	for (int i = 0; i < out.size(); i++) {
		cout << out[i].second << '\n';
	}
}