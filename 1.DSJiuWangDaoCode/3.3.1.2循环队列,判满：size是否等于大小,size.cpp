#include <stdio.h> 
#include <stdlib.h>
#define MaxSize 5
typedef struct {
	int data[MaxSize];
	int front, rear;
	int size;
}SqQueue;
// ��ʼ�� 
void InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
	Q.size = 0;
}
// �ж�Ϊ��
bool QueueEmpty(SqQueue& Q) {
	if (Q.front == Q.rear && Q.size != MaxSize) {
		return true;
	}
	return false;
}
// ��� - ֻ���ڶ�β���� 
bool EnQueue(SqQueue& Q, int e) {
	if (Q.size == MaxSize) {// ���� 
		return false;
	}
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MaxSize;
	Q.size++;
	return true;
}
// ���� - ֻ���ڶ�ͷ�� 
bool DeQueue(SqQueue& Q, int& e) {
	if (Q.front == Q.rear && Q.size != MaxSize) {// �п� 
		return false;
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	Q.size--;
	return true;
}
// ����ͷԪ��
bool GetHead(SqQueue& Q, int& e) {
	if (Q.front == Q.rear && Q.size != MaxSize) {
		return false;
	}
	e = Q.data[Q.front];
	return true;
}
int GetSize(SqQueue& Q) {
	return Q.size;
}
// ��ӡ
void PrintSqQueue(SqQueue& Q) {
	int ct = 0;
	for (int i = Q.front; ct < Q.size; i = (i + 1) % MaxSize) {
		printf("%d\t", Q.data[i]);
		ct++;
	}
	printf("\n");
}
int main()
{
	int e;
	bool b;
	SqQueue Q;
	InitQueue(Q);
	if (QueueEmpty(Q)) printf("����Ϊ��\n");
	EnQueue(Q, 1);
	printf("Ԫ��1��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	EnQueue(Q, 3);
	printf("Ԫ��3��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	EnQueue(Q, 5);
	printf("Ԫ��5��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	EnQueue(Q, 8);
	printf("Ԫ��8��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	EnQueue(Q, 9);
	printf("Ԫ��9��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	PrintSqQueue(Q);

	b = EnQueue(Q, 10);
	if (!b) printf("��������, ����10ʧ�ܣ�\n");
	DeQueue(Q, e);
	printf("��ͷԪ�� %d ����\n", e);
	EnQueue(Q, 10);
	printf("Ԫ��10��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	PrintSqQueue(Q);

	DeQueue(Q, e);
	printf("��ͷԪ�� %d ���ӣ����д�С��%d\n", e, GetSize(Q));
	PrintSqQueue(Q);

	EnQueue(Q, 12);
	printf("Ԫ��12��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	PrintSqQueue(Q);

	DeQueue(Q, e); DeQueue(Q, e); DeQueue(Q, e);
	if (QueueEmpty(Q)) {
		printf("����Ԫ�س��ӣ�����Ϊ��\n");
	}
	return 0;
}
