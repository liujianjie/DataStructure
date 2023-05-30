#include <iostream>
using namespace std;
//----------------------1.带头指针的单链表ADT代码---------------------------
// 带头结点
typedef struct LNode {
	int val;
	struct LNode* next;
}LNode, * LinkList;
// 尾插法创建链表
void CreateListByTailInsert(LinkList& L) {
	L = new LNode();// 创建头结点
	L->next = NULL;// 置位空
	LNode* s, * r = L;
	int val;
	cin >> val;
	while (val != 0) {
		s = new LNode();
		s->val = val;
		r->next = s;// 尾指针的下一个节点是刚创建的节点
		r = s; // 将尾指针移到末尾
		cin >> val;
	}
	r->next = NULL;// 将尾节点的next为空
}
// 遍历链表
void PrintLinkList(LinkList& L) {
	LNode* p = L->next;
	while (p != NULL) {
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;
}
//----------------------2.书上第10题代码---------------------------
// 递归自底向上
// 1.递归求链表中的最大整数
int LinkListMaxInt(LNode* p) {
	// 终止条件
	if (p->next == NULL) {
		return p->val;
	}
	// 递归部分
	int maxval = LinkListMaxInt(p->next);
	return p->val > maxval ? p->val : maxval;
}
// 2.递归求链表中的结点个数
int LinkListCount(LNode* p) {
	// 终止条件
	if (p == NULL) {
		return 0;
	}
	// 递归部分
	return 1 + LinkListCount(p->next); // 自身1个个数加上下一个的个数
}
// 3.递归求链表中的所有整数的平均值
double LinkAvg(LNode* p, int n) {// 注意使用double，如果int会出错
	// 终止条件
	if (p->next == NULL) {
		return p->val;
	}
	// 递归部分
	double zqavg = LinkAvg(p->next, n - 1); // 之前的平均值
	return (zqavg * (n - 1) + p->val) / n;// 新平均值 =（之前的值+当前的值）/ 个数
} 
int main()
{
	LinkList L;// 创建链表
	CreateListByTailInsert(L);
	cout << "创建链表的元素为：" << endl;
	PrintLinkList(L);
	// 1. 问题1，递归求链表中的最大整数
	cout << "链表中的最大整数是：" << LinkListMaxInt(L->next) << endl;
	// 2. 问题2，递归求链表中结点个数
	int n = LinkListCount(L->next);
	cout << "链表中结点个数是：" << n << endl;
	// 3. 问题3，递归求链表中的所有整数的平均值
	cout << "链表中的所有整数的平均值：" << LinkAvg(L->next, n) << endl;
	return 0;
}