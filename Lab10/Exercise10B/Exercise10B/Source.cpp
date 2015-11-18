#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

bool compare_length(std::string const& lhs, std::string const& rhs) {
    return lhs.size() < rhs.size();
}

int main()
{
	std::string temp;
    int count = 0;
	std::vector<std::string> input;
	std::vector<std::string>::iterator it;
	std::vector<std::string>::iterator longest;

	std::cout << "Enter something, enter 'stop' to stop\n" << std::endl;
	while(temp != "stop"){
		std::getline(std::cin, temp);
		if (temp != "stop"){		
			input.push_back(temp);
			count++;
		}
		else std::cout << "\n!!!Reading is stopped!!!\n" << std::endl;
	}

	longest = std::max_element(input.begin(), input.end(), compare_length);
	std::cout << "The longest string was - " + *longest << std::endl;
	
	std::cout << "\nDisplaying all the strings from the vector\n\n";
    for (it = input.begin(); it != input.end(); it++){
		std::cout << *it << std::endl;
	} 
	

	std::cout << "\nNumber of strings entered is " << count << std::endl;

	std::cout << "\nReturn from member function 'size()' is " << input.size() << std::endl; //Shows actual number of objects/elements held in the vector
	std::cout << "\nReturn from member function 'capacty()' is " << input.capacity() << std::endl; // sizeof returns size of the object itself. if it contains pointer to array for example it will not count size of array, it will count only size of pointer (4 on 32 bits)
	std::cout << "\nReturn from member function 'sizeof()' is " << sizeof(input) << std::endl; //Shows the size of storage currently allocated for the vector, can be reallocated in a run-time if run out of space

	return 0;
}