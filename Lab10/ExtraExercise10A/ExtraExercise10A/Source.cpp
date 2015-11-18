#include <vector>
#include <iostream>

inline int enter(){ int temp = 0; std::cin >> temp; return temp;}

int main()
{

	std::vector< std::vector<int> > my_array;
	//std::vector< std::vector<int> >::iterator it;
	int column = 0;
	int row = 0;

	std::cout << "Enter number of columns " << std::endl;
	column = enter();
	std::cout << "Enter number of rows " << std::endl;
	row = enter();

	std::cout << "Add elements into matrix " << std::endl;
	for (int i = 0; i < row; i++) {
		std::vector<int> row; // Create an empty row
    for (int j = 0; j < column; j++) {
        row.push_back(enter()); // Add an element (column) to the row
    }
    my_array.push_back(row); // Add the row to the main vector
	}

	std::cout << "This is your matrix " << std::endl;
	for (int i = 0; i < row; i++) {
	 for (int j = 0; j < column; j++) {
		 std::cout << my_array[i][j] << " ";
	 }
	  std::cout << std::endl;
	}

	return 0;
}