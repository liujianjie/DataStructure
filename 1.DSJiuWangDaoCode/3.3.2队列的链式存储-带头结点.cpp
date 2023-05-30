#include <stdio.h> 
#include <stdlib.h>
// ��ͷ���
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;
// ��ʼ�� 
void InitQueue(LinkQueue& Q) {
	// ͷ���
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front = Q.rear = p;	// ��ʼ��ͷ��βָͬ��ͷ��� 
	Q.rear->next = NULL;		// ͷ������һ����Ϊ��
}
// �ж�Ϊ��
bool QueueEmpty(LinkQueue& Q) {
	return Q.front == Q.rear;
}
// ��� - ֻ���ڶ�β���� 
bool EnQueue(LinkQueue& Q, int e) {
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	p->data = e;
	p->next = NULL;// ע���½����Ҫ�ŵ�ĩβ�ģ���һ��Ҫ��Ϊ��,�ȼ� p->next = Q.rear->next
	Q.rear->next = p;
	Q.rear = p;// ����β���Ϊ�½��
	return true;
}
// ���� - ֻ���ڶ�ͷ�� 
bool DeQueue(LinkQueue& Q, int& e) {
	if (Q.front == Q.rear) {// �п� 
		return false;
	}
	LinkNode* p = Q.front->next;	// ��¼��Ԫ���
	e = p->data;
	Q.front->next = p->next;
	// ע�⣡��ɾ����ֻ��һ��ͷ����ʱ��βָ����޸�,��Ϊβָ��ָ��Ľ��ᱻɾ�����ᵼ��βָ��ָ��λ�ö�ʧ
	if (Q.front->next == NULL || Q.rear == p) {// �Ƿ�ֻ��һ���ڵ�
		Q.front = Q.rear;						// ����ָ��ָͬ��ͷ���,����Ϊ��
	}
	free(p);
	return true;
}
// ����ͷԪ��
bool GetHead(LinkQueue& Q, int& e) {
	if (Q.front == Q.rear) {// �п� 
		return false;
	}
	e = Q.front->next->data;
	return true;
}
int GetSize(LinkQueue& Q) {
	int size = 0;
	LinkNode* p = Q.front;
	while (p->next != NULL) { // ����Ԫ��㿪ʼ
		p = p->next;
		size++;
	}
	return size;
}
// ��ӡ
void PrintLiStack(LinkQueue& Q) {
	LinkNode* p = Q.front;
	while (p->next != NULL) {
		p = p->next;
		printf("%d\t", p->data);
	}
	printf("\n");
}
int main()
{
	int e;
	bool b;
	LinkQueue Q;
	InitQueue(Q);
	if (QueueEmpty(Q)) printf("����Ϊ��\n");
	EnQueue(Q, 1);
	printf("Ԫ��1��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	EnQueue(Q, 6);
	printf("Ԫ��6��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	EnQueue(Q, 7);
	printf("Ԫ��7��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	EnQueue(Q, 9);
	printf("Ԫ��9��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	EnQueue(Q, 11);
	printf("Ԫ��11��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	PrintLiStack(Q);

	DeQueue(Q, e);
	printf("��ͷԪ�� %d ����\n", e);
	PrintLiStack(Q);
	DeQueue(Q, e);
	printf("��ͷԪ�� %d ����\n", e);
	PrintLiStack(Q);

	EnQueue(Q, 15);
	printf("Ԫ��15��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	PrintLiStack(Q);

	DeQueue(Q, e); DeQueue(Q, e); DeQueue(Q, e); DeQueue(Q, e);
	if (QueueEmpty(Q)) {
		printf("����Ԫ�س��ӣ�����Ϊ��\n");
	}
	return 0;
}

