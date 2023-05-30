#include <stdio.h> 
#include <stdlib.h>
#include <cmath> // Ϊ��ʵ��log���㣬����cmath��
#include <queue> // �������У�ʵ�ֲ�α���
#include <stack> // ����ջ��ʵ�ֵ��Ʊ���
using namespace std;
typedef struct TNodeData {
	int data; // ֵ 
	int index;// λ�򣬿��Եó���� 
}TNodeData;

typedef struct BiTNode {
	TNodeData* tdata; 		// ������ 
	struct BiTNode* lchild, * rchild;// ���Һ���ָ�� 
	struct BiTNode* parent;// ���׽�� 
}BiTNode, * BiTree;

// �������� 
bool InsertRootNode(BiTree& btree, int e) {
	btree = (BiTree)malloc(sizeof(BiTNode));
	TNodeData* td = (TNodeData*)malloc(sizeof(TNodeData));
	td->data = e;
	td->index = 1;// ������λ��Ϊ1 

	btree->tdata = td;
	btree->lchild = NULL;
	btree->rchild = NULL;
	btree->parent = NULL;
	return true;
}

// 1.��ǰp�������� 
BiTNode* GetLeftC(BiTree& p) {
	if (p == NULL || p->lchild == NULL) {
		return NULL;
	}
	return p->lchild;
}
// 2.��ǰ�����Һ���  
BiTNode* GetRightC(BiTree& p) {
	if (p == NULL || p->rchild == NULL) {
		return NULL;
	}
	return p->rchild;
}
// 3.��ǰp���ĸ���  
BiTNode* GetParent(BiTree& p) {
	if (p == NULL || p->parent == NULL) {
		return NULL;
	}
	return p->parent;
}
// 4.��ȡ��ǰp�������
int GetDepth(BiTree& p) {
	if (p == NULL) {
		return 0;
	}
	return (log(p->tdata->index) / log(2) + 1);
}
// ��ǰc������һ������
bool InsertTreeLeftNode(BiTree& c, int e) {
	BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
	TNodeData* td = (TNodeData*)malloc(sizeof(TNodeData));
	td->data = e;
	td->index = c->tdata->index * 2;// ����c���ó�λ��

	p->tdata = td;
	p->lchild = NULL;
	p->rchild = NULL;
	p->parent = c;

	c->lchild = p;
	return true;
}
// ��ǰc������һ���ҽ��
bool InsertTreeRightNode(BiTree& c, int e) {
	BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
	TNodeData* td = (TNodeData*)malloc(sizeof(TNodeData));
	td->data = e;
	td->index = c->tdata->index * 2 + 1;// ����c���ó�λ��

	p->tdata = td;
	p->lchild = NULL;
	p->rchild = NULL;
	p->parent = c;

	c->rchild = p;
	return true;
}
// ɾ��c�ڵ� : Ҫɾ��c�������ҽ�㣬�����ͷſռ�
bool DeleteTreeNode(BiTree& c) {
	BiTNode* curp = c;
	BiTNode* p;
	while (curp != NULL) {// ɨ������
		p = curp->lchild;
		if (p != NULL) {
			curp = p->lchild;// ��ǰ��㱻ɾ��֮ǰ��ȡ��ǰ�������㣬�Ա��´�ѭ��
		}
		else {
			curp = NULL;
		}
		free(p);
	}
	curp = c;// ��ǰ�ڵ㿪ʼɨ���ҽڵ� 
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
	// ע��˽��ĸ��ڵ�����ҽ���ÿա� 
	if (c->parent->lchild == c) {
		c->parent->lchild = NULL;
	}
	else {
		c->parent->rchild = NULL;
	}
	free(c);// �ͷ��Լ� 
	return true;
}
// �ж϶������Ƿ�Ϊ��
bool Empty(BiTree& root) {
	if (root == NULL) {
		return true;
	}
	return false;
}
// ��С���ص�------------------------------------------------
// ǰ����� 
void PreOrder(BiTree p) {// ������������ 
	if (p != NULL) {
		printf("%d  ", p->tdata->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}
// ������� 
void InOrder(BiTree p) {// ������������ 
	if (p != NULL) {
		InOrder(p->lchild);
		printf("%d  ", p->tdata->data);
		InOrder(p->rchild);
	}
}
// ������� 
void PostOrder(BiTree p) {// ������������ 
	if (p != NULL) {
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%d  ", p->tdata->data);
	}
}
// ��α��� 
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
// �ѵ�------------------------------------------------
// ���Ʊ���
void PreOrderDiTui(BiTree& root) {// ǰ��
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
void InOrderDiTui(BiTree& root) {// ���� 
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
void PostOrderDiTui(BiTree& root) {// ���� 
	stack<BiTNode*> bistack;
	BiTNode* p = root;
	BiTNode* lastp = NULL;// ��һ�����ʵĽ�� ,�ؼ��㣡�������ж��Ƿ����������� 
	while (p != NULL || !bistack.empty()) {
		// ������������ջ 
		if (p != NULL) {
			bistack.push(p);
			p = p->lchild;
		}
		else {
			// û·�ߣ�������ջ��Ҫ����������������֮һ
			// 1.������Ϊ�ճ�ջ
			// 2.�����������귵��Ҳ���Գ�ջ
			p = bistack.top();
			if (p->rchild == NULL || p->rchild == lastp) {
				lastp = p;
				bistack.pop();
				printf("%d  ", p->tdata->data);
				p = NULL; // ��ס��Ϊ�գ�д��������� 
			}
			else {
				// 1.1���������գ����������� 
				p = p->rchild;
			}
		}
	}
	printf("\n");
}
int main() {
	// �ֶ���������� 
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

	printf("���Խ������:\n");
	int hight = GetDepth(root->lchild->rchild);
	printf("���%d�������%d\n", root->lchild->rchild->tdata->data, hight);

	hight = GetDepth(root->rchild->rchild);
	printf("���%d�������%d\n", root->rchild->rchild->tdata->data, hight);

	hight = GetDepth(root->rchild->rchild->rchild);
	printf("���%d�������%d\n", root->rchild->rchild->rchild->tdata->data, hight);

	printf("ǰ�����:\n");
	PreOrder(root);
	printf("\n�������:\n");
	InOrder(root);
	printf("\n�������:\n");
	PostOrder(root);
	printf("\n��α���:\n");
	CenCi(root);

	// ɾ���ڵ�
	printf("\nɾ�����%d����Ʊ�����������\n", root->lchild->tdata->data);
	DeleteTreeNode(root->lchild);
	printf("����ǰ�����:\n");
	PreOrderDiTui(root);
	printf("�����������:\n");
	InOrderDiTui(root);
	printf("���ƺ������:\n");
	PostOrderDiTui(root);
	printf("��α���:\n");
	CenCi(root);
}
