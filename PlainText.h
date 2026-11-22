#ifndef PLAINTEXT_H
#define PLAINTEXT_H

#include <iostream>

class PlainText 
{
protected:
	std::string text;
	bool isEncrypted;

public:
	PlainText(std::string text);
	~PlainText();
	std::string getText() const;
	bool IsEncrypted() const;
};


#endif