#include <iostream>
#include <string>
#include <vector>

#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    priority_queue<string> pq;

    for (int i = 0, size = tickets.size(); i < size; i++) {
        pq.push(tickets[i][0]);
        pq.push(tickets[i][1]);
    }

    int idx = 1;
    string arr[10000];
    
    while (!pq.empty()) {
        if (pq.top() == "ICN") arr[0] = pq.top();
        else arr[idx++] = pq.top();
        pq.pop();
    }

    sort(arr + 1, arr + idx);

    return answer;
}

int main() {

    return 0;
}