#include <iostream>
#include "file-reader.hpp"

int main () {

	LCSp1 part1;
	FileReader reader;
	if (reader.SetFile("twoStrings.txt") == false) {
		std::cout << "Failed to open twoStrings.txt" << std::endl;
		return -1;
	}

	reader.LoadData(part1);

	std::cout << part1.getString1() << std::endl;
	std::cout << std::endl;
	std::cout << part1.getString2() << std::endl;
	std::cout << std::endl;

	part1.buildCArray();

	int i = part1.getString1().length();
	int j = part1.getString2().length();

	part1.printLCS(i,j);


	return 0;
}