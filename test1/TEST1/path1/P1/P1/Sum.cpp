#include "Sum.h"
#include <iostream>

using namespace std;

int InputInt()//输入正整数n
{
	int Number = 0;

	cout << "Input (n > 0) :";
	cin >> Number;

	return Number;
}

long Sumup1(int n)//循环相加
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

long Sumup2(int n)//利用公式求和
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
