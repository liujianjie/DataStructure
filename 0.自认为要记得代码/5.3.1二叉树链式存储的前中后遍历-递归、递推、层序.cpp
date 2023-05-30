#include <stdio.h> 
#include <stdlib.h>
#include <cmath> // 为了实现log运算，导入cmath库
#include <queue> // 借助队列，实现层次遍历
#include <stack> // 借助栈，实现递推遍历
using namespace std;
typedef struct TNodeData {
	int data; // 值 
	int index;// 位序，可以得出深度 
}TNodeData;

typedef struct BiTNode {
	TNodeData* tdata; 		// 数据域 
	struct BiTNode* lchild, * rchild;// 左右孩子指针 
	struct BiTNode* parent;// 父亲结点 
}BiTNode, * BiTree;

// 插入根结点 
bool InsertRootNode(BiTree& btree, int e) {
	btree = (BiTree)malloc(sizeof(BiTNode));
	TNodeData* td = (TNodeData*)malloc(sizeof(TNodeData));
	td->data = e;
	td->index = 1;// 根结点的位序为1 

	btree->tdata = td;
	btree->lchild = NULL;
	btree->rchild = NULL;
	btree->parent = NULL;
	return true;
}

// 1.当前p结点的左孩子 
BiTNode* GetLeftC(BiTree& p) {
	if (p == NULL || p->lchild == NULL) {
		return NULL;
	}
	return p->lchild;
}
// 2.当前结点的右孩子  
BiTNode* GetRightC(BiTree& p) {
	if (p == NULL || p->rchild == NULL) {
		return NULL;
	}
	return p->rchild;
}
// 3.当前p结点的父亲  
BiTNode* GetParent(BiTree& p) {
	if (p == NULL || p->parent == NULL) {
		return NULL;
	}
	return p->parent;
}
// 4.获取当前p结点的深度
int GetDepth(BiTree& p) {
	if (p == NULL) {
		return 0;
	}
	return (log(p->tdata->index) / log(2) + 1);
}
// 当前c结点插入一个左结点
bool InsertTreeLeftNode(BiTree& c, int e) {
	BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
	TNodeData* td = (TNodeData*)malloc(sizeof(TNodeData));
	td->data = e;
	td->index = c->tdata->index * 2;// 根据c结点得出位序

	p->tdata = td;
	p->lchild = NULL;
	p->rchild = NULL;
	p->parent = c;

	c->lchild = p;
	return true;
}
// 当前c结点插入一个右结点
bool InsertTreeRightNode(BiTree& c, int e) {
	BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
	TNodeData* td = (TNodeData*)malloc(sizeof(TNodeData));
	td->data = e;
	td->index = c->tdata->index * 2 + 1;// 根据c结点得出位序

	p->tdata = td;
	p->lchild = NULL;
	p->rchild = NULL;
	p->parent = c;

	c->rchild = p;
	return true;
}
// 删除c节点 : 要删除c结点的左右结点，并且释放空间
bool DeleteTreeNode(BiTree& c) {
	BiTNode* curp = c;
	BiTNode* p;
	while (curp != NULL) {// 扫描左结点
		p = curp->lchild;
		if (p != NULL) {
			curp = p->lchild;// 当前结点被删除之前获取当前结点的左结点，以便下次循环
		}
		else {
			curp = NULL;
		}
		free(p);
	}
	curp = c;// 当前节点开始扫描右节点 
	while (curp != NULL) {
		p = curp->rchild;
		if (p != NULL) {
			curp = p->rchild;
		}
		else {
			curp = NULL;
		}
		free(p);
	}
	// 注意此结点的父节点的左右结点置空。 
	if (c->parent->lchild == c) {
		c->parent->lchild = NULL;
	}
	else {
		c->parent->rchild = NULL;
	}
	free(c);// 释放自己 
	return true;
}
// 判断二叉树是否为空
bool Empty(BiTree& root) {
	if (root == NULL) {
		return true;
	}
	return false;
}
// 本小节重点------------------------------------------------
// 前序遍历 
void PreOrder(BiTree p) {// 不能引用类型 
	if (p != NULL) {
		printf("%d  ", p->tdata->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}
// 中序遍历 
void InOrder(BiTree p) {// 不能引用类型 
	if (p != NULL) {
		InOrder(p->lchild);
		printf("%d  ", p->tdata->data);
		InOrder(p->rchild);
	}
}
// 后序遍历 
void PostOrder(BiTree p) {// 不能引用类型 
	if (p != NULL) {
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%d  ", p->tdata->data);
	}
}
// 层次遍历 
void CenCi(BiTree& root) { 
	queue<BiTNode*> que;
	que.push(root);
	BiTNode* p;
	while (!que.empty()) {
		p = que.front();
		que.pop();
		printf("%d  ", p->tdata->data);
		if (p->lchild != NULL) {
			que.push(p->lchild);
		}
		if (p->rchild != NULL) {
			que.push(p->rchild);
		}
	}
}
// 难点------------------------------------------------
// 递推遍历
void PreOrderDiTui(BiTree& root) {// 前序
	stack<BiTNode*> bistack;
	BiTNode* p = root;
	while (p != NULL || !bistack.empty()) {
		if (p != NULL) {
			printf("%d  ", p->tdata->data);
			bistack.push(p);
			p = p->lchild;
		}
		else {
			p = bistack.top();
			bistack.pop();
			p = p->rchild;
		}
	}
	printf("\n");
}
void InOrderDiTui(BiTree& root) {// 中序 
	stack<BiTNode*> bistack;
	BiTNode* p = root;
	while (p != NULL || !bistack.empty()) {
		if (p != NULL) {
			bistack.push(p);
			p = p->lchild;
		}
		else {
			p = bistack.top();
			bistack.pop();
			printf("%d  ", p->tdata->data);
			p = p->rchild;
		}
	}
	printf("\n");
}
void PostOrderDiTui(BiTree& root) {// 后序 
	stack<BiTNode*> bistack;
	BiTNode* p = root;
	BiTNode* lastp = NULL;// 上一个访问的结点 ,关键点！，用来判断是否右子树返回 
	while (p != NULL || !bistack.empty()) {
		// 左子树依次入栈 
		if (p != NULL) {
			bistack.push(p);
			p = p->lchild;
		}
		else {
			// 没路走，父结点出栈需要满足以下两个条件之一
			// 1.右子树为空出栈
			// 2.右子树访问完返回也可以出栈
			p = bistack.top();
			if (p->rchild == NULL || p->rchild == lastp) {
				lastp = p;
				bistack.pop();
				printf("%d  ", p->tdata->data);
				p = NULL; // 记住置为空，写错过！！！ 
			}
			else {
				// 1.1右子树不空，往右子树走 
				p = p->rchild;
			}
		}
	}
	printf("\n");
}
int main() {
	// 手动构造二叉树 
	BiTree root = NULL;
	InsertRootNode(root, 1);
	BiTree cur = root;// cur = 1
	InsertTreeLeftNode(cur, 2);
	InsertTreeRightNode(cur, 3);

	cur = root->lchild;// cur = 2
	InsertTreeLeftNode(cur, 4);
	InsertTreeRightNode(cur, 5);

	cur = root->rchild;// cur = 3
	InsertTreeLeftNode(cur, 6);
	InsertTreeRightNode(cur, 7);

	cur = root->lchild->lchild;// cur = 4
	InsertTreeLeftNode(cur, 8);
	InsertTreeRightNode(cur, 9);

	cur = root->lchild->rchild;// cur = 5
	InsertTreeLeftNode(cur, 10);
	InsertTreeRightNode(cur, 11);

	cur = root->rchild->lchild;// cur = 6
	InsertTreeLeftNode(cur, 12);
	InsertTreeRightNode(cur, 13);

	cur = root->rchild->rchild;// cur = 7
	InsertTreeLeftNode(cur, 14);
	InsertTreeRightNode(cur, 15);

	printf("测试结点的深度:\n");
	int hight = GetDepth(root->lchild->rchild);
	printf("结点%d的深度是%d\n", root->lchild->rchild->tdata->data, hight);

	hight = GetDepth(root->rchild->rchild);
	printf("结点%d的深度是%d\n", root->rchild->rchild->tdata->data, hight);

	hight = GetDepth(root->rchild->rchild->rchild);
	printf("结点%d的深度是%d\n", root->rchild->rchild->rchild->tdata->data, hight);

	printf("前序遍历:\n");
	PreOrder(root);
	printf("\n中序遍历:\n");
	InOrder(root);
	printf("\n后序遍历:\n");
	PostOrder(root);
	printf("\n层次遍历:\n");
	CenCi(root);

	// 删除节点
	printf("\n删除结点%d后递推遍历二叉树：\n", root->lchild->tdata->data);
	DeleteTreeNode(root->lchild);
	printf("递推前序遍历:\n");
	PreOrderDiTui(root);
	printf("递推中序遍历:\n");
	InOrderDiTui(root);
	printf("递推后序遍历:\n");
	PostOrderDiTui(root);
	printf("层次遍历:\n");
	CenCi(root);
}
