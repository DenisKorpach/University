#include <iostream>
#include <math.h>
using namespace std;

double calculation1(double xa, double a, double b) {
	double y = cos(xa) + (1 / b) * cos(a * xa + 1) + 
	(1 / pow(b, 2)) * cos(pow(a, 2) * xa + 2) + 
	(1 / pow(b, 3)) * cos(pow(a, 3) * xa + 3) + 
	(1 / pow(b, 4)) * cos(pow(a, 4) * xa + 4);
	return y;
};