#include "LimitedCounter.h"
#include "LimitedCounter.h"

class CounterUser: public Observer {
public:
	CounterUser();
	void IncrementBy(int by);
	void HandleLimitReached(){ 
		cout << "Limit has been reached" << endl;
		lc->reset();
	}
private:
	LimitedCounter *lc;
};