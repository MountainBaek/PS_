#include <iostream>
#include <vector>
using namespace std;
vector<int>tree[10];
char color[10];
bool visit[10];
int cnt;
int SIZE;
void c(int idx) {
	if (idx > SIZE) {
		for (int i = 1; i <= SIZE; i++) {
			for (int j = 0; j < tree[i].size(); j++) {
				if (color[i] == 'B' && color[tree[i][j]] == 'B')return;
			}
		}
		cnt++;
		for (int i = 1; i <= SIZE; i++)
			cout << color[i] << ' ';
		cout << '\n';
		return;
	}
	color[idx] = 'B';
	c(idx + 1);
	color[idx] = 'W';
	c(idx + 1);
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	/*tree[1].push_back(2);
	tree[2].push_back(3);
	tree[2].push_back(4);*/

	/*tree[1].push_back(2);
	tree[2].push_back(3);
	tree[2].push_back(4);
	tree[4].push_back(5);*/

	/*tree[1].push_back(2);
	tree[2].push_back(3);
	tree[2].push_back(4);
	tree[4].push_back(5); 
	tree[3].push_back(6);*/

	/*tree[1].push_back(2);
	tree[2].push_back(3);
	tree[2].push_back(4);
	tree[3].push_back(5);
	tree[3].push_back(6);*/

	/*SIZE = 5;
	tree[1].push_back(2);
	tree[2].push_back(3);
	tree[2].push_back(4);
	tree[2].push_back(5);*/

	/*SIZE = 3;
	tree[1].push_back(2);
	tree[1].push_back(3);*/

	/*SIZE = 6;
	tree[1].push_back(2);
	tree[2].push_back(3);
	tree[2].push_back(4);
	tree[2].push_back(5);
	tree[2].push_back(6);*/

	SIZE = 4;
	tree[1].push_back(2);
	tree[1].push_back(3);
	tree[1].push_back(4);

	c(1);
	cout << cnt;
	return 0;
}