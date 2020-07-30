#include <iostream>
#include <string>
#include <cmath>
#include <typeinfo>

#include <list>
#include <queue>

using namespace std;
/*
 *
 *
 *
 */

//最简单的递归算法：阶乘函数
int factorial(int n)							//阶乘f(n) = n*f(n-1); f(0) = 1
{
	if(n>0){return n*factorial(n-1);}			//调用自己。
	else if(n==0){return 1;}
	else {return 0;}							//可以设置为抛出异常。
}

//经典递归算法：汉诺塔
class hanoi
{private:
	int count;
public:
	hanoi():count(0){}

	void move(char a, char b)					//把a柱顶部的盘子移到b柱顶部。
	{
		cout << "move " << a << " to " << b << endl;
		this->count++;
	}

	void start(int n,char X,char Y,char Z)			//柱X上有n个盘子，要全部移到Z柱上。
	{
		if(n == 1){this->move(X,Z);}
		else if(n>1)
		{
			start(n-1,X,Z,Y);
			this->move(X,Z);
			start(n-1,Y,X,Z);
		}
	}

	void showCount(){cout << "step count = " << this->count << endl;}
};









int main()
{
	cout << "factorial(10) = " << factorial(10)<< endl;

	hanoi h;
	h.start(5,'X','Y','Z');
	h.showCount();



	return 0;
}
