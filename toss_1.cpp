#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	string input;
	cin >> input;
	for (int c = 0,size = input.size(); c < size;c++) {
		if(!(c=='1' && c=='2')){
			cout << "fasle";
			return 0;
		}
		if (c == size - 1 && input[c] == '1') {
			cout << "fasle";
			return 0;
		}
		if (input[c] == '1' && input[c + 1] == '1') {
			cout << "false";
			return 0;
		}
		
	}
	cout << "true";
	return 0;
}