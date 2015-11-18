#include "RoundupCounter.h"

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