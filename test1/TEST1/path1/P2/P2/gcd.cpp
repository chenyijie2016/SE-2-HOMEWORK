#include "gcd.h"
#include <iostream>

using namespace std;

void Input_Integer()//��������
{
	int a = 0, b = 0;

	cout << "�����һ����:";

	cin >> a;

	cout << "����ڶ�����:";

	cin >> b;

	if (a <= 0 || b <= 0)
	{
		cout << endl << "��������";
	}
	else
	{
		cout << "Result(1):" << gcd(a, b) << endl;
		cout << "Result(2):" << gcd2(a, b) << endl;
	}
}

int gcd(int x, int y)//շת�����
{	
	int r;

	while (y > 0)
	{
		r = x % y;
		x = y;
		y = r;		
	}

	return x;
}

int gcd2(int x, int y)//Stein�㷨�����ڶԱȽ�� [����https://www.cnblogs.com/drizzlecrj/archive/2007/09/14/892340.html]
{
	if (x == 0) return y;
	if (y == 0) return x;
	if (x % 2 == 0 && y % 2 == 0) return 2 * gcd2(x >> 1, y >> 1);
	else if (x % 2 == 0) return gcd2(x >> 1, y);
	else if (y % 2 == 0) return gcd2(x, y >> 1);
	return gcd2(abs(x - y), min(x, y));
}

int min(int a, int b)
{
	if (a > b) return b;
	return a;
}
