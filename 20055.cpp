/*컨베이어 벨트 위의 로봇*/
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
using namespace std;
int N, K, zero;
//컨베이어 벨트 위치 정보 : 0 ~ N-1(top) // N ~ 2N-1(bottom)
deque<int>top;
deque<int>bottom;
queue<int>robot_loc;

void rotate() { // 벨트 회전
	int tmp;
	//top의 꼬리를 뽑아 bottom의 머리에 넣고
	tmp = top.back(); top.pop_back();
	bottom.push_front(tmp);
	//bottom의 꼬리를 뽑아 top의 머리에 넣는다.
	tmp = bottom.back(); bottom.pop_back();
	top.push_front(tmp);

	//로봇큐를 차례로 뽑아서 위치정보를 +1 시키고 위치가 내리는 위치가 아닐경우 다시 큐에 넣는다.
	int size = robot_loc.size();
	for (int i = 0; i < size; i++) {
		int loc = robot_loc.front(); robot_loc.pop();
		if (loc + 1 != N - 1) robot_loc.push(loc + 1);
	}
}

void move() { //로봇의 이동
	int size = robot_loc.size();
	vector<bool> chk(100, true);
	//로봇큐를 차례로 뽑아서 현위치 다음 위치가 내구도가 0인지, 내리는 위치인지, 로봇이 있는지 확인한다.
	//로봇이 있는지 확인은 따로 chk배열을 만들어 확인한다(처음 큐에서 나온녀석부터 체크배열에 기록)
	for (int i = 0; i < size; i++) {
		int loc = robot_loc.front(); robot_loc.pop();
		if (top.at(loc + 1) == 0 || chk[loc + 1] == false) { //정지 ( 다음위치 내구도0 || 다음위치 로봇 있음 )
			robot_loc.push(loc);
			chk[loc] = false;
		}
		else { // (다음위치 내구도 0 아님 && 다음위치 로봇 없음)
			if (loc + 1 != N - 1) { //전진(다음위치 내리는 위치 아님)
				robot_loc.push(loc + 1);
				chk[loc + 1] = false;
			}
			top.at(loc + 1)--;
			if (top.at(loc + 1) == 0) zero++; //여기서 내구도가 0이 된 곳이 있으면 zero변수++
		}
	}
}

void put_robot() { //로봇의 추가
	int put_loc = 0;
	if (top.at(put_loc) != 0) {//top.at(0)내구도 확인하고 0이 아니면 추가하고 내구도--후 zeor변수++
		top.at(put_loc)--;
		robot_loc.push(put_loc);//로봇큐에 넣는다.
		if (top.at(put_loc) == 0) zero++;
	}
}

bool loop_end() { //내구도 0 개수 확인후 반복결정
	//zero변수가 K개 이상이면 종료값 반환
	return zero >= K ? true : false;
}


void print() {
	cout << '\n' << "-------------------------------------------" << '\n';
	for (int i = 0; i < top.size(); i++) { cout << top.at(i) << ' '; }
	cout << '\n';
	for (int i = bottom.size()-1; i >=0; i--) { cout << bottom.at(i) << ' '; }
	cout << '\n' << "-------------------------------------------" << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) { int in; cin >> in; top.push_back(in); }
	for (int i = 0; i < N; i++) { int in; cin >> in; bottom.push_back(in); }
	int turn = 0;
	while (1) {
		turn++;
		rotate();
		//cout << "rotate\n";print();
		move();
		//cout << "move\n"; print();
		put_robot();
		//cout << "put\n"; print();
		//print();
		if (loop_end()) { cout << turn << '\n'; break; }
	}
	return 0;
}