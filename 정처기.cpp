#define _USE_MATH_DEFINES 
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int main() {
	char input[] = "123test456";
	//printf("%.3s\n", input);
	//printf("%3s\n", input);
	//printf("%8.6s\n", input);
	//printf("%-8.6s\n", input);

	cout << atan2(62, 40) * 180 / M_PI;
}