 #include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
} LNode, * LinkList;
// ������
LinkList List_TailInsert(LinkList& L) {// β�巨
	L = (LNode*)malloc(sizeof(LNode)); // ��ʼ��һ����Ԫ�ڵ�
	int x;
	LNode* s = L, * r = NULL; // r��βָ��
	scanf("%d", &x);
	while (x != 0) {
		s->data = x;
		if (r != NULL) {  // ��һ�ε�βָ��Ϊ��
			r->next = s;// βָ�����һ�� = �½ڵ�
		}
		r = s;// �ƶ�βָ�뵽�½ڵ���
		scanf("%d", &x);
		s = (LNode*)malloc(sizeof(LNode));
	}
	r->next = NULL;// β���Ľ��Ϊ�� 
	return L;
}
// ��λ��i���ҽ�㣬1�ǵ�һ���ڵ� 
LNode* GetElem(LinkList& L, int i) {
	if (i <= 0) {
		return NULL;
	}
	int j = 1;					// // ע�⣺����ͷ����1��ʼ����Ԫ����λ��Ϊ1
	LNode* p = L;				// ͷ��㿪ʼ 
	while (p != NULL && j < i) {	// ����Ѱ�� 
		p = p->next;
		j++;
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
// ���
int Length(LinkList& L) {
	int j = 0;
	LNode* p = L;
	while (p != NULL) {// ע����p������Ԫ��㿪ʼ
		p = p->next;
		j++;
	}
	return j;
}
// �������
void PrintLinkList(LinkList& L) {
	LNode* p = L;
	while (p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	int e;
	LinkList L;
	printf("����ֵ������������0����\n");
	List_TailInsert(L);
	printf("��λ��3��λ�ò�����\n");
	ListInsert(L, 3, 53);
	PrintLinkList(L);
	printf("ɾ��λ��2�Ľ��\n");
	ListDelete(L, 2, e);
	PrintLinkList(L);
	printf("����%d\t", Length(L));
	return 0;
}