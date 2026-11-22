#include "PlainText.h"
#include <iostream>
#include <string>

class PlainText
{
protected:
	static int numOfTexts;
	std::string text;
	bool isEncrypted;

public:
	PlainText(std::string text)
	{
		this->text = text;
		numOfTexts++;
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
	friend std::ostream& operator<<(std::ostream& os, const PlainText& p)
	{
		os << p.text;
		return os;
	}
};

int PlainText::numOfTexts = 0;