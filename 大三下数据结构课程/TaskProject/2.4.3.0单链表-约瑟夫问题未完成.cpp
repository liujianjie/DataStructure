#include <iostream>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

// β�巨 
LinkList List_TailInsert(LinkList& L) {
	int x;
	L = new LNode();// ����ͷ���
	LNode* s, * r = L;
	cin >> x;
	while (x != 0) {
		s = new LNode();
		s->data = x;
		r->next = s;
		r = s;
		cin >> x;
	}
	r->next = NULL;// β���Ľ��
	return L;
}
// ��λ����ҽ��ֵ��ͷ����λ����01�ǵ�һ���ڵ� 
LNode* GetElem(LinkList& L, int i) {
	if (i < 0) {
		return NULL;
	}
	int j = 0;
	LNode* p = L;				// ͷ��㿪ʼ 
	while (p != NULL && j < i) {	// ����Ѱ�� 
		p = p->next;
		j++;
	}
	return p;
}

// ��λ��i��λ��ɾ��������
bool ListDelete(LinkList& L, int i, int& e) {
	LNode* p = GetElem(L, i - 1);					// �ҵ�i��ǰһ����� 
	if (p == NULL) {
		return false;
	}
	LNode* q = p->next;	// ��qָ��ɾ����� 
	p->next = q->next;	// ��q�ڵ������жϿ� 
	e = q->data;			// eΪ��ɾ������ֵ 
	delete p;			// �ͷű�ɾ�����Ŀռ� 
	return true;
}
// �������
void PrintLinkList(LinkList& L) {
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
		cout << p->data << " ";// �ź�����Ϊͷ�����û��ֵ�� 
	}
	cout << endl;
}
// Լɪ��
void YSFH(LinkList& L) {
	LNode* p = L, *r = L;// p�ǵ�ǰָ�룬r����һ��ָ��
	int ct = 0; // ct�Ǽ�3
	while (p != NULL) {
		while (ct < 3) {
			ct++;
			r = p;
			if (p->next != NULL) {
				p = p->next;
			}
			else {
				p = L->next; // ����Ԫ���
			}
			
		}
		// ɾ�����p�ڵ�
	}
}
int main() {
	int e;
	// ʵ�ֲ���
	LinkList L;
	List_TailInsert(L);
	PrintLinkList(L);
}

