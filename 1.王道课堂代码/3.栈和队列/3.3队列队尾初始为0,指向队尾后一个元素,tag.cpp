#include <stdio.h> 
#include <stdlib.h>
#define MaxSize 5
typedef struct{
	int data[MaxSize];
	int front, rear;
	int tag;// 0Ϊɾ����Ĭ�ϡ�1Ϊ����  
}SqQueue;

// ��ʼ�� 
void InitQueue(SqQueue &Q){
	Q.front = Q.rear = 0;
	Q.tag = 0;
}
// �ж�Ϊ��
bool QueueEmpty(SqQueue &Q){
	if(Q.front == Q.rear && Q.tag == 0){
		return true;
	}
	return false;
}

// ��� - ֻ���ڶ�β���� 
bool EnQueue(SqQueue &Q, int e){
	if(Q.front == Q.rear && Q.tag == 1){// ���� 
		return false;
	}
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MaxSize;
	Q.tag = 1;
	return true;
}

// ���� - ֻ���ڶ�ͷ�� 
bool DeQueue(SqQueue &Q, int &e){
	if(Q.front == Q.rear && Q.tag == 0){// �п� 
		return false;
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize; 
	Q.tag = 0;
	return true;
}
// ����ͷԪ��
bool GetHead(SqQueue &Q, int &e){
	if(Q.front == Q.rear && Q.tag == 0){// �п�
		return false;
	}
	e = Q.data[Q.front];
	return true;
} 
int GetSize(SqQueue &Q) {
	if(Q.front == Q.rear && Q.tag == 0){// �� 
		return 0;	
	}
	if(Q.front == Q.rear && Q.tag == 1){// ���� 
		return MaxSize;
	}
	return (Q.rear - Q.front + MaxSize) % MaxSize; // û�� 
}
// ��ӡ
void PrintLiStack(SqQueue &Q){
	// �ְ�
	if(Q.front == Q.rear && Q.tag == 0){// Ϊ�� 
		return; 
	} 
	if(Q.front == Q.rear && Q.tag == 1){// �� 
		int ct = 0; 
		for(int i = Q.front; ct < MaxSize; i = (i + 1) % MaxSize){
			printf("%d\t", Q.data[i]);
			ct++;
		} 
	}else{// ���� 
		for(int i = Q.front; i != Q.rear; i = (i + 1) % MaxSize){
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
	if(QueueEmpty(Q)){
		printf("����Ϊ��\n");
	}
	// ���
	EnQueue(Q, 1);
	printf("���д�С%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	EnQueue(Q, 3);
	printf("���д�С%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	EnQueue(Q, 6);
	printf("���д�С%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	EnQueue(Q, 8);
	printf("���д�С%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	EnQueue(Q, 11);
	printf("���д�С%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	b = EnQueue(Q, 19);
	if(!b){
		printf("����,����ʧ�ܣ�\n");
	}
	
	GetHead(Q, e);
	printf("��ͷԪ����%d\n", e);
	
	// ���� 
	DeQueue(Q, e);
	printf("��ͷԪ����%d\n", e);
	printf("���д�С%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	DeQueue(Q, e);
	printf("��ͷԪ����%d\n", e);
	printf("���д�С%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	EnQueue(Q, 9);
	printf("���д�С%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	EnQueue(Q, 10);
	printf("���д�С%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	// ���� 
	DeQueue(Q, e);
	DeQueue(Q, e);
	DeQueue(Q, e);
	DeQueue(Q, e);
	DeQueue(Q, e);
	if(QueueEmpty(Q)){
		printf("����Ϊ��\n");
	}
	return 0;
} 
