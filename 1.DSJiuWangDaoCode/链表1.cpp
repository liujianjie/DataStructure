#include <iostream>
using namespace std;

typedef struct LNode {
	int val;
	struct LNode* next;
}LNode, * LinkList;

// 尾插法
void TailInsert(LinkList& L) {
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
// 获取位序i的结点
LNode* GetItem(LinkList& L, int i) {
	LNode* p = L;
	int j = 0; // 头结点的位序刚好为0，首元节点的位序为1
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	if (j < i) { 
		return NULL;
	}
	return p;
}
// 在位序i插入结点
void InsertNodeByI(LinkList& L, int i, int e) {
	LNode* p = GetItem(L, i - 1);// 找到前驱节点
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
// 删除位序i结点
void DeleteNodeByI(LinkList& L, int i, int& e) {
	LNode* p = GetItem(L, i - 1);// 找到前驱节点
	if (p != NULL) {
		LNode* s = p->next;
		p->next = s->next;
		e = s->val;
		delete s;
	}
	else {
		cout << "位序i超过链表长度" << endl;
	}
}
// 遍历链表
void DisplayLinkList(LinkList& L) {
	LNode* p = L->next;
	while (p != NULL) {
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	// 创建链表
	LinkList L;
	TailInsert(L);
	cout << "链表的元素为：" << endl;
	DisplayLinkList(L);

	// 插入节点
	int i = 3;
	InsertNodeByI(L, i, 3);
	cout << "链表的位序" << i << "插入节点后：" << endl;
	DisplayLinkList(L);

	// 删除节点
	int val;
	i = 2;
	DeleteNodeByI(L, i, val);
	cout << "链表的位序" << i << "删除节点后：" << endl;
	DisplayLinkList(L);

	// 查找节点
	LNode* s = GetItem(L, i);
	if (s != NULL)
		cout << "链表的位序" << i << "节点元素为：" << s->val << endl;

	// 遍历节点
	cout << "遍历链表:" << endl;
	DisplayLinkList(L);
	return 0;
}
