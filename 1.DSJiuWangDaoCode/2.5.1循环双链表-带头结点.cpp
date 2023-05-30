#include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;// ��һ��
	struct LNode* prior;// ��һ��
}LNode, * LinkList;
// ѭ��˫����Ľ���
LinkList List_TailInsert(LinkList& L) {// β�巨 
	int x;
	L = (LinkList)malloc(sizeof(LNode));// ����ͷ���
	L->data = -1;						// ͷ����ֵ��ʼ��Ϊ-1��Ϊ�˱�������
	LNode* s, * r = L;					// s�ǵ�ǰ�����Ľ�㣬r��β�ڵ�
	scanf("%d", &x);
	while (x != 0) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;				// β������һ������Ǹմ����Ľ��
		s->prior = r;			// �մ����Ľ�����һ�������β���
		r = s;					// β�ڵ����Ϊ�´����Ľ��
		scanf("%d", &x);
	}
	L->prior = r;				// ͷ������һ�����Ϊβ�ڵ�
	r->next = L;					// β�ڵ����һ�����Ϊͷ���		
	return L;
}
// ��λ��i���ҽ�㣬ͷ����λ����0��1�ǵ�һ���ڵ� 
LNode* GetElem(LinkList& L, int i) {
	if (i < 0 || L == NULL) {
		return NULL;
	}
	int j = 0;					// ע�⣺��ͷ����0��ʼ
	LNode* p = L;				// ͷ��㿪ʼ 
	// ������Ż��������ҵ�λ���������Ĵ�С��ֻ���ҵ�β�ڵ�
	while (j < i) {
		if (p->next == L)
			break;
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
// �������-����һ����㶼����ѭ��������������
void PrintLinkList(LinkList& startNode) {
	LNode* p = startNode;
	bool first = true;						// Ϊ���õ�һ�ν���˳��
	while (first || p != startNode) {      // ������Լ���˵����ͷ��
		if (p->data != -1)					// ����ͷ���
			printf("%d\t", p->data);
		p = p->next;
		first = false;
	}
	printf("\n");
}
int main() {
	int e;
	LinkList L;
	printf("����ֵ������������0����\n");
	List_TailInsert(L);
	PrintLinkList(L);
	printf("��λ��3��λ�ò�����\n");
	ListInsert(L, 3, 59);
	PrintLinkList(L);
	printf("ɾ��λ��2�Ľ��\n");
	ListDelete(L, 2, e);
	PrintLinkList(L);
	printf("ͨ����3������������\n");
	PrintLinkList(L->next->next->next);
	if (L->next->next->next->next != NULL) {
		printf("��4������ǰ���ڵ���%d\n", L->next->next->next->next->prior->data);
	}
}

