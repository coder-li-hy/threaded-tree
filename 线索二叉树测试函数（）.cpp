#include"������.h"
int main()
{
	Treeptr t1 = new Tree;/*����һ��������Ϊ�����ռ䣬�������ڵ�ָ������Ĵ�С*/
	Initialize_Tree(t1->root);
	cout << "ǰ�������������" << endl;
	PreThread(t1->root);
	PreOrder_Traverse(pre);
	return 0;
}