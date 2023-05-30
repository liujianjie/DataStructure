#include <iostream>
using namespace std;
#define MAXSIZE 5

typedef struct  {
	int *base;	// ָ��
	int front, rear; // ͷ��βָ��
}SqQueue;
// ��ʼ��
void InitQueue(SqQueue& Q) {
	Q.base = new int[MAXSIZE];
	Q.front = Q.rear = 0;
}
// ���
bool EnQueue(SqQueue& Q, int e) {
	if ((Q.rear + 1) % MAXSIZE == Q.front) {
		return false;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return true;
}
// ����
bool DeQueue(SqQueue& Q, int& e) {
	if (Q.front == Q.rear) return false; // �п�
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}
// ��ȡ��ͷԪ��
bool GetHead(SqQueue& Q, int& e) {
	if (Q.front == Q.rear) return false; // �п�
	e = Q.base[Q.front];
	return true;
}
// �п�
bool QueueEmpty(SqQueue& Q) {
	return Q.front == Q.rear;
}
// ��ȡ��С
int QueueLength(SqQueue& Q) {
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
// ����
void QueueDisplay(SqQueue& Q) {
	for (int i = Q.front; i != Q.rear; i = (i + 1) % MAXSIZE) {
		cout << Q.base[i] << "\t";
	}
	cout << endl;
}
int main() {
	int e;
	SqQueue sq;
	// ��ʼ������
	InitQueue(sq);
	// �п�
	if (QueueEmpty(sq)) cout << "����Ϊ��" << endl;
	// ���+��ȡ��С
	EnQueue(sq, 1); cout << "Ԫ��1��Ӻ󣬶��д�СΪ��" << QueueLength(sq) << endl;
	EnQueue(sq, 2); cout << "Ԫ��2��Ӻ󣬶��д�СΪ��" << QueueLength(sq) << endl;
	EnQueue(sq, 3); cout << "Ԫ��3��Ӻ󣬶��д�СΪ��" << QueueLength(sq) << endl;
	EnQueue(sq, 4); cout << "Ԫ��4��Ӻ󣬶��д�СΪ��" << QueueLength(sq) << endl;
	if (!EnQueue(sq, 5)) cout << "Ԫ��5���ʧ�ܣ���������" << endl;
	// ��������Ԫ��
	cout << "Ԫ����Ӻ󣬶���Ԫ��Ϊ��" << endl;
	QueueDisplay(sq);
	// ����
	DeQueue(sq, e); cout << "Ԫ��:" << e << "���Ӻ󣬶��д�СΪ��" << QueueLength(sq) << endl;
	DeQueue(sq, e); cout << "Ԫ��:" << e << "���Ӻ󣬶��д�СΪ��" << QueueLength(sq) << endl;
	DeQueue(sq, e); cout << "Ԫ��:" << e << "���Ӻ󣬶��д�СΪ��" << QueueLength(sq) << endl;
	// ��ȡ��ͷ
	if (GetHead(sq, e)) cout << "��ʱ���еĶ�ͷ��:"<< e << endl;
	// ��������Ԫ��
	EnQueue(sq, 5); EnQueue(sq, 6);
	cout << "Ԫ��5��6��Ӻ󣬶���Ԫ��Ϊ��" << endl;
	QueueDisplay(sq);
	return 0;
}