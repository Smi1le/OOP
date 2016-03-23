#include "stdafx.h"
#include "ProcessorString.h"
#include <boost/utility/string_ref.hpp>


using namespace std;

string FindAndReplace(string const &subject, string const &search, string const &replace)
{
	if (subject.empty())
	{
		return subject;
	}
	string bufStr;
	boost::string_ref str(subject);
	for (size_t i = 0; i < subject.length();)
	{
		if (i <= subject.length() - search.length() && (str.substr(i, search.length()) == search))
		{
			bufStr.append(replace);
			i += search.length();
		}
		else
		{
			bufStr += subject[i];
			++i;
		}
	}
	return bufStr;
}