// 1.ʱ�临�Ӷ�O(n * m), �ռ临�Ӷ�O(n)
// ����ͷ����ѭ��������ʵ��Լɪ������
#include <iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node* next;
} LNode, * LinkList;

// �������
void PrintLinkList(LinkList& L) {
	if (L == NULL) return;
	LNode* p = L;
	cout << p->data << " ";
	p = p->next;
	while (p != L) {// ������Ԫ�ڵ�
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

// ������
LinkList List_TailInsert(LinkList& L) {// β�巨
	L = new LNode(); // ��ʼ��һ����Ԫ�ڵ�
	int x;
	LNode* s = L, * r = NULL; // r��βָ��
	cin >> x;
	while (x != 0) {
		s->data = x;
		if (r != NULL) {  // ��һ�ε�βָ��Ϊ��
			r->next = s;// βָ�����һ�� = �½ڵ�
		}
		r = s;// �ƶ�βָ�뵽�½ڵ���
		cin >> x;
		s = new LNode();
	}
	r->next = L;// β���Ľ��Ϊ��Ԫ�ڵ� 
	return L;
}

// Լɪ��
void YSFH(LinkList& L, int M) {// M��������
	LNode* p = L, * r = L;// p�ǵ�ǰָ�룬r����һ��ָ��
	int ct = 1; // ct���ۼ�M�ı�������ʼ��Ϊ1
	while (p->next != p) {// ��ʣ���Լ�һ�����˳�
		while (ct < M) { // ����M
			ct++;
			r = p; // ��¼��һ��ָ��
			p = p->next; // ָ����ǰ
		}
		cout << p->data << " ";// ����������
		r->next = p->next;// �߼���ɾ�����p�ڵ㣬����ռ���ûɾ��
		p = p->next;// pָ��ɾ������һ���ڵ�
		ct = 1; // ��ʼ��1
	}
	// ���ʣ��һ��
	cout << p->data << " ";
	cout << endl;
}
int main()
{
	LinkList L;
	List_TailInsert(L);
	cout << "�����Ԫ��Ϊ:" << endl;
	PrintLinkList(L);
	cout << "Լɪ�������Ԫ��Ϊ:" << endl;
	YSFH(L, 3);// ����3
	return 0;
}