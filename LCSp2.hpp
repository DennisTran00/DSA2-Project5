/***************************************************************
  Student Name: Dennis Tran
  File Name: LCSp2.hpp
  DSA II Project #5
  header file for LCSp2.cpp
  Calcualtes the similarity between strings
***************************************************************/

#ifndef LCSP2_HPP
#define LCSP2_HPP

#include "LCSp1.hpp"
#include <fstream>
#include <stdio.h>
#include <string.h>

class LCSp2
{
	private:
		const static int POSLEN = 20;
		const int LINELEN = 120;
		int positions[POSLEN];
		int totStrings = 0;
	public:
		void computeLengths();
		void directAccess();
		void showPositionsArray();
};

#endif /*LCSP2_HPP*/