/***************************************************************
  Student Name: Dennis Tran
  File Name: file-reader.hpp
  DSA II Project #5
***************************************************************/

#ifndef FILE_READER_HPP
#define FILE_READER_HPP

#include <fstream>
#include "LCSp1.hpp"

class FileReader
{
	private:
		std::ifstream inFile;
	public:
		bool SetFile(std::string filename);
		~FileReader();
		void LoadData(LCSp1 & l);
};

#endif /*FILE_READER_HPP*/