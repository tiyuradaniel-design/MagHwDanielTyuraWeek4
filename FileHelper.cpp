#include "FileHelper.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

FileHelper::FileHelper()
{
public:
	string readFileToString(string fileName)
	{
		std::ifstream inFile(fileName);
		if (!inFile.is_open()) 
		{
			std::cerr << "Error: Failed to open file for reading: " << fileName << "\n";
			return "";
		}

		std::ostringstream buffer;
		buffer << inFile.rdbuf();
		inFile.close();
		return buffer.str();
	}
	void writeWordsToFile(string inputFileName, string outputFileName)
	{
		std::ifstream inFile(inputFileName);
		if (!inFile.is_open()) 
		{
			std::cerr << "Error: Failed to open input file for reading: " << inputFileName << "\n";
			return;
		}
		std::ofstream outFile(outputFileName);
		if (!outFile.is_open()) 
		{
			std::cerr << "Error: Failed to open output file for writing: " << outputFileName << "\n";
			inFile.close();
			return;
		}
		std::string word;
		while (inFile >> word) 
		{
			outFile << word << std::endl;
		}
		inFile.close();
		outFile.close();
	}
	void saveTextInFile(string text, string outputFileName)
	{
		std::ofstream outFile(outputFileName);
		if (!outFile.is_open()) 
		{
			std::cerr << "Error: Failed to open output file for writing: " << outputFileName << "\n";
			return;
		}
		outFile << text;
		outFile.close();
	}
};