#include "BinaryTree.h"

int main()
{
	BinaryTree<int> t = BinaryTree<int>(1);
	BinTreeNode<int>* root = t.getRoot();
	BinTreeNode<int>* p;
	t.insertLeft(root,2);
	t.insertRight(root,6);
	p = root->left;
	t.insertLeft(p,3);
	t.insertRight(p,4);
	p = p->right;
	t.insertLeft(p,5);


	cout << "遍历算法和普通成员方法：" << endl;
	t.preorderTraverse(disp);
	t.inorderTraverse(disp);
	t.postorderTraverse(disp);
	t.levelorderTraverse(disp);
	t.disp_treeShape();
	cout << "t.nodeCount() = " << t.nodeCount() << endl;
	cout << "t.height() = " << t.height() << endl;
	cout << "p->data = " << p->data << endl;
	BinTreeNode<int>* q = t.parent(p);
	cout << "q->data = " << q->data << endl;
	cout << endl;


	cout << "拷贝构造函数" << endl;
	BinaryTree<int> tt = BinaryTree<int>(t);
	tt.disp_treeShape();
	cout << endl;

	cout << "操作单个元素的方法：" << endl;
	t.insertLeft(root->left,99);
	t.insertRight(root->left,100);
	t.preorderTraverse(disp);
	t.deleteRight(root);
	t.preorderTraverse(disp);
	cout << "t.isEmpty() = " << t.isEmpty() << endl;
	cout << endl;

	cout << "内容为空指针的指针变量能否放进队列？" << endl;
	LinkQueue<int*> lqi = LinkQueue<int*>();
	int* pi = nullptr;
	lqi.enQueue(pi);
	cout << "(int)(lqi.isEmpty()) = " << (int)(lqi.isEmpty()) << endl;
	cout << endl;


	cout << "test" << endl;
	BinTreeNode<int> arr[5];
	BinTreeNode<int>* pn = &arr[0];
	cout << (int)(pn==nullptr) << endl;
	pn->data  = 1;
	pn->left = &arr[1];
	pn->right = &arr[2];
	pn++;
	pn->data = 2;
	pn++;
	pn->data = 3;
	pn--;
	pn--;
	BinaryTree<int> ttest = BinaryTree<int>(pn);
	ttest.printInfo();
	ttest.disp_treeShape();
	cout << endl;

	cout << "生成完全二叉树：" << endl;
	BinTreeNode<int>* pc = BinaryTree<int>::completeBT(20);
	cout << "(int)(pc==nullptr) = " << (int)(pc==nullptr) << endl;
	cout << "pc->data = " << pc->data << endl;
	BinaryTree<int> tc = BinaryTree<int>(pc);
	tc.disp_treeShape();







	return 0;
}
