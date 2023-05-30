#include <stdio.h> 
#include <stdlib.h>

// ��סԭ����ʽ���У��ڶ�β���룬�ڶ�ͷɾ�� 
typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinkNode;

typedef struct{
	LinkNode *front, *rear;
}LinkQueue;

// ��ʼ�� 
void InitQueue(LinkQueue &Q){
	// ͷ���
	LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front = Q.rear = p; // ָͬ��ͷ��� 
	Q.rear->next = NULL;
}
// �ж�Ϊ��
bool QueueEmpty(LinkQueue &Q){
	return Q.front == Q.rear;
}

// ��� - ֻ���ڶ�β���� 
bool EnQueue(LinkQueue &Q, int e){
	LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
	p->data = e;
	p->next = NULL;// ע����Ϊ��
	Q.rear->next = p;
	Q.rear = p;
	return true;
}

// ���� - ֻ���ڶ�ͷ�� 
bool DeQueue(LinkQueue &Q, int &e){
	if(Q.front == Q.rear){// �п� 
		return false;
	}
	LinkNode *p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.front->next == NULL || Q.rear == p){
		Q.front = Q.rear;// ����ָ��ָͬ��ͷ�����,����Ϊ��// ע�ⲻҪд��Q.front==Q.rear; 
	} 
	free(p);
	
	//	if(Q.front->next == NULL){// ע���Ƿ�ֻ��һ���ڵ�}
	return true;
}
// ����ͷԪ��
bool GetHead(LinkQueue &Q, int &e){
	if(Q.front == Q.rear){// �п� 
		return false;
	}
	e = Q.front->next->data;
	return true;
} 
int GetSize(LinkQueue &Q) {
	int size = 0;
	LinkNode *p = Q.front;
	while(p->next != NULL){
		p = p->next;
		size++;
	}
	return size;
}
// ��ӡ
void PrintLiStack(LinkQueue &Q){
	LinkNode *p = Q.front;
	while(p->next != NULL){
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
	if(QueueEmpty(Q)){
		printf("����Ϊ��\n");
	}
	// ���
	EnQueue(Q, 1);
	printf("���д�С%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	if(QueueEmpty(Q)){
		printf("����Ϊ��\n");
	}
	
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
	DeQueue(Q, e);
	
	printf("���д�С%d\n", GetSize(Q));
	PrintLiStack(Q);
	if(QueueEmpty(Q)){
		printf("����Ϊ��\n");
	}
	return 0;
} 

