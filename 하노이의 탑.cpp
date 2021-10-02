#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct info { int a, b; };
vector<info>out;
int N;
long long move_cnt;

void hanoi(int cnt,int start, int via, int end) {
	if (cnt == 1) {
		out.push_back({ start,end });
		return;
	}
	else {
		hanoi(cnt - 1, start, end, via);
		out.push_back({ start,end });
		hanoi(cnt - 1, via, start, end);
	}

}

string BigNum(string A,string B) {
	string result;

	return result;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N;
	if (N <= 20) {
		hanoi(N, 1, 2, 3);
		cout << out.size() << '\n';
		for (int i = 0; i < out.size(); i++)
			cout << out[i].a << ' ' << out[i].b << '\n';
		out.clear();
	}
	else {

	}

	return 0;
}