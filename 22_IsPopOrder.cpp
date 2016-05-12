/*输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为
该栈的弹出顺序*/
#include <iostream>
#include <stack>
using namespace std;

bool IsPopOrder(const int * pPush, const int * pPop, int nLength)
{
	bool bPossible = false;
	//初始化标志位

	if (pPush == NULL || pPop == NULL || nLength <= 0)
	{
		//判空等无效条件
		return bPossible;
	}
	else
	{
		const int * pNextPush = pPush;//指针指向入栈队列
		const int * pNextPop = pPop;  //指针指向出栈队列
		
		stack<int> stackData;         //定义一个辅助栈

		while (pNextPop - pPop < nLength)
		{
			//遍历是否结束
			while (stackData.empty() || stackData.top() != *pNextPop)
			{
				//栈顶不是出栈的值
				if (pNextPush - pPush == nLength)
				{
					break;
				}
				stackData.push(*pNextPush);
				//入栈
				pNextPush++;
				//向后比较
			}
			//stackData.empty() || stackData.top() != *pNextPop
			if (stackData.top() != *pNextPop)
			{
				//栈顶不是所需出栈值
				break;
			}
			//反之
			stackData.pop();
			//出栈
			pNextPop++;
			//向后比较
		}

		if (stackData.empty() && pNextPop - pPop == nLength)
		{
			//比较完成
			bPossible = true;
		}
	}

	return bPossible;
}

int main()
{
	const int pPush[5] = { 1, 2, 3, 4, 5 };
	const int pPop[5] = { 4, 5, 3, 2, 1 };
	const int pPop_[5] = { 4, 3, 5, 1, 2 };
	cout << IsPopOrder(pPush, pPop, 5) << endl;
	cout << IsPopOrder(pPush, pPop_, 5) << endl;
	return 0;
}