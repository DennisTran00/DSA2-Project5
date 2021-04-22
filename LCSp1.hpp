/***************************************************************
  Student Name: Dennis Tran
  File Name: LCSp1.hpp
  DSA II Project #5
  header file for LCSp1.cpp
  Calcualtes the LCS of two strings
***************************************************************/

#ifndef LCSP1_HPP
#define LCSP1_HPP

#include <string>
#include <iostream>
#include <sstream>

class LCSp1
{
	private:
		std::string string1;
		std::string string2;
		std::stringstream lcs;
		int** cArray;
		int m;
		int n;
		int count;
	public:
		LCSp1();
		LCSp1(std::string string1, std::string string2);
		~LCSp1();
		void buildCArray();
		void setString1(std::string string1);
		void setString2(std::string string2);
		std::string getString1();
		std::string getString2();
		void constructLCS(int i, int j);
		void printLCS();
		int getCount();

};

#endif /*LCSP1_HPP*/