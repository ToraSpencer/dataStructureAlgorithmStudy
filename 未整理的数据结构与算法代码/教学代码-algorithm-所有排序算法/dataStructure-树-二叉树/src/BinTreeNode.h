/*
 */

#include <stddef.h>
#include <string>
#include <iostream>
using namespace std;


#ifndef SRC_BINTREENODE_H_
#define SRC_BINTREENODE_H_

//二叉树的节点类。
template <typename T>
struct BinTreeNode								//不需要写方法，所以设置成结构体。
{public:
	//成员数据。
	T data;
	BinTreeNode<T>* left;
	BinTreeNode<T>* right;

	//构造函数。
	BinTreeNode();
	BinTreeNode(const T&, BinTreeNode<T>*, BinTreeNode<T>*);
};



//实现部分：
template <typename T>
BinTreeNode<T>:: BinTreeNode():data(0),left(nullptr),right(nullptr){}

template <typename T>
BinTreeNode<T>:: BinTreeNode(const T& e, BinTreeNode<T>* le, BinTreeNode<T>* ri):data(e),left(le),right(ri){}


#endif /* SRC_BINTREENODE_H_ */
