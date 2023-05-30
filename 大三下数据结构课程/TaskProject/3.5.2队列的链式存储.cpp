// 带头结点的链式队列
#include <iostream>
using namespace std;

typedef struct LNode {
	int data;	// 数据
	struct LNode *next; // 下一个指针位置
}LNode;
typedef struct {
	LNode* front, * rear;// 队头队尾指针
}LQueue;
// 初始化
void InitQueue(LQueue& Q) {
	Q.front = Q.rear = new LNode(); // 带头结点, 头和尾指向它
	Q.front->next = NULL;			// 头结点的下一个置为空
}
// 入队 - 在队尾入
bool EnQueue(LQueue& Q, int e) {
	LNode* p = new LNode();
	p->data = e;
	p->next = NULL;// 注意新结点是要放到末尾的，下一个要置为空,等价 p->next = Q.rear->next
	Q.rear->next = p;
	Q.rear = p; // 更新尾结点为新结点
	return true;
}
// 出队 - 在队头出
bool DeQueue(LQueue& Q, int& e) {
	if (Q.front == Q.rear) return false;// 判空
	LNode* p = Q.front->next;// 记录首元结点
	e = p->data;
	Q.front->next = p->next; // 头结点不变，首元结点改变
	// 注意当删除后只有一个头结点的时候，尾指针得修改,因为尾指针指向的结点会被删除，会导致尾指针指向位置丢失
	if (Q.front->next == NULL || p == Q.rear) {
		Q.rear = Q.front; // 队尾指针指向头结点
	}
	delete p;
	return true;
}
// 获取队头元素
bool GetHead(LQueue& Q, int& e) {
	if (Q.front == Q.rear) return false; // 判空
	e = Q.front->next->data;
	return true;
}
// 判空
bool QueueEmpty(LQueue& Q) {
	return Q.front == Q.rear;
}
// 获取大小
int QueueLength(LQueue& Q) {
	LNode* p = Q.front;
	int size = 0;
	while (p->next != NULL) {
		p = p->next;
		size++;
	}
	return size;
}
// 遍历
void QueueDisplay(LQueue& Q) {
	LNode* p = Q.front;
	while (p->next != NULL) {
		p = p->next;
		cout << p->data << " ";
	}
	cout << endl;
}
int main() {
	int e;
	LQueue lq;
	// 初始化队列
	InitQueue(lq);
	// 判空
	if (QueueEmpty(lq)) cout << "队列为空" << endl;
	// 入队+获取大小
	EnQueue(lq, 6); cout << "元素6入队后，队列大小为：" << QueueLength(lq) << endl;
	EnQueue(lq, 7); cout << "元素7入队后，队列大小为：" << QueueLength(lq) << endl;
	EnQueue(lq, 8); cout << "元素8入队后，队列大小为：" << QueueLength(lq) << endl;
	EnQueue(lq, 9); cout << "元素9入队后，队列大小为：" << QueueLength(lq) << endl;
	EnQueue(lq, 10); cout << "元素10入队后，队列大小为：" << QueueLength(lq) << endl;
	// 遍历队列元素
	cout << "元素入队后，队列元素为：" << endl;
	QueueDisplay(lq);
	// 出队
	DeQueue(lq, e); cout << "元素:" << e << "出队后，队列大小为：" << QueueLength(lq) << endl;
	DeQueue(lq, e); cout << "元素:" << e << "出队后，队列大小为：" << QueueLength(lq) << endl;
	DeQueue(lq, e); cout << "元素:" << e << "出队后，队列大小为：" << QueueLength(lq) << endl;
	// 获取队头
	if (GetHead(lq, e)) cout << "此时队列的队头是:" << e << endl;
	// 遍历队列元素
	EnQueue(lq, 11); EnQueue(lq, 12);
	cout << "元素11和12入队后，队列元素为：" << endl;
	QueueDisplay(lq);
	return 0;
}