#ifndef CAESAR_TEXT_H
#define CAESAR_TEXT_H

#include <iostream>

#include "ShiftText.h"

class CaesarText : public ShiftText
{
public:
	CaesarText(std::string text);
	~CaesarText();

	static std::string encrypt(std::string text);
	static std::string decrypt(std::string text);

	std::string encrypt();
	std::string decrypt();
};


#endif