#ifndef __NODE_H__
#define __NODE_H__

//自己编写的链表结点类
template <class ElemType>
struct Node 
{
// 数据成员:
	ElemType data;				// 数据域
	Node<ElemType> *next;		// 指针域

// 构造函数:
	Node();
	Node(ElemType item, Node<ElemType> *link = NULL);
};






//实现部分：
template<class ElemType>
Node<ElemType>::Node()
// 操作结果：构造指针域为空的结点
{
   next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType> *link)
// 操作结果：构造一个数据域为item和指针域为link的结点
{
   data = item;
   next = link;
}

#endif
