#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	///*º°Âï±â2*/
	/*for (int i = N-1; i >= 0; i--) {
		for (int j = 0; j < i; j++) cout << ' ';
		for (int j = 0; j < N - i; j++) cout << '*';
		cout << '\n';
	}*/
	///*º°Âï±â3*/
	/*for (int i = N; i > 0; i--) {
		for (int j = 0; j < i; j++) cout << '*';
		cout << '\n';
	}*/
	///*º°Âï±â4*/
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) cout << ' ';
		for (int j = 0; j < N - i; j++) cout << '*';
		cout << '\n';
	}*/
	///*º°Âï±â5*/
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1 - i; j++) cout << ' ';
		for (int j = 0; j < i * 2 + 1; j++) cout << '*';
		cout << '\n';
	}*/
	///*º°Âï±â6*/
	/*for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) cout << ' ';
		for (int j = 0; j < (N - i) * 2 - 1; j++) cout << '*';
		cout << '\n';
	}*/
	///*º°Âï±â7*/
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1 - i; j++) cout << ' ';
		for (int j = 0; j < i * 2 + 1; j++) cout << '*';
		cout << '\n';
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) cout << ' ';
		for (int j = 0; j < (N - i) * 2 - 1; j++) cout << '*';
		cout << '\n';
	}*/
	///*º°Âï±â9*/
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) cout << ' ';
		for (int j = 0; j < (N - i) * 2 - 1; j++) cout << '*';
		cout << '\n';
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N - 1 - i; j++) cout << ' ';
		for (int j = 0; j < i * 2 + 1; j++) cout << '*';
		cout << '\n';
	}*/

}