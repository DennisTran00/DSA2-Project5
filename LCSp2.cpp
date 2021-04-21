#include "LCSp2.hpp"

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
    	in.getline(line, LINELEN);
    	line[strlen(line)] = '\0'; 
    	std::cout << "this string [" << line << "]" << std::endl;
    	for(j = i+1; j < totStrings; j++) {	
       		in.getline(line, LINELEN);
       		line[strlen(line)] = '\0';
       		std::cout << "  compared with [" << line << "]" << std::endl;
     	}
     	currentPos += positions[i];
     	in.seekg(currentPos);
   }
}

void LCSp2::showPositionsArray() {
  int i;
  for(i = 0; i < totStrings; i++)
  {
    std::cout << " line " << i << " position " << positions[i] << std::endl;
  }
}