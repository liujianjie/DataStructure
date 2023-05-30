#include <iostream>
#include <string>
using namespace std;



class LinkList {
public:
	void List_HeadInsert();
	void PrintLinkList();
public:
	int data;
	LinkList* next;
};
void LinkList::List_HeadInsert() {
	LinkList* s, * r;
	LinkList *L = this;
	int x;
	this->next = NULL;
	cin >> x;
	while ( x != 0) {
		s = new LinkList();
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
	}
}
void LinkList::PrintLinkList() {
	LinkList* p = this;
	while (p->next != NULL) {
		p = p->next;
		printf("%d\t", p->data);// 放后面因为头结点是没有值的 
	}
	printf("\n");
}
int main() {
	LinkList L;
	L.List_HeadInsert();
	L.PrintLinkList();
	return 0;
}



