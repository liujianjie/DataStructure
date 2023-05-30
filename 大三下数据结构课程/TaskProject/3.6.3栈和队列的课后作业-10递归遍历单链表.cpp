#include <iostream>
using namespace std;
//----------------------1.��ͷָ��ĵ�����ADT����---------------------------
// ��ͷ���
typedef struct LNode {
	int val;
	struct LNode* next;
}LNode, * LinkList;
// β�巨��������
void CreateListByTailInsert(LinkList& L) {
	L = new LNode();// ����ͷ���
	L->next = NULL;// ��λ��
	LNode* s, * r = L;
	int val;
	cin >> val;
	while (val != 0) {
		s = new LNode();
		s->val = val;
		r->next = s;// βָ�����һ���ڵ��Ǹմ����Ľڵ�
		r = s; // ��βָ���Ƶ�ĩβ
		cin >> val;
	}
	r->next = NULL;// ��β�ڵ��nextΪ��
}
// ��������
void PrintLinkList(LinkList& L) {
	LNode* p = L->next;
	while (p != NULL) {
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;
}
//----------------------2.���ϵ�10�����---------------------------
// �ݹ��Ե�����
// 1.�ݹ��������е��������
int LinkListMaxInt(LNode* p) {
	// ��ֹ����
	if (p->next == NULL) {
		return p->val;
	}
	// �ݹ鲿��
	int maxval = LinkListMaxInt(p->next);
	return p->val > maxval ? p->val : maxval;
}
// 2.�ݹ��������еĽ�����
int LinkListCount(LNode* p) {
	// ��ֹ����
	if (p == NULL) {
		return 0;
	}
	// �ݹ鲿��
	return 1 + LinkListCount(p->next); // ����1������������һ���ĸ���
}
// 3.�ݹ��������е�����������ƽ��ֵ
double LinkAvg(LNode* p, int n) {// ע��ʹ��double�����int�����
	// ��ֹ����
	if (p->next == NULL) {
		return p->val;
	}
	// �ݹ鲿��
	double zqavg = LinkAvg(p->next, n - 1); // ֮ǰ��ƽ��ֵ
	return (zqavg * (n - 1) + p->val) / n;// ��ƽ��ֵ =��֮ǰ��ֵ+��ǰ��ֵ��/ ����
} 
int main()
{
	LinkList L;// ��������
	CreateListByTailInsert(L);
	cout << "���������Ԫ��Ϊ��" << endl;
	PrintLinkList(L);
	// 1. ����1���ݹ��������е��������
	cout << "�����е���������ǣ�" << LinkListMaxInt(L->next) << endl;
	// 2. ����2���ݹ��������н�����
	int n = LinkListCount(L->next);
	cout << "�����н������ǣ�" << n << endl;
	// 3. ����3���ݹ��������е�����������ƽ��ֵ
	cout << "�����е�����������ƽ��ֵ��" << LinkAvg(L->next, n) << endl;
	return 0;
}