#include "ProccesorMap.h"


using namespace std;

string FindAndReplace(string const &subject, string const &search, string const &replace)
{
	cout << "sdsdsdsd" << endl;
	if (subject.length() != 0)
	{
		string bufStr;
		for (size_t i = 0; i < subject.length();)
		{
			if (i <= subject.length() - search.length() && subject.substr(i, search.length()) == search)
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
	else
	{
		return subject;
	}
}