#include <stdio.h> 
#include <stdlib.h>
#include <cmath>

typedef struct BiTNode {
	int data; 		// ������ 
	struct BiTNode* lchild, * rchild;// ���Һ���ָ�� 
	struct BiTNode* parent;// ���׽�� 
}BiTNode, * BiTree;
// �������� 
bool InsertRootNode(BiTree& btree, int e) {
	btree = (BiTree)malloc(sizeof(BiTNode));
	btree->data = e;
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
// 2.��ǰp�����Һ���  
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
// ��ǰ���c����һ������
bool InsertTreeLeftNode(BiTree& c, int e) {
	BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = e;
	p->lchild = NULL;
	p->rchild = NULL;
	p->parent = c;

	c->lchild = p;
	return true;
}
// ��ǰc������һ���ҽ��
bool InsertTreeRightNode(BiTree& c, int e) {
	BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = e;
	p->lchild = NULL;
	p->rchild = NULL;
	p->parent = c;

	c->rchild = p;
	return true;
}
// ɾ��c�ڵ� : Ҫɾ��c�������ҽ�㣬�����ͷſռ�-�����ǵ��ƣ�û�õݹ�
bool DeleteTreeNode(BiTree& c) {
	BiTNode* curp = c;
	BiTNode* p;
	while (curp != NULL) { // ɨ������
		p = curp->lchild;
		if (p != NULL) {
			curp = p->lchild;// ��ǰ��㱻ɾ��֮ǰ��ȡ��ǰ�������㣬�Ա��´�ѭ��
		}
		else {
			curp = NULL;
		}
		// ע��˽��ĸ��ڵ��������ҽ���ÿա� 
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
		// ע��˽��ĸ��ڵ��������ҽ���ÿա� 
		free(p);
	}
	// ע��˽��ĸ��ڵ��������ҽ���ÿա� 
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
// ����������������� 
void InOrder(BiTree p) {// ������������ 
	if (p != NULL) {
		InOrder(p->lchild);
		printf("%d  ", p->data);
		InOrder(p->rchild);
	}
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

	// ���Ի�ȡ���ҽ�� ����㷽��
	cur = GetLeftC(root->lchild->lchild);
	if (cur != NULL) {
		printf("���%d��������%d\n", root->lchild->lchild->data, cur->data);
	}
	cur = GetRightC(root->rchild->rchild);
	if (cur != NULL) {
		printf("���%d���ҽ����%d\n", root->rchild->rchild->data, cur->data);
	}
	cur = GetParent(root->lchild->rchild);
	if (cur != NULL) {
		printf("���%d�ĸ��׽����%d\n", root->lchild->rchild->data, cur->data);
	}
	printf("���������\n", root->lchild->data);
	InOrder(root);
	// ɾ���ڵ�
	printf("\nɾ�����%d�����������\n", root->lchild->data);
	DeleteTreeNode(root->lchild);
	InOrder(root);
	printf("\n");
}
