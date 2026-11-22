#include <iostream>
#include "CaesarText.h"
#include "ShiftText.h"

class CaesarText : public ShiftText
{
public:
	CaesarText(std::string text)
	{
		this->text = text;
		this->_key = 3;
	}
	~CaesarText() 
	{
		delete[] this->text;
		delete this->isEncrypted;
		delete this->_key;
	}

	static std::string encrypt(std::string text)
	{
		return ShiftText::encrypt(text, 3);
	}
	static std::string decrypt(std::string text) 
	{
		return ShiftText::decrypt(text, 3);
	}

	std::string encrypt()
	{
		this->isEncrypted = false;
		return decrypt(this->text, this->_key);
	}
	std::string decrypt()
	{
		this->isEncrypted = true;
		return encrypt(this->text, this->_key);
	}
};