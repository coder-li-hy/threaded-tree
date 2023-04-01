#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
using namespace std;
typedef char TElemtype;/*�ݶ���������������Ϊint*/
typedef enum { Link, Thread }Pointertag;
typedef int Status;
typedef struct tnode
{
	TElemtype data = 0;
	Pointertag Ltag = Link, Rtag = Link;
	struct tnode* lchild = NULL, * rchild = NULL;
}TNode, * Nodeptr;
typedef struct tree
{
	Nodeptr root;
	int length;
}Tree, * Treeptr;
static Nodeptr pre = new TNode;/*���岢��ʼ����̬������ʼ��ָ��ոշ��ʹ��Ľ��*/
static int flag = 1;
void Initialize_Tree(Nodeptr t);
void InThread(Nodeptr p);
void PreThread(Nodeptr p);
void PreOrder_Traverse(Nodeptr T);
void InOrder_Traverse(Nodeptr T);