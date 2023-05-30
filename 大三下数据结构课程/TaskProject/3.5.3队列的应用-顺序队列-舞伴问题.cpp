#include <iostream>
#include <string>
using namespace std;
#define MAXSIZE 100

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
typedef struct {
	Person* base;	// ָ��
	int front, rear; // ͷ��βָ��
}SqQueue;
// ��ʼ��
void InitQueue(SqQueue& Q) {
	Q.base = new Person[MAXSIZE];
	Q.front = Q.rear = 0;
}
// ���
bool EnQueue(SqQueue& Q, Person e) {
	if ((Q.rear + 1) % MAXSIZE == Q.front) return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return true;
}
// ����
bool DeQueue(SqQueue& Q, Person& e) {
	if (Q.front == Q.rear) return false; // �п�
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}
// ��ȡ��ͷԪ��
bool GetHead(SqQueue& Q, Person& e) {
	if (Q.front == Q.rear) return false; // �п�
	e = Q.base[Q.front];
	return true;
}
// �п�
bool QueueEmpty(SqQueue& Q) {
	return Q.front == Q.rear;
}
// ����
void QueueDisplay(SqQueue& Q) {
	for (int i = Q.front; i != Q.rear; i = (i + 1) % MAXSIZE) {
		cout << Q.base[i].name << "\t";
	}
	cout << endl;
}
// --------------------------����������------------------
void DancePartner(Person dancer[], int num) {
	SqQueue Mdancers, Fdancers;
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
	Person dancer[] = { Person("С��", 'M'), Person("С��", 'M'), Person("С��", 'M'), Person("С��", 'M'),
						Person("С��", 'M'), Person("С��", 'M'), Person("С��", 'M'),
						Person("С��", 'F'), Person("С��", 'F'), Person("С��", 'F'), Person("С��", 'F'),
						Person("С��", 'F') };
	DancePartner(dancer, sizeof(dancer) / sizeof(Person));
	return 0;
}