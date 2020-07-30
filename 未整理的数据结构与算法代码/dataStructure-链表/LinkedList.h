
/*线性结构：
 * 		按照存储结构分类：顺序表、链表
 * 		按照操作分类：线性表、栈、队列
 *
 *链表：
 *		链表 = 若干个链表节点 + head指针。
 *		链表节点 = 数据域 + 指针域。
 *		指针域：只有next指针的是单链表，有prior和next指针的是双链表。
 *
 *注意异常：
 *		索引超出异常。
 *
 */


#ifndef SRC_LINKEDLIST_H_
#define SRC_LINKEDLIST_H_

#include "LinkedListNode.h"
#include <iostream>
using namespace std;

enum Status {SUCCESS, FAIL, UNDER_FLOW, OVER_FLOW,RANGE_ERROR, DUPLICATE_ERROR,
	NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};

template <typename T>
void disp(const T&);

//单链表类。
template <typename T>
class LinkedList
{protected:
	LinkedListNode<T>* head;
	int length;
public:
	//构造、析构函数：
	LinkedList();
	LinkedList(T err[], int n);						//用数组构造链表。
	LinkedList(const LinkedList<T>& l);				//拷贝构造函数
	~LinkedList();

	//set/get方法：
	int getLength()	const;
	LinkedListNode<T>* getHead() const;

	//操作单个元素的方法；
	Status getElem(int i, T& e) const;	 		// 求指定位置的元素
	Status setElem(int i, const T& e);	 		// 设置指定位置的元素值
	Status deleteElem(int i, T& e);		 		// 删除元素
	Status insertElem(int i, const T& e);	 	// 在制定位置插入元素
	Status insertElem(const T& e);	            // 在表尾插入元素

	//其他普通方法：
	bool isEmpty()	const;
	void clear();

	//遍历算法
	void traverse(void(*visit)(const T&));

	//查找算法
	int locateElem(const T&);
};





//实现部分：
template <typename T>
void disp(const T& e){cout << e << "   ";}

template <typename T>
LinkedList<T>:: LinkedList():head(NULL),length(0){}

template <typename T>
LinkedList<T>:: LinkedList(T err[],int n)
{
	LinkedListNode<T>* p = NULL;
	p = new LinkedListNode<T>(err[n-1], nullptr);				//末尾节点。
	if(n<=1){}
	else
	{
		for(int order = n-1; order>=1; order-- )
		{
			p = new LinkedListNode<T>(err[order-1],p);
		}
	}

	this->head = p;
	this->length = n;
}

template <typename T>
LinkedList<T>:: LinkedList(const LinkedList& l)
{
	int n = l.getLength();
	T arr[n];
	for(int i = 1; i<=n; i++){l.getElem(i,arr[i-1]);}
	LinkedList<T> temp = LinkedList<T>(arr, n);
	this->head = temp.getHead();
	this->length = n;
}

template <typename T>
LinkedList<T>:: ~LinkedList(){}

template <typename T>
int LinkedList<T>:: getLength() const {return this->length;}

template <typename T>
LinkedListNode<T>* LinkedList<T>:: getHead() const {return this->head;}

template <typename T>
Status LinkedList<T>:: getElem(int i, T& e) const
{
	if(i<1||i>this->length){return RANGE_ERROR;}
	else
	{
		LinkedListNode<T>* p = this->head;
		for(int order = 1; order<=i-1; order++){p = p->next;}
		e = p->data;
		return SUCCESS;
	}
}

template <typename T>
Status LinkedList<T>:: setElem(int i, const T& e)
{
	if(i<1||i>this->length){return RANGE_ERROR;}
	else
	{
		LinkedListNode<T>* p = this->head;
		for(int j = 1;j<=i;j++){p = p->next;}
		p->data = e;
		return SUCCESS;
	}
}

template <typename T>
Status LinkedList<T>:: deleteElem(int i, T& e)
{
	if(i<1||i>length){return RANGE_ERROR;}
	else
	{
		LinkedListNode<T>* p = this->head;					//前后双指针方法。
		LinkedListNode<T>* q = NULL;
		for(int order = 1;order<=i-1; order++){q = p; p = p->next;}
		e = p->data;
		q->next = p->next;
		delete p;
		this->length--;
		return SUCCESS;
	}
}

template <typename T>
Status LinkedList<T>:: insertElem(int i, const T& e)
{
	if(i<1||i>length){return RANGE_ERROR;}
	else
	{
		LinkedListNode<T>* p = this->head;
		LinkedListNode<T>* q = NULL;
		for(int j = 1;j<=i;j++){q = p; p = p->next;}
		LinkedListNode<T>* newp = new LinkedListNode<T>(e,p);
		q->next = newp;
		this->length++;
		return SUCCESS;
	}
}

template <typename T>
Status LinkedList<T>:: insertElem(const T& e)
{
	LinkedListNode<T>* p = this->head;
	LinkedListNode<T>* newp  = new LinkedListNode<T>(e, nullptr);
	if(p==nullptr)
	{
		p = newp;
		this->head = newp;
	}
	else
	{
		for(int j = 2; j<=this->length; j++){p = p->next;}
		p->next = newp;
	}
	this->length++;
	return SUCCESS;
}

template <typename T>
bool LinkedList<T>:: isEmpty() const
{
	return this->length == 0;
}

template <typename T>
void LinkedList<T>:: clear()
{
	LinkedListNode<T>* p = this->head;				//前后双指针的方法。
	LinkedListNode<T>* q = NULL;
	while(p!=NULL)
	{
		q = p;
		p = p->next;
		delete q;
	}
	this->length = 0;
}

template <typename T>
void LinkedList<T>:: traverse(void(*visit)(const T&))
{
	LinkedListNode<T>* p = this->head;
	if(p==nullptr){}
	else
	{
		for(int j = 1;j<=this->length;j++)
		{
			T temp = p->data;
			(*visit)(temp);
			p = p->next;
		}
	}
	cout << endl;

}

template <typename T>
int LinkedList<T>:: locateElem(const T& e)
{
	LinkedListNode<T>* p = this->head;
	int order = 1;
	while((p!=NULL)&&(p->data!=e)){p = p->next;order++;}
	return p==NULL ? 0 : order;
}











#endif /* SRC_LINKEDLIST_H_ */
