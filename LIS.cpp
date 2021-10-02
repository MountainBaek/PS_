//#include <stdio.h>
//int lis[1001];
//
//int lower_bound(int value, int now_len) {
//	int front = 0;
//	int rear = now_len;
//	while (front <= rear) {
//		int mid = (front + rear) / 2;
//		if (lis[mid] < value) {
//			front = mid;
//		}
//		else {
//			rear = mid;
//		}
//	}
//	return front;
//}
//
//int main() {
//	int N;
//	scanf("%d", &N);
//	int rear = 1;
//	for (int i = 1; i <= N; i++) {
//		int input;
//		scanf("%d", &input);
//		if (lis[rear] < input) lis[++rear] = input;
//		else if (lis[rear] > input) {
//			int find = lower_bound(input, rear);
//			lis[find + 1] = input;
//		}
//	}
//
//
//	return 0;
//}

#include <cstdio>
#include <algorithm>

using namespace std;


int _lower_bound(int start, int end, int* arr, int target)
{
    int mid;
    while (end - start > 0)  // �־��� ����[start,end]���� Ž���ϵ��� �Ѵ�. start == end�̸� �ݺ� ����
    {
        mid = (start + end) / 2;  // �־��� ������ �߰� ��ġ�� ����Ѵ�

        if (arr[mid] < target) // ã���� �ϴ� ������ ������ ���������� �� ĭ�� �� ���� ���� ����
            start = mid + 1;

        else  // ã���� �ϴ� ������ ũ�� �ű���� �� ���� ����
            end = mid;
    }
    return end + 1; // ã�� ������ ���� ��� ���� ������ +1 ��ġ ����
}


int main()
{
    int i, n, j = 0;
    int cnt = 0;
    int lis[1001];
    int arr[1001];

    scanf("%d", &n);

    for (i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    i = 0;

    lis[i] = arr[i];
    i++;

    while (i < n)
    {
        // lis�� ���� ū ������ �� ū���� ������
        if (lis[j] < arr[i])
        {
            lis[j + 1] = arr[i];
            j++;
        }

        else
        {
            int ans = _lower_bound(0, j, lis, arr[i]);
            lis[ans - 1] = arr[i];
        }

        i++;
    }

    printf("%d", j + 1);

    return 0;
}

