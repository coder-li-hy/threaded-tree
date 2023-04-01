#include"二叉树.h"
/*操作前提：树的根结点已经存在*/
/*后置操作：创建完成一棵树*/
void Initialize_Tree(Nodeptr t)
{

	if(flag==1)
		cout << "请按前序遍历的顺序输入树各个结点的数据,按q表示结点为空" << endl;
	char ch;
	if ((ch = getchar()) != 'q')
	{
		if (!t)/*若t指向为空*/
			t = new TNode;/*则为其分配新的空间*/
		t->data = ch;
		flag ++;
		Initialize_Tree(t->lchild);/*跟进处理左子树*/
		Initialize_Tree(t->rchild);/*跟进处理右子树*/
	}
}
void InThread(Nodeptr p)
{
	if (p)//如果现在指向的结点非空
	{
		InThread(p->lchild);
		if (!p->lchild)/*如果当前指向的结点没有左孩子*/
		{
			p->Ltag = Thread;/*将其左侧指针成员标记为指向其前驱的指针*/
			p->lchild = pre;/*指向其前驱*/
		}
		if (!pre->rchild)/*如果前驱没有右孩子*/
		{
			pre->Rtag = Thread;/*将其右侧指针成员标记为指向其前驱的指针*/
			pre->rchild = p;/*右侧指针指向其后继，当前位置*/
		}
		pre = p;
		InThread(p->rchild);
	}
}
/*树的前序线索化*/
void PreThread(Nodeptr p)
{
	if (p)
	{
		if (!p->lchild)
		{
			p->Ltag = Thread;
			p->lchild = pre;
		}
		if (!pre->rchild)
		{
			pre->Rtag = Thread;
			pre->rchild = p;
		}
		pre = p;
		PreThread(p->lchild);
		PreThread(p->rchild);
	}
}

void PreOrder_Traverse(Nodeptr T)/*前序遍历整棵树*/
{
	Nodeptr p;/*定义一个工作指针*/
	/*使得指针T指向头结点*/
	/*头结点是我们在二叉树的基础上为了遍历方便而另设的一个结构，其左指针指向根结点*/
	/*其又是遍历最后一个结点的后继*/
	p = T->lchild;/*使得工作指针从根节点开始遍历*/
	//do {
	//	cout << p->data << endl;/*此处输出结点内数据的信息，可改为其他操作*/
	//	p = p->lchild;/*将指针p向其左侧子树方向遍历*/
	//} while (p && !p->Ltag);/*入口条件循环，若指针的指向为不为null且其左标签为link*/
	//if (p && p->Ltag)
	//{
	//	cout << p->data << endl;
	//}
	while (p!=T)
	{
		while (p->Ltag == Link)
		{
			cout << p->data << endl;
			p = p->lchild;
		}
		while (p->Rtag == Thread && p->rchild != T)
		{
			cout << p->data << endl;
			p = p->rchild;/*指向其后继结点*/
		}
		p = p->rchild;/*指向其右子节点树*/
	}
}
/*树的中序遍历*/
void InOrder_Traverse(Nodeptr T)
{
	Nodeptr p = T->lchild;/*从根结点开始遍历*/
	while (p != T)/*遍历未到结尾*/
	{
		while (p->Ltag == Link)
			p = p->lchild;
		cout << p->data << endl;/*输出数据可转化为其他对数据的操作*/
		while (p->Rtag == Thread && p->rchild != T)
		{
			p = p->rchild;
			cout << p->data << endl;/*访问后一个结点的数据*/
		}
		p = p->rchild;/*进至其右子树结点*/
	}
}