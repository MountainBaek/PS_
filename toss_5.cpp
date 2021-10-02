#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	vector<int>Kim;
	vector<int>Lee;
	
	char input1[100];
	char input2[100];

	cin.getline(input1, 100);
	cin.getline(input2, 100);

	char* split1 = strtok(input1, " ");
	while (split1 != NULL) {
		Kim.push_back(stoi(split1));
		split1 = strtok(NULL, " ");
	}
	char* split2 = strtok(input2, " ");
	while (split2 != NULL) {
		Lee.push_back(stoi(split2));
		split2 = strtok(NULL, " ");
	}
	int Lee_tmp = 0;
	for (int i = 0, size = Kim.size(); i < size; i++) {
		if (Kim[i] - Lee[i] > 0) {
			if (Kim[i] - Lee[i] <= Lee_tmp) {
				cout << "0 ";
				Lee_tmp -= (Kim[i] - Lee[i]);
			}
			else {
				cout << Kim[i] - Lee[i] - Lee_tmp << ' ';
				Lee_tmp = 0;
			}
		}
		else if(Kim[i] - Lee[i] < 0){
			cout << "0 ";
			Lee_tmp += Lee[i] - Kim[i];
		}
		else cout << "0 ";
	}

	return 0;
}