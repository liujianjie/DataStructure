#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList;

void Init(LinkList &L);
LinkList List_HeadInsert(LinkList &L);
LinkList List_TailInsert(LinkList &L);
LNode *GetElem(LinkList& L, int i);
LNode *LocateElem(LinkList& L, int e);
bool InsertNextNode(LNode *p, int e);
bool InsertPriorNode(LNode *p, int e);
bool DeleteZhidingLNode(LNode *p);
bool ListInsert(LinkList &L, int i, int e);
bool ListInsertBefore(LinkList &L, int i, int e);
bool ListDelete(LinkList &L, int i, int &e);
bool ListDeleteZhiding(LinkList &L, int i, int &e);
int Length(LinkList &L);
void PrintLinkList(LinkList &L);
void LinkInsertAtTail(LinkList &L, int e);// ���뵽ĩβ 

void Operate(LinkList &L1, LinkList &L2, LinkList &L3){
	LNode *p = L1->next, *q = L2;
	for(LNode *p = L1->next; p != NULL; p = p->next){
		for(LNode *q = L2->next; q != NULL; q = q->next){
			if(p->data == q->data){
				LinkInsertAtTail(L3, p->data);
			}
		} 
	}
} 

// ������ô�鷳�ҵ����һ���ڵ��λ�ã�ֻ��Ҫ ͷ�巨����β�巨 
void Operate2(LinkList &L1, LinkList &L2, LinkList &L3){
	LNode *r = L3;// β�� 
	LNode *p = L1->next, *q = L2;
	for(LNode *p = L1->next; p != NULL; p = p->next){
		for(LNode *q = L2->next; q != NULL; q = q->next){
			if(p->data == q->data){
				LNode *s = new LNode();
				s->data = p->data;
				r->next = s;
				r = s;
				break; 
			}
		} 
	}
	// ���β���ÿ�
	r->next = NULL; 
} 
int main(){
	int e;
	// ʵ�ֲ���
	LinkList L1;
	List_TailInsert(L1);
	
	
	LinkList L2;
	List_TailInsert(L2);
	
	LinkList L3;
	Init(L3);
	LinkList L4;
	Init(L4);
	Operate(L1, L2, L3);
	PrintLinkList(L3);
	
	Operate2(L1, L2, L4);
	PrintLinkList(L4);
}

void Init(LinkList &L){// ��ʼ�� 
	L = (LinkList)malloc(sizeof(LNode));// ����ͷ���
	L->next = NULL;						// ��ʼΪ������,��Ȼ��ָ��ȷ���ĵط� 
}
// ���Ľ���
// ͷ�巨
LinkList List_HeadInsert(LinkList &L) {// ������������ 
	LNode *s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));// ����ͷ���
	L->next = NULL;						// ��ʼΪ������,��Ȼ��ָ��ȷ���ĵط� 
	scanf("%d", &x); 
	while(x != 0){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}
// β�巨 
LinkList List_TailInsert(LinkList &L){
	int x;
	L = (LinkList)malloc(sizeof(LNode));// ����ͷ���
	LNode *s, *r = L;
//	scanf("%d", &x); 
	cin >> x;
	while(x != 0){
//		s = (LNode*)malloc(sizeof(LNode));
		s = new LNode();
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;// β���Ľ��Ϊ�� 
	return L;
}
// ��λ����ҽ��ֵ��ͷ����λ����0,1�ǵ�һ���ڵ� 
LNode *GetElem(LinkList& L, int i) {
	// �� 
//	if(i == 0){
//		return L;				// ����ͷ��� 
//	}
//	if(i < 1){
//		return NULL;			// ���Ϸ� 
//	}
//	int j = 1; 					// ��ʼ��Ϊ1����ΪĬ��λ��0��ͷ���, 1�ǵ�һ���ڵ� 
//	LNode *p = L->next;			// Ĭ���ҵ���һ����� 
//	while(p != NULL && j < i){	// ����Ѱ�� 
//		p = p->next;
//		j++;
//	}
	// ���
	if(i < 0){
		return NULL;
	} 
	int j = 0;
	LNode *p = L;				// ͷ��㿪ʼ 
	while(p != NULL && j < i){	// ����Ѱ�� 
		p = p->next;
		j++;
	}
	return p; 
}
// ��ֵ���ҽ��
LNode *LocateElem(LinkList& L, int e) {
	LNode *p = L->next;			// ��Ū��ͷ������һ���ڵ㣬Ҳ���ǵ�һ���ڵ� 
	while(p != NULL && p->data != e){	// �� ��һ���ڵ㿪ʼ 
		p = p->next;
	} 
	return p;
}
// ����������p��������½ڵ�
bool InsertNextNode(LNode *p, int e){
	if(p == NULL){
		return false;
	}
	LNode *s = (LNode*)malloc(sizeof(LNode));	// ������ 
	if(s == NULL){
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;									// ��s�������p֮�� 
	return true;
} 

// ǰ���������p���֮ǰ����Ԫ��e
bool InsertPriorNode(LNode *p, int e){
	if(p == NULL){
		return false;
	} 
	LNode *s = (LNode*) malloc(sizeof(LNode));
	if(s == NULL){
		return false;
	}
	s->next = p->next;	// �½��s���¸��ڵ���p���¸��ڵ� 
	p->next = s;		// �½��s����p֮�� 
	s->data = p->data;	// ��p�е�Ԫ�ظ��Ƶ�s�� 
	p->data = e;		// ��p�е�Ԫ�ظ���Ϊe����ɽ��� 
	return true;
} 
 
// ɾ��ָ�����p, �޷��ҵ�ǰ����ֻ�ܽ�����������ɾ�����������һ���ڵ㲻�� 
bool DeleteZhidingLNode(LNode *p){
	if(p == NULL){
		return false; 
	}
	LNode *q = p->next;	// ��qָ��p�ĺ�̽�� 
	p->data = q->data;	// �ͺ�̽�㽻�������� 
	p->next = q->next;	// ��*q��������жϿ� 
	free(q);			// �ͷ�ԭ��̽��Ĵ洢�ռ� 
	return true; 
}

// ��λ��i��λ�ò��������
bool ListInsert(LinkList &L, int i, int e){
	LNode *p = GetElem(L, i - 1);					// �ҵ�i��ǰһ����� 
	return InsertNextNode(p, e); 
} 
// ��λ��i��λ��ǰ���������
bool ListInsertBefore(LinkList &L, int i, int e){
	LNode *p = GetElem(L, i);					// �ҵ�i��� 
	return InsertPriorNode(p, e); 
} 
// ��λ��i��λ��ɾ��������
bool ListDelete(LinkList &L, int i, int &e){
	LNode *p = GetElem(L, i - 1);					// �ҵ�i��ǰһ����� 
	if(p == NULL){
		return false;
	}
	LNode *q = p->next;	// ��qָ��ɾ����� 
	p->next = q->next;	// ��q�ڵ������жϿ� 
	e = q->data;			// eΪ��ɾ������ֵ 
	free(q);			// �ͷű�ɾ�����Ŀռ� 
	return true;
}
// ɾ��λ��i�Ľ�� 
bool ListDeleteZhiding(LinkList &L, int i, int &e){
	LNode *p = GetElem(L, i);					// �ҵ�i��� 
	if(p == NULL){
		return false;
	}
	return DeleteZhidingLNode(p);
}

// ���
int Length(LinkList &L){
	int j = 0;
	LNode *p = L;
	while(p->next != NULL){// ע����p->next  
		p = p->next;
		j++;
	}
	return j;
} 
 
// �������
void PrintLinkList(LinkList &L){
//	LNode *p = L;
//	while(p->next != NULL){
//		p = p->next;
//		printf("%d\t", p->data);// �ź�����Ϊͷ�����û��ֵ�� 
//	}
//	printf("\n");
	LNode *p = L->next;
	while(p != NULL){
		printf("%d\t", p->data);// �ź�����Ϊͷ�����û��ֵ�� 
		p = p->next;
	}
	printf("\n");
} 

void LinkInsertAtTail(LinkList &L, int e){
	LNode *p = L;
	while(p->next != NULL){
		p = p->next;
	}
	LNode *s = new LNode();
	s->data = e;
	s->next = NULL;
	p->next = s;
}



