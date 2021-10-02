#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int>conv;
    while(n > 0) {
        conv.push_back(n % 3);
        n /= 3;
    }
    int a = 1;
    for (int i = conv.size() - 1; i >= 0; i--) {
        answer += (a * conv[i]);
        a *= 3;
    }
    return answer;
}

int main() {
    cout << solution(45);
}