#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
	char name[64];
	unsigned int id;
	//struct Student stu; //error �ṹ�����治�����Լ����͵Ľṹ��Ԫ��
					//ȷ�������������͵��ڴ�Ĵ�С
	struct Student *s;//ok ��Ϊ���� ȷ���ڴ�Ĵ�С 4���ֽ�
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
 * ��������ͷ���
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
 * ��ӽڵ�
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
 * ��ָ���ڵ�ǰ������½ڵ�
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
			//���浱ǰ�ڵ�
			pTmp = tmp;
			//malloc�½ڵ�
			newListNode = (ListNode *)malloc(sizeof(ListNode));
			newListNode->data = value;
			newListNode->next = pTmp->next;
			pTmp->next = newListNode;
			++counter;
			break;
		}
		tmp = tmp->next;
	}
	//�������ʾû����ԭ�������������ѯ����Ӧ��ֵ��ֱ����ͷ�������½ڵ�
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
 * ɾ���ڵ�
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
 * ��������
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
 * ��ӡ�ڵ������
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
 * 1.const���ε�ȫ�ֱ���(��ͨ�;�̬)���Ƿ��ڳ�������,�κη�ʽ�������޸�
 * 2.const���εľֲ��������Ƿ��ڳ�����,���Ƿ���ջ��,���Ա��޸�;
 */
const int a = 10;
const static int c=10;
int main()
{
	int *p = NULL;
	p = &a;
//	*p = 100; //�δ���,����ͨ��������ʽ�޸�const���ε�ȫ�ֱ���
	printf("a=%d\n", a);
	p = NULL;

	const int b = 10;
	p = &b;
	*p = 100;//���ǿ���ͨ��������ʽ�޸�const���εľֲ�����
	printf("b=%d\n", b);
	p = NULL;
	p = &c;
//	*p = 100;//Ҳ����ͨ��������ʽ�޸�const���εľ�̬ȫ�ֱ���
	printf("c=%d\n", b);
	return 0;
}