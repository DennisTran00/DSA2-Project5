/***************************************************************
  Student Name: Dennis Tran
  File Name: LCSp1.hpp
  DSA II Project #5
***************************************************************/

#ifndef LCSP1_HPP
#define LCSP1_HPP

#include <string>
#include <iostream>

class LCSp1
{
	private:
		std::string string1;
		std::string string2;
		int** cArray;
		int m;
		int n;
	public:
		LCSp1();
		~LCSp1();
		void buildCArray();
		void setString1(std::string string1);
		void setString2(std::string string2);
		std::string getString1();
		std::string getString2();
		void printLCS(int i, int j);
		void printChar(int i);

};

#endif /*LCSP1_HPP*/