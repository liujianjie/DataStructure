#include <stdio.h> 
#include <stdlib.h>
#define MaxSize 5
typedef struct{
	int data[MaxSize];
	int front, rear;
	int tag;// 0为删除，默认。1为增加  
}SqQueue;

// 初始化 
void InitQueue(SqQueue &Q){
	Q.front = Q.rear = 0;
	Q.tag = 0;
}
// 判断为空
bool QueueEmpty(SqQueue &Q){
	if(Q.front == Q.rear && Q.tag == 0){
		return true;
	}
	return false;
}

// 入队 - 只能在队尾插入 
bool EnQueue(SqQueue &Q, int e){
	if(Q.front == Q.rear && Q.tag == 1){// 判满 
		return false;
	}
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MaxSize;
	Q.tag = 1;
	return true;
}

// 出队 - 只能在队头出 
bool DeQueue(SqQueue &Q, int &e){
	if(Q.front == Q.rear && Q.tag == 0){// 判空 
		return false;
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize; 
	Q.tag = 0;
	return true;
}
// 读队头元素
bool GetHead(SqQueue &Q, int &e){
	if(Q.front == Q.rear && Q.tag == 0){// 判空
		return false;
	}
	e = Q.data[Q.front];
	return true;
} 
int GetSize(SqQueue &Q) {
	if(Q.front == Q.rear && Q.tag == 0){// 空 
		return 0;	
	}
	if(Q.front == Q.rear && Q.tag == 1){// 满了 
		return MaxSize;
	}
	return (Q.rear - Q.front + MaxSize) % MaxSize; // 没满 
}
// 打印
void PrintLiStack(SqQueue &Q){
	// 分把
	if(Q.front == Q.rear && Q.tag == 0){// 为空 
		return; 
	} 
	if(Q.front == Q.rear && Q.tag == 1){// 满 
		int ct = 0; 
		for(int i = Q.front; ct < MaxSize; i = (i + 1) % MaxSize){
			printf("%d\t", Q.data[i]);
			ct++;
		} 
	}else{// 不满 
		for(int i = Q.front; i != Q.rear; i = (i + 1) % MaxSize){
			printf("%d\t", Q.data[i]);
		} 
	}
	
	// 是否输出 
	printf("\n");
} 
int main()
{
	int e;	
	bool b;
	SqQueue Q;
	InitQueue(Q);
	if(QueueEmpty(Q)){
		printf("队列为空\n");
	}
	// 入队
	EnQueue(Q, 1);
	printf("队列大小%d\n", GetSize(Q));
	PrintLiStack(Q);
	
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
	
	b = EnQueue(Q, 19);
	if(!b){
		printf("已满,插入失败！\n");
	}
	
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
	if(QueueEmpty(Q)){
		printf("队列为空\n");
	}
	return 0;
} 
