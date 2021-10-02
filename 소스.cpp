#include <iostream>
#include <stdlib.h>
#include <algorithm>
#define MAX 30000

using namespace std;

extern int makeBlock(int module[][4][4]);

int main(void)
{
	static int module[MAX][4][4];

	srand(3); // 3 will be changed

	for (int tc = 1; tc <= 10; tc++)
	{
		for (int c = 0; c < MAX; c++)
		{
			int max_ = 1 + (rand() % 6);
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					module[c][y][x] = max_ + (rand() % 3);
				}
			}
		}
		cout << "#" << tc << " " << makeBlock(module) << endl;
	}

	return 0;
}


#define key 1111111111111111
typedef long long ll;

struct B {
	int num;
	ll shp;
	int max_;
	bool operator < (B ex) {
		if (ex.shp > shp) return true;
		else if (ex.shp == shp) return num < ex.num;
		else return false;
	}
	bool operator == (B ex) {
		if (ex.shp == shp) return true;
		else return false;
	}
	B &operator = (B ex) {
		num = ex.num;
		shp = ex.shp;
		max_ = ex.max_;
		return *this;
	}
};

B origin[30000 + 10];
B change_shp[30000 * 4 + 10];
int used_chk[30000 + 10];
B reset;

int BS(ll target) {
	int f = 0, r = 30000 * 4 - 1;
	int mid;
	while (f <= r) {
		mid = (f + r) / 2;
		if (change_shp[mid].shp == target)
			return change_shp[mid].num;//맞는 블록 고유 넘버 반환
		if (change_shp[mid].shp < target)
			f = mid + 1;
		else
			r = mid - 1;
	}
	return -1;//찾지 못했다.
}


B tmp_arr[30000 * 4];

void merge(int left, int mid, int right) {
	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right) {
		if ((change_shp[i] < change_shp[j]) || (change_shp[i] == change_shp[j])) {
			tmp_arr[k] = change_shp[i];
			i++;
		}
		else {
			tmp_arr[k] = change_shp[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (int m = j; m <= right; m++) {
			tmp_arr[k] = change_shp[m];
			k++;
		}
	}
	else {
		for (int m = i; m <= mid; m++) {
			tmp_arr[k] = change_shp[m];
			k++;
		}
	}
	for (int m = left; m <= right; m++) {
		change_shp[m] = tmp_arr[m];
	}
}
void merge_sort(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}


void init() {
	for (int i = 0; i < 30000*4; i++) {
		if (i < 30000) {
			used_chk[i] = 0;
			origin[i] = reset;
		}
		change_shp[i] = reset;
		tmp_arr[i] = reset;
	}
}
int makeBlock(int module[][4][4]) {
	int ans = 0;
	int block_cnt = 0;

	init();

	for (int i = 0; i < 30000; i++) {
		ll make_origin_shp = 0;
		ll make_reverse_shp = 0;
		ll mul = 1;
		int now_shp_tmp[4][4];
		int rotate_arr_tmp[4][4];
		int max_h = 0;
		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				make_origin_shp += module[i][3 - r][3 - c] * mul;
				mul *= 10;
				now_shp_tmp[r][3 - c] = module[i][r][c];
				max_h = max_h < module[i][r][c] ? module[i][r][c] : max_h;
			}
		}

		origin[i].num = i;
		origin[i].shp = make_origin_shp;
		origin[i].max_ = max_h;

		for (int rotate = 0; rotate < 4; rotate++) {
			for (int r = 0; r < 4; r++) {
				for (int c = 0; c < 4; c++) {
					rotate_arr_tmp[3 - c][r] = now_shp_tmp[r][c];
				}
			}
			mul = 1;
			make_reverse_shp = 0;
			for (int r = 0; r < 4; r++) {
				for (int c = 0; c < 4; c++) {
					make_reverse_shp += rotate_arr_tmp[r][c] * mul;
					mul *= 10;
					now_shp_tmp[r][c] = rotate_arr_tmp[r][c];
				}
			}

			change_shp[block_cnt].num = i;
			change_shp[block_cnt].shp = make_reverse_shp;
			change_shp[block_cnt].max_ = max_h;
			block_cnt++;
		}
	}
	//원래 블록들 모양 저장 and 회전시킨 비교군(뒤집은거) 저장완료

	//sort(change_shp, change_shp + 30000 * 4);
	
	merge_sort(0, 30000 * 4 - 1);

	for (int i = 0; i < 30000; i++) {
		ll match_block = (origin[i].max_ + 6)*key - origin[i].shp;//육면체를 만들수 있는 최대 높이 블록
		int match_block_max_h = 8;
		while (1) {
			int BS_result = BS(match_block);
			if (BS_result > -1) {//찾았다
				if (used_chk[BS_result] == 0 && BS_result != i) {//이 블록이 사용을 하지 않은 블록이면
					used_chk[BS_result] = -1;//블록 사용 체크
					used_chk[i] = -1;
					ans += match_block % 10 + origin[i].shp % 10;
					break;
				}
				else {//이미 사용된 블록
					match_block -= key;
					match_block_max_h--;
				}
			}
			else {//못찾음
				match_block -= key;
				match_block_max_h--;
			}
			if (match_block_max_h == 2) break;//최대 높이가 2이면 종료
		}
	}
	return ans;
}
