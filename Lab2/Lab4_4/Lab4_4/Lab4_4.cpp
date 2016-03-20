// Lab4_4.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <new>
#include <locale>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "russian"); //��������� �������� ����� � �������
	unsigned i, j, S; //�������
	int N; //������ �������
	bool *mas; //��������� ������ ���� bool

	cout << "������� ����� �� 1 �� N \n";
	cout << "������� ����� N ";
	cin >> S;
	N = S + 1;
	mas = new bool[N]; //����������� �������� ������ ��� ������ �������� N

	for (i = 1; i <= S; i++) mas[i] = true; //��������� ������ ��������� true;

											//�������� "������ ����������"
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
	//����� ���������� �� �����
	for (i = 1; i <= S; i++)
		if (mas[i]) cout << i << " ";


	system("pause");
	return 0;
}
