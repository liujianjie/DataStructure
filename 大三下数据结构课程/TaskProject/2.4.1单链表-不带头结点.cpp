// 不带头结点的单链表
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
} LNode, * LinkList;

// 链表建立
LinkList List_TailInsert(LinkList& L) {// 尾插法
	L = (LNode*)malloc(sizeof(LNode)); // 初始化一个首元节点
	int x;
	LNode *s = L, *r = NULL; // r是尾指针
	scanf("%d", &x);
	while (x != 0) {
		s->data = x;
		if (r != NULL){  // 第一次的尾指针为空
			r->next = s;// 尾指针的下一个 = 新节点
		}
		r = s;// 移动尾指针到新节点上
		scanf("%d", &x);
		s = (LNode*)malloc(sizeof(LNode));
	}
	r->next = NULL;// 尾部的结点为空 
	return L;
}
// 查找不带头结点的单链表中的第i个结点
LNode* GetElem(LinkList& L, int i) {
	if (i < 0) {
		return NULL;
	}
	int j = 1; // 不带头结点的第一个节点的位置为1
	LNode* p = L;				// 头结点开始 
	while (p != NULL && j < i) {	// 依次寻找 
		p = p->next;
		j++;
	}
	return p;
}
// 链表输出
void PrintLinkList(LinkList& L) {
	LNode* p = L;
	while (p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	LinkList L;
	List_TailInsert(L);
	printf("链表元素为：");
	PrintLinkList(L);
	int i = 1;
	while (i != 0) {
		printf("请输入取第几个位置的元素：");
		scanf("%d", &i);
		LNode* p = GetElem(L, i);
		if(p != NULL)
			printf("第%d个位置的值是%d\n", i, p->data);
	}
    return 0;
}