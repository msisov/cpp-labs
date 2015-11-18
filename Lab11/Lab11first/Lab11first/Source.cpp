#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Ordinary function
void showNumbers(int elem)
{
	cout << elem << " ";
}
//Function object
class RandGen_2 {
	public:
		RandGen_2(): numbers() {
			srand(time(NULL));
		}
		int operator()();
		
 private:
		vector<int> numbers;
};
// function object 
class OutObj {           
public:
	OutObj(): index() {
	index = 0;
	}
	void operator() (int elem) {
	  index++;
	  cout << "#" << index << ": " << elem << endl;
	  ;}
private:
	int index;
};



void main(void) {
		vector<int> numbers(7);	
		vector<int> numbers2(7);
		vector<int> numbers3(14);
		vector<int>::iterator it;
		RandGen_2 randGen_2;
		OutObj out;

		generate(numbers.begin(), numbers.end(), randGen_2);
		cout << "First lotto row: ";
		for_each(numbers.begin(), numbers.end(), showNumbers);

		generate(numbers2.begin(), numbers2.end(), randGen_2);
		cout << endl << "Second lotto row: ";
		for_each(numbers2.begin(), numbers2.end(), showNumbers);

		sort(numbers.begin(), numbers.end());
		sort(numbers2.begin(), numbers2.end());

		it=set_intersection(numbers.begin(), numbers.end(), numbers2.begin(), numbers2.end(), numbers3.begin()); //find same numbers and 
		numbers3.resize(it-numbers3.begin());															//place to num3 vector --->>> resize

		cout << endl << "Same numbers:" << endl;
		for_each(numbers3.begin(), numbers3.end(), out);										//out using funct.obj

}

int RandGen_2::operator()() {
	int number;
		
	do {
		number = rand() % 37 + 1;
	} while(find(numbers.begin(), numbers.end(), number) != numbers.end());

	numbers.push_back(number);
	return number;

}
