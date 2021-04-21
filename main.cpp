/***************************************************************
  Student Name: Dennis Tran
  File Name: main.cpp
  DSA II Project #5
  runs both part1 and part2 of the project
***************************************************************/

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

	part1.buildCArray();

	int i = part1.getString1().length();
	int j = part1.getString2().length();

	part1.constructLCS(i,j);
	part1.printLCS();


	return 0;
}