#include "counter.h"
//#include "counter.obj

//using namespace std;

class LimitedCounter: public Counter{
	
	public:
		LimitedCounter();
		LimitedCounter(const Counter &c, int lim);
		LimitedCounter operator++(int);
		LimitedCounter &operator++();
		//bool operator<(const Counter &c2) const{
		//	return Counter::operator<(c2);
		//}
		//void reset(){
		//	Counter::reset();
		//}
		//int getCount() const{
		//	return Counter::getCount();
		//}
	
	private:
		int limit;
		//int temp;
		//Counter init_value;
};

//ostream &operator<<(ostream &out, const LimitedCounter &c);

int main() {
	LimitedCounter lc(0, 5); //initial value 0, upper limit 5
	
	cout << lc++ << endl; //output should be 0
    cout << ++lc << endl; //output should be 2

	lc.reset();

	for (int i = 0; i < 9; i++) {
		lc++;
		cout << lc << endl;
	}

	cout << lc.getCount() << endl;
	cout << (lc < 7) << endl;//Testing the comparison operator
	cout << (lc < 1) << endl;//Testing the comparison operator

	return 0;
}

LimitedCounter::LimitedCounter(const Counter &c, int lim) : Counter(c)
{
	limit = lim;
}
LimitedCounter::LimitedCounter(): Counter(0)
{
	limit = 0; 
}

LimitedCounter LimitedCounter::operator++(int)
{
	LimitedCounter temp = *this;
	if(*this < limit){
		Counter::operator++();
	}
	return temp;
}
LimitedCounter &LimitedCounter::operator++()
{
	Counter::operator++();
	return *this;
}

/*
ostream &operator<<(ostream &out, const LimitedCounter &c)
{
	out << c.getCount();
	return out;
}*/