// MyStack.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyStack.h"

using namespace std;

int main()
{
	CMyStack<string> stringStack;
	stringStack.Push("Hello");
	{
		CMyStack<string> stringStack1;
		stringStack1 = stringStack;
	}
	return 0;

}

