#include <iostream>
#include <string.h>

using namespace std;


#ifdef _DEBUG													// Active only in Debug Configuration
#define _CRTDBG_MAP_ALLOC										// Visual Studio Mem Leak detector activated
#include <crtdbg.h>												// runtime debug functions are declared here
#endif

class String {
	public:		
		String(const char* name0="");						//Declaration of construction
		String(const String& copy);                         //Declaration of construction copy
		//~String();											//Declaration of destruction
		void list();
	private:
		char *c_string;
};

void f(String s);
void f(int i);
/*void main() {
	String s("abcdefg");
	s.list();
	f(s);
	s.list();
}*/

int main() {
	int i = 0;
	_CrtMemState memory; // C/C++ runtime memory management state storage
	
	while (i < 1000) {
			f(i++);
			// dump memory management state
			_CrtMemCheckpoint(&memory); _CrtMemDumpStatistics(&memory);
	}
	
	_CrtDumpMemoryLeaks(); // check if there were memory leaks
	return 0;
}

String::String(const char* name0)
{
	c_string = new char[strlen(name0) + 1];
	strcpy(c_string, name0);
}

void f(String s)											//If passing by parameter, then copy constr is needed otherwise does not work
{                                                           //If passing by reference, then copy constr is not needed
	s.list();
}

void String::list()
{
	cout << c_string << endl;
}

//String::~String()											//Destruction is called automatically
//{
//	cout << "Destruction success" << endl;					
//	delete c_string;
//}

String::String(const String& copy)							//Construction copy is called automatically
{
	cout << "Construction copy is called" << endl;
	c_string = new char[strlen(copy.c_string) + 1];
	strcpy(c_string, copy.c_string);
}

void f(int i) {
	String s("abcdefghijklmnopqrstuvwxyz");
	if (i % 100 == 0)
	s.list();
}