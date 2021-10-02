#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> table;
    for (auto s : completion) {
        auto it = table.find(s);
        if (it == table.end()) table.insert({ s, 1 });
        else it->second++;
    }

    for (auto s : participant) {
        auto it = table.find(s);
        if (it == table.end()) {
            answer = s;
            break;
        }
        else {
            it->second--;
            if (it->second == 0) table.erase(it);
        }
    }
    return answer;
}

int main() {

    
   vector<string> p = { "marina", "josipa", "nikola", "vinko", "filipa" };
   vector<string> c = { "josipa", "filipa", "marina", "nikola" };
   

    //vector<string> p = { "aaaaaaaaa", "aaaaaaaaa", "aaaaaaaaa", "aaaaaaaaa", "aaaaaaaaa" };
    //vector<string> c = { "aaaaaaaaa", "aaaaaaaaa", "aaaaaaaaa", "aaaaaaaaa" };

    string ans = solution(p, c);
    cout << '[' << ans << ']';
    return 0;
}