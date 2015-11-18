#include <iostream>
#include <string.h>

using namespace std;


class String {
	friend String operator+(const String &s1, const String &s2);
	friend ostream &operator<<(ostream &out, const String &s);
	public:		
		String(const char* name0="");						//Declaration of construction
		String(const String& copy);                         //Declaration of construction copy
		~String();											//Declaration of destruction
		const String& operator=(const String &s);
		String &operator++();                               //Pre-increment
		String operator++(int);
		char& operator[] (int i );
	private:
		char *c_string;
};

/*
int main() {                            //part A

		String s1("abcedf");
		String s2("ghijklmn");
		String sum;
		cout << "String 1 is:" << s1 << endl;
		cout << "String 2 is:" << s2 << endl;
		sum = s1 + s2;
		cout << "Sum is :" << sum << endl;; // output should be
		// abcdefghijklmn
		// This should also work
		sum = sum;
		cout << "Sum is still :" << sum << endl; // output should
		// still be abcdefghijklmn
		return 0;
}*/

int main() { //unary operators

		String s("abcdefg");
		cout << s++ << endl;
		cout << ++s << endl;
		return 0;
}

/*int main() { // indexing
	String s("abcdefg");
	for (int i = 0 ; i < 7 ; i++)
	cout << s[i] << " ";
	s[4] = 'X';
	cout << endl;
	for (int i = 0 ; i < 7 ; i++)
	cout << s[i] << " " ;
	cout << endl;
	return 0;
}*/

String::String(const char* name0)
{
	c_string = new char[strlen(name0) + 1];
	strcpy(c_string, name0);
}

String::~String()											//Destruction is called automatically
{
	//cout << "Destruction success" << endl;
	delete c_string;
}

String::String(const String& copy)							//Construction copy is called automatically
{
	//cout << "Construction copy is called" << endl;
	c_string = new char[strlen(copy.c_string) + 1];
	strcpy(c_string, copy.c_string);
}

const String& String::operator=(const String &s)
{
	if (this != &s){
		delete c_string;
		c_string = new char[strlen(s.c_string) + 1];
		strcpy(c_string, s.c_string);
	}
	return *this;
}

String operator+(const String &s1, const String &s2)
{
	String sum;
	sum.c_string = new char[strlen(s1.c_string) + strlen(s2.c_string) + 1]; //calculating lenght of string in sum
	strcpy(sum.c_string, s1.c_string);										//copy of s1 to sum
	strcat(sum.c_string, s2.c_string);										//conc of s2 to "sum+s1"
	return sum;
}

ostream &operator<<(ostream &out, const String &s)
{
	out << s.c_string;
	return out;
}

String &String::operator++() //Pre increment
{
	String answer;	

	answer.c_string = new char[strlen(c_string) + 1];
	strcpy(answer.c_string, c_string);	
	
	c_string = new char[strlen(c_string) + 2];
	strcpy(c_string, answer.c_string);
	strcat(c_string, "X");	

	return *this;

	/**this = *this + "X";
	return *this;*/
}

String String::operator++(int) //Post Increment
{
	
	String result;

	result.c_string = new char[strlen(c_string) + 1];
	strcpy(result.c_string, c_string);

	c_string = new char[strlen(c_string) + 2];
	strcpy(c_string, result.c_string);
	strcat(c_string, "X");	

	return result;

	/*
	String old = *this;
	*this = *this + "X";
	return old;*/
}

char& String::operator[](int i)
{
	int capacity;
	capacity = strlen(c_string);
	if (0 <= i && i < capacity)
		return c_string[i];
	cout << "Exception should be cought" << endl;
}