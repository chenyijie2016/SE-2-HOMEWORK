#include "gcd.h"
#include <iostream>
#include "test.h"

using namespace std;

int main()
{
	int x;
	
	cout << "1 : �����������в���  2 : ��1000�ڵ��������Զ�����,  3: ����������� " << endl;
	cout << "������1,2 ��3��" << endl;
	cin >> x;

	switch (x)
	{
		case 1: Input_Integer(); break;
		case 2: AutoTest(); break;
		case 3: RandomTest(); break;
	default:
		cout << "��������";
		break;
	}
	system("pause");
	return 0;
}