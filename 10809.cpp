#include <iostream>
#include <string.h>
using namespace std;
int arr[26];
char input[100];
int main() {
	memset(arr, -1, sizeof(arr));
	cin >> input;
	for(int s=0;input[s];s++){
		if (arr[input[s] - 'a'] != -1)continue;
		arr[input[s] - 'a'] = s;
		

	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << ' ';
	}
}