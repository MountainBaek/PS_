#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int dice[10];
int playerOdr[10];
int playerLoc[5];
vector<int> List[32];
const int map[33] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,13,16,19,22,24,28,27,26,25,30,35,0 };
bool mapVisit[33];
const int startIdx = 0, finIdx = 32;
const int N = 10;
int ans;

void init() {
	for (int i = 0; i < N; i++)
		cin >> dice[i];

	for (int i = startIdx; i < 20; i++)
		List[i].push_back(i + 1);
	List[20].push_back(finIdx);
	
	//List[5].push_back(21);
	List[21].push_back(22);
	List[22].push_back(23);
	List[23].push_back(29);

	//List[10].push_back(24);
	List[24].push_back(25);
	List[25].push_back(29);

	//List[15].push_back(26);
	List[26].push_back(27);
	List[27].push_back(28);
	List[28].push_back(29);

	List[29].push_back(30);
	List[30].push_back(31);
	List[31].push_back(20);
}

int Play(int sloc, int diceNum) {
	int go = diceNum;
	int loc = sloc;
	while (go) {
		if (loc == 5 && go == diceNum)
			loc = 21;
		else if (loc == 10 && go == diceNum)
			loc = 24;
		else if (loc == 15 && go == diceNum)
			loc = 26;
		else
			loc = List[loc][0];
		if (loc == finIdx)break;
		go--;
	}
	return loc;
}

void perm(int idx) {
	if (idx == N) {
		memset(playerLoc, 0, sizeof(playerLoc));
		memset(mapVisit, 0, sizeof(mapVisit));
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			int player = playerOdr[i];
			int nowLoc = playerLoc[player];
			if (nowLoc == finIdx) return; // 현 위치가 도착점이면 다음 순서
			int movedLoc = Play(nowLoc, dice[i]);// 다음위치 구하기
			if (mapVisit[movedLoc]) return;//다음위치에 다른 말이 있으면 다음 순서
			playerLoc[player] = movedLoc;
			if(movedLoc != finIdx)
				mapVisit[movedLoc] = true;
			mapVisit[nowLoc] = false;
			
			tmp += map[movedLoc];
		}
		ans = max(ans, tmp);
		return;
	}
	for (int i = 1; i <= 4; i++) {
		playerOdr[idx] = i;
		perm(idx + 1);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	init();
	perm(0);
	cout << ans;
	return 0;
}