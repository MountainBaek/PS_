/*2609번 최대 공약수와 최소 공배수*/
#include <iostream>
using namespace std;
int num1, num2, gcm;

int GCM(int n1, int n2) {
	if (n1%n2 == 0) return n2;
	else return GCM(n2, n1%n2);
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> num1 >> num2;
	gcm = num1 > num2 ? GCM(num1, num2) : GCM(num2, num1);
	cout << gcm << '\n' << num1 * num2 / gcm;
}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int max_div, min_mult = 1;
//int num1, num2, div_n = 2;
//int input[2];//입력 받은 두 수
//vector< vector<int> >div_num;
//
//bool desc(int a, int b) {
//	return a > b;
//}
//int main() {
//	ios::sync_with_stdio(0), cin.tie(0);
//	cin >> input[0] >> input[1];
//	for (int i = 0; i < 2; i++) {
//		vector<int>temp;
//		for (int j = 1; j*j < input[i]; j++) {
//			if (input[i] % j == 0) {
//				temp.push_back(j);
//				temp.push_back(input[i] / j);
//			}
//		}
//		div_num.push_back(temp);
//	}
//
//	for (int i = 0; i < 2; i++) sort(div_num[i].begin(), div_num[i].end(), desc);//내림차순 정렬
//	//최대 공약수
//	for (int i = 0; i < div_num[0].size(); i++) {
//		for (int j = 0; j < div_num[1].size(); j++) {
//			if (div_num[0][i] == div_num[1][j]) { //비교 하다가 같은 수를 만나면 반복 종료
//				max_div = div_num[0][i];
//				break;
//			}
//		}
//		if (max_div != 0)break;//최대 공약수를 구했으면 반복 종료
//	}
//	//최소 공배수
//	num1 = input[0];
//	num2 = input[1];
//	while (1) {
//		if (num1 % div_n == 0 && num2 % div_n == 0) {// 두 수가 동시에 나눠질 때
//			min_mult *= div_n;
//			num1 /= div_n;
//			num2 /= div_n;
//		}
//		else {//나눠 지지 않을 때
//			if (div_n < num1 || div_n < num2) div_n++; // 아직 나누는 수보다 남은 수들이 클때는 나누는 수를 증가시켜준다.
//			else {//남은 수들이 같거나 작으면 남은 수들도 곱해준다.
//				min_mult = min_mult * num1*num2;
//				break;
//			}
//		}
//	}
//	cout << max_div << '\n' << min_mult;
//}