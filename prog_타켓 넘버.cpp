#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ans;

void dfs(int tar, int res, int dep, vector<int> num) {
    if (dep == num.size()) {
        ans += res == tar ? 1 : 0;
        return;
    }
    dfs(tar, res + num[dep], dep + 1, num);
    dfs(tar, res - num[dep], dep + 1, num);
}

int solution(vector<int> numbers, int target) {
    dfs(target, 0, 0, numbers);
    return ans;
}

int main() {
    vector<int> v = { 1, 1, 1, 1, 1 };
    int tar = 3;
    solution(v, tar);
    cout << ans;
    return 0;
}