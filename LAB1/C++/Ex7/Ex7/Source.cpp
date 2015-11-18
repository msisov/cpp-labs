#include <iostream>

using namespace std;

void main()
{
	int *a;
	int n;
	int i;
	
	cout << "Enter the number" << endl;
	cin >> n;
	
	a = new int [n];
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 101;
	}

	cout << endl << "Random numbers are:" << endl;
	for (i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}

	delete a;
}