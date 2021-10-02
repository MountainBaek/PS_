#include <iostream>
#include <queue>
using namespace std;
int A, B, N, M;//가로(열), 세로(행), 로봇 수, 명령어 수
int Map[101][101];
struct Robot { int r, c, dir; }Rbt[101];//로봇 방향 저장, 배열의 번호 = 로봇 넘버 (1번째 배열부터 사용)
struct Commend { int R_num; char commd; int times; }temp;
queue<Commend>Q;
int select_R, crashed_R;
bool crash_flag = 0;
int chk(int r_num, int r, int c) { //반환값 0 : 정상 , 1:벽충돌, 2:로봇끼리 충돌
	select_R = r_num;
	if (!(r<1 || r>B || c<1 || c>A)) {
		for (int i = 1; i <= N; i++) {
			if (i != r_num) {
				if (Rbt[i].r == r && Rbt[i].c == c) {
					crashed_R = i;
					crash_flag = 1;
					cout << "Robot " << select_R << " crashes into robot " << crashed_R << endl;
					return 2;
				}
			}
		}
		return 0;
	}
	else {	
		crash_flag = 1;
		cout << "Robot " << select_R << " crashes into the wall" << endl;
		return 1;
	}
}

void go(int num, char comd, int times) {
	if(comd=='F'){
		for (int i = 0; i < times; i++) {
			int chk_result;
			switch (Rbt[num].dir) {
			case 0:
				chk_result = chk(num, Rbt[num].r - 1, Rbt[num].c);
				if (chk_result != 0) { return; }
				else { Rbt[num].r--; }
				break;
			case 1:
				chk_result = chk(num, Rbt[num].r, Rbt[num].c + 1);
				if (chk_result != 0) { return; }
				else { Rbt[num].c++; }
				break;
			case 2:
				chk_result = chk(num, Rbt[num].r + 1, Rbt[num].c);
				if (chk_result != 0) { return; }
				else { Rbt[num].r++; }
				break;
			case 3:
				chk_result = chk(num, Rbt[num].r, Rbt[num].c - 1);
				if (chk_result != 0) { return; }
				else { Rbt[num].c--; }
				break;
			}
		}
	}
	else {
		int mod4 = times % 4;
		if (comd == 'R') {
			switch (mod4){
			case 1: Rbt[num].dir = (Rbt[num].dir + 1) % 4; break;
			case 2: Rbt[num].dir = (Rbt[num].dir + 2) % 4; break;
			case 3: Rbt[num].dir = (Rbt[num].dir + 3) % 4; break;
			}
		}
		else {
			switch (mod4) {
			case 3: Rbt[num].dir = (Rbt[num].dir + 1) % 4; break;
			case 2: Rbt[num].dir = (Rbt[num].dir + 2) % 4; break;
			case 1: Rbt[num].dir = (Rbt[num].dir + 3) % 4; break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> A >> B;
	cin >> N >> M;
	int x, y, R_num, times;
	char d, comd;
	for (int i = 1; i <= N; i++) {
		cin >> x >> y >> d;
		Map[B - y + 1][x] = i;
		Rbt[i].r = B - y + 1;
		Rbt[i].c = x;
		switch (d)	{
		case 'N':Rbt[i].dir = 0; break;
		case 'E':Rbt[i].dir = 1; break;
		case 'S':Rbt[i].dir = 2; break;
		case 'W':Rbt[i].dir = 3; break;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> R_num >> comd >> times;
		temp = { R_num,comd,times };
		Q.push(temp);
	}
	while (!Q.empty()) {
		go(Q.front().R_num,Q.front().commd,Q.front().times);
		Q.pop();
		if (crash_flag != 0) break;
	}
	if (crash_flag == 0) cout << "OK" << endl;
}