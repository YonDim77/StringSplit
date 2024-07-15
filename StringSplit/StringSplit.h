#ifndef STRING_SPLIT_H
#define STRING_SPLIT_H

#include "StringSplitOtherVersion.h"


inline int countSubStrings(const char *string, const char *delimiter, int *subStringsLength)
{
	int count = 0, lengthSubString = 0;
	int lengthDelimiter = strlen(delimiter);
	bool isEqualToDelimiter = false;
	int consecutiveDelimiters = 0;	// If string begins with more than one consecutive delimiters

	while (*string)
	{
		int countDelimiterSymbols = 0;
		isEqualToDelimiter = isEqualStrings(string, delimiter, lengthDelimiter, countDelimiterSymbols);

		if (isEqualToDelimiter)
		{
			consecutiveDelimiters++;
			delimiter -= lengthDelimiter - 1;
			if (count != 0 || lengthSubString != 0 || consecutiveDelimiters > 1)
				subStringsLength[count++] = lengthSubString;
			lengthSubString = -1;
		}
		else
		{
			delimiter -= countDelimiterSymbols;
			string -= countDelimiterSymbols;
		}
		string++; lengthSubString++;
	}
	if (!isEqualToDelimiter)
		subStringsLength[count++] = lengthSubString;

	return count;
}

inline void insertSubStrings(const char *&string, const char *delimiter, const int *subStringsLength, const int i, char **resultArray)
{
	int lengthDelimiter = strlen(delimiter), c = 0;
	while (*string && c < subStringsLength[i])
	{
		int countDelimiterSymbols = 0;
		bool isEqualToDelimiter = isEqualStrings(string, delimiter, lengthDelimiter, countDelimiterSymbols);

		if (isEqualToDelimiter)
		{
			delimiter -= lengthDelimiter - 1;
		}
		else
		{
			delimiter -= countDelimiterSymbols;
			string -= countDelimiterSymbols;
			resultArray[i][c] = *string;
			c++;
		}
		string++;
	}
	resultArray[i][c] = '\0';
}

int numberOfSubStrings = 0, countEmptyElements = 0;

inline char **stringSplit(const char *string, const char *delimiter, bool &keepEmptyElements)
{
	int subStringsLength[50] = { 0 };
	numberOfSubStrings = countSubStrings(string, delimiter, subStringsLength);
	char **resultArray = new (std::nothrow) char*[numberOfSubStrings + 1];  // + 1 for nullptr
	if (!resultArray)
	{
		std::cout << "Failed to allocate memory for result array in stringSpli()!\n";
		return resultArray;
	}
	int i;
	for (i = 0; i < numberOfSubStrings; i++)
	{
		if (subStringsLength[i] == 0)
		{
			keepEmptyElements = true;
			countEmptyElements++;
		}

		resultArray[i] = new (std::nothrow) char[subStringsLength[i] + 1];
		if (!resultArray[i])
		{
			std::cout << "Failed to allocate memory for result array row in stringSpli()!\n";
			for (int j = 0; j < i; j++)
			{
				delete[] resultArray[j];
			}
			delete[] resultArray;
			return nullptr;
		}
		insertSubStrings(string, delimiter, subStringsLength, i, resultArray);
	}
	resultArray[i] = nullptr;

	return resultArray;
}


#endif
