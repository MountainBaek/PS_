#include <iostream>
#include <map>
#include <string>
using namespace std;
map<int, int>Map;

int compute(int num) {
	return num + num;
}

int main() {
	string input;
	getline(cin, input);
	for (int i = 0,size = input.size(); i < size; i += 2) {
		int num = input[i] - '0';
		auto it = Map.find(num);
		if (it == Map.end()) {
			int res = compute(num);
			Map.insert({ num,res });
			cout << res;
		}
		else {
			cout << it->second;
		}
	}
	return 0;
}