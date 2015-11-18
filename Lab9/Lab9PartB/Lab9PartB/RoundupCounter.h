#include "counter.h"

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