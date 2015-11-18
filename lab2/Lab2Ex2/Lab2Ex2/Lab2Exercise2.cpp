#include <iostream>
#include "time.h"


using namespace std;

class Dice {
	public:
		void initialize();
		float roll();
	private:
		double number;
};

class Counter {
	public:
		void reset();
		int getCount();
		void increment();
	private:
		int count;
};

class Inspector {
	public:
		float setLimits(float first, float second);
		bool isInLimits(float rand_numb);
	private:
		float lim_one;
		float lim_two;		
};

void main(void) {
	Dice dice;
	Counter counter1, counter2, i;
	Inspector inspector;
	
	dice.initialize();
	counter1.reset(); counter2.reset(), i.reset();
	inspector.setLimits(0.0, 0.5);
	
	while (i.getCount() < 100) {
		if (inspector.isInLimits(dice.roll()))
			counter1.increment(); 
		else
			counter2.increment();
			i.increment();
	}
	
	cout << counter1.getCount() << endl;
	cout << counter2.getCount() << endl;
}

void Dice::initialize()
{
	number = 0.0;	
	srand(time(NULL));
}

float Dice::roll()
{	
	number =  (float)rand() / (float) RAND_MAX;
	
	return number;
}

void Counter::reset()
{
	count = 0;
}

int Counter::getCount()
{
	return count;
}

void Counter::increment()
{
	count = count + 1;
}

float Inspector::setLimits(float first, float second)
{
	lim_one = first;
	lim_two = second;

	return 0;
}

bool Inspector::isInLimits(float rand_numb)
{
	if (rand_numb > lim_one && rand_numb <= lim_two) {
		return true;
	}

	else {
		return false;
	}
}