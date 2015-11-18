/* ex_memleak.cpp -- lab12 exercise program
*
* This programs has classes Point and Triangle. Triangle consists
* three points. which are reserved separately from dynamic memory.
* Therefore Triangle has three pointers to Points. Memory for the
* Triangle itself has also been reserved from the dynamic memory.
*
* Program can generate an exception at the Nth Point constructor call.
* N is now 4 which means that all those three Points (in Triangle) can
* be created.
*/

#include <iostream>
#ifdef _DEBUG // Active only in Debug Configuration
#define _CRTDBG_MAP_ALLOC // Visual Studio Mem Leak detector activated
#include <crtdbg.h> // runtime debug functions are declared here
#endif
using namespace std;

// N spesifies which constructor of the Point fails (throws an exception)
#define N 3 //phase 4

// Class definition for Point
class Point {
	friend ostream& operator<<(ostream &out, const Point &point);
public:
	Point(float x0 = 0.0, float y0 = 0.0);
	Point(const Point &p0);
	~Point();
	static int count;
private:
	float x;
	float y;
};
int Point::count = 0;
class Triangle {
	friend ostream &operator<<(ostream & out, const Triangle &triangle);
public:
	Triangle(float x1, float y1, float x2, float y2, float x3, float y3);
	~Triangle();
private:
	auto_ptr<Point> apex1; //Phase 3
	auto_ptr<Point> apex2; //Phase 3
	auto_ptr<Point> apex3; //Phase 3
};

// Definition for exception class
class Exception {
public:
	Exception(const char *explanation0) {explanation = explanation0;}
	const char *what() const {return explanation;}
private:
	const char *explanation;
};

// Main function
int main () {
	_CrtMemState memory;{
	try {
		auto_ptr<Triangle> p(new Triangle(1.0, 1.0, 2.0, 2.0, 3.0, 3.0)); //phase 3 Triangle *p; p = new Triangle(...); to <----
		cout << *p;
		throw Exception ("Exception after Triangle has been created");	
		//delete p; //no need because of auto_ptr...phase3
	}
	catch (Exception e) {
		cout << "Exception explanation is: " << e.what() << endl;
		cout << "Exception is managed now" << endl;
	}
	//cout << "Constructor for point is executed " << Point::count << " times" << endl;
	_CrtMemCheckpoint(&memory); _CrtMemDumpStatistics(&memory);
	}	
	_CrtDumpMemoryLeaks();
	system("PAUSE");
	return EXIT_SUCCESS;
}

//-----------------------------------------------------------------
// Implementation of class Point
Point:: Point(float x0, float y0): x(x0), y(y0) {
	count++;
	if (count >= N)
		throw Exception ("Does not succeed to create the last apex");
	cout << "Point constructor is done " << (void*)this << endl;
}

Point::~Point() {
	cout << "\nDestructor for Point " << (void*)this << " : ("
		<< x << "," << y << ")" << endl;
}
// Friend functions of Point
ostream &operator<<(ostream & out, const Point &point) {
	out << "(" << point.x << "," << point.y << ")";
	return out;
}

//-----------------------------------------------------------------
// Implementation of class Triangle
Triangle::Triangle(float x1, float y1, float x2, float y2, float x3, float y3): apex1(new Point(x1,y1)), apex2(new Point(x2,y2)), apex3(new Point(x3,y3)) {
		     //Phase 3
	//apex1 = new Point(x1, y1);
	//apex2 = new Point(x2, y2);
	//apex3 = new Point(x3, y3);
	cout << "Triangle constructor is done " << (void*)this << endl;
}
Triangle::~Triangle() {
	cout <<  endl << "Destructor for Triangle " << endl;
	//delete apex1; //auto_ptr phase3
	//delete apex2; //auto_ptr phase3
	//delete apex3; //auto_ptr phase3
}

// Friend functions of Triangle
ostream &operator<<(ostream & out, const Triangle &triangle) {

	out << "Triangle is : " ;
	out <<  *triangle.apex1 << " " << *triangle.apex2 << " " << *triangle.apex3 << endl;
	return out;
}

