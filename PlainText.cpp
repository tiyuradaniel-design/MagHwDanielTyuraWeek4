#include "PlainText.h"
#include <iostream>
#include <string>

class PlainText
{
protected:
	std::string text;
	bool isEncrypted;

public:
	PlainText(std::string text)
	{
		this->text = text;
	}
	~PlainText() 
	{
		delete[] this->text;
		delete this->isEncrypted;
	}
	std::string getText() const 
	{
		return this->text;
	}
	bool IsEncrypted() const
	{
		return this->isEncrypted;
	}
};