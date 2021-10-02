/*13458번 시험 감독*/
#include <iostream>
using namespace std;
int N, B, C;
int room[1000000];
long ALL_Manager;
long subManager;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> room[i];
	}
	cin >> B >> C;
	ALL_Manager = N;
	for (int i = 0; i < N; i++) {
		long subable = room[i] - B;
		if (subable < 0) subable = 0;
		subManager = subable / C;
		if ((subable % C) != 0) { subManager++; }
		ALL_Manager = ALL_Manager + subManager;
	}

	cout << ALL_Manager;
}