#include "CounterUser.h"

CounterUser::CounterUser()
{
	LimitedCounter lc(0, 5);
	lc.SetObserver(this);
	this->lc = &lc;
}

void CounterUser::IncrementBy(int by)
{
	for(int i = 0; i<by; i++){
		lc++;
	}
}