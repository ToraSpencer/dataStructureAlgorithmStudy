//链表节点类

#ifndef SRC_LINKEDLISTNODE_H_
#define SRC_LINKEDLISTNODE_H_

#include <stddef.h>									//加入后可以避免识别不了NULL,nullptr的意外发生。

template <typename T>
struct LinkedListNode
{public:
	T data;
	LinkedListNode<T> *next;
	//构造、析构函数
	LinkedListNode();								//构造一个数据域、指针域都为空的节点。
	LinkedListNode(T,LinkedListNode<T>*);			//指定数据和指针的节点。
	LinkedListNode(const LinkedListNode<T>&);		//拷贝构造函数。
	~LinkedListNode();

};




//实现部分：
template <typename T>
LinkedListNode<T>::LinkedListNode():data(0),next(nullptr){}

template <typename T>
LinkedListNode<T>::LinkedListNode(T da, LinkedListNode<T>* ne):data(da),next(ne){}

template <typename T>
LinkedListNode<T>::LinkedListNode(const LinkedListNode& n)
{
	this->data = n.data;
	this->next = n.next;
}

template <typename T>
LinkedListNode<T>::~LinkedListNode(){}




#endif 
