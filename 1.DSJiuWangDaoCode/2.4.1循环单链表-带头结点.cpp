#include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;
// ������Ľ���
LinkList List_TailInsert(LinkList& L) {// β�巨 
	int x;
	L = (LinkList)malloc(sizeof(LNode));// ����ͷ���
	L->data = -1;						// ͷ����ֵ��ʼ��Ϊ-1��Ϊ�˱�������
	LNode* s, * r = L;
	scanf("%d", &x);
	while (x != 0) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = L;							// β���Ľ��ָ��ͷ��㣬���ﲻͬ
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
	LNode* p = GetElem(L, i - 1);					// �ҵ�i��ǰһ����� 
	if (p == NULL) {
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));	// ������ 
	if (s == NULL) {
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;									// ��s�������p֮�� 
	return true;
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
	free(q);			// �ͷű�ɾ�����Ŀռ� 
	return true;
}
// �������-����һ����㶼����ѭ��������������
void PrintLinkList(LinkList& startNode) {// 
	LNode* p = startNode;
	bool first = true;						// Ϊ���õ�һ�ν���˳��
	while (first || p != startNode) {      // ������Լ���˵����ͷ��
		if(p->data != -1)					// ����ͷ���
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
	ListInsert(L, 3, 58);
	PrintLinkList(L);
	printf("ɾ��λ��2�Ľ��\n");
	ListDelete(L, 2, e);
	PrintLinkList(L);
	printf("ͨ����2������������\n");
	PrintLinkList(L->next->next);
	printf("λ��Ϊ3�Ľ�㣺%d\n", GetElem(L, 3)->data);
}

