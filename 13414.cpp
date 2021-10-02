#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#define Miter map<string,int>::iterator
using namespace std;
struct info {
	string ID;
	int ord;
};

map<string, int>list;
map<int, string>out;
vector<string>input;

bool cmpID(const info &a, const info &b) {
	if (a.ID < b.ID) return true;
	else return false;
}

bool cmpOrd(const info &a, const info &b) {
	if (a.ord < b.ord) return true;
	else return false;
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int K, L;
	cin >> K >> L;
	for (int i = 0; i < L; i++) {
		string stu;
		cin >> stu;
		input.push_back(stu);
	}
	int ord = input.size();
	for (int i = input.size() - 1; i >= 0; i--) {
		Miter it = list.find(input[i]);
		if (it == list.end())
			list.insert({ input[i],ord-- });
	}
	
	for (auto i = list.begin(); i != list.end(); i++) {
		string tmp1 = i->first;
		int tmp2 = i->second;
		out.insert({tmp2,tmp1});
	}
	//cout << "___________________\n";
	int cnt = 0;
	for (auto j : out) {
		if (cnt == K) break;
		cout << j.second << '\n';
		cnt++;
	}
	return 0;
}