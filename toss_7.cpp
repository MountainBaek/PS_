#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int _copy_[8];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	char input[100];
	cin.getline(input,100);

	vector<int>memory;
	char* split = strtok(input, ";");
	int idx = stoi(split);
	split = strtok(NULL, ";");
	char* split2 = strtok(split, " ");
	while (split2 != NULL) {
		memory.push_back(stoi(split2));
		split2 = strtok(NULL, " ");
	}
	int i = 0;
	while (1) {
		if (memory[idx] == 0) {
			_copy_[i++] = memory[idx];
			_copy_[i++] = i + 1;
			idx = memory[idx + 1];
			
		}
		else {
			_copy_[i++] = memory[idx];
			_copy_[i++] = memory[idx + 1];
			break;
		}
	}
	cout << "0; ";
	for (int i = 0; i < 8; i++) {
		cout << _copy_[i] << ' ';
	}
	return 0;
}