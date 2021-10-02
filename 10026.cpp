#include <iostream>
#include <queue>
#include <string>
using namespace std;
int N;
string Map[100];
int N_visit[100][100];
int CB_visit[100][100];
int drc[] = { 0,0,-1,1,-1,1,0,0 };
struct Point { int r, c; }temp;
queue<Point>N_Q,CB_Q;
int Red, Blue, Green;
int Red_Green;

void Normal() {
	while (!N_Q.empty()) {
		int rr = N_Q.front().r;
		int cc = N_Q.front().c;
		N_Q.pop();

	}
}
void Color_Blindness() {
	while (!CB_Q.empty()) {

	}
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Map[i];
		for (int j = 0; j == '\0'; j++) {
			if(Map[i][j]
		}
	}

	temp.r = temp.c = 0;
	N_Q.push(temp);
	CB_Q.push(temp);
	N_visit[0][0] = 1;
	CB_visit[0][0] = 1;

	Normal();
	Color_Blindness();

	cout << Red + Blue + Green << ' ' << Red_Green + Blue;
}