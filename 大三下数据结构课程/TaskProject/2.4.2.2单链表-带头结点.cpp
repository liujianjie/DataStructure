#include <iostream>
using namespace std;

typedef struct LNode {
	int val;
	struct LNode* next;
}LNode, * LinkList;

// 尾插法创建链表
void CreateListByTailInsert(LinkList& L) {
	L = new LNode();// 创建头结点
	L->next = NULL;// 置位空
	LNode* s, *r = L;
	int val;
	cin >> val;
	while (val != 0) {
		s = new LNode();
		s->val = val;
		r->next = s;// 尾指针的下一个节点是刚创建的节点
		r = s; // 将尾指针移到末尾
		cin >> val;
	}
	r->next = NULL;// 将尾节点的next为空
}
// 按位序查找节点
LNode* GetItem(LinkList& L, int i) {
	LNode* p = L;
	int j = 0; // 头结点的位序刚好为0，首元节点的位序为1
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	if (j < i) { // j没有前进到指定位序说明找不到
		return NULL;
	}
	return p;
}

// 在位序i上插入节点
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

// 按位序删除节点
void DeleteNodeByI(LinkList& L, int i, int& e) {
	LNode* p = GetItem(L, i - 1);// 找到前驱节点
	if (p != NULL) {
		LNode* s = p->next;
		if (s != NULL) {
			p->next = s->next;
			e = s->val;
			delete s;
		}
		else {
			// 意图删除尾节点的下一个空节点
			cout << "位序i超过链表长度" << endl;
		}
	}
	else {
		cout << "位序i超过链表长度" << endl;
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
	// 1.创建链表
	LinkList L;
	CreateListByTailInsert(L);
	cout << "创建链表的元素为：" << endl;
	PrintLinkList(L);

	// 2.插入节点
	int i = 3;
	InsertNodeByI(L, i, 3);
	InsertNodeByI(L, i, 4);
	cout << "在链表的位序" << i <<"插入节点后：" << endl;
	PrintLinkList(L);

	// 3.删除节点
	int val;
	i = 2;
	DeleteNodeByI(L, i, val);
	cout << "在链表的位序" << i << "删除节点后：" << endl;
	PrintLinkList(L);

	// 4.查找节点
	LNode* s = GetItem(L, i);
	if(s != NULL)
		cout << "在链表的位序" << i << "节点元素为：" << s->val << endl;

	// 5.遍历节点
	cout << "遍历节点:" << endl;
	PrintLinkList(L);
	return 0;
}