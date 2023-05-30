#include <iostream>
using namespace std;

typedef struct LNode {
	int val;
	struct LNode* next;
}LNode, * LinkList;

// β�巨��������
void CreateListByTailInsert(LinkList& L) {
	L = new LNode();// ����ͷ���
	L->next = NULL;// ��λ��
	LNode* s, *r = L;
	int val;
	cin >> val;
	while (val != 0) {
		s = new LNode();
		s->val = val;
		r->next = s;// βָ�����һ���ڵ��Ǹմ����Ľڵ�
		r = s; // ��βָ���Ƶ�ĩβ
		cin >> val;
	}
	r->next = NULL;// ��β�ڵ��nextΪ��
}
// ��λ����ҽڵ�
LNode* GetItem(LinkList& L, int i) {
	LNode* p = L;
	int j = 0; // ͷ����λ��պ�Ϊ0����Ԫ�ڵ��λ��Ϊ1
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	if (j < i) { // jû��ǰ����ָ��λ��˵���Ҳ���
		return NULL;
	}
	return p;
}

// ��λ��i�ϲ���ڵ�
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

// ��λ��ɾ���ڵ�
void DeleteNodeByI(LinkList& L, int i, int& e) {
	LNode* p = GetItem(L, i - 1);// �ҵ�ǰ���ڵ�
	if (p != NULL) {
		LNode* s = p->next;
		if (s != NULL) {
			p->next = s->next;
			e = s->val;
			delete s;
		}
		else {
			// ��ͼɾ��β�ڵ����һ���սڵ�
			cout << "λ��i����������" << endl;
		}
	}
	else {
		cout << "λ��i����������" << endl;
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
	// 1.��������
	LinkList L;
	CreateListByTailInsert(L);
	cout << "���������Ԫ��Ϊ��" << endl;
	PrintLinkList(L);

	// 2.����ڵ�
	int i = 3;
	InsertNodeByI(L, i, 3);
	InsertNodeByI(L, i, 4);
	cout << "�������λ��" << i <<"����ڵ��" << endl;
	PrintLinkList(L);

	// 3.ɾ���ڵ�
	int val;
	i = 2;
	DeleteNodeByI(L, i, val);
	cout << "�������λ��" << i << "ɾ���ڵ��" << endl;
	PrintLinkList(L);

	// 4.���ҽڵ�
	LNode* s = GetItem(L, i);
	if(s != NULL)
		cout << "�������λ��" << i << "�ڵ�Ԫ��Ϊ��" << s->val << endl;

	// 5.�����ڵ�
	cout << "�����ڵ�:" << endl;
	PrintLinkList(L);
	return 0;
}