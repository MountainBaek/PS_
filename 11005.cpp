#include <iostream>
#include <string.h>
using namespace std;
int temp[30];
int input, B, q, r, x;
char out;

int main() {
	memset(temp, -1, sizeof(temp));
	cin >> input >> B;
	while (input != 0) {
		temp[x] = input % B;
		input = input / B;
		x++;
	}
	
	for (int i = 29; i >= 0; i--) {
		if (temp[i] != -1) {
			if (temp[i] >= 10) {
				out = 'A' + (temp[i] - 10);
				cout << out;
			}
			else {
				cout << temp[i];
			}
		}
	}
}