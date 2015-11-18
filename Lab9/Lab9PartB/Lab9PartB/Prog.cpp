#include "counter.h"
#include <vector>
#include <string>
using namespace std;

int UseCounter(Counter* c, int increment);

class Observer;
class LimitedCounter: public Counter{
	
	public:
		LimitedCounter();
		LimitedCounter(const Counter &c, int lim);
		LimitedCounter operator++(int);
		LimitedCounter &operator++();
		void SetObserver(Observer *ob);
		void Notify();
	private:
		int limit;
		vector<Observer*> observers;
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

class Observer {
public:
	virtual void HandleLimitReached(string message) = 0;
};

class CounterUser: public Observer {
public:
	CounterUser();
	//void set(LimitedCounter *lc){ this->lc = lc; };
	void IncrementBy(int by);
	void HandleLimitReached(string message){ 
		cout << message << endl;
		lc->reset();
	};
private:
	LimitedCounter *lc;
};


//ostream &operator<<(ostream &out, const LimitedCounter &c);

void main() {
	CounterUser *c = new CounterUser();
	c->IncrementBy(12);
	
	delete c;
} //OUTPUT: two times "Limit has been reached"

CounterUser::CounterUser()
{
	LimitedCounter *lc = new LimitedCounter(0,5);
	lc->SetObserver(&(*this));
	this -> lc = lc;
}

void CounterUser::IncrementBy(int by)
{
	//CounterUser temp = *this;
	for(int i = 0; i<by; i++){
		lc->operator++();
	}
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
	cout << "int" << endl;
	LimitedCounter temp = *this;
	if(*this < limit){
		temp++;
		Notify();
	}
	*this = temp;
	return *this;
}
LimitedCounter &LimitedCounter::operator++()
{
	if(*this < limit){
		Counter::operator++();
		
	}
	else Notify();
	return *this;
}

void LimitedCounter::SetObserver(Observer *ob)
{
	observers.push_back(ob);
}

void LimitedCounter::Notify() {
	for (int i = 0; i < observers.size() ; i++)
		observers[i]->HandleLimitReached("Limit has been reached");
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
/*
int UseCounter(Counter* c, int increment)
{
	for (int i = 0; i<increment; i++){
		c->operator++();
	}

	return 0;
}*/