#include "LCSp1.hpp"

LCSp1::LCSp1() {
	this->string1 = "";
	this->string2 = "";
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