#include <iostream>
using namespace std;

typedef struct LNode {
	int val;
	struct LNode* next;
}LNode, * LinkList;

// β�巨
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
		r = s; // ��βָ���Ƶ�ĩβ
		cin >> val;
	}
	r->next = NULL;// ��β�ڵ��nextΪ��
}
// ��ȡλ��i�Ľ��
LNode* GetItem(LinkList& L, int i) {
	LNode* p = L;
	int j = 0; // ͷ����λ��պ�Ϊ0����Ԫ�ڵ��λ��Ϊ1
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	if (j < i) { 
		return NULL;
	}
	return p;
}
// ��λ��i������
void InsertNodeByI(LinkList& L, int i, int e) {
	LNode* p = GetItem(L, i - 1);// �ҵ�ǰ���ڵ�
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
// ɾ��λ��i���
void DeleteNodeByI(LinkList& L, int i, int& e) {
	LNode* p = GetItem(L, i - 1);// �ҵ�ǰ���ڵ�
	if (p != NULL) {
		LNode* s = p->next;
		p->next = s->next;
		e = s->val;
		delete s;
	}
	else {
		cout << "λ��i����������" << endl;
	}
}
// ��������
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
	// ��������
	LinkList L;
	TailInsert(L);
	cout << "�����Ԫ��Ϊ��" << endl;
	DisplayLinkList(L);

	// ����ڵ�
	int i = 3;
	InsertNodeByI(L, i, 3);
	cout << "�����λ��" << i << "����ڵ��" << endl;
	DisplayLinkList(L);

	// ɾ���ڵ�
	int val;
	i = 2;
	DeleteNodeByI(L, i, val);
	cout << "�����λ��" << i << "ɾ���ڵ��" << endl;
	DisplayLinkList(L);

	// ���ҽڵ�
	LNode* s = GetItem(L, i);
	if (s != NULL)
		cout << "�����λ��" << i << "�ڵ�Ԫ��Ϊ��" << s->val << endl;

	// �����ڵ�
	cout << "��������:" << endl;
	DisplayLinkList(L);
	return 0;
}
