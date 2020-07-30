/*树——二叉树
 *
 *
 * 		遍历算法：遍历的本质————多维降到一维
 * 				深度优先遍历：
 * 							先序：所有节点第一次碰到就访问。
 * 							中序：叶子节点第一次碰到就访问，其他节点第二次碰到才访问。
 * 							后序：叶子节点第一次碰到就访问，其他节点最后一次碰到才访问。
 * 				广度优先遍历：
 *
 * 		特殊的二叉树：
 * 				满二叉树(full binary tree)：除最后一层外，每个节点都有两个孩子节点
 * 				完全二叉树(complete BT)：
 * 									   	定义：对于深度为K的，有n个结点的二叉树，当且仅当其每一个结点都与深度为K的满二叉树中编号从1至n的结点一一对应时称之为完全二叉树。
 * 										性质：第i个节点的左孩子是第2*i个节点，右孩子是第2*i+1个节点。
 *
 * 				二叉查找树（有序二叉树BTS）：对于每一个节点，值都满足：左<根<右边。
 *
 */

#ifndef SRC_BINARYTREE_H_
#define SRC_BINARYTREE_H_

#include "BinTreeNode.h"
#include "LinkQueue.h"
#include <vector>



//二叉树类
template <typename T>
class BinaryTree
{protected:
	//成员数据：
	BinTreeNode<T>* root;					// 根节点。

	//私有方法：帮助其他类方法运转。
	BinTreeNode<T>* copyTree(BinTreeNode<T>* p);		//拷贝出一棵以*p为根的树，返回拷贝出的树的根节点。
	void destroy(BinTreeNode<T>* p);					//删除以*p为根的二叉树(递归)
	void preorderTraverse(BinTreeNode<T>* pb, void (*visit)(const T &)) const;			//对*pb为根节点的树进行递归先序遍历：根左右
	void inorderTraverse(BinTreeNode<T>* pb, void (*visit)(const T &)) const;
	void postorderTraverse(BinTreeNode<T>* pb, void (*visit)(const T &)) const;
	void levelorderTraverse(BinTreeNode<T>* pb, void (*visit)(const T &)) const;
    int height(const BinTreeNode<T> *p) const;						// 求以p为根的二叉树的高
	int nodeCount(const BinTreeNode<T> *p) const;					// 求以p为根的二叉树的结点个数
	BinTreeNode<T>* parent(BinTreeNode<T>* pp, const BinTreeNode<T>* p) const;	// 从pp节点开始往下找p的父节点。

public:
	//构造、析构函数。
	BinaryTree();
	BinaryTree(const T &e);								// 输入一个数据e，建立数据域为e的根节点的二叉树。
	BinaryTree(BinTreeNode<T> *pn);						// 输入一个二叉树节点的指针pn，以此为根节点构造二叉树；
	BinaryTree(const BinaryTree<T> &b);				    // 拷贝构造函数
	virtual ~BinaryTree();

	//get/set方法。
	BinTreeNode<T>*  getRoot() const;
	BinTreeNode<T>*  getLeft() const;
	BinTreeNode<T>*  getRight() const;

	//操作单个元素的方法。
	Status getElem(BinTreeNode<T>* p, T e) const;			// 用变量e接收p指向的节点的数据域的值。
	Status setElem(BinTreeNode<T>* p, const T& e);			// 将p指向的节点的数据域的值更改为e。
	void insertLeft(BinTreeNode<T>* p, const T& e);			// 插入一个结点e作为p的左孩子
	void insertRight(BinTreeNode<T>* p, const T& e);		// 插入一个结点e作为p的右孩子
	void deleteLeft(BinTreeNode<T>* p);						// 删除p的左子树
	void deleteRight(BinTreeNode<T>* p);					// 删除p的右子树

	//普通成员方法。
	bool isEmpty() const;
	void clear();
	int height() const;										//求树的深度。
	int nodeCount() const;									//求节点个数。
	BinTreeNode<T>* parent(const BinTreeNode<T>* p) const;
	void ancestors(BinTreeNode<T>* p) const;				//依次打印p节点所有祖先的节点值，直到根节点为止。
	void printInfo() const;									//打印该树的所有属性。


	//打印二叉树的方法：
	void disp_treeShape();									//分层打印二叉树

	//生成特殊的二叉树的方法：
	static BinTreeNode<T>* completeBT(int n);		 				//生成一个n个节点的完全二叉树，每个节点的值就是它的编号。


	//遍历算法。
	//深度优先遍历：
	void preorderTraverse(void (*visit)(const T &)) const;			//递归先序遍历：根左右
	void inorderTraverse(void (*visit)(const T &)) const;			//递归中序遍历：左根右
	void inorderTraverse_nonrecursive(void (*visit)(const T&)) const;//栈实现的非递归中序遍历。
	void postorderTraverse(void (*visit)(const T &)) const;			//递归后序遍历：左右根
	//广度优先遍历：
	void levelorderTraverse(void (*visit)(const T &)) const;		//层次遍历，队列实现。

	//查找算法。
	BinTreeNode<T>* find(const T& e) const;							//返回数据域值为e的节点的指针。
};








//实现部分

//构造、析构函数：
template <typename T>
BinaryTree<T>:: BinaryTree():root(nullptr){}

template <typename T>
BinaryTree<T>:: BinaryTree(const T& e)
{
	BinTreeNode<T>* p = nullptr;
	p = new BinTreeNode<T>(e,nullptr,nullptr);
	this->root = p;
}

template <typename T>
BinaryTree<T>:: BinaryTree(BinTreeNode<T>* pn):root(pn){}

template <typename T>
BinTreeNode<T>* BinaryTree<T>:: copyTree(BinTreeNode<T>* p)
//从p开始向下递归，每碰到一个节点就new出一个节点。
{
	BinTreeNode<T>* l = nullptr;
	BinTreeNode<T>* r = nullptr;
	BinTreeNode<T>* q = nullptr;
	if(p == nullptr){return nullptr;}		//若p是空树的根，复制一个空树。
	else
	{
		l = copyTree(p->left);
		r = copyTree(p->right);				//递归碰到叶子节点为止，沿途碰到的节点都被new出来。
		q = new BinTreeNode<T>(p->data,l,r);
		return q;
	}
}

template <typename T>
BinaryTree<T>:: BinaryTree(const BinaryTree& b)
{
	BinTreeNode<T>* broot = b.getRoot();
	BinTreeNode<T>* p = copyTree(broot);
	this->root = p;
}

template <typename T>
BinaryTree<T>:: ~BinaryTree(){destroy(this->root);}

//get/set函数
template <typename T>
BinTreeNode<T>* BinaryTree<T>:: getRoot() const
{
	return this->root;
}

template <typename T>
BinTreeNode<T>* BinaryTree<T>:: getLeft() const
{
	return this->root->left;
}

template <typename T>
BinTreeNode<T>* BinaryTree<T>:: getRight() const
{
	return this->root->right;
}



//操作单个元素的方法：
template <typename T>
Status BinaryTree<T>:: getElem(BinTreeNode<T>* p, T e) const
{
	if(p == nullptr){return NOT_PRESENT;}
	else
	{
		e = p->data;
		return SUCCESS;
	}
}

template <typename T>
Status BinaryTree<T>:: setElem(BinTreeNode<T>* p, const T& e)
{
	if(p == nullptr){return NOT_PRESENT;}
	else
	{
		p->data = e;
		return SUCCESS;
	}
}

template <typename T>
void BinaryTree<T>:: insertLeft(BinTreeNode<T>* p, const T& e)
{
	if(p!=nullptr)
	{
		BinTreeNode<T>* temp;
		temp = new BinTreeNode<T>(e,nullptr,nullptr);
		if(p->left == nullptr){p->left = temp;}
		else
		{
			temp->left = p->left;
			p->left = temp;
		}
	}

}

template <typename T>
void BinaryTree<T>:: insertRight(BinTreeNode<T>* p, const T& e)
{
	if(p!=nullptr)
	{
		BinTreeNode<T>* temp;
		temp = new BinTreeNode<T>(e,nullptr,nullptr);
		if(p->right == nullptr){p->right = temp;}
		else
		{
			temp->right = p->left;
			p->right = temp;
		}
	}
}

template <typename T>
void BinaryTree<T>:: destroy(BinTreeNode<T>* p)					//递归纵向延伸：从底部往上删除每一个节点。
{
	if(p!=nullptr)				//当*p的树不为空时实施删除。
	{
		destroy(p->left);		//递归纵向延伸，纵向上删除每一个节点。
		destroy(p->right);
		delete p;
		p = nullptr;
	}
}

template <typename T>
void BinaryTree<T>:: deleteLeft(BinTreeNode<T>* p)
{
	if(p!=nullptr){destroy(p->left);}
}

template <typename T>
void BinaryTree<T>:: deleteRight(BinTreeNode<T>* p)
{
	if(p!=nullptr){destroy(p->right);}
}




//其他普通类方法：
template <typename T>
bool BinaryTree<T>:: isEmpty() const
{
	return this->root == nullptr;
}

template <typename T>
void BinaryTree<T>:: clear()
{
	if(this->root!=nullptr){destroy(this->root);}
}

template <typename T>
int BinaryTree<T>:: height(const BinTreeNode<T>* p) const		//递归纵向延伸：每往下一层计数+1，一直到底部为止。
/*递归函数：
 * 		1. height(p) = max(height(p->left),height(p->right)) + 1;
 * 		2. height(nullptr) = 0;
 */
{
	if(p==nullptr){return 0;}
	else
	{
		int lHeight,rHeight;
		lHeight = height(p->left);
		rHeight = height(p->right);
		return (lHeight > rHeight ? lHeight : rHeight)+1;
	}

}

template <typename T>
int BinaryTree<T>:: height() const
{
	return height(this->root);
}

template <typename T>
int BinaryTree<T>:: nodeCount(const BinTreeNode<T>* p) const	//递归纵向延伸：每往下碰到一个节点计数+1，一直碰到叶子节点位置。
{
	if(p==nullptr){return 0;}
	else
	{
		return nodeCount(p->left)+nodeCount(p->right)+1;
	}
}

template <typename T>
int BinaryTree<T>:: nodeCount() const
{
	return nodeCount(this->root);
}

template <typename T>
BinTreeNode<T>* BinaryTree<T>:: parent(BinTreeNode<T>* pp, const BinTreeNode<T>* p) const
//递归纵向延伸：从pp节点开始，判断是否是p的父节点，不是的话，继续往下层搜索，直到叶子节点为止。
/* 递归函数：
 * 			parent(q) = parent(q->left);
 * 			parent(q) = parent(q->right);
 *			parent(nullptr) = 0;							递归终止条件1.
 *			parent(q) = 1;		q->left = p||q->right = p;  递归终止条件2.
 */
{
	BinTreeNode<T>* q = nullptr;
	if(pp==nullptr)							//1.pp节点为空，终止搜索
	{
		return nullptr;
	}
	else if(pp==p)							 //2.pp==p，终止搜索。
	{
		return nullptr;
	}
	else if(pp->left==p||pp->right==p)		//3.pp就是p的父节点。
	{
		return pp;							//递归终止条件1
	}
	else									//4.开始递归
	{
		q = parent(pp->left, p);
		if(q!=nullptr){return q;}
		else
		{
			q = parent(pp->right,p);
			if(q!=nullptr){return q;}		//递归终止条件2：返回空指针，表示pp下面没有p的父节点。
			else
			{
				return nullptr;
			}
		}
	}
}

template <typename T>
BinTreeNode<T>* BinaryTree<T>:: parent(const BinTreeNode<T>* p) const
{
	return this->parent(this->root,p);
}

template <typename T>
void BinaryTree<T>:: ancestors(BinTreeNode<T>* p) const
{
	BinTreeNode<T>* pa;
	pa = p;
	cout << "the ancestors line is : ";
	while(pa!=nullptr)
	{
		cout << pa->data << "  ";
		pa = parent(pa);
	}
	cout << endl;
}

template <typename T>
void BinaryTree<T>:: printInfo() const
{
	cout << "该树的节点数为： " << this->nodeCount() << endl;
	cout << "该树的深度为： " << this->height() << endl;
}


//打印二叉树的方法：
template <typename T>
void BinaryTree<T>:: disp_treeShape()
{
	LinkQueue<BinTreeNode<T>* > lq = LinkQueue<BinTreeNode<T>* >();
	BinTreeNode<T>* pn = nullptr;
	if(this->root==nullptr){return;}				//若树为空.
	else
	{
		int upLevelStorage = 1;						//队列中的上层节点数。
		int nextLevelStorage = 0;					//队列中的下层节点数。
		lq.enQueue(this->root);
		while(!lq.isEmpty())						//队列不为空的时候一直执行循环。
		{
			if(upLevelStorage==0)					//上层节点全部出队后，换一行打印。
			{
				cout << endl;
				upLevelStorage = nextLevelStorage;
				nextLevelStorage = 0;
			}

			lq.delQueue(pn);
			upLevelStorage--;
			cout << pn->data << "(";
			if(pn->left==nullptr){cout << "NULL, ";}
			else
			{
				cout << pn->left->data << ", ";
				lq.enQueue(pn->left); nextLevelStorage++;
			}
			if(pn->right==nullptr){cout << "NULL)";}
			else{
				cout << pn->right->data << ")";
				lq.enQueue(pn->right);
				nextLevelStorage++;
			}
			cout << "   ";

		}
		cout << endl;
	}


}



//生成特殊二叉树的方法：

//!!!!！函数里的变量都是局部变量，所以容器里只能放节点的指针，不能放节点，否则函数结束后里面的节点全部都会被销毁。
template <typename T>
BinTreeNode<T>* BinaryTree<T>:: completeBT(int n)
/* 函数说明：生成的完全二叉树的每个节点的值就是其编号，若将此树广度优先遍历打印，则打印出的值为1,2,3,...n
 * 实现：
 * 		1.先依次创建所有节点，节点指针存入到容器之中。
 * 		2.使用下标访问容器中的节点，依次给节点的指针域赋值。
 */
{
	vector<BinTreeNode<T>* > v = vector<BinTreeNode<T>* >();
	BinTreeNode<T>* pn = nullptr;
	int count = 1;
	while(count<n)
	{
		v.push_back(new BinTreeNode<T>(count,nullptr,nullptr));
		count++;
	}

	for(int i = 1; i<n; i++)
	{
		pn = v[i-1];
		if(2*i<=n){pn->left = v[2*i-1];}
		else{pn->left = nullptr;}
		if(2*i+1<=n){pn->right = v[2*i+1-1];}
		else{pn->right = nullptr;}
	}
	pn = v[0];
	return pn;
}

//遍历算法：
template <typename T>
void BinaryTree<T>:: preorderTraverse(BinTreeNode<T>* pb, void (*visit)(const T &)) const
//递归纵向延伸：碰到节点就访问。
{
	if(pb!=nullptr)
	{
		(*visit)(pb->data);
		preorderTraverse(pb->left, visit);
		preorderTraverse(pb->right, visit);
	}
}

template <typename T>
void BinaryTree<T>:: preorderTraverse(void (*visit)(const T &)) const
{
	preorderTraverse(this->root,visit);
	cout << endl;
}

template <typename T>
void BinaryTree<T>:: inorderTraverse(BinTreeNode<T>* pb, void (*visit)(const T &)) const
{
	if(pb!=nullptr)
	{
		inorderTraverse(pb->left, visit);
		(*visit)(pb->data);
		inorderTraverse(pb->right, visit);
	}
}

template <typename T>
void BinaryTree<T>:: inorderTraverse(void (*visit)(const T &)) const
{
	inorderTraverse(this->root,visit);
	cout << endl;
}

template <typename T>
void BinaryTree<T>:: inorderTraverse_nonrecursive(void (*visit)(const T&)) const
{


}

template <typename T>
void BinaryTree<T>:: postorderTraverse(BinTreeNode<T>* pb, void (*visit)(const T &)) const
{
	if(pb!=nullptr)
	{
		postorderTraverse(pb->left, visit);
		postorderTraverse(pb->right, visit);
		(*visit)(pb->data);
	}
}

template <typename T>
void BinaryTree<T>:: postorderTraverse(void (*visit)(const T &)) const
{
	postorderTraverse(this->root,visit);
	cout << endl;
}

template <typename T>
void BinaryTree<T>:: levelorderTraverse(BinTreeNode<T>* pb, void (*visit)(const T &)) const
//循环：节点入队；节点出队，访问节点；节点左右孩子入队；    循环结束条件：队列为空。
{
	LinkQueue<BinTreeNode<T>* > lq = LinkQueue<BinTreeNode<T>* >();
	BinTreeNode<T>* pn = nullptr;
	if(pb == nullptr){return;}
	else
	{	lq.enQueue(pb);
		while(!lq.isEmpty())
		{
			lq.delQueue(pn);
			(*visit)(pn->data);
			if(pn->left!=nullptr){lq.enQueue(pn->left);}
			if(pn->right!=nullptr){lq.enQueue(pn->right);}
		}
	}


}

template <typename T>
void BinaryTree<T>:: levelorderTraverse(void (*visit)(const T &)) const
{
	levelorderTraverse(this->root,visit);
	cout << endl;
}


//查找算法：
template <typename T>
BinTreeNode<T>* BinaryTree<T>:: find(const T& e) const
{}



#endif /* SRC_BINARYTREE_H_ */
