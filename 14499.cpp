#include <iostream>
using namespace std;

int N, M, X, Y, K;
int map[20][20];
int cube[4][3] = {
	{0,0,0},
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

bool range_chk(int r, int c) { return (0 <= r && r < N && 0 <= c && c < M) ? true : false; };
void move_E() {	int tmp = cube[1][0]; cube[1][0] = cube[3][1]; cube[3][1] = cube[1][2]; cube[1][2] = cube[1][1]; cube[1][1] = tmp; }
void move_W() {	int tmp = cube[1][0]; cube[1][0] = cube[1][1]; cube[1][1] = cube[1][2]; cube[1][2] = cube[3][1]; cube[3][1] = tmp; }
void move_N() {	int tmp = cube[0][1]; cube[0][1] = cube[1][1]; cube[1][1] = cube[2][1]; cube[2][1] = cube[3][1]; cube[3][1] = tmp; }
void move_S() {	int tmp = cube[0][1]; cube[0][1] = cube[3][1]; cube[3][1] = cube[2][1]; cube[2][1] = cube[1][1]; cube[1][1] = tmp; }

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> X >> Y >> K;
	for (int r = 0; r < N; r++) for (int c = 0; c < M; c++) cin >> map[r][c];
	for (int i = 0; i < K; i++) {
		int d; cin >> d;
		int nr = X + ("1102"[d - 1] - '1');
		int nc = Y + ("2011"[d - 1] - '1');
		if (!range_chk(nr, nc)) continue;
		X = nr; Y = nc;
		switch (d) {
		case 1: move_E(); break;
		case 2: move_W(); break;
		case 3: move_N(); break;
		case 4: move_S(); break;
		}
		int cube_bottom = cube[3][1], cube_top = cube[1][1];
		if (map[X][Y] == 0) { map[X][Y] = cube_bottom; }
		else { cube[3][1] = map[X][Y]; map[X][Y] = 0; }
		cout << cube_top << '\n';
	}
	return 0;
}