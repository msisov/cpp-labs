#include <iostream>

double initialize_xy(double* x, double* y)
{
	*x = 0;
	*y = 0;
	return 0;
}

double initialize_xy2(double *x, double *y, double a, double b)
{
	*x = a;
	*y = b;
	return 0;
}

using namespace std;

void main()
{
	double x, y;

	initialize_xy(&x, &y);

	cout << x << endl;
	cout << y << endl;

	initialize_xy2(&x, &y, 1.0, 2.0);

	cout << x << endl;
	cout << y << endl;

}
