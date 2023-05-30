#include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;// 下一个
	struct LNode* prior;// 上一个
}LNode, * LinkList;
// 双链表的建立
LinkList List_TailInsert(LinkList& L) {// 尾插法 
	int x;
	L = (LinkList)malloc(sizeof(LNode));// 创建头结点
	L->prior = NULL;				// 头结点的上一个结点为空
	LNode* s, * r = L;			// s是当前创建的结点，r是尾节点
	scanf("%d", &x);
	while (x != 0) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;				// 尾结点的下一个结点是刚创建的结点
		s->prior = r;			// 刚创建的结点的上一个结点是尾结点
		r = s;					// 尾节点更新为新创建的结点
		scanf("%d", &x);
	}
	r->next = NULL;				// 尾节点的下一个结点为空			
	return L;
}
// 按位序i查找结点，头结点的位序是0，1是第一个节点 
LNode* GetElem(LinkList& L, int i) {
	if (i < 0) {
		return NULL;
	}
	int j = 0;					// 注意：带头结点从0开始
	LNode* p = L;				// 头结点开始 
	while (p != NULL && j < i) {	// 依次寻找 
		p = p->next;
		j++;
	}
	return p;
}
// 按值e查找结点
LNode* LocateElem(LinkList& L, int e) {
	LNode* p = L->next;					// 先弄出头结点的下一个节点，也就是首元（第一个）节点 
	while (p != NULL && p->data != e) {	// 从首元（第一个）节点开始 
		p = p->next;
	}
	return p;
}
// 在位序i的位置插入结点操作
bool ListInsert(LinkList& L, int i, int e) {
	LNode* p = GetElem(L, i - 1);					// 找到i结点 
	if (p == NULL) {
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));	// 创造结点 
	if (s == NULL) {
		return false;
	}
	s->data = e;
	s->next = p->next;			
	s->prior = p;
	p->next->prior = s;
	p->next = s;									// 将s结点连到p之后，这语句必须放在最后
	return true;
}
// 在位序i的位置删除结点操作
bool ListDelete(LinkList& L, int i, int& e) {
	LNode* p = GetElem(L, i - 1);					// 找到i的前一个结点 
	if (p == NULL) {
		return false;
	}
	LNode* q = p->next;	// 令q指向被删除结点 
	p->next = q->next;	// 被删除结点的前一个结点的下一个结点指向被删除结点的后一个结点
	q->next->prior = p;	// 被删除结点的后一个结点的上一个结点指向被删除结点的前一个结点
	e = q->data;			// e为被删除结点的值 
	free(q);				// 释放被删除结点的空间 
	return true;
}
// 链表输出
void PrintLinkList(LinkList& L) {
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
		printf("%d\t", p->data);// 放后面因为头结点是没有值的 
	}
	printf("\n");
}
int main() {
	int e;
	// 实现操作
	LinkList L;
	printf("输入值建立链表，输入0结束\n");
	List_TailInsert(L);  // 输入链表值，输入0结束
	PrintLinkList(L);
	printf("在位序3的位置插入结点\n");
	ListInsert(L, 3, 57);
	PrintLinkList(L);
	printf("删除位序2的结点\n");
	ListDelete(L, 2, e);
	PrintLinkList(L);
	if (L->next->next->next != NULL) {
		printf("第3个结点的前驱节点是：%d\t", L->next->next->next->prior->data);
	}
}

