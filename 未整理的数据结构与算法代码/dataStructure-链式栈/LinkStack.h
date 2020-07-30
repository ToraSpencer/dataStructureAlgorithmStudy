//链式栈类。
/*栈：
 * 先进先出
 * 分类：顺序栈，链式栈。
 *
 */

#ifndef LINKSTACK_H_
#define LINKSTACK_H_

#include "LinkedListNode.h"
#include <iostream>
#include <stddef.h>
using namespace std;

//自定义类型
enum Status {SUCCESS, FAIL, UNDER_FLOW, OVER_FLOW,RANGE_ERROR, DUPLICATE_ERROR,
			 NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};




//对元素的访问函数
template <typename T>
void disp(const T&);							//输出元素


//链式栈类
template <typename T>
class LinkStack
{protected:
	LinkedListNode<T>* top;						//栈顶指针。
public:
	//构造函数和析构函数。
	LinkStack();
	LinkStack(const LinkStack& s);				//拷贝构造函数。
	~LinkStack();

	//get/set方法。
	LinkedListNode<T>* getTop()	const;
	int getLength()	const;							//返回栈长度：栈元素个数。

	//操作单个元素的方法。
	Status push(const T&);						//将元素e追加到栈顶,如成功则返加SUCCESS,否则若栈已满，动态内存已耗尽，返回OVER_FLOW
	Status pop(T&);
	Status Top(T&)	const;

	//其他普通方法：
	bool isEmpty()	const;
	void clear();

	//遍历方法：
	void Traverse(void (*Visit)(const T &)) const ;


};


//实现部分：
template <typename T>
void disp(const T& el)
{
	cout << el << "  " << endl;

}

template <typename T>
LinkStack<T>::LinkStack():top(NULL){}

template <typename T>
LinkStack<T>::LinkStack(const LinkStack& s)						//？？？
{
	if(s.isEmpty() == 1){this->top = NULL;}
	else
	{
		LinkedListNode<T>* p;
		T tempdata;
		s.Top(tempdata);

		p = new LinkedListNode<T>();

		for(p = s.top;p!=NULL;p = p->next)
		{
			T temp = p->data;
			this->push(temp);
		}
	}
}

template <typename T>
LinkStack<T>::~LinkStack(){this->clear();}

template <typename T>
LinkedListNode<T>*  LinkStack<T>::getTop()	const
{return this->top;}

template <typename T>
int LinkStack<T>::getLength()	const
{
	int count = 0;												//计数器。
	for(LinkedListNode<T>* p = top; top!=NULL; p = p->next){count++;}	//栈里的元素一个个数过去。
	return count;
}

template <typename T>
Status LinkStack<T>::push(const T& el)
{
	LinkedListNode<T>* top = this->getTop();
	LinkedListNode<T>* p = new LinkedListNode<T>(el, top);
	if(p == NULL){return OVER_FLOW;}						//上溢
	else{this->top = p; return SUCCESS;}
}

template <typename T>
Status LinkStack<T>::pop(T& PopReturnValue)
{
	if(this->isEmpty()){return UNDER_FLOW;}					//下溢
	else
	{
		LinkedListNode<T>* p = this->top;
		PopReturnValue = p->data;								//用外部的变量接收pop出的data————一种让函数有多个返回值的方法，引用传递。
		this->top = this->top->next;
		delete p;
		return SUCCESS;
	}

}

template <typename T>
Status LinkStack<T>::Top(T& TopReturnValue)	const
{
	if(this->isEmpty()){return UNDER_FLOW;}
	else
	{
		LinkedListNode<T>* top = this->getTop();
		TopReturnValue = top->data;
		return SUCCESS;
	}
}

template <typename T>
bool LinkStack<T>::isEmpty()	const
{
	if(top == NULL){return true;}
	else{return false;}
}

template <typename T>
void LinkStack<T>::clear()
{
	LinkedListNode<T>* p = NULL;
	while(p != NULL)
	{
		p = this->getTop();
		this->top = this->top->next;
		delete p;
	}
}

template <typename T>
void LinkStack<T>::Traverse(void (*Visit)(const T &)) const
// 操作结果：从栈顶到栈底依次对栈的每个元素调用函数(*visit)访问
{
	LinkedListNode<T> *p;
	for (p = top; p != NULL; p = p->next)	// 用p依次搜寻当前栈的每个元素
		(*Visit)(p->data);					// 对p所指向的元素调用函数(*visit)访问
}







#endif /* LINKSTACK_H_ */
