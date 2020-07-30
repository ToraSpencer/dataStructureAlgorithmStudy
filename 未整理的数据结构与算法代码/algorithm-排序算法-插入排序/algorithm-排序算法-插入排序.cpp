#include "Assistance.h"
#include <string>
#include <iostream>

#include "ShellSort_teachingCode.h"
#include "StraightInsertSort_teachingCode.h"
using namespace std;

/*插入排序：
 * 		1. 直接插入排序。
 * 		2. shell希尔排序。
 *
 *
 *
 *
 *
 */

//test1: 直接插入排序；
void test1()
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10;
	cout << "排序前:";
	Display(a, n);
	StraightInsertSort(a, n);
	cout << "排序后:";
	Display(a, n);
}

void test2()
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10;
	cout << "排序前:";
	Display(a, n);
	ShellSort(a, n);			// 希尔排序
	cout << "排序后:";
	Display(a, n);
}


int main()
{
	//test1();
	test2();

	return 0;
}
