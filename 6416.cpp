#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <string.h>
using namespace std;

int in[10000];
int out[10000];
bool node[10000];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int tc = 1;
	bool _PROGRAMEND_ = false;
	while (!_PROGRAMEND_) {
		int maxNode = -1;
		int minNode = INT_MAX;
		int edgeCnt = 0;
		int NodeCnt = 0;
		while (1) {
			int v, e;
			cin >> v >> e;
			if (v < 0 && e < 0) {
				_PROGRAMEND_ = true;
				break;
			}
			if (v == 0 && e == 0) {
				if (edgeCnt == 0) {
					cout << "Case " << tc++ << " is a tree.\n";
				}
				else {
					bool treeChk = true;
					int rootCnt = 0;
					for (int i = minNode; i <= maxNode; i++) {
						if (!node[i])continue;
						else NodeCnt++;
						if (in[i] == 0) rootCnt++;
						if (in[i] > 1 || rootCnt > 1) {
							treeChk = false;
							break;
						}
					}
					if (NodeCnt - 1 != edgeCnt) treeChk = false;
					if(treeChk) cout << "Case " << tc++ << " is a tree.\n";
					else cout << "Case " << tc++ << " is not a tree.\n";
				}
				break;
			}
			node[v] = node[e] = true;
			maxNode = max(maxNode, max(v, e));
			minNode = min(minNode, min(v, e));
			edgeCnt++;
			in[e]++;
			out[v]++;
		}
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(node, 0, sizeof(node));

	}
	return 0;
}