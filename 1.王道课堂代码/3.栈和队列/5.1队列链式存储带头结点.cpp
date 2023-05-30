#include <stdio.h> 
#include <stdlib.h>

// 记住原理，链式队列，在队尾插入，在队头删除 
typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinkNode;

typedef struct{
	LinkNode *front, *rear;
}LinkQueue;

// 初始化 
void InitQueue(LinkQueue &Q){
	// 头结点
	LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front = Q.rear = p; // 同指向头结点 
	Q.rear->next = NULL;
}
// 判断为空
bool QueueEmpty(LinkQueue &Q){
	return Q.front == Q.rear;
}

// 入队 - 只能在队尾插入 
bool EnQueue(LinkQueue &Q, int e){
	LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
	p->data = e;
	p->next = NULL;// 注意置为空
	Q.rear->next = p;
	Q.rear = p;
	return true;
}

// 出队 - 只能在队头出 
bool DeQueue(LinkQueue &Q, int &e){
	if(Q.front == Q.rear){// 判空 
		return false;
	}
	LinkNode *p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.front->next == NULL || Q.rear == p){
		Q.front = Q.rear;// 两个指针同指向头结点了,代表为空// 注意不要写出Q.front==Q.rear; 
	} 
	free(p);
	
	//	if(Q.front->next == NULL){// 注意是否只有一个节点}
	return true;
}
// 读队头元素
bool GetHead(LinkQueue &Q, int &e){
	if(Q.front == Q.rear){// 判空 
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
// 打印
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
		printf("队列为空\n");
	}
	// 入队
	EnQueue(Q, 1);
	printf("队列大小%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	if(QueueEmpty(Q)){
		printf("队列为空\n");
	}
	
	EnQueue(Q, 3);
	printf("队列大小%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	EnQueue(Q, 6);
	printf("队列大小%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	EnQueue(Q, 8);
	printf("队列大小%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	EnQueue(Q, 11);
	printf("队列大小%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	GetHead(Q, e);
	printf("队头元素是%d\n", e);
	
	// 出队 
	DeQueue(Q, e);
	printf("队头元素是%d\n", e);
	printf("队列大小%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	DeQueue(Q, e);
	printf("队头元素是%d\n", e);
	printf("队列大小%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	EnQueue(Q, 9);
	printf("队列大小%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	EnQueue(Q, 10);
	printf("队列大小%d\n", GetSize(Q));
	PrintLiStack(Q);
	
	// 出队 
	DeQueue(Q, e);
	DeQueue(Q, e);
	DeQueue(Q, e);
	DeQueue(Q, e);
	DeQueue(Q, e);
	DeQueue(Q, e);
	
	printf("队列大小%d\n", GetSize(Q));
	PrintLiStack(Q);
	if(QueueEmpty(Q)){
		printf("队列为空\n");
	}
	return 0;
} 

