#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
	char name[64];
	unsigned int id;
	//struct Student stu; //error 结构体里面不能套自己类型的结构体元素
					//确定不了数据类型的内存的大小
	struct Student *s;//ok 因为可以 确定内存的大小 4个字节
}Student;

typedef struct Teacher
{
	char name[64];
	unsigned int id;
	char *hobby;
	char **p;
	Student stu;
}Teacher;


typedef struct ListNode
{
	int data;
	struct ListNode *next;
}ListNode;


/**
 * 创建链表头结点
 */
ListNode *createListNode(ListNode **listNode)
{
	if (listNode==NULL)
	{
		return NULL;
	}
	ListNode *tmp = NULL;
	tmp = (ListNode *)malloc(sizeof(ListNode));
	if (tmp !=NULL)
	{
		*listNode = tmp;
		(*listNode)->data = 0;
		(*listNode)->next = NULL;
		return *listNode;
	}
	return NULL;
}


/**
 * 添加节点
 */
static int counter=0;
ListNode * addListNode(ListNode *pHead,int data)
{
	if (pHead==NULL)
	{
		return NULL;
	}
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = pHead;
	pHead = newNode;
	++counter;
	return newNode;
}


/**
 * 在指定节点前面插入新节点
 */
ListNode *addListNodeByIndex(ListNode *pHead, int index,int value)
{
	if (pHead==NULL)
	{
		return;
	}
	ListNode *tmp = NULL;
	tmp = pHead;
	ListNode *newListNode = NULL;
	ListNode *pTmp = NULL;
	while (tmp->data!=0&&tmp)
	{
		if (tmp->data==index)
		{
			//保存当前节点
			pTmp = tmp;
			//malloc新节点
			newListNode = (ListNode *)malloc(sizeof(ListNode));
			newListNode->data = value;
			newListNode->next = pTmp->next;
			pTmp->next = newListNode;
			++counter;
			break;
		}
		tmp = tmp->next;
	}
	//到这里表示没有在原来的链表里面查询到对应的值，直接在头部插入新节点
	if (newListNode==NULL)
	{
		newListNode = (ListNode *)malloc(sizeof(ListNode));
		newListNode->data = value;
		newListNode->next = pHead;
		pHead = newListNode;
		++counter;
	}
	return newListNode;
}


void listNode_Reverise(ListNode *pHead)
{
	if (pHead=NULL)
	{
		return;
	}

	ListNode *tmp=NULL;
	tmp = pHead;
	ListNode *p = NULL;
	while (tmp)
	{
		if (NULL==tmp->next)
		{
			p = tmp;
		}
	}

	pHead->next = p;

	ListNode *ptmp = NULL;
	tmp = pHead;
	while (tmp)
	{
		ptmp = tmp->next;
		ptmp->next = tmp;
		tmp = tmp->next;
	}
	p->next = NULL;
	p->data = 0;

}

/**
 * 删除节点
 */
void listNode_Del(ListNode *pHead,int value)
{
	if (pHead == NULL)
	{
		return;
	}
	ListNode *tmp = NULL;
	tmp = pHead;
	ListNode *pTmp = NULL;
	while (tmp&&tmp->data!=0)
	{
		if (tmp->data==value)
		{
			pTmp = tmp;
			free(tmp);
		}
	}
}


/**
 * 销毁链表
 */
void listNode_Destory(ListNode **pHead)
{
	if (pHead==NULL)
	{
		return;
	}
	ListNode *tmp = NULL;
	tmp = *pHead;
	ListNode *pTmp = NULL;
	while (tmp && tmp->data != 0)
	{
		pTmp = tmp->next;
		free(tmp);
		tmp = pTmp;
	}
	tmp = NULL;
	//*pHead = NULL;
}

/**
 * 打印节点的数据
 */
void listNode_Print(ListNode *pHead)
{
	if (pHead==NULL)
	{
		return;
	}
	ListNode *tmp = NULL;
	tmp = pHead;
	while (tmp&&tmp->data!=0)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	
}



int main()
{
	ListNode *pHead = NULL;
	
	createListNode(&pHead);
	ListNode *tmpHead = pHead;
	pHead = addListNode(pHead, 10);
	pHead = addListNode(pHead, 20);
	pHead = addListNode(pHead, 30);
	pHead = addListNode(pHead, 40);
	pHead = addListNode(pHead, 50);
	printf("%d\n", counter);
	listNode_Print(pHead);

	addListNodeByIndex(pHead, 30, 60);
	printf("%d\n", counter);
	printf("\n");
	listNode_Print(pHead);




	listNode_Reverise(pHead);
	listNode_Print(pHead);

	//listNode_Destory(&pHead);
	//free(tmpHead); //error
	//tmpHead = NULL;
	//pHead = NULL;
	//listNode_Print(pHead);
	return 0;
}