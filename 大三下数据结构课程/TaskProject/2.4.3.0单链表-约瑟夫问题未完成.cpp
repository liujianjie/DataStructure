#include <iostream>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

// 尾插法 
LinkList List_TailInsert(LinkList& L) {
	int x;
	L = new LNode();// 创建头结点
	LNode* s, * r = L;
	cin >> x;
	while (x != 0) {
		s = new LNode();
		s->data = x;
		r->next = s;
		r = s;
		cin >> x;
	}
	r->next = NULL;// 尾部的结点
	return L;
}
// 按位序查找结点值，头结点的位序是01是第一个节点 
LNode* GetElem(LinkList& L, int i) {
	if (i < 0) {
		return NULL;
	}
	int j = 0;
	LNode* p = L;				// 头结点开始 
	while (p != NULL && j < i) {	// 依次寻找 
		p = p->next;
		j++;
	}
	return p;
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
	delete p;			// 释放被删除结点的空间 
	return true;
}
// 链表输出
void PrintLinkList(LinkList& L) {
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
		cout << p->data << " ";// 放后面因为头结点是没有值的 
	}
	cout << endl;
}
// 约瑟夫环
void YSFH(LinkList& L) {
	LNode* p = L, *r = L;// p是当前指针，r是上一个指针
	int ct = 0; // ct是计3
	while (p != NULL) {
		while (ct < 3) {
			ct++;
			r = p;
			if (p->next != NULL) {
				p = p->next;
			}
			else {
				p = L->next; // 到首元结点
			}
			
		}
		// 删除这个p节点
	}
}
int main() {
	int e;
	// 实现操作
	LinkList L;
	List_TailInsert(L);
	PrintLinkList(L);
}

