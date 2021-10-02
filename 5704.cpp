#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int arr[26];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (1) {
		RE:
		memset(arr, 0, sizeof(arr));
		string in;
		getline(cin, in);
		if (in == "*")break;
		for (int i = 0; i < in.size(); i++) {
			if (in[i] == ' ')continue;
			arr[in[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (arr[i] == 0) {
				cout << "N\n";
				goto RE;
			}
		}
		cout << "Y\n";
	}
	return 0;
}