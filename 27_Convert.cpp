//二叉搜索树与双向链表
/*输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向
链表，要求不能创建任何新的结点，只能调用树中结点指针的指向。*/
#include <iostream>
#include <stdio.h>
using namespace std;

typedef char ElemType;

typedef struct BiNode
{
	ElemType data;
	BiNode * lchild;
	BiNode * rchild;
}BiNode, *BiTree;

//创建子树
void CreateNode(BiTree * T)
{
	ElemType c;
	scanf("%c", &c);

	if (' ' == c)
	{
		*T = NULL;
	}
	else
	{
		*T = (BiNode*)malloc(sizeof(BiNode));
		(*T)->data = c;
		CreateNode(&(*T)->lchild);
		CreateNode(&(*T)->rchild);
	}
}

void ConvertNode(BiNode * pNode, BiNode ** pLastNode)
{
	if (pNode == NULL)                        //判空
	{
		return;
	}
	BiNode * pCur = pNode;                    //指向当前结点
	if (pCur->lchild != NULL)                 //判断左孩子
	{
		ConvertNode(pCur->lchild, pLastNode); 
	}
	pCur->lchild = *pLastNode;   
	if (*pLastNode != NULL)
	{
		(*pLastNode)->rchild = pCur;        
	}

	*pLastNode = pCur;

	if (pCur->rchild != NULL)
	{
		ConvertNode(pCur->rchild, pLastNode);
	}
}

BiNode * Convert(BiNode * pRoot)
{
	BiNode * pLastNode = NULL;        //指向双向链表的尾结点
	ConvertNode(pRoot, &pLastNode);   //调用子函数

	BiNode * pHead = pLastNode;
	while (pHead != NULL && pHead->lchild != NULL)
	{
		pHead = pHead->lchild;
		//向左逐渐推进指向双链表的头结点
	}

	return pHead;
}

void ShowList(BiNode * T)
{
	if (T == NULL)
	{
		return;
	}
	BiNode * p = T;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->rchild;
		//rchild相当于next指针
		//lchild相当于prior指针
	}
}

int main()
{
	BiTree T;
	CreateNode(&T);
	BiNode * newHead = Convert(T);
	ShowList(newHead);
	cout << endl;
	return 0;
}