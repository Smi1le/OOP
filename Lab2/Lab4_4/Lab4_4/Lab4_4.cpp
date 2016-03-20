// Lab4_4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <new>
#include <locale>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "russian"); //установка русского языка в консоли
	unsigned i, j, S; //индексы
	int N; //размер массива
	bool *mas; //объявляем массив типа bool

	cout << "Простые числа от 1 до N \n";
	cout << "Введите число N ";
	cin >> S;
	N = S + 1;
	mas = new bool[N]; //динамически выделяем память под массив размером N

	for (i = 1; i <= S; i++) mas[i] = true; //заполняем массив значением true;

											//Алгоритм "Решето Эратосфена"
	for (i = 2; ((i*i) <= S); i++)
	{
		if (mas[i])
		{
			for (j = (i*i); j <= S; j += i)
			{
				if (mas[j]) mas[j] = false;
			}
		}
	}
	//Вывод результата на экран
	for (i = 1; i <= S; i++)
		if (mas[i]) cout << i << " ";


	system("pause");
	return 0;
}
