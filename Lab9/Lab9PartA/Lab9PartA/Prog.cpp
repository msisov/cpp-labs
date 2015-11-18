#include "counter.h"

int UseCounter(Counter* c, int increment);

class LimitedCounter: public Counter{
	
	public:
		LimitedCounter();
		LimitedCounter(const Counter &c, int lim);
		LimitedCounter *operator++(int);
		LimitedCounter &operator++();	
	private:
		int limit;
		
};

class RoundupCounter: public Counter{
public:
	RoundupCounter();
	RoundupCounter(const Counter &c, int lim);
	RoundupCounter *operator++(int);
	RoundupCounter &operator++();
private:
	int roundup_limit;
	int count_times;
};



//ostream &operator<<(ostream &out, const LimitedCounter &c);

int main() {
	LimitedCounter counterA(0, 5);
	RoundupCounter counterB(0, 5);

	UseCounter(&counterA, 8); UseCounter(&counterB, 8);

	cout << "Counter A: " << counterA << endl; // output should be 5
	cout << "Counter B: " << counterB << endl; // output should be 2

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

LimitedCounter* LimitedCounter::operator++(int)
{
	LimitedCounter temp = *this;
	if(*this < limit){
		Counter::operator++();
	}
	return this;
}
LimitedCounter &LimitedCounter::operator++()
{
	LimitedCounter temp = *this;
	if(*this < limit){
		Counter::operator++();
	}
	return *this;
}

RoundupCounter::RoundupCounter(const Counter &c, int lim) : Counter(c)
{
	roundup_limit = lim;
}
RoundupCounter::RoundupCounter(): Counter(0)
{
	roundup_limit = 0; 
}

RoundupCounter* RoundupCounter::operator++(int)
{
	RoundupCounter temp = *this;
	if(*this < roundup_limit){
		Counter::operator++();
	}
	return this;
}
RoundupCounter &RoundupCounter::operator++()
{
	RoundupCounter temp = *this; //if count == 5; int round++; 
	count_times = 0;
	if(*this < roundup_limit){
		Counter::operator++();
	}
	else {
		Counter::reset();
	}
	
	return *this;
}

int UseCounter(Counter* c, int increment)
{
	for (int i = 0; i<increment; i++){
		c->operator++();
	}

	return 0;
}