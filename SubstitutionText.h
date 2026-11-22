#ifndef SUBSTITUTION_TEXT_H
#define SUBSTITUTION_TEXT_H

#include <iostream>
#include "PlainText.h"
#include "FileHelper.h"

class SubstitutionText : public PlainText
{
private:
	std::string _dictionaryFileName;
public:
	SubstitutionText(std::string text, std::string dictionaryFileName);
	~SubstitutionText();
	static std::string encrypt(std::string text, std::string dictionaryFileName);
	static std::string decrypt(std::string text, std::string dictionaryFileName);

	std::string encrypt();
	std::string decrypt();
};


#endif