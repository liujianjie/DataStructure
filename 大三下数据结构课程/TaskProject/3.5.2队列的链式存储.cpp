// ��ͷ������ʽ����
#include <iostream>
using namespace std;

typedef struct LNode {
	int data;	// ����
	struct LNode *next; // ��һ��ָ��λ��
}LNode;
typedef struct {
	LNode* front, * rear;// ��ͷ��βָ��
}LQueue;
// ��ʼ��
void InitQueue(LQueue& Q) {
	Q.front = Q.rear = new LNode(); // ��ͷ���, ͷ��βָ����
	Q.front->next = NULL;			// ͷ������һ����Ϊ��
}
// ��� - �ڶ�β��
bool EnQueue(LQueue& Q, int e) {
	LNode* p = new LNode();
	p->data = e;
	p->next = NULL;// ע���½����Ҫ�ŵ�ĩβ�ģ���һ��Ҫ��Ϊ��,�ȼ� p->next = Q.rear->next
	Q.rear->next = p;
	Q.rear = p; // ����β���Ϊ�½��
	return true;
}
// ���� - �ڶ�ͷ��
bool DeQueue(LQueue& Q, int& e) {
	if (Q.front == Q.rear) return false;// �п�
	LNode* p = Q.front->next;// ��¼��Ԫ���
	e = p->data;
	Q.front->next = p->next; // ͷ��㲻�䣬��Ԫ���ı�
	// ע�⵱ɾ����ֻ��һ��ͷ����ʱ��βָ����޸�,��Ϊβָ��ָ��Ľ��ᱻɾ�����ᵼ��βָ��ָ��λ�ö�ʧ
	if (Q.front->next == NULL || p == Q.rear) {
		Q.rear = Q.front; // ��βָ��ָ��ͷ���
	}
	delete p;
	return true;
}
// ��ȡ��ͷԪ��
bool GetHead(LQueue& Q, int& e) {
	if (Q.front == Q.rear) return false; // �п�
	e = Q.front->next->data;
	return true;
}
// �п�
bool QueueEmpty(LQueue& Q) {
	return Q.front == Q.rear;
}
// ��ȡ��С
int QueueLength(LQueue& Q) {
	LNode* p = Q.front;
	int size = 0;
	while (p->next != NULL) {
		p = p->next;
		size++;
	}
	return size;
}
// ����
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
	// ��ʼ������
	InitQueue(lq);
	// �п�
	if (QueueEmpty(lq)) cout << "����Ϊ��" << endl;
	// ���+��ȡ��С
	EnQueue(lq, 6); cout << "Ԫ��6��Ӻ󣬶��д�СΪ��" << QueueLength(lq) << endl;
	EnQueue(lq, 7); cout << "Ԫ��7��Ӻ󣬶��д�СΪ��" << QueueLength(lq) << endl;
	EnQueue(lq, 8); cout << "Ԫ��8��Ӻ󣬶��д�СΪ��" << QueueLength(lq) << endl;
	EnQueue(lq, 9); cout << "Ԫ��9��Ӻ󣬶��д�СΪ��" << QueueLength(lq) << endl;
	EnQueue(lq, 10); cout << "Ԫ��10��Ӻ󣬶��д�СΪ��" << QueueLength(lq) << endl;
	// ��������Ԫ��
	cout << "Ԫ����Ӻ󣬶���Ԫ��Ϊ��" << endl;
	QueueDisplay(lq);
	// ����
	DeQueue(lq, e); cout << "Ԫ��:" << e << "���Ӻ󣬶��д�СΪ��" << QueueLength(lq) << endl;
	DeQueue(lq, e); cout << "Ԫ��:" << e << "���Ӻ󣬶��д�СΪ��" << QueueLength(lq) << endl;
	DeQueue(lq, e); cout << "Ԫ��:" << e << "���Ӻ󣬶��д�СΪ��" << QueueLength(lq) << endl;
	// ��ȡ��ͷ
	if (GetHead(lq, e)) cout << "��ʱ���еĶ�ͷ��:" << e << endl;
	// ��������Ԫ��
	EnQueue(lq, 11); EnQueue(lq, 12);
	cout << "Ԫ��11��12��Ӻ󣬶���Ԫ��Ϊ��" << endl;
	QueueDisplay(lq);
	return 0;
}