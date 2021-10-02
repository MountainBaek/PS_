#include <iostream>
#include <vector>
#include <string>
#define TABLE_SIZE 400001
using namespace std;


struct info {
    string name;
    int cnt;
};

info table[TABLE_SIZE];

int hash_fnc(string str) {
    int seed = 401;
    unsigned long long hash = 0;
    /*for (int i = 0, size = str.size(); i < size; i++) 
        hash = (hash * seed) + str[i];*/
    for (int i = 0, size = str.size(); i < size; i++) {
        hash += (hash << 4) + str[i];
    }
    return hash % TABLE_SIZE;
}

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for (auto s : completion) {
        int res = hash_fnc(s);
        if (table[res].name == "") {
            table[res] = { s,1 };
        }
        else {
            table[res].cnt++;
        }
    }

    for (auto s : participant) {
        int res = hash_fnc(s);
        if (table[res].name != s) {
            answer = s;
            break;
        }
        else {
            if (table[res].cnt == 0) {
                answer = s;
                break;
            }
            else {
                table[res].cnt--;
            }
        }
    }

    return answer;
}

int main() {
    /*
    vector<string> p = { "marina", "josipa", "nikola", "vinko", "filipa" };
    vector<string> c = { "josipa", "filipa", "marina", "nikola" };
    */
    vector<string> p = { "aaaaaaaaa", "aaaaaaaaa", "aaaaaaaaa", "aaaaaaaaa", "aaaaaaaaa" };
    vector<string> c = { "aaaaaaaaa", "aaaaaaaaa", "aaaaaaaaa", "aaaaaaaaa" };

    string ans = solution(p, c);
    cout << '[' << ans << ']';
	return 0;
}