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
ListNode * addListNode(ListNode **pHead,int data)
{
	if (pHead==NULL)
	{
		return NULL;
	}
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = *pHead;
	*pHead = newNode;
	++counter;
	return newNode;
}


/**
 * 在指定节点前面插入新节点
 */
ListNode *addListNodeByIndex(ListNode **pHead, int index,int value)
{
	if (pHead==NULL)
	{
		return;
	}
	ListNode *tmp = NULL;
	tmp = *pHead;
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
		newListNode->next = *pHead;
		*pHead = newListNode;
		++counter;
	}
	return newListNode;
}


void listNode_Reverise(ListNode *pHead)
{
	if (NULL==pHead)
	{
		return;
	}

	ListNode *tmp=NULL;
	ListNode *pre = NULL;
	ListNode *cur = NULL;
	pre = pHead;
	cur = pHead->next;
	while (cur->next!=NULL)
	{
		tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	pHead->next->next = NULL;
	pHead->next = pre;
	
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
	while (tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	
}



int main01()
{
	ListNode *pHead = NULL;
	
	createListNode(&pHead);
	ListNode *tmpHead = pHead;
	addListNode(&pHead, 10);
	addListNode(&pHead, 20);
	addListNode(&pHead, 30);
	addListNode(&pHead, 40);
	addListNode(&pHead, 50);
	printf("%d\n", counter);
	listNode_Print(pHead);
	printf("\n");
	addListNodeByIndex(&pHead, 30, 60);
	printf("%d\n", counter);
	printf("\n");
	listNode_Print(pHead);

	printf("\n");


	listNode_Reverise(pHead);
	listNode_Print(pHead);

	//listNode_Destory(&pHead);
	//free(tmpHead); //error
	//tmpHead = NULL;
	//pHead = NULL;
	//listNode_Print(pHead);
	return 0;
}


/**
 * 1.const修饰的全局变量(普通和静态)都是放在常量区的,任何方式都不能修改
 * 2.const修饰的局部变量不是放在常量区,而是放在栈区,可以被修改;
 */
const int a = 10;
const static int c=10;
int main()
{
	int *p = NULL;
	p = &a;
//	*p = 100; //段错误,不能通过这种形式修改const修饰的全局变量
	printf("a=%d\n", a);
	p = NULL;

	const int b = 10;
	p = &b;
	*p = 100;//但是可以通过这种形式修改const修饰的局部变量
	printf("b=%d\n", b);
	p = NULL;
	p = &c;
//	*p = 100;//也不能通过这种形式修改const修饰的静态全局变量
	printf("c=%d\n", b);
	return 0;
}