#include <stdio.h> 
#include <stdlib.h>
// ����ͷ���
typedef struct Linknode {
	int data;
	struct Linknode* next;
}Linknode, * LiStack;
// ��巨����,����ջ�״�����һ���ڵ� 
bool InsertNextNode(LiStack& L, int e) {
	Linknode* s = (Linknode*)malloc(sizeof(Linknode));
	s->data = e;
	if (L == NULL) {
		L = s;	// ��һ���ڵ� 
		s->next = NULL;// ��һ����ʼ��Ϊ�� ������ 
	}
	else {
		s->next = L;
		L = s;
	}
	return true;
}
// ͷ�巨��������
LiStack LiStack_HeadInsert(LiStack& L) {
	int x = 1;
	scanf("%d", &x);
	while (x != 0) {
		InsertNextNode(L, x);
		scanf("%d", &x);
	}
	return L;
}
// ��ջ
bool Push(LiStack& L, int e) {
	return InsertNextNode(L, e);
}
// ��ջ
bool Pop(LiStack& L, int& e) {
	if (L == NULL) {
		return false;
	}
	Linknode* s = L;
	e = s->data;
	L = s->next;
	free(s);
	return true;
}
// �Ƿ�Ϊ��
bool LiStackEmpty(LiStack& L) {
	if (L == NULL) {
		return true;
	}
	return false;
}
// ��ӡ
void PrintLiStack(LiStack& L) {
	if (L == NULL) {
		return;
	}
	Linknode* p = L;
	while (p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	int e;
	bool b;
	LiStack L = NULL;
	b = LiStackEmpty(L);
	if (b) printf("ջΪ��\n");
	printf("����ֵ����ջ������0����\n");
	LiStack_HeadInsert(L);
	PrintLiStack(L);
	Push(L, 11);
	Push(L, 13);
	Push(L, 16);
	printf("Ԫ��ѹ��ջ��\n");
	PrintLiStack(L);
	b = Pop(L, e);
	printf("��ջԪ�أ�%d\n", e);
	PrintLiStack(L);
	b = Pop(L, e);
	printf("��ջԪ�أ�%d\n", e);
	PrintLiStack(L);
	
	return 0;
}
