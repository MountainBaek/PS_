#include <iostream>
#include <string>
using namespace std;
struct info {
	string num;
	int S, B;
};
int num[] = { 1,2,3,4,5,6,7,8,9 };
bool sel[9];
info list[100];
int N, ans;

string tmp;
void makeNum(int dep) {
	if (dep == 3) {
		bool OK = true;
		for (int i = 0; i < N; i++) {
			int Stk = 0, Ball = 0;
			for (int l = 0; l < 3; l++) {
				for (int t = 0; t < 3; t++) {
					if (tmp[t] == list[i].num[l]) {
						if (l == t) Stk++;
						else Ball++;
					}
				}
			}
			if (!(Stk == list[i].S && Ball == list[i].B)) {
				OK = false;
				break;
			}
		}
		if (OK == true) ans++;
		return;
	}
	else {
		for (int i = 0; i < 9; i++) {
			if (sel[i] == true)continue;
			sel[i] = true;
			tmp += to_string(num[i]);
			makeNum(dep + 1);
			tmp.pop_back();
			sel[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string n;
		int s, b;
		cin >> n >> s >> b;
		list[i] = { n,s,b };
	}
	makeNum(0);
	cout << ans;
	return 0;
}