using namespace std;
#define _CRT_RAND_S 
#include <stdlib.h> 
#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream>
#ifdef _DEBUG    // Active only in Debug Configuration 
#define _CRTDBG_MAP_ALLOC // Visual Studio Mem Leak detector activated 
#include <crtdbg.h> 
#endif


class WordPool{
	public:		
		WordPool();
		void fill(string cat, ifstream &in);
		int size_of_array() const;
		void resize( int new_size);
		string get();
		~WordPool();
	private:
		string *phrases;
		int l;
};

WordPool::WordPool()
{
	l = 1;
	phrases = new string[1];
	phrases[0] = "";
}

WordPool::~WordPool()
{
	delete []phrases;
}

int WordPool::size_of_array() const
{
	return l;
}

void WordPool::fill(string cat, ifstream &in)
{
	string temp;
	string check = "[" + cat + "]";

			do{
				getline(in, temp);
				if (temp != check){
					phrases[l-1] = temp;
					resize(l+1);				
				}			
			}while(temp != "");

		/*
	string line;
	do{
			getline(in, line);
	} while (line != "[" + cat + "]");
		
	if( line != "")
		do
		{			
			getline(in, line);
			resize(l+1);			
			phrases[l-1] = line;
			
		} while (line != "");
		*/
}

void WordPool::resize(int new_size)
{
	string *new_array = new string[new_size];
	for(int i = 0; i < l; i++){
		new_array[i] = phrases[i];
	}
	delete[] phrases;
	phrases = new_array;
	l = new_size;	
}

string WordPool::get()
{	
	unsigned int rand_num = 1;
	errno_t err;

	err = rand_s(&rand_num);
	rand_num = (unsigned int) ((double) rand_num/ ((double) UINT_MAX + 1)*l);

	return phrases[rand_num];
}

string giveStatement(string filename) {
	WordPool g, a, s, v;
	ifstream inputFile(filename);
	
	
	g.fill("G", inputFile); a.fill("A", inputFile);s.fill("S", inputFile); v.fill("V", inputFile);
	return g.get() + " " + a.get() + " " + s.get() + " " + v.get() + " " + g.get() + " " + a.get() + " " + s.get();	
}


int main (void) 
{	
		
		cout << giveStatement("Z://Studying//2013-2014//C++//Lab5Ex2C//Lab5Ex2C//oracle.dat") << endl;
		

#ifdef _DEBUG
		if (_CrtDumpMemoryLeaks())
			cout << "WARNING: There was memory leak in your program" << endl;
		else
			cout << "Your program has no memory leaks, congratulations!" << endl;
#endif
		//system("PAUSE");
}