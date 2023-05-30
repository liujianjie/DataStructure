#include <stdio.h> 
#include <stdlib.h>
#define MaxSize 5
typedef struct {
	int data[MaxSize];
	int front, rear;
	int tag;// 0Ϊɾ����Ĭ�ϡ�1Ϊ����  
}SqQueue;
// ��ʼ�� 
void InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
	Q.tag = 0;
}
// �ж�Ϊ��
bool QueueEmpty(SqQueue& Q) {
	if (Q.front == Q.rear && Q.tag == 0) {
		return true;
	}
	return false;
}
// ��� - ֻ���ڶ�β���� 
bool EnQueue(SqQueue& Q, int e) {
	if (Q.front == Q.rear && Q.tag == 1) {// ���� 
		return false;
	}
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MaxSize;
	Q.tag = 1;
	return true;
}
// ���� - ֻ���ڶ�ͷ�� 
bool DeQueue(SqQueue& Q, int& e) {
	if (Q.front == Q.rear && Q.tag == 0) {// �п� 
		return false;
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	Q.tag = 0;
	return true;
}
// ����ͷԪ��
bool GetHead(SqQueue& Q, int& e) {
	if (Q.front == Q.rear && Q.tag == 0) {// �п�
		return false;
	}
	e = Q.data[Q.front];
	return true;
}
int GetSize(SqQueue& Q) {
	if (Q.front == Q.rear && Q.tag == 0) {// �� 
		return 0;
	}
	if (Q.front == Q.rear && Q.tag == 1) {// ���� 
		return MaxSize;
	}
	return (Q.rear - Q.front + MaxSize) % MaxSize; // û�� 
}
// ��ӡ
void PrintSqQueue(SqQueue& Q) {
	if (Q.front == Q.rear && Q.tag == 0) {// Ϊ�� 
		return;
	}
	if (Q.front == Q.rear && Q.tag == 1) {// �� 
		int ct = 0;
		for (int i = Q.front; ct < MaxSize; i = (i + 1) % MaxSize) {
			printf("%d\t", Q.data[i]);
			ct++;
		}
	}
	else {// ���� 
		for (int i = Q.front; i != Q.rear; i = (i + 1) % MaxSize) {
			printf("%d\t", Q.data[i]);
		}
	}
	// �Ƿ���� 
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
