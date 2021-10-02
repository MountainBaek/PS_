/*16198번 에너지 모으기*/
#include <iostream>
#include <vector>
using namespace std;
vector<int>ball;
int N;
int Max_power, power_sum;

void power_gain(vector<int> v) {
	if (v.size() == 2) {
		if (Max_power < power_sum) Max_power = power_sum;
	}
	else {
		for (int i = 1; i < v.size()-1; i++) {
			power_sum += v.at(i - 1)*v.at(i + 1);
			int temp = v.at(i);
			v.erase(v.begin() + i, v.begin() + i + 1);
			power_gain(v);
			v.insert(v.begin() + i, temp);
			power_sum -= v.at(i - 1)*v.at(i + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		ball.push_back(a);
	}
	power_gain(ball);
	cout << Max_power;
}