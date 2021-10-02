#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
struct pib { int first; bool second; };
int N;
int map[20][20], arr[20][20];
int sweepDir[5];//0:상 1:하 2:좌 3:우
int ans;

void sweepU() {
	for (int c = 0; c < N; c++) {
		stack<pib>res;
		
		for (int r = 0; r < N; r++) {
			if (arr[r][c] != 0 && res.empty()) {
				res.push({ arr[r][c], false });
				arr[r][c] = 0;
				continue;
			}
			if (res.empty()) continue;
			pib prev = res.top();
			if (prev.first == arr[r][c] && !prev.second) {
				res.pop();
				res.push({ prev.first * 2, true });
			}
			else {
				if (arr[r][c] != 0)
					res.push({ arr[r][c],false });
			}
			arr[r][c] = 0;
		}
		
		int r = res.size() - 1;
		while (!res.empty()) {
			arr[r][c] = res.top().first;
			ans = ans < arr[r][c] ? arr[r][c] : ans;
			r--;
			res.pop();
		}
	}
}

void sweepD() {
	for (int c = 0; c < N; c++) {
		stack<pib>res;
		for (int r = N - 1; r >= 0; r--) {
			if (arr[r][c] != 0 && res.empty()) {
				res.push({ arr[r][c], false });
				arr[r][c] = 0;
				continue;
			}
			if (res.empty()) continue;
			pib prev = res.top();
			if (prev.first == arr[r][c] && !prev.second) {
				res.pop();
				res.push({ prev.first * 2,1 });
			}
			else {
				if(arr[r][c]!=0)
					res.push({ arr[r][c],0 });
			}
			arr[r][c] = 0;
		}
		
		int r = N - res.size();

		while (!res.empty()) {
			arr[r][c] = res.top().first;
			ans = ans < arr[r][c] ? arr[r][c] : ans;
			r++;
			res.pop();
		}
	}
}

void sweepR() {
	for (int r = 0; r < N; r++) {
		stack<pib>res;
		for (int c = 0; c < N; c++) {
			if (arr[r][c] != 0 && res.empty()) {
				res.push({ arr[r][c], false });
				arr[r][c] = 0;
				continue;
			}
			if (res.empty()) continue;
			pib prev = res.top();
			if (prev.first == arr[r][c] && !prev.second) {
				res.pop();
				res.push({ prev.first * 2,1 });
			}
			else {
				if (arr[r][c] != 0)
					res.push({ arr[r][c],0 });
			}
			arr[r][c] = 0;
		}
		
		int c = res.size() - 1;
		while (!res.empty()) {
			arr[r][c] = res.top().first;
			ans = ans < arr[r][c] ? arr[r][c] : ans;
			c--;
			res.pop();
		}
	}
}

void sweepL() {
	for (int r = 0; r < N; r++) {
		stack<pib>res;
		for (int c = N - 1; c >= 0; c--) {
			if (arr[r][c] != 0 && res.empty()) {
				res.push({ arr[r][c], false });
				arr[r][c] = 0;
				continue;
			}
			if (res.empty()) continue;
			pib prev = res.top();
			if (prev.first == arr[r][c] && !prev.second) {
				res.pop();
				res.push({ prev.first * 2,1 });
			}
			else {
				if (arr[r][c] != 0)
					res.push({ arr[r][c],0 });
			}
			arr[r][c] = 0;
		}
		
		int c = N - res.size();
		while (!res.empty()) {
			arr[r][c] = res.top().first;
			ans = ans < arr[r][c] ? arr[r][c] : ans;
			c++;
			res.pop();
		}
	}
}


void play() {
	memcpy(arr, map, sizeof(map));
	for (int i = 0; i < 5; i++) {
		if (sweepDir[i] == 0)
			sweepU();
		else if (sweepDir[i] == 1)
			sweepD();
		else if (sweepDir[i] == 2) 
			sweepR();
		else if (sweepDir[i] == 3) 
			sweepL();
	}
}

void set(int dep) {
	if (dep == 5) {
		play();//게임 실행
		return;
	}
	for (int d = 0; d < 4; d++) {
		sweepDir[dep] = d;
		set(dep + 1);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> map[r][c];
		}
	}

	set(0);

	cout << ans;
	return 0;
}