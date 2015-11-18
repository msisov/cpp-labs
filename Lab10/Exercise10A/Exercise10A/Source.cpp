#include <string>
#include <iostream>

int main ()
{
	std::pair <std::string, std::string> string_pair1 ("aaaaa", "xxxxxxx");		//Constructor of a pair of strings
	std::pair <std::string, std::string> string_pair2 ("bbb", "yyy");			//Constructor of a pair of strings
	
	 std::pair<int, std::pair<std::string, std::string>> map_create1(123, string_pair1);			//Construct and init int and pair of strings
	 std::pair<int, std::pair<std::string, std::string>> map_create2 (345, string_pair2);			//Construct and init int and pair of strings

	 //map_create1.insert(make_pair(123, string_pair1));							//Map init of int and pair
	// map_create2.insert(make_pair(345, string_pair2));

	/*
	std::cout << "no\t" << "first name\t" << "last name" << std::endl;	
   
	typedef std::map<int, std::pair<std::string, std::string>>::const_iterator MapIterator;

	for (MapIterator iter = map_create1.begin(); iter != map_create1.end(); iter++)
	{
		std::cout << iter->first << "\t" << iter->second.first << "\t\t" << iter->second.second << std::endl;
	}

	for (MapIterator iter = map_create2.begin(); iter != map_create2.end(); iter++)
	{
		std::cout << iter->first << "\t" << iter->second.first << "\t\t" << iter->second.second << std::endl;
	}
	*/
	 std::cout << "no\t" << "first name\t" << "last name" << std::endl;	
	 std::cout << map_create1.first << "\t" << map_create1.second.first << "\t\t"<< map_create1.second.second << std::endl;
	 std::cout << map_create2.first << "\t" << map_create2.second.first << "\t\t"<< map_create2.second.second << std::endl;
	return 0;
}