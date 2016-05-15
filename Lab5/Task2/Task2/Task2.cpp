// Task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyString.h"

int main()
{
	std::string str1 = "someString";
	std::string str2 = " kakawka";
	CMyString str(str1 + str2);
	CMyString strr("ssssss");
	strr.Display();
	str.Display();
    return 0;
}

