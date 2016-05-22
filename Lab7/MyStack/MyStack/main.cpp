// MyStack.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyStack.h"

using namespace std;

int main()
{
	CMyStack<int> stack;
	
	std::cout << stack.Peek() << endl;
	stack.Push(23);
	std::cout << stack.Peek() << endl;
	stack.Pop();
	std::cout << stack.Peek() << endl;
	return 0;

}

