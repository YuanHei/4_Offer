//二叉搜索树的后序遍历序列
/*输入一个整数数组，判断该数组是不是某二叉搜索树的后序
遍历结果，如果是返回true，否则返回false。*/
#include <iostream>
using namespace std;

bool VerifySquenceOfBST(int sequence[], int length)
{
	if (sequence == NULL || length <= 0)
	{
		return false;
	}

	int root = sequence[length - 1];
	//指向根结点
	int i;
	for (i = 0; i < length - 1; ++i)
	{
		if (sequence[i] > root)
		{
			break;
		}
	}
	//i遍历完左子树
	int j;
	for (j = i; j < length - 1; ++j)
	{
		if (sequence[j] < root)
		{
			return false;
		}
	}
	//j遍历完右子树

	//判断左子树是不是二叉搜索树
	bool left = true;
	if (i < length - 1)
	{
		//左子树
		left = VerifySquenceOfBST(sequence, i);
	}
	bool right = true;
	if (i < length - 1)
	{
		//右子树
		right = VerifySquenceOfBST(sequence + i, length - i - 1);
		//length-i-1是减去左子树个数和根结点个数
	}

	return (left&&right);
}

int main()
{
	int sequence[] = { 5, 7, 6, 9, 11, 10, 8 };
	cout << VerifySquenceOfBST(sequence, 7) << endl;
	return 0;
}