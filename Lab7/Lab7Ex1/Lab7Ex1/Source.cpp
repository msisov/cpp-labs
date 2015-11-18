#include "counter.h"
//#include "counter.obj"

using namespace std;

class LimitedCounter{
	friend ostream &operator<<(ostream &out, const LimitedCounter &c);
	public:
		LimitedCounter();
		LimitedCounter(const Counter &c, int lim);
		LimitedCounter operator++(int);
		LimitedCounter &operator++();
		bool operator<(const Counter &c2) const{
			return init_value.operator<(c2);
		}
		void reset(){
			init_value.reset();
		}
		int getCount() const{
			return init_value.getCount();
		}
	
	private:
		int limit;
		int temp;
		Counter init_value;
};


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

LimitedCounter::LimitedCounter(const Counter &c, int lim) : init_value(c)
{
	limit = lim;
}
LimitedCounter::LimitedCounter() : init_value(0)
{
	limit = 0; 
}

LimitedCounter LimitedCounter::operator++(int)
{
	LimitedCounter temp = *this;
	if(init_value < limit){
	init_value++;
	}
	return temp;
}
LimitedCounter &LimitedCounter::operator++()
{
	++init_value;
	return *this;
}

ostream &operator<<(ostream &out, const LimitedCounter &c)
{
	out << c.init_value;
	return out;
}