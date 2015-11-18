#include <iostream>

using namespace std;

//class definitions
class Time {
	public:
		void read(char *time);              //Time read
		int lessThan(Time t_compare);		//Time compare
		Time subtract(Time t_sub);			//Duration
		void display();						//Time display
	private:
		int hour;
		int min;		
};



int main(void) {
	
	Time time1, time2, duration;
	time1.read("Enter time 1: ");
	time2.read("Enter time 2: ");
	
	if (time1.lessThan(time2)) {
		duration = time2.subtract(time1);
		cout << "Starting time was ";
		time1.display();
		cout << endl;
	}
	
	else {
		duration = time1.subtract(time2);
		cout << "Starting time was ";
		time2.display();
		cout << endl;
	}
	
	cout << "Duration was ";
	duration.display();
	
	cout << endl;
	return 0;
}

void Time::read(char *time)
{
	cout << time;
	cin >> hour;
	cin >> min;
}

int Time::lessThan(Time t_comp)
{

	int t1min, t2min;
	t1min = hour * 60 + min;					//target obj
	t2min = t_comp.hour * 60 + t_comp.min;		//parameter obj
	if (t1min > t2min) {
		return 0;
	}
	else {
		return -1;
	}

}

Time Time::subtract(Time t_sub)
{
	Time aux;
	int dmin, t1min, t2min;
	
	t1min = hour * 60 + min;
	t2min = t_sub.hour * 60 + t_sub.min;		//target obj
	dmin = t1min - t2min;						//parameter obj
	
	aux.hour = dmin/60;							//local obj
	aux.min = dmin%60;							//local obj
	
	return aux;
}

void Time::display()
{	
	cout << hour;
	cout << ":";
		
	if (min >= 10){
		cout << min;
	}
	else {
		cout << "0";
		cout << min;
	}
}