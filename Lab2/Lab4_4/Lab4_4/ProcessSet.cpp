#include "stdafx.h"
#include "ProcessSet.h"

using namespace std;

set<int> SieveOfEratosthenes(vector<bool> &arrayOfBool)
{
	set<int> primeNumbersList = { 1 };
	for (size_t i = 2; ((i*i) <= arrayOfBool.size() - 1); ++i)
	{
		if (arrayOfBool[i])
		{
			for (size_t j = (i*i); j <= arrayOfBool.size() - 1; j += i)
			{
				if (arrayOfBool[j])
				{
					arrayOfBool[j] = false;
				}
			}
		}
	}
	for (size_t i = 1; i <= arrayOfBool.size(); ++i)
	{
		if (arrayOfBool[i])
		{
			primeNumbersList.insert(static_cast<int>(i));
		}
	}
	return primeNumbersList;
}

void OutputInConsole(set<int> const &primeNumbersList)
{
	copy(primeNumbersList.begin(), primeNumbersList.end(), ostream_iterator<int>(cout, " "));
}

set<int> GeneratePrimeNumbersSet(int const &upperBound)
{
	vector<bool> arrayOfBool;
	arrayOfBool.resize(upperBound, true);
	set<int> primeNumbersList;
	primeNumbersList = SieveOfEratosthenes(arrayOfBool);
	return primeNumbersList;
}