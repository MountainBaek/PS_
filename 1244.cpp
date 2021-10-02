#include <iostream>
using namespace std;

int N;
int sw[200];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> sw[i];
	}
	int stu;
	cin >> stu;
	for (int i = 0; i < stu; i++) {
		int sex, sw_num;
		cin >> sex >> sw_num;
		if (sex == 1) {
			for (int i = sw_num; i <= N; i += sw_num) {
				sw[i] = (sw[i] + 1) % 2;
			}
		}
		else {
			int i = 1;
			sw[sw_num] = (sw[sw_num] + 1) % 2;
			while (1) {
				if (1 <= sw_num - i && sw_num + i <= N) {
					if (sw[sw_num - i] == sw[sw_num + i]) {
						sw[sw_num + i] = (sw[sw_num + i] + 1) % 2;
						sw[sw_num - i] = (sw[sw_num - i] + 1) % 2;
					}
					else
						break;
				}
				else
					break;
				i++;
			}
		}
	
	}
	for (int i = 1; i <= N; i++) {
		cout << sw[i];
		if (i%20 == 0) cout << '\n';
		else cout << ' ';
	}
	return 0;
}