#pragma once
#include <vector>
#include <iostream>

template <typename T>
bool FindMax(std::vector<T> const &arr, T &maxValue)
{
	return FindMax(arr, maxValue, std::less<T>());
}

template <typename T, typename Less>
bool FindMax(std::vector<T> const &arr, T &maxValue, Less const &less)
{
	if (arr.empty())
	{
		return false;
	}
	T value = arr.front();
	for (auto const &element : arr)
	{
		if (less(value, element))
		{
			value = element;
		}
	}
	maxValue = value;
	return true;
}