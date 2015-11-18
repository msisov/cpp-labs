#include "counter.h"
#include "Observer.h"
#include <vector>

class Observer;
class LimitedCounter: public Counter{
	
	public:
		LimitedCounter();
		LimitedCounter(const Counter &c, int lim);
		LimitedCounter *operator++(int);
		LimitedCounter &operator++();
		void SetObserver(Observer *ob);
		void Notify();
	private:
		int limit;
		std::vector<Observer*> observers;
};