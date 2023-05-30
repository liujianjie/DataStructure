#include <stdio.h> 
#include <stdlib.h>
// 带头结点
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;
// 初始化 
void InitQueue(LinkQueue& Q) {
	// 头结点
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front = Q.rear = p;	// 初始化头和尾同指向头结点 
	Q.rear->next = NULL;		// 头结点的下一个置为空
}
// 判断为空
bool QueueEmpty(LinkQueue& Q) {
	return Q.front == Q.rear;
}
// 入队 - 只能在队尾插入 
bool EnQueue(LinkQueue& Q, int e) {
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	p->data = e;
	p->next = NULL;// 注意新结点是要放到末尾的，下一个要置为空,等价 p->next = Q.rear->next
	Q.rear->next = p;
	Q.rear = p;// 更新尾结点为新结点
	return true;
}
// 出队 - 只能在队头出 
bool DeQueue(LinkQueue& Q, int& e) {
	if (Q.front == Q.rear) {// 判空 
		return false;
	}
	LinkNode* p = Q.front->next;	// 记录首元结点
	e = p->data;
	Q.front->next = p->next;
	// 注意！当删除后只有一个头结点的时候，尾指针得修改,因为尾指针指向的结点会被删除，会导致尾指针指向位置丢失
	if (Q.front->next == NULL || Q.rear == p) {// 是否只有一个节点
		Q.front = Q.rear;						// 两个指针同指向头结点,代表为空
	}
	free(p);
	return true;
}
// 读队头元素
bool GetHead(LinkQueue& Q, int& e) {
	if (Q.front == Q.rear) {// 判空 
		return false;
	}
	e = Q.front->next->data;
	return true;
}
int GetSize(LinkQueue& Q) {
	int size = 0;
	LinkNode* p = Q.front;
	while (p->next != NULL) { // 从首元结点开始
		p = p->next;
		size++;
	}
	return size;
}
// 打印
void PrintLiStack(LinkQueue& Q) {
	LinkNode* p = Q.front;
	while (p->next != NULL) {
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
	if (QueueEmpty(Q)) printf("队列为空\n");
	EnQueue(Q, 1);
	printf("元素1入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 6);
	printf("元素6入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 7);
	printf("元素7入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 9);
	printf("元素9入队后，队列大小：%d\n", GetSize(Q));
	EnQueue(Q, 11);
	printf("元素11入队后，队列大小：%d\n", GetSize(Q));
	PrintLiStack(Q);

	DeQueue(Q, e);
	printf("队头元素 %d 出队\n", e);
	PrintLiStack(Q);
	DeQueue(Q, e);
	printf("队头元素 %d 出队\n", e);
	PrintLiStack(Q);

	EnQueue(Q, 15);
	printf("元素15入队后，队列大小：%d\n", GetSize(Q));
	PrintLiStack(Q);

	DeQueue(Q, e); DeQueue(Q, e); DeQueue(Q, e); DeQueue(Q, e);
	if (QueueEmpty(Q)) {
		printf("所有元素出队，队列为空\n");
	}
	return 0;
}

