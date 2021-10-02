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
    while (end - start > 0)  // 주어진 범위[start,end]에서 탐색하도록 한다. start == end이면 반복 종료
    {
        mid = (start + end) / 2;  // 주어진 범위의 중간 위치를 계산한다

        if (arr[mid] < target) // 찾고자 하는 값보다 작으면 오른쪽으로 한 칸만 더 시작 구간 갱신
            start = mid + 1;

        else  // 찾고자 하는 값보다 크면 거기까지 끝 구간 갱신
            end = mid;
    }
    return end + 1; // 찾는 구간에 없는 경우 가장 마지막 +1 위치 전달
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
        // lis의 가장 큰 값보다 더 큰값이 들어오면
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

