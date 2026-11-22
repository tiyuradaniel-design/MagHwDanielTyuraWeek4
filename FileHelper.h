#ifndef FILE_HELPER_H
#define FILE_HELPER_H

#include <iostream>

class FileHelper
{
public:
	string readFileToString(string fileName);
	void writeWordsToFile(string inputFileName, string outputFileName);
	void saveTextInFile(string text, string outputFileName);
};

#endif