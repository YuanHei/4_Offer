//字符串的排列
/*输入一个字符串，打印出该字符串中字符的所有排列，
例如输入字符串abc，则打印出由字符a，b，c所能排列出来的所有字符串
abc acb bac bca cab cba*/
#include <iostream>
using namespace std;

void Permutation_(char *pStr, char * pBegin)
{
	if (*pBegin == '\0')
	{
		//字符串结束则输出
		cout << pStr << endl;
	}
	else
	{
		for (char *pCh = pBegin; *pCh != '\0'; ++pCh)
		{
			//指向字符串中的字符，将开始的字符与后序字符交换
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

			Permutation_(pStr, pBegin + 1);

			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}

void Permutation(char *pStr)
{
	if (pStr == NULL)
	{
		return;
	}
	Permutation_(pStr, pStr);
}

int main()
{
	char str[] = "abc";
	Permutation(str);
	return 0;
}