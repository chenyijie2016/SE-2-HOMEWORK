#include "gcd.h"
#include <iostream>
#include "test.h"

using namespace std;

int main()
{
	int x;
	
	cout << "1 : 对两个数进行测试  2 : 对1000内的数进行自动测试,  3: 进行随机测试 " << endl;
	cout << "请输入1,2 或3：" << endl;
	cin >> x;

	switch (x)
	{
		case 1: Input_Integer(); break;
		case 2: AutoTest(); break;
		case 3: RandomTest(); break;
	default:
		cout << "输入有误！";
		break;
	}
	system("pause");
	return 0;
}