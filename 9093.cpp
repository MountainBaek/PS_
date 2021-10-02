//#include <stdio.h>
//#include <string.h>
//#include <stack>
//char input[10005];
//
//void fun() {
//	scanf("%[^\n]", input);
//	getchar();
//	std::stack<char>S;
//	int len = strlen(input);
//	for (int i = 0; i <= len; i++) {
//		if (input[i] == ' ' || input[i]=='\0') {
//			while (!S.empty()) {
//				printf("%c", S.top());
//				S.pop();
//			}
//			printf(" ");
//		}
//		else {
//			S.push(input[i]);
//		}
//	}
//	printf("\n");
//}
//
//int main() {
//	int n;
//	scanf("%d", &n);
//	getchar();
//	while (n--) {
//		fun();
//	}
//	return 0;
//}
