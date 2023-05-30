#include <stdio.h> 
#include <stdlib.h>
#define MaxSize 5
typedef struct {
	int data[MaxSize];
	int front, rear;
	int tag;// 0为删除，默认。1为增加  
}SqQueue;
// 初始化 
void InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
	Q.tag = 0;
}
// 判断为空
bool QueueEmpty(SqQueue& Q) {
	if (Q.front == Q.rear && Q.tag == 0) {
		return true;
	}
	return false;
}
// 入队 - 只能在队尾插入 
bool EnQueue(SqQueue& Q, int e) {
	if (Q.front == Q.rear && Q.tag == 1) {// 判满 
		return false;
	}
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MaxSize;
	Q.tag = 1;
	return true;
}
// 出队 - 只能在队头出 
bool DeQueue(SqQueue& Q, int& e) {
	if (Q.front == Q.rear && Q.tag == 0) {// 判空 
		return false;
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	Q.tag = 0;
	return true;
}
// 读队头元素
bool GetHead(SqQueue& Q, int& e) {
	if (Q.front == Q.rear && Q.tag == 0) {// 判空
		return false;
	}
	e = Q.data[Q.front];
	return true;
}
int GetSize(SqQueue& Q) {
	if (Q.front == Q.rear && Q.tag == 0) {// 空 
		return 0;
	}
	if (Q.front == Q.rear && Q.tag == 1) {// 满了 
		return MaxSize;
	}
	return (Q.rear - Q.front + MaxSize) % MaxSize; // 没满 
}
// 打印
void PrintSqQueue(SqQueue& Q) {
	if (Q.front == Q.rear && Q.tag == 0) {// 为空 
		return;
	}
	if (Q.front == Q.rear && Q.tag == 1) {// 满 
		int ct = 0;
		for (int i = Q.front; ct < MaxSize; i = (i + 1) % MaxSize) {
			printf("%d\t", Q.data[i]);
			ct++;
		}
	}
	else {// 不满 
		for (int i = Q.front; i != Q.rear; i = (i + 1) % MaxSize) {
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
	if (QueueEmpty(Q)) printf("队列为空\n");
	EnQueue(Q, 1);
	printf("元素1入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 3);
	printf("元素3入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 5);
	printf("元素5入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 8);
	printf("元素8入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 9);
	printf("元素9入队后，队列大小：%d\n", GetSize(Q));
	PrintSqQueue(Q);

	b = EnQueue(Q, 10);
	if (!b) printf("队列已满, 插入10失败！\n");
	DeQueue(Q, e);
	printf("队头元素 %d 出队\n", e);
	EnQueue(Q, 10);
	printf("元素10入队后，队列大小：%d\n", GetSize(Q));
	PrintSqQueue(Q);

	DeQueue(Q, e);
	printf("队头元素 %d 出队，队列大小：%d\n", e, GetSize(Q));
	PrintSqQueue(Q);

	EnQueue(Q, 12);
	printf("元素12入队后，队列大小：%d\n", GetSize(Q));
	PrintSqQueue(Q);

	DeQueue(Q, e); DeQueue(Q, e); DeQueue(Q, e);
	if (QueueEmpty(Q)) {
		printf("所有元素出队，队列为空\n");
	}
	return 0;
}
