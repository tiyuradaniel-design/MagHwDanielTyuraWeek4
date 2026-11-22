#ifndef SHIFT_TEXT_H
#define SHIFT_TEXT_H

#include <iostream>

#include "PlainText.h"

class ShiftText : public PlainText
{
private:
	int _key;
public:
	ShiftText(std::string text, int key);
	~ShiftText();
	std::string encrypt();
	std::string decrypt();
};


#endif