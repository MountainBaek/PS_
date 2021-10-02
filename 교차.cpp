#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
struct line {
	pii S, E;
};

int ccw(pii a, pii b, pii c) {
	int t1 = a.first*b.second + b.first*c.second + c.first*a.second;
	int t2 = a.second*b.first + b.second*c.first + c.second*a.first;
	int ans = t1 - t2;
	if (ans < 0) return -1;
	else if (ans == 0) return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		line l;
		vector<line>sq;
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		l = { {sx,sy},{ex,ey} };
		int lx, ty, rx, by;
		cin >> lx >> ty >> rx >> by;
		sq.push_back({ {lx,ty},{rx,ty} });
		sq.push_back({ {lx,ty},{lx,by} });
		sq.push_back({ {rx,by},{rx,ty} });
		sq.push_back({ {rx,by},{lx,by} });

		bool OK = true;
		for (int i = 0; i < 4; i++) {
			pii s1, s2;
			s1 = sq[i].S;
			s2 = sq[i].E;

			if (ccw(l.S, l.E, s1) * ccw(l.S, l.E, s2) <= 0 && ccw(s1, s2, l.S)*ccw(s1, s2, l.E) <= 0) {
				if (ccw(l.S, l.E, s1) * ccw(l.S, l.E, s2) == 0 && ccw(s1, s2, l.S)*ccw(s1, s2, l.E) == 0) {
					if (l.S > l.E) swap(l.S, l.E);
					if (s1 > s2)swap(s1, s2);
					if ((s1 < l.S && s2 < l.S) || (s1 > l.E && s2 > l.E)) {
						continue;
					}
				}
				OK = false;
				break;
			}
		}

		//사각형 내부 확인
		if (lx > rx) swap(lx, rx);
		if (by > ty) swap(by, ty);

		bool inside = true;
		if (!(lx <= sx && sx <= rx)) inside = false;
		if (!(lx <= ex && ex <= rx)) inside = false;
		if (!(by <= sy && sy <= ty)) inside = false;
		if (!(by <= ey && ey <= ty)) inside = false;
		
		if (inside == true) OK = false;
		if (OK == true) cout << "F\n";
		else cout << "T\n";
	}

	return 0;
}