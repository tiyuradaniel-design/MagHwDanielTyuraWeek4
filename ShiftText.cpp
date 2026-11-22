#include <iostream>

#include "ShiftText.h"
#include "PlainText.h"

class ShiftText : public PlainText
{
private:
	int _key;
public:
	ShiftText(std::string text, int key)
	{
		this->text = text;
		this->_key = key;
	}
	~ShiftText()
	{
		delete[] this->text;
		delete this->isEncrypted;
		delete this->_key;
	}
	static std::string encrypt(std::string text, int key)
	{
		std::string result = text;
		for (int i = 0; i < result.length(); i++)
		{
			if (result[i] >= 'A' && result[i] <= 'Z')
			{
				result[i] = 'A' + (result[i] - 'A' + key) % 26;
			}
			else if (result[i] >= 'a' && result[i] <= 'z')
			{
				result[i] = 'a' + (result[i] - 'a' + key) % 26;
			}
		}
		this->isEncrypted = true;
		return result;
	}
	static std::string decrypt(std::string text, int key)
	{
		std::string result = text;
		for (int i = 0; i < result.length(); i++)
		{
			if (result[i] >= 'A' && result[i] <= 'Z')
			{
				result[i] = 'A' + (result[i] - 'A' - key + 26) % 26;
			}
			else if (result[i] >= 'a' && result[i] <= 'z')
			{
				result[i] = 'a' + (result[i] - 'a' - key + 26) % 26;
			}
		}
		this->isEncrypted = false;
		return result;
	}

	std::string encrypt()
	{
		return encrypt(this->text, this->_key);
	}
	std::string decrypt()
	{
		return decrypt(this->text, this->_key);
	}

};