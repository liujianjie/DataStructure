#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList;

LinkList List_HeadInsert(LinkList &L);
LinkList List_TailInsert(LinkList &L);
LNode *GetElem(LinkList& L, int i);
LNode *LocateElem(LinkList& L, int e);
bool InsertNextNode(LNode *p, int e);
bool InsertPriorNode(LNode *p, int e);
bool DeleteZhidingLNode(LNode *p);
bool ListInsert(LinkList &L, int i, int e);
bool ListInsertBefore(LinkList &L, int i, int e);
bool ListDelete(LinkList &L, int i, int &e);
bool ListDeleteZhiding(LinkList &L, int i, int &e);
int Length(LinkList &L);
void PrintLinkList(LinkList &L);


// 删除第i个元素
bool ListDeleteByI(LinkList &L, int i, int &e){
	LNode* p = L;
	// 1.先找到第i个结点的前驱(位序是i-1) 
	for(int j = 0; p != NULL && j < i - 1; j++){// 写错过，要注意不能找到空 
		p = p->next;
	}
	// 2.再执行相关操作
	LNode* q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return true;
} 
// 统计个数
int CountLink(LinkList &L, int e){
	int ct = 0;
	LNode *p = L->next;
	while(p != NULL){
		if(p->data == e){
			ct++;
		}
		p = p->next;
	}
	return ct;
} 
int main(){
	int e;
	// 实现操作
	LinkList L;
	List_TailInsert(L);
	
	ListDeleteByI(L, 4, e);// 删除第四个 
	PrintLinkList(L);
	
	int c = CountLink(L, 2);
	cout<<c<<endl;
}


// 结点的建立
// 头插法
LinkList List_HeadInsert(LinkList &L) {// 建立逆序单链表 
	LNode *s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));// 创建头结点
	L->next = NULL;						// 初始为空链表,不然会指向不确定的地方 
	scanf("%d", &x); 
	while(x != 0){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}
// 尾插法 
LinkList List_TailInsert(LinkList &L){
	int x;
	L = (LinkList)malloc(sizeof(LNode));// 创建头结点
	LNode *s, *r = L;
//	scanf("%d", &x); 
	cin >> x;
	while(x != 0){
//		s = (LNode*)malloc(sizeof(LNode));
		s = new LNode();
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;// 尾部的结点为空 
	return L;
}
// 按位序查找结点值，头结点的位序是0,1是第一个节点 
LNode *GetElem(LinkList& L, int i) {
	// 书 
//	if(i == 0){
//		return L;				// 返回头结点 
//	}
//	if(i < 1){
//		return NULL;			// 不合法 
//	}
//	int j = 1; 					// 初始化为1，因为默认位序0是头结点, 1是第一个节点 
//	LNode *p = L->next;			// 默认找到第一个结点 
//	while(p != NULL && j < i){	// 依次寻找 
//		p = p->next;
//		j++;
//	}
	// 间接
	if(i < 0){
		return NULL;
	} 
	int j = 0;
	LNode *p = L;				// 头结点开始 
	while(p != NULL && j < i){	// 依次寻找 
		p = p->next;
		j++;
	}
	return p; 
}
// 按值查找结点
LNode *LocateElem(LinkList& L, int e) {
	LNode *p = L->next;			// 先弄出头结点的下一个节点，也就是第一个节点 
	while(p != NULL && p->data != e){	// 从 第一个节点开始 
		p = p->next;
	} 
	return p;
}
// 后插操作，在p结点后插入新节点
bool InsertNextNode(LNode *p, int e){
	if(p == NULL){
		return false;
	}
	LNode *s = (LNode*)malloc(sizeof(LNode));	// 创造结点 
	if(s == NULL){
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;									// 将s结点连到p之后 
	return true;
} 

// 前插操作：在p结点之前插入元素e
bool InsertPriorNode(LNode *p, int e){
	if(p == NULL){
		return false;
	} 
	LNode *s = (LNode*) malloc(sizeof(LNode));
	if(s == NULL){
		return false;
	}
	s->next = p->next;	// 新结点s的下个节点是p的下个节点 
	p->next = s;		// 新结点s连到p之后 
	s->data = p->data;	// 将p中的元素复制到s中 
	p->data = e;		// 将p中的元素覆盖为e，完成交换 
	return true;
} 
 
// 删除指定结点p, 无法找到前驱，只能交换数据那样删除，但是最后一个节点不行 
bool DeleteZhidingLNode(LNode *p){
	if(p == NULL){
		return false; 
	}
	LNode *q = p->next;	// 令q指向p的后继结点 
	p->data = q->data;	// 和后继结点交换数据域 
	p->next = q->next;	// 将*q结点在链中断开 
	free(q);			// 释放原后继结点的存储空间 
	return true; 
}

// 在位序i的位置插入结点操作
bool ListInsert(LinkList &L, int i, int e){
	LNode *p = GetElem(L, i - 1);					// 找到i的前一个结点 
	return InsertNextNode(p, e); 
} 
// 在位序i的位置前插入结点操作
bool ListInsertBefore(LinkList &L, int i, int e){
	LNode *p = GetElem(L, i);					// 找到i结点 
	return InsertPriorNode(p, e); 
} 
// 在位序i的位置删除结点操作
bool ListDelete(LinkList &L, int i, int &e){
	LNode *p = GetElem(L, i - 1);					// 找到i的前一个结点 
	if(p == NULL){
		return false;
	}
	LNode *q = p->next;	// 令q指向被删除结点 
	p->next = q->next;	// 令q节点在链中断开 
	e = q->data;			// e为被删除结点的值 
	free(q);			// 释放被删除结点的空间 
	return true;
}
// 删除位序i的结点 
bool ListDeleteZhiding(LinkList &L, int i, int &e){
	LNode *p = GetElem(L, i);					// 找到i结点 
	if(p == NULL){
		return false;
	}
	return DeleteZhidingLNode(p);
}

// 求表长
int Length(LinkList &L){
	int j = 0;
	LNode *p = L;
	while(p->next != NULL){// 注意是p->next  
		p = p->next;
		j++;
	}
	return j;
} 
 
// 链表输出
void PrintLinkList(LinkList &L){
//	LNode *p = L;
//	while(p->next != NULL){
//		p = p->next;
//		printf("%d\t", p->data);// 放后面因为头结点是没有值的 
//	}
//	printf("\n");
	LNode *p = L->next;
	while(p != NULL){
		printf("%d\t", p->data);// 放后面因为头结点是没有值的 
		p = p->next;
	}
	printf("\n");
} 



