#ifndef __BIN_TREE_NODE_H__
#define __BIN_TREE_NODE_H__

//二叉树结点结构体模板：只需要构造函数，所以设置成结构体。
template <class ElemType>
struct BinTreeNode
{
// 数据成员:
	ElemType data;						// 数据域
	BinTreeNode<ElemType>  *leftChild;	// 左孩子指针域
	BinTreeNode<ElemType>  *rightChild;	// 右孩子指针域

//	构造函数:
	BinTreeNode();						//指针为空，是一个叶节点。
	BinTreeNode(const ElemType &val, BinTreeNode<ElemType> *lChild = NULL, BinTreeNode<ElemType> *rChild = NULL);
};





// 实现部分：
template <class ElemType>
BinTreeNode<ElemType>::BinTreeNode()
{
	leftChild = rightChild = NULL;
}

template <class ElemType>
BinTreeNode<ElemType>::BinTreeNode(const ElemType &val, 
	BinTreeNode<ElemType> *lChild, BinTreeNode<ElemType> *rChild)
{	
	data = val;					// 数据元素值
	leftChild = lChild;			// 左孩子
	rightChild = rChild;		// 右孩子
}

#endif

