#pragma once
#include <vector>
template <typename T, typename Less>

bool FindMax(std::vector<T> const &arr, T &maxValue,
	Less const &less = [&](T const &lhs, T const &rhs) {return lhs > rhs; })
{
	if (arr.empty())
	{
		return false;
	}
	for (auto const &element : arr)
	{
		if (less(element, maxValue))
		{
			maxValue = element;
		}
	}
	return true;
}