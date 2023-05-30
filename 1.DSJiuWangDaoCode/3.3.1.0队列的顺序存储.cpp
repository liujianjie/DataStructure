#include <stdio.h> 
#include <stdlib.h>
#define MaxSize 5
typedef struct {
	int data[MaxSize];
	int front, rear;
}SqQueue;
// 初始化 
void InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
}
// 判断为空
bool QueueEmpty(SqQueue& Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	return false;
}
// 入队 - 只能在队尾插入 
bool EnQueue(SqQueue& Q, int e) {
	if (Q.rear == MaxSize) {// 判满 
		return false;
	}
	Q.data[Q.rear] = e;
	Q.rear = Q.rear + 1;
	return true;
}
// 出队 - 只能在队头出 
bool DeQueue(SqQueue& Q, int& e) {
	if (Q.front == Q.rear) {// 判空 
		return false;
	}
	e = Q.data[Q.front];
	Q.front = Q.front + 1;
	return true;
}
// 读队头元素
bool GetHead(SqQueue& Q, int& e) {
	if (Q.front == Q.rear) {
		return false;
	}
	e = Q.data[Q.front];  // 注意不同于出队操作，front不+1
	return true;
}
int GetSize(SqQueue& Q) {
	return Q.rear - Q.front;
}
// 打印
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
	if (QueueEmpty(Q)) printf("队列为空\n");
	EnQueue(Q, 1);
	printf("元素1入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 3);
	printf("元素3入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 5);
	printf("元素5入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 7);
	printf("元素7入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 9);
	printf("元素9入队后，队列大小：%d\n", GetSize(Q));
	PrintLiStack(Q);

	b = EnQueue(Q, 10);
	if (!b) printf("队列已满,插入10失败！\n");

	DeQueue(Q, e);
	printf("队头元素 %d 出队\n", e);

	b = EnQueue(Q, 10);
	if (!b) {
		printf("队列已满,插入10失败！，队列大小： % d\n", GetSize(Q));
		printf("-----说明队列假溢出！-----\n");
		PrintLiStack(Q);
	}
	DeQueue(Q, e);DeQueue(Q, e);DeQueue(Q, e);DeQueue(Q, e);
	if (QueueEmpty(Q)) {
		printf("所有元素出队，队列为空\n");
	}
	return 0;
}
