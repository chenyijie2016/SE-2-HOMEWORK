#include "test.h"
#include "gcd.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

void SigleTest()
{
	Input_Integer();
}

void AutoTest()//自动测试1000以内任意两个数的最大公约数 结果保存在result.txt内
{
	ofstream fout;
	fout.open("result.txt");

	int i, j;
	system("echo %time%");
	cout << "测试中..." << endl;
	for (i = 1; i <= 1000; i++)
	{
		
		
		for (j = 1; j <= i; j++)
		{
			fout << "____________________________" << endl;
			fout << "gcd(" << i << "," << j << ")=" << gcd(i, j) << endl;
			fout << "gcd2(" << i << "," << j << ")=" << gcd2(i, j) << endl;
			fout << "____________________________" << endl;
		}
	}
	system("echo %time%");
	cout << "测试完成，结果在result.txt中" << endl;
}

void RandomTest()//利用生成的随机数自动测试1000组
{
	srand(unsigned(time(0)));

	int i, a, b, tem1, tem2, mistake = 0;
	system("echo %time%");
	for (i = 1; i <= 1000; i++)
	{
		a = rand();

		b = rand();

		tem1 = gcd(a, b);
		tem2 = gcd2(a, b);
		if (tem1 != tem2)
		{
			mistake++;
		}
		cout << "____________________________" << endl;
		cout << "gcd(" << a << "," << b << ")=" << tem1 << endl;
		cout << "gcd2(" << a << "," << b << ")=" << tem2 << endl;
		cout << "____________________________" << endl;
	}
	
	cout << "测试完成，共有" << mistake << "组不同" << endl;
}
