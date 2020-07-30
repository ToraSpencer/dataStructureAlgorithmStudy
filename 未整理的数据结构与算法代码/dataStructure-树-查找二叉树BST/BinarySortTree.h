/*
 * 二叉查找树/二叉搜索树/有序二叉树
 * binary sort/search tree
 *		所有节点满足：左子树所有key值 < 该节点key值 < 右子树所有节点key值
 *		没有键值相等的节点。
 *
 */

#ifndef SRC_BINARYSORTTREE_H_
#define SRC_BINARYSORTTREE_H_

#include "BinaryTree.h"
#include <random>

//查找二叉树类模板，继承自一般的二叉树类模板：
template <typename T>
class BinarySortTree:public BinaryTree<T>
{protected:
	BinTreeNode<T>* find(BinTreeNode<T>* p, const T& e) const;

public:
	BinarySortTree();
	BinarySortTree(const T &e);
	BinarySortTree(BinTreeNode<T> *pn);
	BinarySortTree(const BinarySortTree<T> &b);
	virtual ~BinarySortTree();

	BinTreeNode<T>* insert(const T& e);					//BTS的插入节点操作不能用父类的insertLeft和insertRight，因为有左<根<右的约束，所以要定义新的插入操作。
	void deleteNode(const T& e);						//重定义的删除操作，删除后的树仍然满足左<根<右的约束

	void randBST(int n);							   //将现有的BST销毁，建立起一个节点数为n的key值随机的BST；

	BinTreeNode<T>* find(const T& e) const;				//重定义查找算法，BST的查找算法比一般的BT的查找算法更高效
	BinTreeNode<T>* find_iteration(BinTreeNode<T>* p, const T& e) const;  //迭代查找算法，非递归。
	BinTreeNode<T>* findMax() const;					//查找最大值的算法。
	BinTreeNode<T>* findMin() const;

};








//实现部分
template <typename T>
BinarySortTree<T>::BinarySortTree():BinaryTree<T>(){}

template <typename T>
BinarySortTree<T>::BinarySortTree(const T &e):BinaryTree<T>(e){}

template <typename T>
BinarySortTree<T>::BinarySortTree(BinTreeNode<T> *pn):BinaryTree<T>(pn){}

template <typename T>
BinarySortTree<T>::BinarySortTree(const BinarySortTree<T> &b):BinaryTree<T>(b){}

template <typename T>
BinarySortTree<T>:: ~BinarySortTree(){}

//迭代
template <typename T>
BinTreeNode<T>* BinarySortTree<T>:: insert(const T& e)
/* BTS特有的插入节点操作：
 *		1.如果是空树，直接创建一个根节点。
 *		2.如果不是空树。
 *			需要先检验e在树种是否已经存在，如果已经存在则不执行插入。
 *			如果e在树中不存在，按照搜索算法的思路：e<f向左，e>f向右，纵向递归到空节点。
 *
 * 递归函数：
 * 	insert(pn(f)) = insert(pn->left(f));   e < f;
 * 	insert(pn(f)) = insert(pn->right(f));	e > f;
 * 	insert(nullptr) = 1;	递归终止条件
 * 这里没有用递归实现，用的是迭代实现，基本思想是一样的。
 */
{
	BinTreeNode<T>* p = nullptr;
	BinTreeNode<T>* q = nullptr;
	if(this->root == nullptr)			//树为空，直接插入节点做根。
	{
		p = new BinTreeNode<T>(e,nullptr,nullptr);
		this->root = p;
		return p;
	}
	else
	{
		p = this->root;
		q = this->root;
		while(p!=nullptr)
		{
			if(e < p->data)
			{
				q = p;					//双指针法。
				p = p->left;
			}
			else if(e > p->data)
			{
				q = p;
				p = p->right;
			}
			else
			{
				cout << "树中已有此元素，或此元素和节点键值类型不匹配，插入失败。" << endl;
				return nullptr;		//e==f说明树中已经有e，取消插入；若e无法和f比较大小，说明不是同一个数据类型，不可以插入。
			}
		}
		p = new BinTreeNode<T>(e,nullptr,nullptr);
		if(e < q->data){q->left = p;}
		else{q->right = p;}
		return p;
		}
	}
//XXX删除节点的左右子树都非空的情形有错误，考虑以后用SWITCH语句改写。
template <typename T>
void BinarySortTree<T>:: deleteNode(const T& e)
/* 满足BTS约束的删除操作：
 * 		1.如果树为空，则删除失败。
 * 		2.如果被删除节点只有一个子树，直接把子树往上移。
 * 		3.如果被删除节点左右子树都有，有两种方法：(1)该节点换为左子树的最大元素；(2)该节点换为右子树的最小元素。
 */
{
	BinTreeNode<T>* p = nullptr;
	BinTreeNode<T>* q = nullptr;
	if(this->root==nullptr){return;}					//空树
	else
	{
		p = this->find(e);
		if(p==nullptr)									//树中没有这个元素。
		{
			cout << "树中没有这个元素。" << endl;
			return;
		}
		else
		{
			if(p->left==nullptr&&p->right==nullptr)		//1.待删除节点是叶子。
			{
				q = this->parent(p);
				if(q->left==p){q->left = nullptr;}
				else{q->right = nullptr;}
				delete p;
				p = nullptr;
			}

			else if(p->right==nullptr)					//2.待删除节点只有左子树。
			{
				q = this->parent(p);
				if(q->left==p){q->left = p->left;}
				else{q->right = p->left;}
				delete p;
				p = nullptr;
			}

			else if(p->left==nullptr)					//3.待删除节点只有右子树。
			{
				q = this->parent(p);
				if(q->left==p){q->left = p->right;}
				else{q->right = p->right;}
				delete p;
				p = nullptr;
			}

			else										//4.待删除节点左右子树都非空。
			{											//采用方法1，节点换为左子树的最大节点。
				q = this->parent(p);
				BinarySortTree<T> tl = BinarySortTree(p->left);
				BinTreeNode<T>* r = tl.findMax();						//最大节点必定是叶子。
				BinTreeNode<T>* pr = this->parent(r);
				if(p==q->left){q->left = r;}
				else{q->right = r;}
				r->left = p->left;
				r->right = p->right;
				pr->right = nullptr;
				delete p;
				p = nullptr;
				cout << "@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
				return;
			}
		}
	}
}

template <typename T>
void BinarySortTree<T>:: randBST(int n)
{
	int count = 0;
	int insertNum;
	BinTreeNode<T>* p = nullptr;
	BinTreeNode<T>* r = nullptr;
	default_random_engine e;
	uniform_int_distribution<int> i(-100,100);

	this->destroy(this->root->left);
	this->destroy(this->root->right);
	this->root = nullptr;


	if(n <= 0){cout << "参数错误，n必须为大于0的整数。";}
	else
	{
		insertNum =  (T)i(e);
		r = this->insert(insertNum);
		count++;
		while(count<n)
		{
			insertNum =  (T)i(e);
			p = this->insert(insertNum);
			if(p!=nullptr){count++;}
		}
		this->root = r;
	}

}

//递归
template <typename T>
BinTreeNode<T>* BinarySortTree<T>:: find(BinTreeNode<T>* p, const T& e) const
//元素和当前节点值f比较，小于f则左下搜索，大于f则右下搜索，等于则返回当前节点。
/* 递归函数： find(pn(f)) = find(pn->left(f));   e < f
 * 		     find(pn(f)) = find(pn->rignt(f));  e > f
 *           find(pn(f)) = 1;  f = e      			//递归终止条件
 * 			 find(nullptr) = 0			  			//递归终止条件
 */
{
	if(p==nullptr){return nullptr;}					//起始节点为空，无从查找。
	if(e<p->data){return find(p->left, e);}
	if(e>p->data){return find(p->right,e);}
	else{return p;}
}

template <typename T>
BinTreeNode<T>* BinarySortTree<T>:: find(const T& e) const
{
	return find(this->root,e);
}

template <typename T>
BinTreeNode<T>* BinarySortTree<T>::find_iteration(BinTreeNode<T>* p, const T& e) const
/* 迭代算法实现的查找。
 * 		while循环实现的迭代。
 *		循环终止条件：搜索到空指针，或循环体内出现return终止了函数。
 */
{
	while(p!=nullptr)
	{
		if(e < p->data){p = p->left;}
		if(e > p->data){p = p->right;}
		else{return p;}
	}
	return nullptr;
}

template <typename T>
BinTreeNode<T>* BinarySortTree<T>:: findMax() const
//最大键值节点一定在最右端，一直往右查即可。
{
	if(this->isEmpty()){return nullptr;}
	BinTreeNode<T>* p = this->root;					//双指针法。
	BinTreeNode<T>* q = q;
	while(p!=nullptr)
	{
		q = p;
		p = p->right;
	}
	return q;
}

template <typename T>
BinTreeNode<T>* BinarySortTree<T>:: findMin() const
{
	if(this->isEmpty()){return nullptr;}
	BinTreeNode<T>* p = this->root;
	BinTreeNode<T>* q = q;
	while(p!=nullptr)
	{
		q = p;
		p = p->left;
	}
	return q;

}





#endif /* SRC_BINARYSORTTREE_H_ */
