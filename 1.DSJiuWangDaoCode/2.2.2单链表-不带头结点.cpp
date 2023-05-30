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
	LNode* s = L, * r = NULL; // r是尾指针
	scanf("%d", &x);
	while (x != 0) {
		s->data = x;
		if (r != NULL) {  // 第一次的尾指针为空
			r->next = s;// 尾指针的下一个 = 新节点
		}
		r = s;// 移动尾指针到新节点上
		scanf("%d", &x);
		s = (LNode*)malloc(sizeof(LNode));
	}
	r->next = NULL;// 尾部的结点为空 
	return L;
}
// 按位序i查找结点，1是第一个节点 
LNode* GetElem(LinkList& L, int i) {
	if (i <= 0) {
		return NULL;
	}
	int j = 1;					// // 注意：不带头结点从1开始，首元结点的位序为1
	LNode* p = L;				// 头结点开始 
	while (p != NULL && j < i) {	// 依次寻找 
		p = p->next;
		j++;
	}
	return p;
}
// 在位序i的位置插入结点操作
bool ListInsert(LinkList& L, int i, int e) {
	LNode* p = GetElem(L, i - 1);					// 找到i的前一个结点 
	if (p == NULL) {
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));	// 创造结点 
	if (s == NULL) {
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;									// 将s结点连到p之后 
	return true;
}
// 在位序i的位置删除结点操作
bool ListDelete(LinkList& L, int i, int& e) {
	LNode* p = GetElem(L, i - 1);					// 找到i的前一个结点 
	if (p == NULL) {
		return false;
	}
	LNode* q = p->next;	// 令q指向被删除结点 
	p->next = q->next;	// 令q节点在链中断开 
	e = q->data;			// e为被删除结点的值 
	free(q);			// 释放被删除结点的空间 
	return true;
}
// 求表长
int Length(LinkList& L) {
	int j = 0;
	LNode* p = L;
	while (p != NULL) {// 注意是p，从首元结点开始
		p = p->next;
		j++;
	}
	return j;
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
	int e;
	LinkList L;
	printf("输入值建立链表，输入0结束\n");
	List_TailInsert(L);
	printf("在位序3的位置插入结点\n");
	ListInsert(L, 3, 53);
	PrintLinkList(L);
	printf("删除位序2的结点\n");
	ListDelete(L, 2, e);
	PrintLinkList(L);
	printf("表长：%d\t", Length(L));
	return 0;
}