// Exercise 5

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string find_field(string p, string x);

int main (void) {
	
	string page, line, location, temperature;
	ifstream inputFile("weather.xml");
	
	while (getline (inputFile, line)) {
 	    page.append(line);
		//cout << line << endl;
		location = find_field(page, "location");
		temperature = find_field(page, "temp_c");
 		line.erase();
	}

	// Now page is a string that contains the whole xml page
	
	// Here you need to write something that finds and 
	// extracts location and temperature from the XML
	// data in the string page and stores them in 
	// the strings location and temperature respectively
	
	cout << "Location: " << location << endl;
	cout << "Temperature: " << temperature << endl; 
	system("pause");
}

string find_field(string p, string x)
{
	int pos1;
	int pos2;
	int length;
	string answer;

	if (pos1 = p.find(x)){						//True if string is found
			pos1 += x.length() + 1;				//End of string + ">"
			pos2 = p.rfind(x) - 2;				//Start of string + "</"
			length = pos2 - pos1;				//Length between strings
			answer.append(p, pos1, length);
	}
	return answer;
}
