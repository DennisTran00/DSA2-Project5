/***************************************************************
  Student Name: Dennis Tran
  File Name: LCSp1.cpp
  DSA II Project #5
  Calculates the LCS of two strings
***************************************************************/

#include "LCSp1.hpp"

LCSp1::LCSp1() {
	this->string1 = "";
	this->string2 = "";
	this->m = 0;
	this->n = 0;
}

LCSp1::~LCSp1() {
	for (int i = 0; i < m; ++i) {
		delete [] cArray[i];
	}
	delete [] cArray;
}

void LCSp1::buildCArray() {
	this->m = this->string1.length()+1;
	this->n = this->string2.length()+1;

	cArray = new int*[m];

	for (int j = 0; j < m; ++j) {
		this->cArray[j] = new int[n];
	}

	std::cout << "length(X) = " << this->string1.length() << std::endl;
	std::cout << "length(Y) = " << this->string2.length() << std::endl;

	//setting all values on the first row and column to 0
	for (int i = 1; i < m; ++i) {
		cArray[i][0] = 0;
	}
	for (int j = 0; j < n; ++j) {
		cArray[0][j] = 0;
	}

	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			if (string1[i-1] == string2[j-1]) {
				cArray[i][j] = cArray[i-1][j-1] + 1;
			} else {
				if (cArray[i-1][j] >= cArray[i][j-1]) {
					cArray[i][j] = cArray[i-1][j];
				} else {
					cArray[i][j] = cArray[i][j-1];
				}
			}
		}
	}
}

void LCSp1::constructLCS(int i, int j) {
	if(i == 0 || j == 0) {
		return;
	} else if (string1[i-1] == string2[j-1]) {
		constructLCS(i-1,j-1);
		this->lcs << this->string1[i-1];
	} else if (cArray[i-1][j] >= cArray[i][j-1]) {
		constructLCS(i-1,j);
	} else {
		constructLCS(i,j-1);
	}
}

void LCSp1::printLCS() {
	std::string result;
	this->lcs >> result;
	std::cout << "LCS length = " << result.length() << std::endl;
	std::cout << "The LCS = " << result << std::endl;
}

void LCSp1::setString1(std::string string1) {
	this->string1 = string1;
}

void LCSp1::setString2(std::string string2) {
	this->string2 = string2;
}

std::string LCSp1::getString1() {
	return this->string1;
}

std::string LCSp1::getString2() {
	return this->string2;
}