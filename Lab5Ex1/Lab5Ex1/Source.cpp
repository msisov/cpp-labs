#include <iostream>

using namespace std;


class String {
	friend ostream &operator<<(ostream &out, const String &s);
	public:		
		String(const char* name0="");						//Declaration of construction
		String(const String& copy);                         //Declaration of construction copy
		~String();											//Declaration of destruction	
		const String& operator=(const String &s);
		operator char*(){									//Conv from string to c-string
			char *temp;
			temp = new char[strlen(c_string) + 1];
			strcpy(temp, c_string);
			return temp;
		}

	private:
		char *c_string;
};


void main() 
{
		String s;
		char name[30];
		
		s = "Matti"; //Conversion c-string -> String
		
		cout << s << endl;;
		
		strcpy(name, s); //Conversion String -> c-string
		
		cout << name << endl;
}

const String& String::operator=(const String &s) //Conv from c-string -> String
{
	if (this != &s){
		delete c_string;
		c_string = new char[strlen(s.c_string) + 1];
		strcpy(c_string, s.c_string);
	}
	return *this;
}

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
	cout << c_string;
}


ostream &operator<<(ostream &out, const String &s)
{
	out << s.c_string;
	return out;
}