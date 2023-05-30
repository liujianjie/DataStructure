#include <iostream>
using namespace std;

struct Person {
	string name;
	char sex;
	Person(string name, char sex) {
		this->name = name;
		this->sex = sex;
	}
	Person() {}
};
// --------------------------���л�����������------------------
typedef struct LNode {
	Person data;
	struct LNode* next;
}LNode;
typedef struct {
	LNode* front,*rear;
}LQueue;
// ��ʼ��
void InitQueue(LQueue& Q) {
	Q.front = Q.rear = new LNode();
	Q.front->next = Q.rear->next = NULL;
}
// ��� - �ڶ�β��
bool EnQueue(LQueue& Q, Person e) {
	LNode* p = new LNode();
	p->data = e;
	p->next = Q.rear->next;
	Q.rear->next = p;
	Q.rear = p;
	return true;
}
// ���� - �ڶ�ͷ��
bool DeQueue(LQueue& Q, Person& e) {
	if (Q.front == Q.rear) return false;
	LNode* p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.front->next == NULL || p == Q.rear) {
		Q.rear = Q.front;
	}
	delete p;
	return true;
}
// ��ȡ��ͷԪ��
bool GetHead(LQueue& Q, Person& e) {
	if (Q.front == Q.rear) return false;
	e = Q.front->next->data;
	return true;
}
// �п�
bool QueueEmpty(LQueue& Q) {
	return Q.front == Q.rear;
}
// ����
void QueueDisplay(LQueue& Q) {
	LNode* p = Q.front;
	while (p->next != NULL) {
		p = p->next;
		cout << p->data.name << " ";
	}
	cout << endl;
}
// --------------------------����������------------------
void DancePartner(Person dancer[], int num) {
	LQueue Mdancers, Fdancers;
	InitQueue(Mdancers);
	InitQueue(Fdancers);
	for (int i = 0; i < num; i++) {
		if (dancer[i].sex == 'M') {				// �����Ա�ͬ���벻ͬ���е���
			EnQueue(Mdancers, dancer[i]);
		}
		else {
			EnQueue(Fdancers, dancer[i]);
		}
	}
	cout << "��ʿ����:" << endl;
	QueueDisplay(Mdancers);
	cout << "Ůʿ����" << endl; 
	QueueDisplay(Fdancers);
	Person tempPerson;
	while (!QueueEmpty(Mdancers) && !QueueEmpty(Fdancers)) {	// ������
		DeQueue(Mdancers, tempPerson);						// ��ʿ���г���
		cout << tempPerson.name << "��";
		DeQueue(Fdancers, tempPerson);						// Ůʿ���г���
		cout << tempPerson.name << "�ɶ�" << endl;
	}
	if (!QueueEmpty(Mdancers)) {								// ��ʿ���зǿգ������ʿ��ͷ
		GetHead(Mdancers, tempPerson);
		cout << "��ǰ����������ͷ�ĵȴ����ǣ�" << tempPerson.name << endl;
	}
	if (!QueueEmpty(Fdancers)) {								// Ůʿ���зǿգ����Ůʿ��ͷ
		GetHead(Fdancers, tempPerson);
		cout << "��ǰ����Ů����ͷ�ĵȴ����ǣ�" << tempPerson.name << endl;
	}
}
int main() {
	Person dancer[] = {Person("С��", 'F'), Person("С��", 'F'), Person("С��", 'F'), Person("С��", 'F'),
						Person("С��", 'F'), Person("С��", 'F'),
						Person("С��", 'M'), Person("С��", 'M'), Person("С��", 'M'), Person("С��", 'M'),
						Person("С��", 'M')};
	DancePartner(dancer, sizeof(dancer) / sizeof(Person));
	return 0;
}