#include <iostream>
#include <string.h>
#include <string>
#include <stack>
using namespace std;
struct COMD {
	char cmd;
	int label;
};
int memory[100005];
COMD command[5000], arr[5000];
int memory_size, command_size, input_size;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		memset(memory, 0, sizeof(memory));
		memcpy(command, arr, sizeof(arr));
		cin >> memory_size >> command_size >> input_size;
		stack<int>loopIdx;
		for (int i = 0; i < command_size; i++) {
			cin >> command[i].cmd;
			if (command[i].cmd == '[')
				loopIdx.push(i);
			else if (command[i].cmd == ']') {
				command[i].label = loopIdx.top();
				command[loopIdx.top()].label = i;
				loopIdx.pop();
			}
		}
		string input;
		cin >> input;

		int memory_pointer = 0;
		int loopLabel = -1;
		int loopCnt = 0;
		int cmdCnt = 0;
		int comdIdx = 0;
		int inputIdx = 0;
		int mod = 1 << 8;

		int loop = -1;
		bool _END_ = false;
		while (1) {
			if (comdIdx == command_size) {
				cout << "Terminates\n";
				break;
			}
			cmdCnt++;
			switch (command[comdIdx].cmd) {
			case '-':
				memory[memory_pointer] = ((memory[memory_pointer] - 1) % mod);
				break;
			case '+':
				memory[memory_pointer] = ((memory[memory_pointer] + 1) % mod);
				break;
			case '<':
				memory_pointer--;
				if (memory_pointer < 0) memory_pointer = memory_size - 1;
				break;
			case '>':
				memory_pointer++;
				if (memory_pointer == memory_size) memory_pointer = 0;
				break;
			case '[':
				if (loop == -1)loop = comdIdx;
				if (cmdCnt >= 50000000) {
					
					//cout << "Loops " << loop << ' ' << command[loop].label << '\n';
					_END_ = true;
					break;
				}
				if (memory[memory_pointer] == 0) {
					if (loopLabel == comdIdx) loopCnt++;
					else {
						loopCnt = 0;
						loopLabel = comdIdx;
					}
					comdIdx = command[comdIdx].label;
					continue;
				}
				break;
			case ']':
				if (memory[memory_pointer] != 0) {
					if (loopLabel == command[comdIdx].label) loopCnt++;
					comdIdx = command[comdIdx].label;
					loopLabel = comdIdx;
					continue;
				}
				else {
					if (loop == command[comdIdx].label)
						loop = -1;
				}
				break;
			case '.':
				//cout << (char)memory[memory_pointer];
				break;
			case ',':
				if (input.size() == 0 || inputIdx >= input.size())
					memory[memory_pointer] = 255;
				else
					memory[memory_pointer] = input[inputIdx++];
				break;
			}
			comdIdx++;
			if (_END_) break;
		}
		if (_END_)cout << "Loops " << loop << ' ' << command[loop].label << '\n';
	}
	return 0;
}
/*
1
100 11 1
+[-[[-]+]-]
a

1
100 7 1
+[[-]+]
a

1
100 8 1
[+[+-]-]
a

*/