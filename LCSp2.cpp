#include "LCSp2.hpp"

LCSp2::LCSp2() {
	this->totStrings = 0;
	this->tenPercentLong = 0.0;
	this->twentyPercentLong = 0.0;
	this->fortyPercentLong = 0.0;
	this->ninetyPercentShort = 0.0;
	this->eightyPercentShort = 0.0;
	this->fiftyPercentShort = 0.0;
}

void LCSp2::computeLengths() {
	std::ifstream in;
	char line[LINELEN];
	in.open("multiStrings.txt");
	this->positions[0] = 0; 
	while(in.getline(line, LINELEN))
	{
	  positions[totStrings] = strlen(line)+1;
	  totStrings++;
	  line[strlen(line)] = '\0';
	}
	in.close();
}

void LCSp2::directAccess() {
	//matrix columns
	int numOfStrings = this->totStrings-1;
	std::cout << std::setw(3) << " ";
	for (int k = 0; k < numOfStrings; ++k) {
		std::string stringCount = "0" + std::to_string(k+1);
		std::cout << std::setw(3) << std::left << stringCount;
	}
	std::cout << std::endl;

	//matrix rows
    int i, j, currentPos = positions[0];
    char line[LINELEN];
    std::ifstream in;
    in.open("multiStrings.txt");
    in.seekg(currentPos);
    for(i = 1; i < totStrings-1; i++) {
    	//print row (string) number
    	std::string stringCount = "0" + std::to_string(i);
    	std::cout << std::setw(3) << std::left << stringCount;

    	//hyphens where strings are not compared
    	for (int m = 0; m < i; m++) {
    		std::cout << std::setw(3) << std::left << " -";
    	}
    	in.getline(line, LINELEN);
    	line[strlen(line)] = '\0';
    	//stringX is the row string 
    	std::string stringX = line;
    	for(j = i+1; j < totStrings; j++) {	
       		in.getline(line, LINELEN);
       		line[strlen(line)] = '\0';
       		std::string stringY = line;
       		determineSimilarity(stringX,stringY);
     	}
     	currentPos += positions[i];
     	in.seekg(currentPos);
     	std::cout << std::endl;
   }
   //printing last row, which is empty
   std::string stringCount = "0" + std::to_string(numOfStrings);
   std::cout << std::setw(3) << std::left << stringCount;
   for (int n = 0; n < numOfStrings; ++n) {
   		std::cout << std::setw(3) << std::left << " -";
   }
}

void LCSp2::determineSimilarity(std::string stringX, std::string stringY) {
	LCSp1 lcs(stringX,stringY);
	lcs.buildCArray();
	lcs.constructLCS(stringX.length(),stringY.length());  //updates count to get the length of the LCS
	int lcsLength = lcs.getCount();

	//stringX is the longer string
	if (stringX.length() >= stringY.length()) {
		//computing nevessary percentages for the long and short string
		this->tenPercentLong = stringX.length() - (stringX.length() * 0.10);
		this->twentyPercentLong = stringX.length() - (stringX.length() * 0.20);
		this->fortyPercentLong = stringX.length() - (stringX.length() * 0.40);

		this->ninetyPercentShort = stringY.length() * 0.90;
		this->eightyPercentShort = stringY.length() * 0.80;
		this->fiftyPercentShort = stringY.length() * 0.50;

		if (stringY.length() >= tenPercentLong) { // the length of the shorter string is within 10% of the length of the longer string
			if (lcsLength >= ninetyPercentShort) {
				std::cout << std::setw(3) << std::left << " H";
			} else if (lcsLength >= eightyPercentShort) {
				std::cout << std::setw(3) << std::left << " M";
			} else if (lcsLength >= fiftyPercentShort) {
				std::cout << std::setw(3) << std::left << " L";
			} else {
				std::cout << std::setw(3) << std::left << " D";
			}
		} else if (stringY.length() >= twentyPercentLong) { // the length of the shorter string is within 20% of the longer string
			if (lcsLength >= eightyPercentShort) {
				std::cout << std::setw(3) << std::left << " M";
			} else if (lcsLength >= fiftyPercentShort) {
				std::cout << std::setw(3) << std::left << " L";
			} else {
				std::cout << std::setw(3) << std::left << " D";
			}
		} else if (stringY.length() >= fortyPercentLong) { // the length of the shorter string is within 40% of the longer string
			if (lcsLength >= fiftyPercentShort) {
				std::cout << std::setw(3) << std::left << " L";
			} else {
				std::cout << std::setw(3) << std::left << " D";
			}
		} else { // Dissimilar strings are any that meet none of the above criteria
			std::cout << std::setw(3) << std::left << " D";
		}
	} else { //stringY is the larger string
		this->tenPercentLong = stringY.length() - (stringY.length() * 0.10);
		this->twentyPercentLong = stringY.length() - (stringY.length() * 0.20);
		this->fortyPercentLong = stringY.length() - (stringY.length() * 0.40);

		this->ninetyPercentShort = stringX.length() * 0.90;
		this->eightyPercentShort = stringX.length() * 0.80;
		this->fiftyPercentShort = stringX.length() * 0.50;

		if (stringX.length() >= tenPercentLong) { // the length of the shorter string is within 10% of the length of the longer string
			if (lcsLength >= ninetyPercentShort) {
				std::cout << std::setw(3) << std::left << " H";
			} else if (lcsLength >= eightyPercentShort) {
				std::cout << std::setw(3) << std::left << " M";
			} else if (lcsLength >= fiftyPercentShort) {
				std::cout << std::setw(3) << std::left << " L";
			} else {
				std::cout << std::setw(3) << std::left << " D";
			}
		} else if (stringX.length() >= twentyPercentLong) { // the length of the shorter string is within 20% of the longer string
			if (lcsLength >= eightyPercentShort) {
				std::cout << std::setw(3) << std::left << " M";
			} else if (lcsLength >= fiftyPercentShort) {
				std::cout << std::setw(3) << std::left << " L";
			} else {
				std::cout << std::setw(3) << std::left << " D";
			}
		} else if (stringX.length() >= fortyPercentLong) { // the length of the shorter string is within 40% of the longer string
			if (lcsLength >= fiftyPercentShort) {
				std::cout << std::setw(3) << std::left << " L";
			} else {
				std::cout << std::setw(3) << std::left << " D";
			}
		} else { // Dissimilar strings are any that meet none of the above criteria
			std::cout << std::setw(3) << std::left << " D";
		}
	}
}
