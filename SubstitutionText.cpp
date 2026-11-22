#include <iostream>
#include <fstream>
#include <string>

#include "SubstitutionText.h"
#include "FileHelper.h"
#include "PlainText.h"

class SubstitutionText : public PlainText
{
private:
	std::string _dictionaryFileName;
public:
	SubstitutionText(std::string text, std::string dictionaryFileName) 
	{
		this->text = text;
		this->_dictionaryFileName = dictionaryFileName;
	}
	~SubstitutionText() 
	{
		delete[] this->text;
		delete this->isEncrypted;
		delete[] this->_dictionaryFileName;
	}
	static std::string encrypt(std::string text, std::string dictionaryFileName) 
	{
		std::string dictionary = FileHelper::readFileToString(dictionaryFileName);

		std::string result = text;

		for (int i = 0; i < result.length(); i++)
		{
			for (int j = 0; j < dictionary.length(); j += 3)
			{
				if (result[i] == dictionary[j])
				{
					result[i] = dictionary[j + 1];
				}
			}
		}
		
		return result;
	}
	static std::string decrypt(std::string text, std::string dictionaryFileName) 
	{
		std::string dictionary = FileHelper::readFileToString(dictionaryFileName);

		std::string result = text;

		for (int i = 0; i < result.length(); i++)
		{
			for (int j = 0; j < dictionary.length(); j += 3)
			{
				if (result[i] == dictionary[j + 1])
				{
					result[i] = dictionary[j];
				}
			}
		}

		return result;
	}

	std::string encrypt() 
	{
		this->isEncrypted = true;
		return encrypt(this->text, this->_dictionaryFileName);
	}
	std::string decrypt() 
	{
		this->isEncrypted = false;
		return decrypt(this->text, this->_dictionaryFileName);
	}
};