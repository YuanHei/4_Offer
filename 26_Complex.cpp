//复杂链表的复制
/*请实现函数ComplexListNode* Clone(ComplexListNode* pHead),
复制一个复杂链表。在复杂链表中，每个结点除了有一个next指针
指向下一个结点外，还有一个Sibling指向链表中的任意结点或者
NULL。*/

#include<iostream>
using namespace std;

typedef char ElemType;

struct ComplexListNode
{
	ElemType         m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

//复制原始链表的任意结点N并创建新结点N',再把N'链接到N的后面
void CloneNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead->m_pNext;
	while (pNode != NULL)
	{
		ComplexListNode* pCloned = new ComplexListNode();
		pCloned->m_nValue = pNode->m_nValue;
		pCloned->m_pNext = pNode->m_pNext;
		pCloned->m_pSibling = NULL;

		pNode->m_pNext = pCloned;
		pNode = pCloned->m_pNext;
	}
}

//如果原始链表删的节点N的m_pSibling指向S，则它对应复制的结点N'的m_pSibling指向S的下一结点S'
void ConnectSiblingNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead->m_pNext;
	while (pNode != NULL)
	{
		ComplexListNode* pCloned = pNode->m_pNext;
		if (pNode->m_pSibling != NULL)
		{
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
		}
		pNode = pCloned->m_pNext;
	}
}

//将长链表拆分成两个链表，奇数位的结点用m_pNext链接起来的就是原始链表，
//把偶数位置的结点用m_pNext连接起来的是复制出来的链表。
ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead->m_pNext;
	ComplexListNode* pClonedHead = NULL;
	ComplexListNode* pClonedNode = NULL;

	if (pNode != NULL)
	{
		pClonedHead = pClonedNode = pNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	while (pNode != NULL)
	{
		pClonedNode->m_pNext = pNode->m_pNext;
		pClonedNode = pClonedNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	return pClonedHead;
}

ComplexListNode* Clone(ComplexListNode* pHead)
{
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}

ComplexListNode* InsertNodes(ComplexListNode* pHead, ElemType e)
{
	if (pHead == NULL)
	{
		pHead = new ComplexListNode();
		pHead->m_pNext = NULL;
		pHead->m_pSibling = NULL;
	}
	ComplexListNode * temp = pHead;
	while (temp->m_pNext != NULL)
	{
		temp = temp->m_pNext;
	}
	ComplexListNode * pNode = new ComplexListNode();
	pNode->m_nValue = e;
	pNode->m_pNext = NULL;
	pNode->m_pSibling = NULL;
	temp->m_pNext = pNode;

	return pHead;
}

ComplexListNode* CreateComplexList()
{
	ComplexListNode *pHead = NULL;
	for (char a = 'A'; a < 'F'; a++)
	{
		pHead = InsertNodes(pHead, a);
	}
	ComplexListNode *pNode = pHead->m_pNext;
	ComplexListNode *pTemp = NULL;
	while (pNode != NULL)
	{
		if (pNode->m_nValue == 'A')
		{
			pNode->m_pSibling = pNode->m_pNext->m_pNext;
		}
		if (pNode->m_nValue == 'B')
		{
			pTemp = pNode;
			pNode->m_pSibling = pNode->m_pNext->m_pNext->m_pNext;
		}
		if (pNode->m_nValue == 'D')
		{
			pNode->m_pSibling = pTemp;
		}
		pNode = pNode->m_pNext;
	}
	return pHead;
}

void PrintComplexList(ComplexListNode * L)
{
	ComplexListNode *pNode = L->m_pNext;
	while (pNode != NULL)
	{
		cout << "节点：" << pNode->m_nValue << "  Next: ";
		if (pNode->m_pNext != NULL)
		{
			cout << pNode->m_pNext->m_nValue << "  Sibling: ";
		}
		else
		{
			cout << "NULL" << "  Sibling: ";
		}
		if (pNode->m_pSibling != NULL)
		{
			cout << pNode->m_pSibling->m_nValue << endl;
		}
		else
		{
			cout << "NULL" << endl;
		}
		pNode = pNode->m_pNext;
	}
}


int main()
{
	ComplexListNode *pHead = NULL;
	ComplexListNode *pCopyHead = new ComplexListNode();
	pCopyHead->m_pNext = NULL;
	pCopyHead->m_pSibling = NULL;

	pHead = CreateComplexList();
	cout << "原始列表为：" << endl;
	PrintComplexList(pHead);

	pCopyHead->m_pNext = Clone(pHead);
	cout << "复制的列表为：" << endl;
	PrintComplexList(pCopyHead);

	return 0;
}