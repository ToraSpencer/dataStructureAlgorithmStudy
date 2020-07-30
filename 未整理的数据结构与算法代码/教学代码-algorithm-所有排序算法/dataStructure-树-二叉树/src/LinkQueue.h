//链式栈类。
/* 队列：
 * 		先进后出（首进尾出，或尾进首出）
 * 		分类：顺序队列，链式队列。
 *
 *
 *  注意异常：
 *  	上溢出：队列塞满时还要进行加入元素的操作。
 *  	下溢出：队列为空时还要进行弹出元素，读取元素的操作。
 *
 */

#ifndef SRC_LINKQUEUE_H_
#define SRC_LINKQUEUE_H_

#include "LinkedListNode.h"
#include <stddef.h>
#include <iostream>
using namespace std;
//自定义类型
enum Status {SUCCESS, FAIL, UNDER_FLOW, OVER_FLOW,RANGE_ERROR, DUPLICATE_ERROR,
			 NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};


//对元素的访问函数
template <typename T>
void disp(const T&);							//输出元素

//链式队列类（尾进首出）
template <typename T>
class LinkQueue
{protected:
	LinkedListNode<T>* front;
	LinkedListNode<T>* rear;						//队首队尾指针。
public:
	//构造、析构函数：
	LinkQueue();
	LinkQueue(const LinkQueue<T> &q);		 			// 拷贝构造函数
	virtual ~LinkQueue();

	//get/set方法
	int getLength() const;
	LinkedListNode<T>* getFront() const;
	LinkedListNode<T>* getRear() const;


	//访问、操作单个元素的方法：
	Status getHead(T &e) const;			     			// 取队头操作
	Status delQueue(T &e);				     			// 出队操作
	Status enQueue(const T e);			     			// 入队操作

	//其他普通成员方法：
	bool isEmpty() const;
	void clear();

	//遍历算法
	void traverse(void (*visit)(const T&)) const ;
};






//实现部分
template <typename T>
void disp(const T& el)
{
	cout << el << "  " ;
}

template <typename T>
LinkQueue<T>:: LinkQueue():front(nullptr),rear(nullptr){}
/////
template <typename T>
LinkQueue<T>:: LinkQueue(const LinkQueue<T> &lq)
{
	T temp;
	this->front = nullptr;
	this->rear = nullptr;
	LinkedListNode<T>* p = lq.getFront();
	LinkedListNode<T>* q = nullptr;
	while(p!=nullptr)
	{
		q = p;
		temp = p->data;
		p = p->next;
		this->enQueue(temp);
	}
}

template <typename T>
LinkQueue<T>::  ~LinkQueue(){}

template <typename T>
int LinkQueue<T>:: getLength() const
{
	LinkedListNode<T>* p = this->front;
	LinkedListNode<T>* q = nullptr;
	int count = 0;
	while(p!=nullptr)
	{
		count++;
		q = p;
		p = p->next;
	}
	return count;
}

template <typename T>
LinkedListNode<T>* LinkQueue<T>:: getFront() const
{return this->front;}

template <typename T>
LinkedListNode<T>* LinkQueue<T>:: getRear() const
{return this->rear;}


template <typename T>
Status LinkQueue<T>:: getHead(T &e) const
{
	if(this->front == nullptr){return UNDER_FLOW;}					//下溢出；
	else
	{
		e = this->front->data;
		return SUCCESS;
	}
}

template <typename T>
Status LinkQueue<T>:: delQueue(T &e)
{
	if(this->front == nullptr){return UNDER_FLOW;}
	else
	{
		LinkedListNode<T>* temp = this->front;
		e = temp->data;
		this->front = this->front->next;
		if(this->rear == temp){this->rear = this->front;}		//出队前队里只有一个元素的话，出队后变为空队。
		delete temp;
		return SUCCESS;
	}

}

template <typename T>
Status LinkQueue<T>:: enQueue(const T e)
{
	LinkedListNode<T>* p;
	p = new LinkedListNode<T>(e, nullptr);
	if(p != nullptr)
	{
		if(this->rear == nullptr)
		{
			this->rear = p;
			this->front = p;
		}
		else
		{
			this->rear->next = p;
			this->rear = p;
		}
		return SUCCESS;
	}
	else{return OVER_FLOW;}									//因为系统问题开辟内存失败的话，返回上溢出异常。
}

template <typename T>
bool LinkQueue<T>:: isEmpty() const
{
	return this->front == nullptr;
}

template <typename T>
void LinkQueue<T>:: clear()
{
	LinkedListNode<T>* p = this->front;
	LinkedListNode<T>* q = nullptr;
	while(p!=nullptr)
	{
		q = p;
		p = p->next;
		delete q;
	}
	this->front = nullptr;
	this->rear = nullptr;
}

template <typename T>
void LinkQueue<T>:: traverse(void (*visit)(const T&)) const
{
	T temp;
	LinkedListNode<T>* p = this->front;
	LinkedListNode<T>* q = nullptr;
	while(p!=nullptr)
	{
		q = p;
		temp = q->data;
		(*visit)(temp);
		p = p->next;
	}
	cout << endl;

}





#endif /* SRC_LINKQUEUE_H_ */
