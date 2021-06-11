#ifndef __BIN_TREE_NODE_H__
#define __BIN_TREE_NODE_H__

// 二叉链表结点�?
template <class ElemType>
struct BinTreeNode
{
// 数据成员:
	ElemType data;						// 数据�?
	BinTreeNode<ElemType>  *leftChild;	// 左孩子指针域
	BinTreeNode<ElemType>  *rightChild;	// 右孩子指针域

//	构造函�?:
	BinTreeNode();		// 无参数的构造函�?
	BinTreeNode(const ElemType &d,// 已知数据元素�?,指向左右孩子的指针构造一个结�?
		BinTreeNode<ElemType> *lChild = NULL, 
		BinTreeNode<ElemType> *rChild = NULL);
};

// 二叉树结点类的实现部�?
template <class ElemType>
BinTreeNode<ElemType>::BinTreeNode()
// 操作结果：构造一个叶结点
{
	leftChild = rightChild = NULL;	// 叶结点左右孩子为�?
}

template <class ElemType>
BinTreeNode<ElemType>::BinTreeNode(const ElemType &d, 
	BinTreeNode<ElemType> *lChild, BinTreeNode<ElemType> *rChild)
// 操作结果：构造一个数据域为d,左孩子为lChild,右孩子为rChild的结�?
{	
	data = d;					// 数据元素�?
	leftChild = lChild;			// 左孩�?
	rightChild = rChild;		// 右孩�?
}

#endif

