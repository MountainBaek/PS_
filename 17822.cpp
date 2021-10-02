#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

deque<int>plate[51];
int table[51][51];
int N, M, T, remain_cnt, sum;

void spin(int x,int d,int k) { //반지름이 x배수 판을 d방향으로 k칸 회전
	for (int r = x; r <= N; r += x) {
		if (d == 0) {
			for (int i = 0; i < (k % M); i++) {
				int tmp = plate[r].back();
				plate[r].pop_back();
				plate[r].push_front(tmp);
			}
		}
		else {
			for (int i = 0; i < (k % M); i++) {
				int tmp = plate[r].front();
				plate[r].pop_front();
				plate[r].push_back(tmp);
			}
		}
	}
}

void adj_chk(int chk[51][51]) {
	bool adj = false;
	int tmp[51][51];
	for (int r = 1; r <= N; r++) {
		for (int i = 0; i < M; i++) {
			tmp[r][i] = plate[r].front();
			plate[r].pop_front();
		}
	}

	for (int r = 1; r <= N; r++) {
		for (int i = 0; i < M; i++) {
			if (tmp[r][i] == -1)continue;
			for (int d = 0; d < 4; d++) {
				int nr = r + ("2011"[d] - '1');
				int ni = i + ("1120"[d] - '1');
				if (nr < 1 || nr > N) continue;
				if (ni < 0) ni = M - 1;
				if (ni >= M) ni = 0;
				if (tmp[r][i] == tmp[nr][ni]) {
					adj = true;
					chk[r][i] = chk[nr][ni] = 1;
				}
			}
		}
	}

	if (adj) {//del
		for (int r = 1; r <= N; r++) {
			for (int i = 0; i < M; i++) {
				if (tmp[r][i] == -1)continue;
				if (chk[r][i] == 1) {
					sum -= tmp[r][i];
					remain_cnt--;
					tmp[r][i] = -1;
				}
			}
		}
	}
	else {//update
		double avg = (double)sum / (double)remain_cnt;
		for (int r = 1; r <= N; r++) {
			for (int i = 0; i < M; i++) {
				if (tmp[r][i] == -1)continue;
				if ((double)tmp[r][i] < avg) {
					tmp[r][i]++;
					sum++;
				}
				else if((double)tmp[r][i] > avg){
					tmp[r][i]--;
					sum--;
				}
			}
		}
	}

	for (int r = 1; r <= N; r++) for (int i = 0; i < M; i++) plate[r].push_back(tmp[r][i]);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> T;
	remain_cnt = N * M;
	for (int r = 1; r <= N; r++) {
		for (int j = 0; j < M; j++) {
			int in;
			cin >> in;
			plate[r].push_back(in);
			sum += in;
		}
	}
	
	for (int t = 0; t < T; t++) {
		int chk[51][51];
		memset(chk, 0, sizeof(chk));
		int x, d, k;
		cin >> x >> d >> k;
		if (x == 1) continue;
		spin(x, d, k);
		adj_chk(chk);
		
		//cout << "sum : " << sum << '\n';

		if (remain_cnt == 0) break;
	}

	cout << sum;
	return 0;
}