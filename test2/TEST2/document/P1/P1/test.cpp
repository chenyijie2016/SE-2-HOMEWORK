#include "test.h"
#include "Sum.h"
#include <iostream>
using namespace std;
void StartTest()
{
	int i;

	cout << "START AUTOMATIC TEST" << endl;
	system("pause");

	for (i = 2; i <= 10000; i = i + 2)
	{
		cout << "----------Test n = " << i << "-----------" << endl;

		cout << "time:";
		system("@echo %time%");

		cout << "Result (1):" << Sumup1(i) << endl;

		cout << "time:";
		system("@echo %time%");

		cout << "Result (2):" << Sumup2(i) << endl;

		cout << "time:";
		system("@echo %time%");

		if (Sumup1(i) == Sumup2(i))
		{
			cout << "No difference!" << endl;
		}
		else
		{
			cout << "Test failed: Wrong Answer!" << endl;
		}

		cout << "--------------------------------" << endl;
		system("pause");
	}
	system("pause");
}

void StartSingleTest()
{
	int n = 0;

	n = InputInt();

	if (n <= 0)
	{
		cout << "Error!";
	}
	else
	{
		cout << "You input n = " << n << endl;
		cout << "time:";
		system("@echo %time%");
		cout << "Result1:" << Sumup1(n) << endl;
		cout << "time:";
		system("@echo %time%");
		cout << "Result2:" << Sumup2(n) << endl;
		cout << "time:";
		system("@echo %time%");
	}

	system("pause");

}
