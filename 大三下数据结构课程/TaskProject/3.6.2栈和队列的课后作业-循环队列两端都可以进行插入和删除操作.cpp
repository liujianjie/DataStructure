#include <iostream>
using namespace std;
#define MAXSIZE 5
// ��1��д��ѭ�����е����Ͷ���------------------------------------------------
typedef struct {
	int* base;	// ָ��
	int front, rear; // ͷ��βָ��
}SqQueue;
// ��ʼ��
void InitQueue(SqQueue& Q) {
	Q.base = new int[MAXSIZE];
	Q.front = Q.rear = 0;
}
// ��2��д�����Ӷ�βɾ�����͡��Ӷ�ͷ���롱���㷨--------------------------------
//  �Ӷ�βɾ��
bool DeQueue(SqQueue& Q, int& e) {
	if (Q.front == Q.rear) return false; // �п�
	e = Q.base[Q.rear];
	Q.rear = (Q.rear - 1 + MAXSIZE) % MAXSIZE; // �ȼ�, ע����Ļ�Ҫ+MAXSIZE
	// e = Q.base[(Q.rear - 1 + MAXSIZE) % MAXSIZE]; // ���ȡֵ�ź��棬rearҪ���ϼ�ȥ��1
	return true;
}
// �Ӷ�ͷ����
bool EnQueue(SqQueue& Q, int e) {
	if ((Q.front - 1 + MAXSIZE) % MAXSIZE == Q.rear) {// �Ǽ�-1, ע����Ļ�Ҫ+MAXSIZE
		return false;
	}
	Q.base[Q.front] = e;
	Q.front = (Q.front - 1 + MAXSIZE) % MAXSIZE; // ��1, ע����Ļ�Ҫ+MAXSIZE
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
	for (int i = Q.rear; i != Q.front; i = (i - 1 + MAXSIZE) % MAXSIZE) {
		cout << Q.base[i] << "\t";
	}
	cout << endl;
}
int main() {
	int e;
	SqQueue sq;
	InitQueue(sq);// ��ʼ������
	// ���
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
	// ��������Ԫ��
	EnQueue(sq, 5); EnQueue(sq, 6);
	cout << "Ԫ��5��6��Ӻ󣬶���Ԫ��Ϊ��" << endl;
	QueueDisplay(sq);
	// ����
	DeQueue(sq, e); cout << "Ԫ��:" << e << "���Ӻ󣬶��д�СΪ��" << QueueLength(sq) << endl;
	// ��������Ԫ��
	cout << "����Ԫ��Ϊ��" << endl;
	QueueDisplay(sq);
	return 0;
}