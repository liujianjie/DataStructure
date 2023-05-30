#include <iostream>
using namespace std;

typedef struct LNode {
	int val;
	struct LNode* next;
}LNode, * LinkList;

// 尾插法
void CreateList(LinkList& L) {
	L = new LNode();
	L->next = NULL;
	LNode* s, * r = L;
	int val;
	cin >> val;
	while (val != 0) {
		s = new LNode();
		s->val = val;
		r->next = s;
		r = s; // 将尾指针移到末尾
		cin >> val;
	}
	r->next = NULL;// 将尾节点的next为空
}
// 按位序查找节点
LNode* GetItem(LinkList& L, int i) {
	LNode* p = L;
	int j = 0; 
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	if (j < i) { 
		return NULL;
	}
	return p;
}

// 在位序i上插入节点
void InsertNodeByI(LinkList& L, int i, int e) {
	LNode* p = GetItem(L, i - 1);
	if (p != NULL) {
		LNode* s = new LNode();
		s->val = e;
		s->next = p->next;
		p->next = s;
	}
	else {
		cout << "位序i超过链表长度" << endl;
	}
}

// 按位序删除节点
void DeleteNodeByI(LinkList& L, int i, int& e) {
	LNode* p = GetItem(L, i - 1);
	if (p != NULL) {
		LNode* s = p->next;
		if (s != NULL) {
			p->next = s->next;
			e = s->val;
			delete s;
		}
	}
}

// 遍历链表
void PrintLinkList(LinkList& L) {
	LNode* p = L->next;
	while (p != NULL) {
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	LinkList L;
	CreateList(L);
	cout << "创建链表的元素为：" << endl;
	PrintLinkList(L);

	int i = 3;
	InsertNodeByI(L, i, 3);
	InsertNodeByI(L, i, 4);
	cout << "在链表的位序" << i << "插入节点后：" << endl;
	PrintLinkList(L);

	int val;
	i = 2;
	DeleteNodeByI(L, i, val);
	cout << "在链表的位序" << i << "删除节点后：" << endl;
	PrintLinkList(L);

	LNode* s = GetItem(L, i);
	if (s != NULL)
		cout << "在链表的位序" << i << "节点元素为：" << s->val << endl;

	cout << "遍历节点:" << endl;
	PrintLinkList(L);
	return 0;
}