#include "Sum.h"
#include <iostream>

using namespace std;

int InputInt()//����������n
{
	int Number = 0;

	cout << "Input (n > 0) :";
	cin >> Number;

	return Number;
}

long Sumup1(int n)//ѭ�����
{
	long i, result = 0;

	for (i = 0; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			result += i;
		}
	}

	return result;
}

long Sumup2(int n)//���ù�ʽ���
{
	if (n % 2 == 0)
	{
		return n / 4 * (n + 2);
	}
	else
	{
		return (n - 1) / 4 * (n + 1);
	}
}
