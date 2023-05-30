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
// --------------------------队列基本操作代码------------------
typedef struct LNode {
	Person data;
	struct LNode* next;
}LNode;
typedef struct {
	LNode* front,*rear;
}LQueue;
// 初始化
void InitQueue(LQueue& Q) {
	Q.front = Q.rear = new LNode();
	Q.front->next = Q.rear->next = NULL;
}
// 入队 - 在队尾入
bool EnQueue(LQueue& Q, Person e) {
	LNode* p = new LNode();
	p->data = e;
	p->next = Q.rear->next;
	Q.rear->next = p;
	Q.rear = p;
	return true;
}
// 出队 - 在队头出
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
// 获取队头元素
bool GetHead(LQueue& Q, Person& e) {
	if (Q.front == Q.rear) return false;
	e = Q.front->next->data;
	return true;
}
// 判空
bool QueueEmpty(LQueue& Q) {
	return Q.front == Q.rear;
}
// 遍历
void QueueDisplay(LQueue& Q) {
	LNode* p = Q.front;
	while (p->next != NULL) {
		p = p->next;
		cout << p->data.name << " ";
	}
	cout << endl;
}
// --------------------------舞伴问题代码------------------
void DancePartner(Person dancer[], int num) {
	LQueue Mdancers, Fdancers;
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
	Person dancer[] = {Person("小红", 'F'), Person("小美", 'F'), Person("小花", 'F'), Person("小丽", 'F'),
						Person("小燕", 'F'), Person("小颜", 'F'),
						Person("小明", 'M'), Person("小李", 'M'), Person("小飞", 'M'), Person("小武", 'M'),
						Person("小建", 'M')};
	DancePartner(dancer, sizeof(dancer) / sizeof(Person));
	return 0;
}