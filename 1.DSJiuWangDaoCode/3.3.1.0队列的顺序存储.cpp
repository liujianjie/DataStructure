#include <stdio.h> 
#include <stdlib.h>
#define MaxSize 5
typedef struct {
	int data[MaxSize];
	int front, rear;
}SqQueue;
// ��ʼ�� 
void InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
}
// �ж�Ϊ��
bool QueueEmpty(SqQueue& Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	return false;
}
// ��� - ֻ���ڶ�β���� 
bool EnQueue(SqQueue& Q, int e) {
	if (Q.rear == MaxSize) {// ���� 
		return false;
	}
	Q.data[Q.rear] = e;
	Q.rear = Q.rear + 1;
	return true;
}
// ���� - ֻ���ڶ�ͷ�� 
bool DeQueue(SqQueue& Q, int& e) {
	if (Q.front == Q.rear) {// �п� 
		return false;
	}
	e = Q.data[Q.front];
	Q.front = Q.front + 1;
	return true;
}
// ����ͷԪ��
bool GetHead(SqQueue& Q, int& e) {
	if (Q.front == Q.rear) {
		return false;
	}
	e = Q.data[Q.front];  // ע�ⲻͬ�ڳ��Ӳ�����front��+1
	return true;
}
int GetSize(SqQueue& Q) {
	return Q.rear - Q.front;
}
// ��ӡ
void PrintLiStack(SqQueue& S) {
	for (int i = S.front; i != S.rear; i++) {
		printf("%d\t", S.data[i]);
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
	EnQueue(Q, 7);
	printf("Ԫ��7��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	EnQueue(Q, 9);
	printf("Ԫ��9��Ӻ󣬶��д�С��%d\n", GetSize(Q));
	PrintLiStack(Q);

	b = EnQueue(Q, 10);
	if (!b) printf("��������,����10ʧ�ܣ�\n");

	DeQueue(Q, e);
	printf("��ͷԪ�� %d ����\n", e);

	b = EnQueue(Q, 10);
	if (!b) {
		printf("��������,����10ʧ�ܣ������д�С�� % d\n", GetSize(Q));
		printf("-----˵�����м������-----\n");
		PrintLiStack(Q);
	}
	DeQueue(Q, e);DeQueue(Q, e);DeQueue(Q, e);DeQueue(Q, e);
	if (QueueEmpty(Q)) {
		printf("����Ԫ�س��ӣ�����Ϊ��\n");
	}
	return 0;
}
