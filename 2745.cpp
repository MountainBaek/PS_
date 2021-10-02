#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string input;
int B, temp, q;
char tempc;

void convert() {
	for (int i = 0; i < input.length(); i++) {
		if (input[i] >= '0'&&input[i] <= '9') temp = temp + (input[i] - '0')*pow(B, i);
		else temp = temp + (input[i] - 'A' + 10)*pow(B, i);
	}
	return;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> input >> B;

	for (int i = 0; i < input.length() / 2; i++) {
		tempc = input[i];
		input[i] = input[input.length() - 1 - i];
		input[input.length() - 1 - i] = tempc;
	}
	convert();
	cout << temp;
}