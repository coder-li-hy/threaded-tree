#include"������.h"
/*����ǰ�᣺���ĸ�����Ѿ�����*/
/*���ò������������һ����*/
void Initialize_Tree(Nodeptr t)
{

	if(flag==1)
		cout << "�밴ǰ�������˳��������������������,��q��ʾ���Ϊ��" << endl;
	char ch;
	if ((ch = getchar()) != 'q')
	{
		if (!t)/*��tָ��Ϊ��*/
			t = new TNode;/*��Ϊ������µĿռ�*/
		t->data = ch;
		flag ++;
		Initialize_Tree(t->lchild);/*��������������*/
		Initialize_Tree(t->rchild);/*��������������*/
	}
}
void InThread(Nodeptr p)
{
	if (p)//�������ָ��Ľ��ǿ�
	{
		InThread(p->lchild);
		if (!p->lchild)/*�����ǰָ��Ľ��û������*/
		{
			p->Ltag = Thread;/*�������ָ���Ա���Ϊָ����ǰ����ָ��*/
			p->lchild = pre;/*ָ����ǰ��*/
		}
		if (!pre->rchild)/*���ǰ��û���Һ���*/
		{
			pre->Rtag = Thread;/*�����Ҳ�ָ���Ա���Ϊָ����ǰ����ָ��*/
			pre->rchild = p;/*�Ҳ�ָ��ָ�����̣���ǰλ��*/
		}
		pre = p;
		InThread(p->rchild);
	}
}
/*����ǰ��������*/
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

void PreOrder_Traverse(Nodeptr T)/*ǰ�����������*/
{
	Nodeptr p;/*����һ������ָ��*/
	/*ʹ��ָ��Tָ��ͷ���*/
	/*ͷ����������ڶ������Ļ�����Ϊ�˱�������������һ���ṹ������ָ��ָ������*/
	/*�����Ǳ������һ�����ĺ��*/
	p = T->lchild;/*ʹ�ù���ָ��Ӹ��ڵ㿪ʼ����*/
	//do {
	//	cout << p->data << endl;/*�˴������������ݵ���Ϣ���ɸ�Ϊ��������*/
	//	p = p->lchild;/*��ָ��p������������������*/
	//} while (p && !p->Ltag);/*�������ѭ������ָ���ָ��Ϊ��Ϊnull�������ǩΪlink*/
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
			p = p->rchild;/*ָ�����̽��*/
		}
		p = p->rchild;/*ָ�������ӽڵ���*/
	}
}
/*�����������*/
void InOrder_Traverse(Nodeptr T)
{
	Nodeptr p = T->lchild;/*�Ӹ���㿪ʼ����*/
	while (p != T)/*����δ����β*/
	{
		while (p->Ltag == Link)
			p = p->lchild;
		cout << p->data << endl;/*������ݿ�ת��Ϊ���������ݵĲ���*/
		while (p->Rtag == Thread && p->rchild != T)
		{
			p = p->rchild;
			cout << p->data << endl;/*���ʺ�һ����������*/
		}
		p = p->rchild;/*���������������*/
	}
}