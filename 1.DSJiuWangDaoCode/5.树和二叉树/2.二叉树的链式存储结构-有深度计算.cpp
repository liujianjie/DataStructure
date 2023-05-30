#include <stdio.h> 
#include <stdlib.h>
#include <cmath>

typedef struct TNodeData{
	int data;// ֵ 
	int index;// �����±� ���ó����Ҫ�� 
}TNodeData;

typedef struct BiTNode{
	TNodeData *tdata; 		// ������ 
	struct BiTNode *lchild, *rchild;// ���Һ���ָ�� 
	struct BiTNode *parent;// ���׽�� 
}BiTNode, *BiTree;

// 0.�������� 
bool InsertRootNode(BiTree &btree, int e){
	btree = (BiTree)malloc(sizeof(BiTNode));
	TNodeData *td = (TNodeData*)malloc(sizeof(TNodeData));
	td->data = e;
	td->index = 1;// ����������Ϊ1 
	
	btree->tdata = td;
	btree->lchild = NULL;
	btree->rchild = NULL;
	btree->parent = NULL; 
	return true;
}

// 1.��ǰ�������� 
BiTNode* GetLeftC(BiTree &p){
	if(p == NULL || p->lchild == NULL){
		return NULL;
	}
	return p->lchild;
} 
// 2.��ǰ�����Һ���  
BiTNode* GetRightC(BiTree &p){
	if(p == NULL || p->rchild == NULL){
		return NULL;
	}
	return p->rchild;
} 
// 3.��ǰ���ĸ���  
BiTNode* GetParent(BiTree &p){
	if(p == NULL || p->parent == NULL){
		return NULL;
	}
	return p->parent;
} 
// 4.��ȡ��ǰ�������
int GetDepth(BiTree &p){
	if(p == NULL){
		return 0;
	}
	return (log(p->tdata->index) / log(2) + 1) ;
} 
// ��ǰ������һ������
bool InsertTreeLeftNode(BiTree &c, int e){
	BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
	TNodeData *td = (TNodeData*)malloc(sizeof(TNodeData));
	td->data = e;
	td->index = c->tdata->index * 2;// ����c���ó����� 
	
	p->tdata = td;
	p->lchild = NULL;
	p->rchild = NULL;
	p->parent = c;
	
	c->lchild = p;
	return true;
} 
// ��ǰ������һ���ҽ��
bool InsertTreeRightNode(BiTree &c, int e){
	BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
	TNodeData *td = (TNodeData*)malloc(sizeof(TNodeData));
	td->data = e;
	td->index = c->tdata->index * 2 + 1;// ����c���ó����� 
	
	p->tdata = td;
	p->lchild = NULL;
	p->rchild = NULL;
	p->parent = c;
	
	c->rchild = p;
	return true;
} 

// ɾ��c�ڵ� 
bool DeleteTreeNode(BiTree &c){
	// �ͷſռ�,�������ҽ��
	BiTNode *curp = c;
	BiTNode *p;
	while(curp != NULL){// �ͷ���ڵ�ռ� 
		p = curp->lchild;
		if(p != NULL){
			curp = p->lchild;
		}else{
			curp = NULL;
		}
		free(p);
	} 
	curp = c;// ��ǰ�ڵ㿪ʼɨ���ҽڵ� 
	while(curp != NULL){
		p = curp->rchild;
		if(p != NULL){
			curp = p->rchild;
		}else{
			curp = NULL;
		}
		free(p);
	}  
	// ע��˽��ĸ��ڵ�����ҽ���ÿա� 
	if(c->parent->lchild == c){
		c->parent->lchild = NULL; 		
	}else{
		c->parent->rchild = NULL; 
	}
	free(c);// �ͷ��Լ� 
	return true;
} 
// �ж�Ϊ��
bool Empty(BiTree &root){
	if(root->lchild == root->rchild){
		return true;
	}
	return false;
} 
// ǰ����� 
void PreOrder(BiTree p){// ������������ 
	if(p != NULL){
		printf("%d\t", p->tdata->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
} 
// ������� 
void InOrder(BiTree p){// ������������ 
	if(p != NULL){
		InOrder(p->lchild);
		printf("%d\t", p->tdata->data);
		InOrder(p->rchild);
	}
} 
// ������� 
void PostOrder(BiTree p){// ������������ 
	if(p != NULL){
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%d\t", p->tdata->data);
	}
}
// 
void PrintAll(BiTree &root){// 
	
}

int main(){
	BiTree root = NULL;
	InsertRootNode(root, 1);
	// root��ַ���� 
	BiTree cur = root; 
	InsertTreeLeftNode(cur, 2);
	InsertTreeRightNode(cur, 3);
	
	cur = root->lchild; 
	InsertTreeLeftNode(cur, 4);
	InsertTreeRightNode(cur, 5);
	
	cur = root->rchild;
	InsertTreeLeftNode(cur, 6);
	InsertTreeRightNode(cur, 7);
	
	cur = root->lchild->lchild; 
	InsertTreeLeftNode(cur, 8);
	InsertTreeRightNode(cur, 9);
	
	cur = root->lchild->rchild;
	InsertTreeLeftNode(cur, 10);
	InsertTreeRightNode(cur, 11);
	
	cur = root->rchild->lchild; 
	InsertTreeLeftNode(cur, 12);
	InsertTreeRightNode(cur, 13);
	
	cur = root->rchild->rchild;
	InsertTreeLeftNode(cur, 14);
	InsertTreeRightNode(cur, 15);
	
	// ������� 
	InOrder(root);
	printf("\n"); 
	
	// ���Ի�ȡ���ҽ�� ����㷽��
	cur = GetLeftC(root->lchild->lchild);
	if(cur != NULL){
		printf("���%d��������%d\n", root->lchild->lchild->tdata->data, cur->tdata->data);
	}
	cur = GetRightC(root->rchild->rchild);
	if(cur != NULL){
		printf("���%d���ҽ����%d\n", root->rchild->rchild->tdata->data, cur->tdata->data);
	}
	cur = GetParent(root->lchild->rchild);
	if(cur != NULL){
		printf("���%d�ĸ��׽����%d\n", root->lchild->rchild->tdata->data, cur->tdata->data);
	}
	
	// ���Ը߶�
	int hight = GetDepth(root->lchild->rchild);
	printf("���%d�������%d\n", root->lchild->rchild->tdata->data, hight); 
	
	hight = GetDepth(root->rchild->rchild);
	printf("���%d�������%d\n", root->rchild->rchild->tdata->data, hight); 
	
	hight = GetDepth(root->rchild->rchild->rchild);
	printf("���%d�������%d\n", root->rchild->rchild->rchild->tdata->data, hight); 
	
	// ɾ���ڵ�
	DeleteTreeNode(root->lchild->lchild);
	InOrder(root);
	printf("\n"); 
	
	DeleteTreeNode(root->rchild->rchild);
	InOrder(root);
	printf("\n"); 

}
