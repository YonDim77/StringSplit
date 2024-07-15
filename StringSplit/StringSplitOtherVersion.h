#ifndef STRING_SPLIT_OTHER_VERSION_H
#define STRING_SPLIT_OTHER_VERSION_H

#include <iostream>
#include <string>

inline bool isEqualStrings(const char *&string, const char *&delimiter, const int lengthDelimiter, int &countDelimiterSymbols)
{
	while (*delimiter == *string)
	{
		countDelimiterSymbols++;
		if (countDelimiterSymbols == lengthDelimiter)
			break;
		delimiter++;
		string++;
	}
	return *delimiter == *string;
}

int rowsInResultArray(const char *string, const char *delimiter, char resultArray[20][20])
{
	int lengthSubString = 0;
	int lengthDelimiter = strlen(delimiter);
	bool isEqualToDelimiter = false;
	int consecutiveDelimiters = 0;	// If string begins with more than one consecutive delimiters
	int rows = 0, columns = 0;
	while (*string)
	{
		int countDelimiterSymbols = 0;
		isEqualToDelimiter = isEqualStrings(string, delimiter, lengthDelimiter, countDelimiterSymbols);

		if (isEqualToDelimiter)
		{
			consecutiveDelimiters++;
			delimiter -= lengthDelimiter - 1;

			if (lengthSubString != 0 || consecutiveDelimiters > 1)
				resultArray[rows++][columns++] = '\0';
			lengthSubString = -1, columns = 0;
		}
		else
		{
			delimiter -= countDelimiterSymbols;
			string -= countDelimiterSymbols;
			resultArray[rows][columns++] = *string;
		}
		string++; lengthSubString++;
	}
	if (!isEqualToDelimiter)
		resultArray[rows++][columns++] = '\0';

	return rows;
}

int countOfSubStrings = 0, numberOfEmptyElements = 0;

inline char **stringSplitOtherVersion(const char *string, const char *delimiter, bool &keepEmptyElements)
{
	char saveResultArray[20][20] = {};
	countOfSubStrings = rowsInResultArray(string, delimiter, saveResultArray);
	char **resultArray = new (std::nothrow) char*[countOfSubStrings + 1];  // + 1 for nullptr
	if (!resultArray)
	{
		std::cout << "Failed to allocate memory for result array in stringSplitOtherVersion()!\n";
		return resultArray;
	}
	int i;
	for (i = 0; i < countOfSubStrings; i++)
	{
		if (strlen(saveResultArray[i]) == 0)
		{
			keepEmptyElements = true;
			numberOfEmptyElements++;
		}

		int saveResultArrayRowLength = strlen(saveResultArray[i]);
		resultArray[i] = new (std::nothrow) char[saveResultArrayRowLength + 1];
		if (!resultArray[i])
		{
			std::cout << "Failed to allocate memory for result array row in stringSplitOtherVersion()!\n";
			for (int j = 0; j < i; j++)
			{
				delete[] resultArray[j];
			}
			delete[] resultArray;
			return nullptr;
		}
		memcpy(resultArray[i], saveResultArray[i], saveResultArrayRowLength + 1);
	}
	resultArray[i] = nullptr;

	return resultArray;
}


#endif
