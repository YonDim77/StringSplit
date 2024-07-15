#include "StringSplit.h"


int main()
{
	const char *string = "  the quick brown fox  jumps over the brown fence  ";
	const char *delimiter = " ";
	std::cout << "Original string:\"" << string << "\"\n";
	std::cout << "Delimiter:\"" << delimiter << "\"\n";

	bool keepEmptyElements = false;
	char **resultArray = stringSplit(string, delimiter, keepEmptyElements);
	if (!resultArray)
		return 0;

	std::cout << "\nResult of stringSplit():" << "\nArray of substrings:\n\n{";
	for (int r = 0; r <= numberOfSubStrings; r++)
	{
		if (resultArray[r])
			std::cout << "\"" << resultArray[r] << "\", ";
		else
			std::cout << "Null pointer}\n";
	}

	if (keepEmptyElements)
		std::cout << "Array of substrings contains " << countEmptyElements << " empty elements\n";
	else
		std::cout << "Array of substrings not contains empty elements\n";

	// stringSplitOtherVersion()

	keepEmptyElements = false;
	char **sameResultArray = stringSplitOtherVersion(string, delimiter, keepEmptyElements);
	if (!sameResultArray)
	{
		for (int j = 0; j < numberOfSubStrings; j++)
		{
			delete[] resultArray[j];
		}
		delete[] resultArray;
		return 0;
	}

	std::cout << "\nResult of stringSplitOtherVersion():" << "\nArray of substrings:\n\n{";
	for (int r = 0; r <= countOfSubStrings; r++)
	{
		if (sameResultArray[r])
			std::cout << "\"" << sameResultArray[r] << "\", ";
		else
			std::cout << "Null pointer}\n";
	}

	if (keepEmptyElements)
		std::cout << "Array of substrings contains " << numberOfEmptyElements << " empty elements\n";
	else
		std::cout << "Array of substrings not contains empty elements\n";

	for (int j = 0; j < countOfSubStrings; j++)
	{
		delete[] sameResultArray[j];
	}
	delete[] sameResultArray;

	for (int j = 0; j < numberOfSubStrings; j++)
	{
		delete[] resultArray[j];
	}
	delete[] resultArray;

	return 0;
}

