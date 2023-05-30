#include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;
// 单链表的建立
LinkList List_TailInsert(LinkList& L) {// 尾插法 
	int x;
	L = (LinkList)malloc(sizeof(LNode));// 创建头结点
	L->data = -1;						// 头结点的值初始化为-1，为了遍历代码
	LNode* s, * r = L;
	scanf("%d", &x);
	while (x != 0) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = L;							// 尾部的结点指向头结点，这里不同
	return L;
}
// 按位序i查找结点，头结点的位序是0，1是第一个节点 
LNode* GetElem(LinkList& L, int i) {
	if (i < 0 || L == NULL) {
		return NULL;
	}
	int j = 0;					// 注意：带头结点从0开始
	LNode* p = L;				// 头结点开始 
	// 这里待优化：当查找的位序大于链表的大小则只会找到尾节点
	while (j < i) {	
		if (p->next == L)
			break;
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
// 链表输出-任意一个结点都可以循环遍历整个链表
void PrintLinkList(LinkList& startNode) {// 
	LNode* p = startNode;
	bool first = true;						// 为了让第一次进入顺利
	while (first || p != startNode) {      // 如果是自己，说明到头了
		if(p->data != -1)					// 忽略头结点
			printf("%d\t", p->data); 
		p = p->next;
		first = false;
	}
	printf("\n");
}
int main() {
	int e;
	LinkList L;
	printf("输入值建立链表，输入0结束\n");
	List_TailInsert(L);
	PrintLinkList(L);
	printf("在位序3的位置插入结点\n");
	ListInsert(L, 3, 58);
	PrintLinkList(L);
	printf("删除位序2的结点\n");
	ListDelete(L, 2, e);
	PrintLinkList(L);
	printf("通过第2个结点遍历链表\n");
	PrintLinkList(L->next->next);
	printf("位序为3的结点：%d\n", GetElem(L, 3)->data);
}

