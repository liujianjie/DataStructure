// 1.时间复杂度O(n * m), 空间复杂度O(n)
// 不带头结点的循环单链表实现约瑟夫环问题
#include <iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node* next;
} LNode, * LinkList;

// 链表输出
void PrintLinkList(LinkList& L) {
	if (L == NULL) return;
	LNode* p = L;
	cout << p->data << " ";
	p = p->next;
	while (p != L) {// 不是首元节点
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

// 链表建立
LinkList List_TailInsert(LinkList& L) {// 尾插法
	L = new LNode(); // 初始化一个首元节点
	int x;
	LNode* s = L, * r = NULL; // r是尾指针
	cin >> x;
	while (x != 0) {
		s->data = x;
		if (r != NULL) {  // 第一次的尾指针为空
			r->next = s;// 尾指针的下一个 = 新节点
		}
		r = s;// 移动尾指针到新节点上
		cin >> x;
		s = new LNode();
	}
	r->next = L;// 尾部的结点为首元节点 
	return L;
}

// 约瑟夫环
void YSFH(LinkList& L, int M) {// M是数到几
	LNode* p = L, * r = L;// p是当前指针，r是上一个指针
	int ct = 1; // ct是累计M的变量，初始化为1
	while (p->next != p) {// 就剩下自己一个就退出
		while (ct < M) { // 数到M
			ct++;
			r = p; // 记录上一个指针
			p = p->next; // 指针向前
		}
		cout << p->data << " ";// 输出这个数到
		r->next = p->next;// 逻辑上删除这个p节点，物理空间上没删除
		p = p->next;// p指向被删除的下一个节点
		ct = 1; // 初始化1
	}
	// 最后剩下一个
	cout << p->data << " ";
	cout << endl;
}
int main()
{
	LinkList L;
	List_TailInsert(L);
	cout << "链表的元素为:" << endl;
	PrintLinkList(L);
	cout << "约瑟夫输出的元素为:" << endl;
	YSFH(L, 3);// 数到3
	return 0;
}