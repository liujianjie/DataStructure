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
// --------------------------队列基本操作代码------------------
typedef struct {
	Person* base;	// 指针
	int front, rear; // 头和尾指针
}SqQueue;
// 初始化
void InitQueue(SqQueue& Q) {
	Q.base = new Person[MAXSIZE];
	Q.front = Q.rear = 0;
}
// 入队
bool EnQueue(SqQueue& Q, Person e) {
	if ((Q.rear + 1) % MAXSIZE == Q.front) return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return true;
}
// 出队
bool DeQueue(SqQueue& Q, Person& e) {
	if (Q.front == Q.rear) return false; // 判空
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}
// 获取队头元素
bool GetHead(SqQueue& Q, Person& e) {
	if (Q.front == Q.rear) return false; // 判空
	e = Q.base[Q.front];
	return true;
}
// 判空
bool QueueEmpty(SqQueue& Q) {
	return Q.front == Q.rear;
}
// 遍历
void QueueDisplay(SqQueue& Q) {
	for (int i = Q.front; i != Q.rear; i = (i + 1) % MAXSIZE) {
		cout << Q.base[i].name << "\t";
	}
	cout << endl;
}
// --------------------------舞伴问题代码------------------
void DancePartner(Person dancer[], int num) {
	SqQueue Mdancers, Fdancers;
	InitQueue(Mdancers);
	InitQueue(Fdancers);
	for (int i = 0; i < num; i++) {
		if (dancer[i].sex == 'M') {				// 根据性别不同插入不同队列当中
			EnQueue(Mdancers, dancer[i]);
		}
		else {
			EnQueue(Fdancers, dancer[i]);
		}
	}
	cout << "男士队列:" << endl;
	QueueDisplay(Mdancers);
	cout << "女士队列" << endl;
	QueueDisplay(Fdancers);
	Person tempPerson;
	while (!QueueEmpty(Mdancers) && !QueueEmpty(Fdancers)) {	// 舞伴配对
		DeQueue(Mdancers, tempPerson);						// 男士队列出队
		cout << tempPerson.name << "与";
		DeQueue(Fdancers, tempPerson);						// 女士队列出队
		cout << tempPerson.name << "成对" << endl;
	}
	if (!QueueEmpty(Mdancers)) {								// 男士队列非空，输出男士队头
		GetHead(Mdancers, tempPerson);
		cout << "当前排在男生队头的等待者是：" << tempPerson.name << endl;
	}
	if (!QueueEmpty(Fdancers)) {								// 女士队列非空，输出女士队头
		GetHead(Fdancers, tempPerson);
		cout << "当前排在女生队头的等待者是：" << tempPerson.name << endl;
	}
}
int main() {
	Person dancer[] = { Person("小明", 'M'), Person("小李", 'M'), Person("小飞", 'M'), Person("小武", 'M'),
						Person("小建", 'M'), Person("小陈", 'M'), Person("小杰", 'M'),
						Person("小红", 'F'), Person("小美", 'F'), Person("小花", 'F'), Person("小丽", 'F'),
						Person("小颜", 'F') };
	DancePartner(dancer, sizeof(dancer) / sizeof(Person));
	return 0;
}