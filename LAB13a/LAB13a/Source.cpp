#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

#ifdef _DEBUG // Active only in Debug Configuration
#define _CRTDBG_MAP_ALLOC // Visual Studio Mem Leak detector activated
#include <crtdbg.h> // runtime debug functions are declared here
#endif

using namespace std;
#define N 4

class Point {
	friend ostream& operator<<(ostream &out, const Point &point);
	public:
		Point(float x0 = 0.0, float y0 = 0.0);
		Point(const Point &p0);
		~Point();
        float distance() const;
        static int count;
	private:
		float x;
		float y;
};
int Point::count = 0;

//Definition for exception class
class Exception {
	public:
		Exception(const char *explanation0) {explanation = explanation0;}
		const char *what() const {return explanation;}
	private:
		const char *explanation;
};

bool PComp(unique_ptr<Point>& const a, unique_ptr<Point>& const b);
//bool PComp(Point* a, Point* b);
void print_out(Point *a);
int main(void)
{
	_CrtMemState memory; {
		try {
		//vector<Point*> points;
		//points.push_back(new Point(3.0, 4.0));
		//points.push_back(new Point(5.3, 5.3));
		//points.push_back(new Point (3.5, 3.5));	
		//for_each(points.begin(), points.end(), print_out);	
		//for_each(points.begin(), points.end(), PComp);
		//for_each(points.begin(), points.end(),[](Point *p){delete p;});
			
			vector<unique_ptr<Point>> points; 
			unique_ptr<Point> p1(new Point(3.0, 4.0)); //5
			unique_ptr<Point> p2(new Point(2.0, 3.0)); //3.6
			unique_ptr<Point> p3(new Point(6.0, 1.0)); //6.08
		
		points.push_back(move (p1)); //5
		points.push_back(move (p2)); //3.6
		points.push_back(move (p3)); //6

		cout << "Before sort" << endl;
		for (unsigned int i = 0; i<points.size(); i++)
			cout << *points[i] << endl;

	    sort(points.begin(), points.end(), PComp);
		
		cout << "After sort" << endl;
		for (unsigned int i = 0; i<points.size(); i++)
			cout << *points[i] << endl;
	  	
		//throw Exception ("Exception after points have been created");	
	}
	catch (Exception e) {
		cout << "Exception explanation is: " << e.what() << endl;
		cout << "Exception is managed now" << endl;
	}
	_CrtMemCheckpoint(&memory); _CrtMemDumpStatistics(&memory);
	}	
	_CrtDumpMemoryLeaks();

	system("PAUSE");
	return EXIT_SUCCESS;
	
}

//-----------------------------------------------------------------
//Implementation of class Point
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

float Point::distance() const {
   // float deltax = p2.x - x;
   // float deltay = p2.y - y;   
    return sqrt(x*x + y*y);
}


// Friend functions of Point
ostream &operator<<(ostream & out, const Point &point) {
	out << "(" << point.x << "," << point.y << ")";
	return out;
}

void print_out(Point *a)
{
	cout << *a << endl;
}

bool PComp(unique_ptr<Point>& const a, unique_ptr<Point>& const b)
{
	return (a->distance() < b->distance());
}
