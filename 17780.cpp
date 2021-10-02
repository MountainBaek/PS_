/*17780�� ���ο� ����*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;//== vector< vector<vi> > == vector< vector< vector<int> > > >

struct info { int r, c, dir; };
struct pnt { int r, c; };
info rb[11];
pnt drc[5] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };
vvvi Map(13, vvi(13));
int board[13][13];
int N, K, end_flag, _time;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> board[r][c];
		}
	}

	for (int i = 1; i <= K; i++) {
		int r, c, d;
		cin >> r >> c >> d;
		rb[i] = { r,c,d };
		Map[r][c].push_back(i);
	}

	while (end_flag == 0) {
		_time++;
		for (int num = 1; num <= K; num++) {
			//num�κ��� ��ġã��
			int now_r = rb[num].r;
			int now_c = rb[num].c;
			int now_dir = rb[num].dir;

			/*���� ���迡���� num�κ��� ��ġ�� ���� �Ʒ� ���ο� ������� 
			���ʰ� �Ǹ� num�κ��� ���� ���� �κ����� �̵�*/
			//num�κ��� ���� �Ʒ��� �ƴϸ� ���� �κ� ����
			if (Map[now_r][now_c][0] != num) continue;

			//num�κ��� ���� ��ġ�� ���� �ִ��� Ȯ��
			int next_r = now_r + drc[now_dir].r;
			int next_c = now_c + drc[now_dir].c;

			//���� �ۿ� ����� �ݴ� �������� ��ȯ
			if (next_r < 1 || next_c < 1 || next_r > N || next_c > N) {
				if (now_dir == 1) rb[num].dir = 2;
				else if (now_dir == 2) rb[num].dir = 1;
				else if (now_dir == 3) rb[num].dir = 4;
				else if (now_dir == 4) rb[num].dir = 3;
			}
			//���̸� �ݴ� �������� ��ȯ
			if (board[next_r][next_c] == 2) {
				if (now_dir == 1) rb[num].dir = 2;
				else if (now_dir == 2) rb[num].dir = 1;
				else if (now_dir == 3) rb[num].dir = 4;
				else if (now_dir == 4) rb[num].dir = 3;
			}

			now_dir = rb[num].dir;
			next_r = now_r + drc[now_dir].r;
			next_c = now_c + drc[now_dir].c;

			//���� ��ȯ �Ŀ��� ���̳� ���� ���̸� ���� �κ� ����
			if (next_r < 1 || next_c < 1 || next_r > N || next_c > N) continue;
			if (board[next_r][next_c] == 2) continue;

			//�̵�
			if (board[next_r][next_c] == 0) {
				for (int i = 0; i < Map[now_r][now_c].size(); i++) {
					Map[next_r][next_c].push_back(Map[now_r][now_c][i]);
					rb[Map[now_r][now_c][i]].r = next_r;
					rb[Map[now_r][now_c][i]].c = next_c;
				}
				Map[now_r][now_c].clear();
			}
			else {//����ĭ�� ��
				for (int i = Map[now_r][now_c].size() - 1; i >= 0; i--) {
					Map[next_r][next_c].push_back(Map[now_r][now_c][i]);
					rb[Map[now_r][now_c][i]].r = next_r;
					rb[Map[now_r][now_c][i]].c = next_c;
				}
				Map[now_r][now_c].clear();
			}
			
			//�̵��� ������ ��, �κ��� 4�� �̻� �׿����� Ȯ��
			if (Map[next_r][next_c].size() >= 4) {
				end_flag = 1;
				break;
			}
		}
	
		if (_time > 1000) {
			_time = -1;
			break;
		}
	}
	cout << _time;
	return 0;
}