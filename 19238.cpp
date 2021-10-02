#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, Fuel;
int map[21][21];
struct PNT { int r, c; };
struct INFO { PNT start, arrival; int dist; };
bool operator<(PNT a, PNT b) {
	if (a.r > b.r) return true;
	else if (a.r == b.r) {
		if (a.c > b.c) return true;
		else return false;
	}
	else return false;
}
INFO pass[401];
PNT taxi;

bool range_chk(int r, int c) { return (1 <= r && r <= N && 1 <= c && c <= N) ? true : false; }

int res_dist(PNT start, PNT arrival) {
	queue<PNT>Q;
	int visit[21][21];	memset(visit, -1, sizeof(visit));
	visit[start.r][start.c] = 0;
	Q.push(start);
	while (!Q.empty()) {
		PNT now = Q.front(); Q.pop();
		for (int d = 0; d < 4; d++) {
			int nr = now.r + ("2011"[d] - '1');
			int nc = now.c + ("1120"[d] - '1');
			if (!range_chk(nr, nc) || map[nr][nc] == -1 || visit[nr][nc] != -1) continue;
			visit[nr][nc] = visit[now.r][now.c] + 1; Q.push({ nr,nc });
			if (arrival.r == nr && arrival.c == nc) return visit[nr][nc];
		}
	}
	return -1;
}

bool find_pass() { //taxi-->passenger
	if (map[taxi.r][taxi.c] != 0) {
		int pass_num = map[taxi.r][taxi.c];
		map[taxi.r][taxi.c] = 0;
		if (Fuel >= pass[pass_num].dist) {
			taxi = pass[pass_num].arrival;
			Fuel += pass[pass_num].dist;
			return true;
		}
		else return false;
	}

	queue<PNT>Q;
	int visit[21][21];	memset(visit, -1, sizeof(visit));
	visit[taxi.r][taxi.c] = 0;
	Q.push(taxi);
	while (!Q.empty()) {
		int size = Q.size();
		priority_queue<PNT>PQ;
		for (int i = 0; i < size; i++) {
			PNT now = Q.front(); Q.pop();
			for (int d = 0; d < 4; d++) {
				int nr = now.r + ("2011"[d] - '1');
				int nc = now.c + ("1120"[d] - '1');
				if (!range_chk(nr, nc) || map[nr][nc] == -1 || visit[nr][nc] != -1) continue;
				visit[nr][nc] = visit[now.r][now.c] + 1; Q.push({ nr,nc });
				if (map[nr][nc] > 0) PQ.push({ nr,nc });
			}
		}
		if (PQ.size() > 0) {
			PNT pass_pnt = PQ.top();
			int pass_num = map[pass_pnt.r][pass_pnt.c];
			int dist = visit[pass_pnt.r][pass_pnt.c];
			map[pass_pnt.r][pass_pnt.c] = 0;
			if (dist <= Fuel) {
				taxi = pass_pnt;
				Fuel -= dist;
			}
			else return false;
			
			if (Fuel >= pass[pass_num].dist) {
				taxi = pass[pass_num].arrival;
				Fuel += pass[pass_num].dist;
			}
			else return false;

			return true;
		}
	}
	return false;
}

void service() {
	int is_fail = false;
	for (int i = 0; i < M; i++) {
		if (!find_pass()) { is_fail = true; break; }
	}
	if (is_fail) cout << -1;
	else cout << Fuel;
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> Fuel;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int in; cin >> in; 
			map[r][c] = in * -1;
		}
	}
	int a, b, c, d;
	cin >> a >> b;
	taxi = { a,b };
	bool flag = true;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b >> c >> d;
		int res = res_dist({ a,b }, { c,d });
		if (res == -1) {
			flag = false;
			break;
		}
		pass[i] = { {a,b},{c,d},res };
		map[a][b] = i;
	}
	if (flag) service();
	else cout << -1;
	return 0;
}