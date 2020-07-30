#include <cstdio>
#include <string>
#include <iostream>
#include <vector>						//vector类模板在头文件<vector>中
using namespace std;



//  
/*
*/





/***************************************************************************
***************************************************************************/
// 全局变量、类型定义



/***************************************************************************
***************************************************************************/
// extern变量
extern void(*pfun[100])(void);
extern int inputTag, inputNum, interfaceLevel;


/***************************************************************************
***************************************************************************/
// 函数声明
void set_fun_treeStructure_basic(void);
void start_treeStructure_basic(void);


static void test0(void);
static void test1(void);
static void test2(void);
static void test3(void);
static void test4(void);


/***************************************************************************
***************************************************************************/
// extern函数
extern void traverse_pfun(void);



/***************************************************************************
***************************************************************************/
// 自定义类的实现



/***************************************************************************
***************************************************************************/
// 函数定义
void set_fun_treeStructure_basic(void)
{
	pfun[0] = test0;
	pfun[1] = test0;
	pfun[2] = test0;
	pfun[3] = test0;
	pfun[4] = test0;
	pfun[5] = test0;
}



void start_treeStructure_basic(void)
{
	// 界面层级符置为3，进入三级界面：
	interfaceLevel = 3;
	while (3 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MENU: linearStructure_sequence_list**********************" << endl;
		cout << "Please choose a demon function to run:" << endl;
		cout << "-2: Run all existed demon function." << endl;
		cout << "-1: Back to the previous interface." << endl;
		cout << "0. test0:  " << endl;


		inputTag = scanf("%d", &inputNum);

		// 若输入值不是整数，重新输入。
		if (inputTag != 1)
		{
			printf("Invalid input. Please input again:\n");
			setbuf(stdin, NULL);
			continue;
		}

		// 对三级界面输入值的响应。
		switch (inputNum)
		{
		case -2:
			traverse_pfun();
			break;

		case -1:
			interfaceLevel = 2;
			break;

		case 0:
			(*pfun[0])();
			break;
		
		
		case 1:
			(*pfun[1])();
			break;
		
		
		case 2:
			(*pfun[2])();
			break;
		
		
		case 3:
			(*pfun[3])(); 	
			break;
		
		
		case 4:
			(*pfun[4])();
			break;
		
			
		case 5:
			(*pfun[5])();
			break;





		default:
			printf("Invalid input. Please input again:\n");
			break;
		}


	}


}



//	test0: 
static void test0(void) {}



//	test1: 
static void test1(void) {}



//	test2: 
static void test2(void) {}



//	test3: 
static void test3(void) {}



//	test4: 
static void test4(void) {}



//	test5: 
static void test5(void) {}



