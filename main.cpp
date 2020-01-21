#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstdio>
using namespace std;



/*
**	general note:
**
**
**
*/


/***************************************************************************
***************************************************************************/
// 全局变量、类型定义
void(*pfun[100])(void) = { nullptr };
int inputTag;							// 菜单界面中判断输入是否有效的标识符。
int inputNum;							// 菜单界面中用户输入的整数
int interfaceLevel;						// 当前菜单界面的层级，主菜单是一级。




/***************************************************************************
***************************************************************************/
// extern变量



/***************************************************************************
***************************************************************************/
// 函数声明



/***************************************************************************
***************************************************************************/
// extern函数
extern void reset_pfun(void);
extern void traverse_pfun(void);

extern void set_fun_linearStructure_sequence_list(void);
extern void set_fun_linearStructure_linked_list(void);



extern void start_linearStructure_sequence_list(void);
extern void start_linearStructure_linked_list(void);


/***************************************************************************
***************************************************************************/
// 函数定义
int main(int argc, char** argv)
{
	inputNum = 99;
	inputTag = 0;
	interfaceLevel = 1;


	reset_pfun();

	// 主界面循环——选择章节
	while (1 == interfaceLevel)
	{
		cout << "\n\n\n\n" << endl;
		cout << "**************************MAIN MENU**********************" << endl;
		cout << "Please input a number to choose a function setting plan:" << endl;
		cout << "-1. Quit" << endl;
		cout << "0. 线性结构" << endl;
		cout << "1. 树型结构" << endl;
		cout << "2. 图型结构" << endl;
		cout << "3. 查找算法" << endl;
		cout << "4. 排序算法" << endl;

		inputTag = scanf("%d", &inputNum);


		// 若输入值不是整数，重新输入。
		if (0 == inputTag)
		{
			cout << "Invalid input. Please input again:" << endl;
			setbuf(stdin, NULL);			// stdin输入流由默认缓冲区转为无缓冲区，这样就清空了缓冲区中的内容。
													// 不要用fflush来清空缓存区，该函数很多编译器支持得不好。
			continue;
		}


		// 对主界面输入值的响应：
		switch (inputNum)
		{
		case -1:							// 退出程序
		{
			interfaceLevel = 0;
			break;
		}

		case 0:								// 0. 线性结构
		{
			// 界面层级符置为2，进入二级界面：
			interfaceLevel = 2;
			while (2 == interfaceLevel)
			{
				cout << "\n\n\n\n" << endl;
				cout << "**************************LINEAR STRUCTURE MENU**********************" << endl;
				cout << "Please input a number to choose a function setting plan:" << endl;
				cout << "-1. Back to the previous interface" << endl;
				cout << "0. 线性结构——顺序表" << endl;
				cout << "1. 线性结构——链表" << endl;

				inputTag = scanf("%d", &inputNum);

				// 若输入值不是整数，重新输入。
				if (0 == inputTag)
				{
					cout << "Invalid input. Please input again:" << endl;
					setbuf(stdin, NULL);				// stdin输入流由默认缓冲区转为无缓冲区，这样就清空了缓冲区中的内容。
																// 不要用fflush来清空缓存区，该函数很多编译器支持得不好。
					continue;
				}

				// 对二级界面输入值的响应：
				switch (inputNum)
				{
				case -1:
					interfaceLevel = 1;
					break;

				case 0:
					reset_pfun();
					set_fun_linearStructure_sequence_list();
					start_linearStructure_sequence_list();
					break;
 
				case 1:
					reset_pfun();
					set_fun_linearStructure_linked_list();
					start_linearStructure_linked_list();
					break;

				default:
					cout << "Invalid input. Please input again:" << endl;
					break;
				}

			}
			break;
		}

		case 1:								// 1. 树形结构
		{}

		case 2:								// 2. 图型结构
		{}

		case 3:								// 3. 查找算法
		{}

		case 4:								// 4 . 排序算法
		{}
 
 

		default:							// default. 不合法的整数输入：
		{
			cout << "Invalid input. Please input again:" << endl;
			break;
		}

		}


	}



	return 0;




}

