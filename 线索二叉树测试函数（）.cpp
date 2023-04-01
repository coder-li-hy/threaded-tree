#include"二叉树.h"
int main()
{
	Treeptr t1 = new Tree;/*创建一颗树，并为其分配空间，包括根节点指针和树的大小*/
	Initialize_Tree(t1->root);
	cout << "前序线索二叉遍历" << endl;
	PreThread(t1->root);
	PreOrder_Traverse(pre);
	return 0;
}