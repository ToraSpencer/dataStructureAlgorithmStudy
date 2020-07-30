	#include "BinarySortTree.h"

int main()
{
	cout << "测试不同的构造函数：" << endl;
	BinTreeNode<int>* pn;
	BinTreeNode<int>* root;
	pn = new BinTreeNode<int>(0,nullptr,nullptr);
	BinarySortTree<int> t = BinarySortTree<int>(pn);
	root = t.getRoot();
	pn = t.getRoot();
	cout << "pn->data = " << pn->data << endl;

	cout << "检验查找算法" << endl;
	t.insertLeft(pn,-16);
	t.insertRight(pn,16);
	pn = pn->left;
	t.insertLeft(pn,-24);
	t.insertRight(pn,-8);
	pn = t.parent(pn);
	pn = pn->right;
	t.insertLeft(pn,8);
	t.insertRight(pn,24);
	t.disp_treeShape();
	cout << endl;
	t.ancestors(pn);
	pn = t.find_iteration(root,24);
	t.ancestors(pn);
	pn = t.find(24);
	cout << "(int)(pn == nullptr) = " << (int)(pn == nullptr) << endl;
	t.ancestors(pn);
	pn = t.findMax();
	cout << "max = " << pn->data << endl;
	pn = t.findMin();
	cout << "min = " << pn->data << endl;
	cout << endl;

	cout << "检查插入操作：" << endl;
	t.insert(88);
	t.disp_treeShape();
	cout << "############################" << endl;
	BinarySortTree<int> t1 = BinarySortTree<int>();
	t1.insert(1);
	t1.insert(2);
	t1.insert(5);
	t1.insert(88);
	t1.insert(-9);
	t1.disp_treeShape();
	cout << endl;

	cout << "测试void randBST(int n)" << endl;
	t.randBST(25);
	t.disp_treeShape();
	cout << endl;

	cout << "测试删除算法" << endl;
	cout << "待删除元素在树中不存在：" << endl;
	t.deleteNode(999);
	cout << "待删除节点是叶子：t.deleteNode(15);" << endl;
	t.deleteNode(15);
	t.disp_treeShape();
	cout << "待删除节点只有左子树：t.deleteNode(68);" << endl;
	t.deleteNode(68);
	t.disp_treeShape();
	cout << "待删除节点左右子树都非空：t.delteNode(70);" << endl;
	t.deleteNode(70);
	cout << "############################" << endl;

























	return 0;
}
