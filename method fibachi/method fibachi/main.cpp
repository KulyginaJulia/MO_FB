#include "function.h"
#include <iostream>

double Fibanachi(int a, int b, int n);
using namespace std;

int main() {
	double min;
	int n, a, b;
	cout << "Enter distans: \n";
	cin >> a >> b;

	n = minOfN(b, a);

	min = Fibanachi(a, b, n);
	
	cout << "\n min = " << min;

	system("pause");
	return 0;

}