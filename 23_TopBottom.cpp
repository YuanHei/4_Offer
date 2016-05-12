
//从上往下打印二叉树（层次遍历）
#include <iostream>
#include <deque>
using namespace std;

typedef char ElemType;

typedef struct BiNode
{
	ElemType data;
	BiNode   *lchild;
	BiNode   *rchild;
}BiNode, *BiTree;

void CreateTree(BiTree *T)
{
	char c;
	scanf("%c", &c);

	if ( ' ' == c )
	{
		*T = NULL;
	}
	else
	{
		*T = (BiNode*)malloc(sizeof(BiNode));
		(*T)->data = c;
		CreateTree(&(*T)->lchild);
		CreateTree(&(*T)->rchild);
	}
}

void PrintFromTopBottom(BiTree pTreeRoot)
{
	if (!pTreeRoot)                 //判空
	{
		return;
	}
	deque<BiTree> Q;                //定义Q

	Q.push_back(pTreeRoot);         //将根结点入队

	while (Q.size())                //队列不为空
	{
		BiNode * p = Q.front();     //指向队头
		Q.pop_front();              //依次出队

		cout << p->data << " ";     //输出结果

		if (p->lchild)              //将左孩子放在队列中
		{
			Q.push_back(p->lchild);
		}
		if (p->rchild)              //将右孩子放在队列中
		{
			Q.push_back(p->rchild);
		}
	}
	cout << endl;
}

int main()
{
	BiTree T;
	CreateTree(&T);
	PrintFromTopBottom(T);
	return 0;
}