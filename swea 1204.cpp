#include <iostream>
#define ios_ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define max(a,b) a<b?b:a
#define enter '\n'
using namespace std;

int main() {
	ios_;
	int T;
	cin >> T;
	while (T--) {
		int score_[101] = { 0, };
		int case_num;
		cin >> case_num;
		int stu_ = 100;
		while (stu_--) {
			score_[stu_]++;
		}
		int max_ = 0;
		for (int i = 1; i <= 100; i++) {
			max_ = max(score_[i], max_);
		}
		cout << '#' << case_num << " " << max_ << enter;
	}
}