#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int T;
vector<int> smt(29,0);// 1-28 까지 사용
vector<int> errSmt(29, 0);
int visit[29];
int numb[4];
int transTime, min_t = 1440;
//1-7 세그먼트로 numb[1]생성
//8-14 세그먼트로 numb[2]
//15-21 세그먼트로 numb[3]
//22-28 세그먼트로 numb[4]
int makeNum(int i) {
	if (smt[i * 7 + 1] == 0 && smt[i * 7 + 2] == 0 && smt[i * 7 + 3] == 0 && smt[i * 7 + 4] == 0 && smt[i * 7 + 5] == 1 && smt[i * 7 + 6] == 1 && smt[i * 7 + 7] == 0) return 1;

	else if (smt[i * 7 + 1] == 1 && smt[i * 7 + 2] == 0 && smt[i * 7 + 3] == 1 && smt[i * 7 + 4] == 1 && smt[i * 7 + 5] == 0 && smt[i * 7 + 6] == 1 && smt[i * 7 + 7] == 1) return 2;
	
	else if (smt[i * 7 + 1] == 1 && smt[i * 7 + 2] == 0 && smt[i * 7 + 3] == 0 && smt[i * 7 + 4] == 1 && smt[i * 7 + 5] == 1 && smt[i * 7 + 6] == 1 && smt[i * 7 + 7] == 1) return 3;
	
	else if (smt[i * 7 + 1] == 0 && smt[i * 7 + 2] == 1 && smt[i * 7 + 3] == 0 && smt[i * 7 + 4] == 0 && smt[i * 7 + 5] == 1 && smt[i * 7 + 6] == 1 && smt[i * 7 + 7] == 1) return 4;
	
	else if (smt[i * 7 + 1] == 1 && smt[i * 7 + 2] == 1 && smt[i * 7 + 3] == 0 && smt[i * 7 + 4] == 1 && smt[i * 7 + 5] == 1 && smt[i * 7 + 6] == 0 && smt[i * 7 + 7] == 1) return 5;
	
	else if (smt[i * 7 + 1] == 1 && smt[i * 7 + 2] == 1 && smt[i * 7 + 3] == 1 && smt[i * 7 + 4] == 1 && smt[i * 7 + 5] == 1 && smt[i * 7 + 6] == 0 && smt[i * 7 + 7] == 1) return 6;
	
	else if (smt[i * 7 + 1] == 1 && smt[i * 7 + 2] == 0 && smt[i * 7 + 3] == 0 && smt[i * 7 + 4] == 0 && smt[i * 7 + 5] == 1 && smt[i * 7 + 6] == 1 && smt[i * 7 + 7] == 0) return 7;
	
	else if (smt[i * 7 + 1] == 1 && smt[i * 7 + 2] == 1 && smt[i * 7 + 3] == 1 && smt[i * 7 + 4] == 1 && smt[i * 7 + 5] == 1 && smt[i * 7 + 6] == 1 && smt[i * 7 + 7] == 1) return 8;
	
	else if (smt[i * 7 + 1] == 1 && smt[i * 7 + 2] == 1 && smt[i * 7 + 3] == 0 && smt[i * 7 + 4] == 1 && smt[i * 7 + 5] == 1 && smt[i * 7 + 6] == 1 && smt[i * 7 + 7] == 1) return 9;
	
	else if (smt[i * 7 + 1] == 1 && smt[i * 7 + 2] == 1 && smt[i * 7 + 3] == 1 && smt[i * 7 + 4] == 1 && smt[i * 7 + 5] == 1 && smt[i * 7 + 6] == 1 && smt[i * 7 + 7] == 0) return 0;
	
	else return -1;
}
void error(int e) {
	int x = e;
	if (x > 0) {
		for (int i = 1; i < 29; i++) {
			if (visit[i] == 0) {
				if (smt[i] == 0) smt[i]++;
				else if (smt[i] == 1) smt[i]--;
				visit[i] = 1;
				x--;
				error(x);
				x++;
				visit[i] = 0;
				if (smt[i] == 0) smt[i]++;
				else if (smt[i] == 1) smt[i]--;
			}
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			int chk = makeNum(i);
			if (chk != -1) numb[i] = makeNum(i);
			else {
				for (int i = 0; i < 4; i++) numb[i] = 9;
				break;
			}
		}
		transTime = numb[0] * 10 * 60 + numb[1] * 60 + numb[2] * 10 + numb[3];
		if (min_t >= transTime) min_t = transTime;
		return;
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int t = 1; t < T + 1; t++) {
		for (int i = 1; i < 29; i++) {
			cin >> smt[i];
		}
		for (int e = 0; e < 3; e++) {
			error(e);
		}
		cout << '#' << t << ' ' << min_t / 60 << ' ' << min_t % 60<<'\n';
		min_t = 1440;
		memset(visit, 0, sizeof(visit));
	}
}