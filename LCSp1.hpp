/***************************************************************
  Student Name: Dennis Tran
  File Name: LCSp1.hpp
  DSA II Project #5
***************************************************************/

#ifndef LCSP1_HPP
#define LCSP1_HPP

#include <string>

class LCSp1
{
	private:
		std::string string1;
		std::string string2;
	public:
		LCSp1();
		void setString1(std::string string1);
		void setString2(std::string string2);
		std::string getString1();
		std::string getString2();

};

#endif /*LCSP1_HPP*/