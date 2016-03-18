// Lab2_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "ProccesorMap.h"

using namespace std;

int main()
{
	string subject = "I can Fly, maybe. You can?";
	string search = "can";
	string replace = "trololo";
	string str = FindAndReplace(subject, search, replace);
	cout << str << endl;
	return 0;
}

