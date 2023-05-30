#include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;// ��һ��
	struct LNode* prior;// ��һ��
}LNode, * LinkList;
// ˫����Ľ���
LinkList List_TailInsert(LinkList& L) {// β�巨 
	int x;
	L = (LinkList)malloc(sizeof(LNode));// ����ͷ���
	L->prior = NULL;				// ͷ������һ�����Ϊ��
	LNode* s, * r = L;			// s�ǵ�ǰ�����Ľ�㣬r��β�ڵ�
	scanf("%d", &x);
	while (x != 0) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;				// β������һ������Ǹմ����Ľ��
		s->prior = r;			// �մ����Ľ�����һ�������β���
		r = s;					// β�ڵ����Ϊ�´����Ľ��
		scanf("%d", &x);
	}
	r->next = NULL;				// β�ڵ����һ�����Ϊ��			
	return L;
}
// ��λ��i���ҽ�㣬ͷ����λ����0��1�ǵ�һ���ڵ� 
LNode* GetElem(LinkList& L, int i) {
	if (i < 0) {
		return NULL;
	}
	int j = 0;					// ע�⣺��ͷ����0��ʼ
	LNode* p = L;				// ͷ��㿪ʼ 
	while (p != NULL && j < i) {	// ����Ѱ�� 
		p = p->next;
		j++;
	}
	return p;
}
// ��ֵe���ҽ��
LNode* LocateElem(LinkList& L, int e) {
	LNode* p = L->next;					// ��Ū��ͷ������һ���ڵ㣬Ҳ������Ԫ����һ�����ڵ� 
	while (p != NULL && p->data != e) {	// ����Ԫ����һ�����ڵ㿪ʼ 
		p = p->next;
	}
	return p;
}
// ��λ��i��λ�ò��������
bool ListInsert(LinkList& L, int i, int e) {
	LNode* p = GetElem(L, i - 1);					// �ҵ�i��� 
	if (p == NULL) {
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));	// ������ 
	if (s == NULL) {
		return false;
	}
	s->data = e;
	s->next = p->next;			
	s->prior = p;
	p->next->prior = s;
	p->next = s;									// ��s�������p֮����������������
	return true;
}
// ��λ��i��λ��ɾ��������
bool ListDelete(LinkList& L, int i, int& e) {
	LNode* p = GetElem(L, i - 1);					// �ҵ�i��ǰһ����� 
	if (p == NULL) {
		return false;
	}
	LNode* q = p->next;	// ��qָ��ɾ����� 
	p->next = q->next;	// ��ɾ������ǰһ��������һ�����ָ��ɾ�����ĺ�һ�����
	q->next->prior = p;	// ��ɾ�����ĺ�һ��������һ�����ָ��ɾ������ǰһ�����
	e = q->data;			// eΪ��ɾ������ֵ 
	free(q);				// �ͷű�ɾ�����Ŀռ� 
	return true;
}
// �������
void PrintLinkList(LinkList& L) {
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
		printf("%d\t", p->data);// �ź�����Ϊͷ�����û��ֵ�� 
	}
	printf("\n");
}
int main() {
	int e;
	// ʵ�ֲ���
	LinkList L;
	printf("����ֵ������������0����\n");
	List_TailInsert(L);  // ��������ֵ������0����
	PrintLinkList(L);
	printf("��λ��3��λ�ò�����\n");
	ListInsert(L, 3, 57);
	PrintLinkList(L);
	printf("ɾ��λ��2�Ľ��\n");
	ListDelete(L, 2, e);
	PrintLinkList(L);
	if (L->next->next->next != NULL) {
		printf("��3������ǰ���ڵ��ǣ�%d\t", L->next->next->next->prior->data);
	}
}

