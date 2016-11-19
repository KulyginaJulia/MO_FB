#pragma once

#include <iostream>
#define delta  0.001
#define eps  0.00001
double Fun(double x) {
	double f = x * x;
	return f;
}

int F(int k) {
	int f;
	
	if (k >= 2)
		f = F(k - 1) + F(k - 2);
	else if ((k == 1) || (k == 0))
		f = 1;

	return f;
}

int minOfN(int b, int a) {
	int n = 1;
	while (((b - a) / F(n) + eps) > delta)
	{
		n++;
	}
	return n;
}

double Fibanachi(int a, int b, int n) {
	int j = 0;
	double min = 0, x1 = 0, x2=0, f1=0, f2=0;
	int tmpa = a, tmpb = b;

	x1 = tmpb - (tmpb - tmpa)*(F(n - 1) / (double)F(n));
	x2 = tmpa + (tmpb - tmpa)*(F(n - 1) / (double)F(n));
	for (j = 0; j < n - 2; j++) {
			f1 = Fun(x1);
			f2 = Fun(x2);
			if (f1 <= f2) {
				tmpb = x2;
				x2 = x1;
				x1 = tmpa + (tmpb - tmpa)*(F(n - j - 2) / F(n - j));
			}
			if (f1 > f2) {
				tmpa = x1;
				x1 = x2;
				x2 = tmpa + (tmpb - tmpa)*(F(n - j - 1) / F(n - j));
			}
			std::cout << "Iteration:  " << j << " ";
		}
	x1 = eps + (tmpa + tmpb) / 2;
	x2 = (tmpa + tmpb) / 2;
	f1 = Fun(x1);
	f2 = Fun(x2);
	if (f1 > f2) {
	std::	cout << "[ " << x1 << "," << tmpb << "]"<<"\n";
	}
	else {
	std::	cout << "[ " << tmpa << "," << x2 << "]" << "\n";
	}
	return Fun((a + b) / 2.0);
}
