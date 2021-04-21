/***************************************************************
  Student Name: Dennis Tran
  File Name: file-reader.cpp
  DSA II Project #5
  Reads the strings from twoStrings.txt
  sets string1 and string2 in the LCSp1 class
***************************************************************/

#include "file-reader.hpp"

//Used to open twoStrings.txt as an input file.
//Returns false if the file is not in the directory or is spelled incorrectly
bool FileReader::SetFile (std::string filename) {
	inFile.open(filename);

	if(!inFile.is_open()) {
		return false;
	} else {
		return true;
	}
}

//closes the input file
FileReader::~FileReader () {
	inFile.close();
}


//Takes the two strings from twoStrings.txt and sets string1 and string2 respectively
void FileReader::LoadData (LCSp1 & l) {
	std::string s1 = "";
	std::string s2 = "";

	inFile >> s1;
	inFile >> s2;

	l.setString1(s1);
	l.setString2(s2);
}