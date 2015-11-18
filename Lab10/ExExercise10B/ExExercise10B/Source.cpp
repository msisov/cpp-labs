#include <iostream>
using namespace std;

//#define smallest(a,b) ((a) < (a) ? (b) : (b))
template <class T> const 
T& smallest (const T& a, const T& b) {
  return !(b < a) ? a : b;    
}


struct arr {
	static const int n = 10;
	int a[n];

	int elements() {
		int k = 0, *p = &a[0];
		
		// count the number of array elements
		while (smallest(p++, &a[n]) != &a[n])
			k++;
		return k;
		
	}
	int size() {
		return n;
	}

};


void main() {
	arr a;

	cout << "Elements: " << a.elements() << ", expecting: " << a.size() << endl;
	system("PAUSE");
}