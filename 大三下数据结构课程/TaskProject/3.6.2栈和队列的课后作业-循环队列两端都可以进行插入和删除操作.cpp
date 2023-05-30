#include <iostream>
using namespace std;
#define MAXSIZE 5
// 问1：写出循环队列的类型定义------------------------------------------------
typedef struct {
	int* base;	// 指针
	int front, rear; // 头和尾指针
}SqQueue;
// 初始化
void InitQueue(SqQueue& Q) {
	Q.base = new int[MAXSIZE];
	Q.front = Q.rear = 0;
}
// 问2：写出“从队尾删除”和“从队头插入”的算法--------------------------------
//  从队尾删除
bool DeQueue(SqQueue& Q, int& e) {
	if (Q.front == Q.rear) return false; // 判空
	e = Q.base[Q.rear];
	Q.rear = (Q.rear - 1 + MAXSIZE) % MAXSIZE; // 先减, 注意减的话要+MAXSIZE
	// e = Q.base[(Q.rear - 1 + MAXSIZE) % MAXSIZE]; // 如果取值放后面，rear要加上减去的1
	return true;
}
// 从队头插入
bool EnQueue(SqQueue& Q, int e) {
	if ((Q.front - 1 + MAXSIZE) % MAXSIZE == Q.rear) {// 是减-1, 注意减的话要+MAXSIZE
		return false;
	}
	Q.base[Q.front] = e;
	Q.front = (Q.front - 1 + MAXSIZE) % MAXSIZE; // 减1, 注意减的话要+MAXSIZE
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
	for (int i = Q.rear; i != Q.front; i = (i - 1 + MAXSIZE) % MAXSIZE) {
		cout << Q.base[i] << "\t";
	}
	cout << endl;
}
int main() {
	int e;
	SqQueue sq;
	InitQueue(sq);// 初始化队列
	// 入队
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
	// 遍历队列元素
	EnQueue(sq, 5); EnQueue(sq, 6);
	cout << "元素5和6入队后，队列元素为：" << endl;
	QueueDisplay(sq);
	// 出队
	DeQueue(sq, e); cout << "元素:" << e << "出队后，队列大小为：" << QueueLength(sq) << endl;
	// 遍历队列元素
	cout << "队列元素为：" << endl;
	QueueDisplay(sq);
	return 0;
}