#include <stdio.h> 
#include <stdlib.h>
#define MaxSize 5
typedef struct{
	int data[MaxSize];
	int front, rear;
	int tag; // 0��ɾ�� Ĭ�ϡ�1�ǲ���  
}SqQueue;

// ��ʼ�� 
void InitQueue(SqQueue &Q){
	Q.front = 0;
	Q.rear = MaxSize - 1;
	Q.tag = 0;
}
// �ж�Ϊ��
bool QueueEmpty(SqQueue &Q){
	if((Q.rear + 1) % MaxSize == Q.front && Q.tag == 0){
		return true;
	}
	return false;
}

// ��� - ֻ���ڶ�β���� 
bool EnQueue(SqQueue &Q, int e){
	if((Q.rear + 1) % MaxSize == Q.front && Q.tag == 1){// ���� 
		return false;
	}
	Q.rear = (Q.rear + 1) % MaxSize;
	Q.data[Q.rear] = e;
	Q.tag = 1;
	return true;
}

// ���� - ֻ���ڶ�ͷ�� 
bool DeQueue(SqQueue &Q, int &e){
	if((Q.rear + 1) % MaxSize == Q.front && Q.tag == 0){// �п� 
		return false;
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize; 
	Q.tag = 0;
	return true;
}
// ����ͷԪ��
bool GetHead(SqQueue &Q, int &e){
	if((Q.rear + 1) % MaxSize == Q.front && Q.tag == 0){// �п� 
		return false;
	}
	e = Q.data[Q.front];
	return true;
} 
int GetSize(SqQueue &Q) {
	if((Q.rear + 1) % MaxSize == Q.front && Q.tag == 0){// �п� 
		return 0;
	}
	if((Q.rear + 1) % MaxSize == Q.front && Q.tag == 1){// �� �� 
		return MaxSize; 
	}
	// û�� 
	return (Q.rear - Q.front + 1 + MaxSize) % MaxSize;
}
// ��ӡ
void PrintLiStack(SqQueue &Q){
	if((Q.rear + 1) % MaxSize == Q.front && Q.tag == 0){// �п� 
		return;
	}
	if((Q.rear + 1) % MaxSize == Q.front && Q.tag == 1){// �� �� 
		int ct = 0;
		for(int i = Q.front; ct < MaxSize; i = (i + 1) % MaxSize){
			printf("%d\t", Q.data[i]);
			ct++;
		}
	}else{
		// û �� 
		for(int i = Q.front; i != (Q.rear + 1) % MaxSize; i = (i + 1) % MaxSize){
			printf("%d\t", Q.data[i]);
		}
	}
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
