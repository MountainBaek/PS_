/*1037¹ø ¾à¼ö*/
#include <iostream>
#include <algorithm>
using namespace std;
int div_cnt;
int divisor[50];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> div_cnt;
	for (int i = 0; i < div_cnt; i++) cin >> divisor[i];
	sort(divisor, divisor + div_cnt);
	cout << divisor[0] * divisor[div_cnt - 1];
}