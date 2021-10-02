#include <stdio.h>

int main() {
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	int x = (c * e - f * b) / (a * e - b * d);
	int y = (c * d - f * a) / (b * d - e * a);
	printf("%d %d", x, y);
	return 0;
}