#include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;
// ������Ľ���
LinkList List_HeadInsert(LinkList& L) {// ͷ�巨�������������� 
	LNode* s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));// ����ͷ���
	L->next = NULL;						// ��ʼΪ������,��Ȼ��ָ��ȷ���ĵط� 
	scanf("%d", &x);
	while (x != 0) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}
LinkList List_TailInsert(LinkList& L) {// β�巨 
	int x;
	L = (LinkList)malloc(sizeof(LNode));// ����ͷ���
	LNode* s, * r = L;
	scanf("%d", &x);
	while (x != 0) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;// β���Ľ����һ��Ϊ�� 
	return L;
}
// ��λ��i���ҽ�㣬ͷ����λ����0��1�ǵ�һ���ڵ� 
LNode* GetElem(LinkList& L, int i) {
	// ����д�� 
//	if(i == 0){
//		return L;				// ����ͷ��� 
//	}
//	if(i < 1){
//		return NULL;			// ���Ϸ� 
//	}
//	int j = 1; 					// ��ʼ��Ϊ1����ΪĬ��λ��0��ͷ���, 1�ǵ�һ���ڵ� 
//	LNode *p = L->next;			// Ĭ���ҵ���һ����� 
//	while(p != NULL && j < i){	// ����Ѱ�� 
//		p = p->next;
//		j++;
//	}
	// ��Ƶд���������
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
	LNode* p = L->next;			// ��Ū��ͷ������һ���ڵ㣬Ҳ������Ԫ����һ�����ڵ� 
	while (p != NULL && p->data != e) {	// ����Ԫ����һ�����ڵ㿪ʼ 
		p = p->next;
	}
	return p;
}
// ���������ڽ��p������½ڵ�-����1
bool InsertNextNode(LNode* p, int e) {
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
// ǰ��������ڽ��p֮ǰ����Ԫ��e-����2
bool InsertPriorNode(LNode* p, int e) {
	if (p == NULL) {
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) {
		return false;
	}
	s->next = p->next;	// �½��s���¸��ڵ���p���¸��ڵ� 
	p->next = s;		// �½��s����p֮�� 
	s->data = p->data;	// ��p�е�Ԫ�ظ��Ƶ�s�� 
	p->data = e;		// ��p�е�Ԫ�ظ���Ϊe����ɽ��� 
	return true;
}
// ��λ��i��λ�ò��������
bool ListInsert(LinkList& L, int i, int e) {
	LNode* p = GetElem(L, i - 1);					// �ҵ�i��ǰһ����� 
	return InsertNextNode(p, e);
}
// ��λ��i��λ�ò��������
bool ListInsertBefore(LinkList& L, int i, int e) {
	LNode* p = GetElem(L, i);						// �ҵ�i��㣬���ﲻͬ����һ�������ҵ�i-1��ǰһ����� 
	return InsertPriorNode(p, e);
}
// ��λ��i��λ��ɾ��������-����1
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
//  ɾ��ָ�����p, ��ͨ��ǰ���ڵ�������ý�����������ɾ��������ע�����һ���ڵ㲻������ɾ��-����2
bool DeleteZhidingLNode(LNode* p) {
	if (p == NULL) {
		return false;
	}
	LNode* q = p->next;	// ��qָ��p�ĺ�̽�� 
	p->data = q->data;	// �ͺ�̽�㽻�������� 
	p->next = q->next;	// ��*q��������жϿ� 
	free(q);			// �ͷ�ԭ��̽��Ĵ洢�ռ� 
	return true;
}
// ��λ��i��λ��ɾ��������
bool ListDeleteZhiding(LinkList& L, int i, int& e) {
	LNode* p = GetElem(L, i);					// �ҵ�i��� 
	if (p == NULL) {
		return false;
	}
	return DeleteZhidingLNode(p);
}
// ���
int Length(LinkList& L) {
	int j = 0;
	LNode* p = L;
	while (p->next != NULL) {// ע����p->next������Ԫ��㿪ʼ 
		p = p->next;
		j++;
	}
	return j;
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
	List_TailInsert(L);// β��
	//	List_HeadInsert(L);// ͷ��
	PrintLinkList(L);
	// ���ֲ��뷽�����ԣ�������i��λ�ò���ڵ� 
	printf("��λ��3��λ�ò�����\n");
	ListInsert(L, 3, 33);		
	PrintLinkList(L);
	printf("��λ��5��λ�ò�����\n");
	ListInsertBefore(L, 5, 55); 
	PrintLinkList(L);
	// ����ɾ����������
	printf("ɾ��λ��2�Ľ��\n");
	ListDelete(L, 2, e);			// ͨ��ǰ���ڵ�
	PrintLinkList(L);
	printf("ɾ��λ��4�Ľ��\n");
	ListDeleteZhiding(L, 4, e);// ��ͨ��ǰ���ڵ㣬ͨ���������ݷ��� 
	PrintLinkList(L);
}


// �ṹ��ָ��
//struct St{
//	int a;
//	int b;
//};
//struct St s1;
//	s1.a = 3;
//	printf("%d\n", s1.a);
//	 
//	struct St *s2 = &s1;
//	printf("%d\n", s2);
//	printf("%d\n", (*s2).a);
//	printf("%d\n", s2->a);

