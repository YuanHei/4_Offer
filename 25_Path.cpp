//二叉树中和为某一值的路径
/*输入一棵二叉树和一个整数，打印出二叉树中结点值得和
为输入整数的所有路径，从根结点开始往下一直到叶结点所
经过的结点形成一条路径。*/

#include <iostream>
#include <vector>
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
void FindPath_(BiTree pRoot, int Sum, vector<ElemType>& path, int &curSum)
{
	curSum += pRoot->data - '0';                                 //将当前结点的值加起来
	path.push_back(pRoot->data);                                 //添加到vector中

	//如果是叶结点，并且路径上结点的和等于输入的值
	//打印出这条路径
	bool isLeaf = pRoot->lchild == NULL && pRoot->rchild == NULL;
	if (curSum == Sum && isLeaf)
	{
		cout << "A path is found:";
		vector<ElemType>::iterator iter = path.begin();
		for (; iter != path.end(); ++iter)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}
	//如果不是叶结点，则遍历它的子结点
	if (pRoot->lchild != NULL)
	{
		FindPath_(pRoot->lchild, Sum, path, curSum);
	}
	if (pRoot->rchild != NULL)
	{
		FindPath_(pRoot->rchild, Sum, path, curSum);
	}
	//在返回到父结点之前，在路径上删除当前的结点
	//并在curSum中减去当前结点的值
	curSum -= pRoot->data - '0';
	path.pop_back();
}

void FindPath(BiTree pRoot, int Sum)
{
	if (NULL == pRoot)
	{
		return;
	}
	vector<ElemType> path;
	int curSum = 0;
	FindPath_(pRoot, Sum, path, curSum);
}

int main()
{
	BiTree T;
	CreateTree(&T);
	FindPath(T, 12);
	return 0;
}