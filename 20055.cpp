/*�����̾� ��Ʈ ���� �κ�*/
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
using namespace std;
int N, K, zero;
//�����̾� ��Ʈ ��ġ ���� : 0 ~ N-1(top) // N ~ 2N-1(bottom)
deque<int>top;
deque<int>bottom;
queue<int>robot_loc;

void rotate() { // ��Ʈ ȸ��
	int tmp;
	//top�� ������ �̾� bottom�� �Ӹ��� �ְ�
	tmp = top.back(); top.pop_back();
	bottom.push_front(tmp);
	//bottom�� ������ �̾� top�� �Ӹ��� �ִ´�.
	tmp = bottom.back(); bottom.pop_back();
	top.push_front(tmp);

	//�κ�ť�� ���ʷ� �̾Ƽ� ��ġ������ +1 ��Ű�� ��ġ�� ������ ��ġ�� �ƴҰ�� �ٽ� ť�� �ִ´�.
	int size = robot_loc.size();
	for (int i = 0; i < size; i++) {
		int loc = robot_loc.front(); robot_loc.pop();
		if (loc + 1 != N - 1) robot_loc.push(loc + 1);
	}
}

void move() { //�κ��� �̵�
	int size = robot_loc.size();
	vector<bool> chk(100, true);
	//�κ�ť�� ���ʷ� �̾Ƽ� ����ġ ���� ��ġ�� �������� 0����, ������ ��ġ����, �κ��� �ִ��� Ȯ���Ѵ�.
	//�κ��� �ִ��� Ȯ���� ���� chk�迭�� ����� Ȯ���Ѵ�(ó�� ť���� ���³༮���� üũ�迭�� ���)
	for (int i = 0; i < size; i++) {
		int loc = robot_loc.front(); robot_loc.pop();
		if (top.at(loc + 1) == 0 || chk[loc + 1] == false) { //���� ( ������ġ ������0 || ������ġ �κ� ���� )
			robot_loc.push(loc);
			chk[loc] = false;
		}
		else { // (������ġ ������ 0 �ƴ� && ������ġ �κ� ����)
			if (loc + 1 != N - 1) { //����(������ġ ������ ��ġ �ƴ�)
				robot_loc.push(loc + 1);
				chk[loc + 1] = false;
			}
			top.at(loc + 1)--;
			if (top.at(loc + 1) == 0) zero++; //���⼭ �������� 0�� �� ���� ������ zero����++
		}
	}
}

void put_robot() { //�κ��� �߰�
	int put_loc = 0;
	if (top.at(put_loc) != 0) {//top.at(0)������ Ȯ���ϰ� 0�� �ƴϸ� �߰��ϰ� ������--�� zeor����++
		top.at(put_loc)--;
		robot_loc.push(put_loc);//�κ�ť�� �ִ´�.
		if (top.at(put_loc) == 0) zero++;
	}
}

bool loop_end() { //������ 0 ���� Ȯ���� �ݺ�����
	//zero������ K�� �̻��̸� ���ᰪ ��ȯ
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