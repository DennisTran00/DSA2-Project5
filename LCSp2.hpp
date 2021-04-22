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
#include <iomanip>

class LCSp2
{
	private:
		const static int POSLEN = 20;
		const int LINELEN = 120;
		int positions[POSLEN];
		int totStrings;
		double tenPercentLong, twentyPercentLong, fortyPercentLong;
		double ninetyPercentShort, eightyPercentShort, fiftyPercentShort;
	public:
		LCSp2();
		void computeLengths();
		void directAccess();
		void determineSimilarity(std::string stringX, std::string stringY);
};

#endif /*LCSP2_HPP*/