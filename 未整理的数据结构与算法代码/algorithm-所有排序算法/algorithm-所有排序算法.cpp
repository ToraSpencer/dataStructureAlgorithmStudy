
#include "Assistance.h"
#include "HeapSort.h"				// 堆排序算法
#include "LinkInsertSort.h"	    	// 静态链表上的插入排序算法
#include "LinkMergeSort.h"
#include "LinkSelectionSort.h"
#include "RadixSort.h"
#include "RecursionMergeSort.h"
#include "ShellSort.h"
#include "SimpleSelectionSort.h"
#include "StraightInsertSort.h"

#include <string>
#include <iostream>
using namespace std;

//test1：堆排序
void test1()
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10;
	cout << "排序前:";
	Display(a, n);
	HeapSort(a, n);					// 堆排序
	cout << "排序后:";
	Display(a, n);
}

//test2：链表插入排序
void test2()
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
		int n = 10, p;
	    Node<int> *table;              	// 静态链表

	    table = new Node<int>[n + 1];
	    for (p = 1; p <= n; p++){		// 根据数组a中的元素构造静态链表
	        table[p].data = a[p - 1];
	        table[p - 1].next = p;
	    }
	    table[n].next = -1;


		cout << "排序前:";
	    for (p = table[0].next; p != -1; p = table[p].next)
	        cout << table[p].data << "   ";
	    cout << endl;

		LinkInsertSort(table);		   // 静态链表上的插入排序

		cout << "排序后:";
	    for (p = table[0].next; p != -1; p = table[p].next)
	        cout << table[p].data << "   ";
	    cout << endl;
}


/*
//test3：链表归并排序。
void test3()
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10, p;
    Node<int> *table;              // 静态链表

    table = new Node<int>[n + 1];
    for (p = 1; p <= n; p++){
        table[p].data = a[p - 1];
        table[p].next = -1;
    }


	cout << "排序前:" << endl;
    for (p = 1; p <= n; p++)
        cout << "(" << table[p].data << "," << table[p].next << ")" << endl;
    cout << endl;

	table[0].next = LinkListMergeSort(table, 1, n);		    // 静态链表上的归并排序

	cout << "排序后:";
    for (p = table[0].next; p != -1; p = table[p].next)
        cout << table[p].data << "   ";
    cout << endl;
}
*/




//test4：链表选择排序
void test4()
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10, p;
    Node<int> *table;              	// 静态链表

    table = new Node<int>[n + 1];
    for (p = 1; p <= n; p++){		// 根据数组a中的元素构造初始静态链表
        table[p].data = a[p - 1];
        table[p - 1].next = p;
    }
    table[n].next = -1;


	cout << "排序前:";
    for (p = table[0].next; p != -1; p = table[p].next)
        cout << table[p].data << "   ";
    cout << endl;

	LinkSelectionSort(table);		// 静态链表上的选择排序

	cout << "排序后:";
    for (p = table[0].next; p != -1; p = table[p].next)
        cout << table[p].data << "   ";
    cout << endl;

}

//test：基数排序
void test5()
{
	int a[] = {432, 820, 53, 786, 481, 529, 314, 608, 764, 104};
	int n = 10, r = 10, d = 3, p;
    Node<int> *table;              // 静态链表

    table = new Node<int>[n + 1];
    for (p = 1; p <= n; p++){
        table[p].data = a[p - 1];
        table[p - 1].next = p;
    }
    table[n].next = -1;

	cout << "排序前:";
    for (p = table[0].next; p != -1; p = table[p].next)
        cout << table[p].data << "   ";
    cout << endl;

	RadixSort(table, d, r);			// 基数排序

	cout << "排序后:";
    for (p = table[0].next; p != -1; p = table[p].next)
        cout << table[p].data << "   ";
    cout << endl;

}

//test6：递归归并排序
void test6()
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10;
	cout << "排序前:";
	Display(a, n);
	RecursionMergeSort(a, 0, n - 1, n);	// 递归的归并排序
	cout << "排序后:";
	Display(a, n);

}

//test7：希尔排序
void test7()
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10;
	cout << "排序前:";
	Display(a, n);
	ShellSort(a, n);			// 希尔排序
	cout << "排序后:";
	Display(a, n);

}

//test8：简单选择排序。
void test8()
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10;
	cout << "排序前:";
	Display(a, n);
	SimpleSelectionSort(a, n);		// 简单选择排序
	cout << "排序后:";
	Display(a, n);

}

//test9：直接插入排序。
void test9()
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10;
	cout << "排序前:";
	Display(a, n);
	StraightInsertSort(a, n);
	cout << "排序后:";
	Display(a, n);

}


int main(void)
{
	test9();



	return 0;
}
