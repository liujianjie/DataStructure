// ����ͷ���ĵ�����
#define _CRT_SECURE_NO_WARNINGS
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
	LNode *s = L, *r = NULL; // r��βָ��
	scanf("%d", &x);
	while (x != 0) {
		s->data = x;
		if (r != NULL){  // ��һ�ε�βָ��Ϊ��
			r->next = s;// βָ�����һ�� = �½ڵ�
		}
		r = s;// �ƶ�βָ�뵽�½ڵ���
		scanf("%d", &x);
		s = (LNode*)malloc(sizeof(LNode));
	}
	r->next = NULL;// β���Ľ��Ϊ�� 
	return L;
}
// ���Ҳ���ͷ���ĵ������еĵ�i�����
LNode* GetElem(LinkList& L, int i) {
	if (i < 0) {
		return NULL;
	}
	int j = 1; // ����ͷ���ĵ�һ���ڵ��λ��Ϊ1
	LNode* p = L;				// ͷ��㿪ʼ 
	while (p != NULL && j < i) {	// ����Ѱ�� 
		p = p->next;
		j++;
	}
	return p;
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
	LinkList L;
	List_TailInsert(L);
	printf("����Ԫ��Ϊ��");
	PrintLinkList(L);
	int i = 1;
	while (i != 0) {
		printf("������ȡ�ڼ���λ�õ�Ԫ�أ�");
		scanf("%d", &i);
		LNode* p = GetElem(L, i);
		if(p != NULL)
			printf("��%d��λ�õ�ֵ��%d\n", i, p->data);
	}
    return 0;
}