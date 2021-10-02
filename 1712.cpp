#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int A, B, C;
	cin >> A >> B >> C;
	if (C - B <= 0) cout << -1;
	else cout << A / (C - B) + 1;
	return 0;
}

/*
매년
고정비용 : 임대료 + 재산세 + 보험료 + 금여 + @
가변비용 : 재료비 + 인건비 + @

ex) 
고정비용 1000만원
가변비용 70만원

--> 100대 생산 = 1000만 + 70*100 = 8000
--> 10대 생산  = 1000만 + 70*10  = 1700

노트북 가격 C만원

어느순간 총비용 (고정 + 가변) < 판매비용 --> 이 시점을 손익분기점

A + (B*X) < C*X
A < (C-B)*X
A/(C-B) < X

-> 1000 / (170 - 70) < X 
 = 10 < X

 ans --> A/(C-B) +1 ?

 3/1-2 = -3 ?

 A 1000 B 70 C 70 X 판매량
 x=1 
 

*/