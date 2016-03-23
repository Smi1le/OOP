#include "stdafx.h"
#include "ProcessSet.h"
#include <iterator>
#include <vector>
#include <iostream>

using namespace std;

set<int> SieveOfEratosthenes(vector<bool> &vectorOfBool)
{
	set<int> primeNumbersList;
	for (size_t i = 2; ((i*i) <= vectorOfBool.size() - 1); ++i)
	{
		if (vectorOfBool[i])
		{
			for (size_t j = (i*i); j <= vectorOfBool.size() - 1; j += i)
			{
				if (vectorOfBool[j])
				{
					vectorOfBool[j] = false;
				}
			}
		}
	}

	for (size_t i = 2; i <= vectorOfBool.size(); ++i)
	{
		if (vectorOfBool[i])
		{
			primeNumbersList.insert(primeNumbersList.end(), static_cast<int>(i));
		}
	}
	return primeNumbersList;
}

void OutputInConsole(set<int> const &primeNumbersList)
{
	copy(primeNumbersList.begin(), primeNumbersList.end(), ostream_iterator<int>(cout, ", "));
}

set<int> GeneratePrimeNumbersSet(int const &upperBound)
{
	vector<bool> vectorOfBool;
	vectorOfBool.resize(upperBound + 1, true);
	return SieveOfEratosthenes(vectorOfBool);
}