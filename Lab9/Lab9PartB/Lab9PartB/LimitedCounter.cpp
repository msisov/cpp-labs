#include "LimitedCounter.h"

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
		std::cout << "blah blahh" << endl;
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

void LimitedCounter::SetObserver(Observer *ob)
{
	observers.push_back(ob);
}