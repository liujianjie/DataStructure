#include <iostream>
using namespace std;
#define MAXSIZE 5

typedef struct  {
	int *base;	// 指针
	int front, rear; // 头和尾指针
}SqQueue;
// 初始化
void InitQueue(SqQueue& Q) {
	Q.base = new int[MAXSIZE];
	Q.front = Q.rear = 0;
}
// 入队
bool EnQueue(SqQueue& Q, int e) {
	if ((Q.rear + 1) % MAXSIZE == Q.front) {
		return false;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return true;
}
// 出队
bool DeQueue(SqQueue& Q, int& e) {
	if (Q.front == Q.rear) return false; // 判空
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}
// 获取队头元素
bool GetHead(SqQueue& Q, int& e) {
	if (Q.front == Q.rear) return false; // 判空
	e = Q.base[Q.front];
	return true;
}
// 判空
bool QueueEmpty(SqQueue& Q) {
	return Q.front == Q.rear;
}
// 获取大小
int QueueLength(SqQueue& Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
// 遍历
void QueueDisplay(SqQueue& Q) {
	for (int i = Q.front; i != Q.rear; i = (i + 1) % MAXSIZE) {
		cout << Q.base[i] << "\t";
	}
	cout << endl;
}
int main() {
	int e;
	SqQueue sq;
	// 初始化队列
	InitQueue(sq);
	// 判空
	if (QueueEmpty(sq)) cout << "队列为空" << endl;
	// 入队+获取大小
	EnQueue(sq, 1); cout << "元素1入队后，队列大小为：" << QueueLength(sq) << endl;
	EnQueue(sq, 2); cout << "元素2入队后，队列大小为：" << QueueLength(sq) << endl;
	EnQueue(sq, 3); cout << "元素3入队后，队列大小为：" << QueueLength(sq) << endl;
	EnQueue(sq, 4); cout << "元素4入队后，队列大小为：" << QueueLength(sq) << endl;
	if (!EnQueue(sq, 5)) cout << "元素5入队失败，队列已满" << endl;
	// 遍历队列元素
	cout << "元素入队后，队列元素为：" << endl;
	QueueDisplay(sq);
	// 出队
	DeQueue(sq, e); cout << "元素:" << e << "出队后，队列大小为：" << QueueLength(sq) << endl;
	DeQueue(sq, e); cout << "元素:" << e << "出队后，队列大小为：" << QueueLength(sq) << endl;
	DeQueue(sq, e); cout << "元素:" << e << "出队后，队列大小为：" << QueueLength(sq) << endl;
	// 获取队头
	if (GetHead(sq, e)) cout << "此时队列的队头是:"<< e << endl;
	// 遍历队列元素
	EnQueue(sq, 5); EnQueue(sq, 6);
	cout << "元素5和6入队后，队列元素为：" << endl;
	QueueDisplay(sq);
	return 0;
}