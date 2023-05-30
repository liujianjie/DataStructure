#include <iostream>
using namespace std;

typedef struct LNode {
	int val;
	struct LNode* next;
}LNode, * LinkList;

// β�巨
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
		r = s; // ��βָ���Ƶ�ĩβ
		cin >> val;
	}
	r->next = NULL;// ��β�ڵ��nextΪ��
}
// ��λ����ҽڵ�
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

// ��λ��i�ϲ���ڵ�
void InsertNodeByI(LinkList& L, int i, int e) {
	LNode* p = GetItem(L, i - 1);
	if (p != NULL) {
		LNode* s = new LNode();
		s->val = e;
		s->next = p->next;
		p->next = s;
	}
	else {
		cout << "λ��i����������" << endl;
	}
}

// ��λ��ɾ���ڵ�
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

// ��������
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
	cout << "���������Ԫ��Ϊ��" << endl;
	PrintLinkList(L);

	int i = 3;
	InsertNodeByI(L, i, 3);
	InsertNodeByI(L, i, 4);
	cout << "�������λ��" << i << "����ڵ��" << endl;
	PrintLinkList(L);

	int val;
	i = 2;
	DeleteNodeByI(L, i, val);
	cout << "�������λ��" << i << "ɾ���ڵ��" << endl;
	PrintLinkList(L);

	LNode* s = GetItem(L, i);
	if (s != NULL)
		cout << "�������λ��" << i << "�ڵ�Ԫ��Ϊ��" << s->val << endl;

	cout << "�����ڵ�:" << endl;
	PrintLinkList(L);
	return 0;
}