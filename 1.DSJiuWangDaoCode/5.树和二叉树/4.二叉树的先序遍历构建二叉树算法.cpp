#include <stdio.h> 
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack> 
using namespace std;
typedef struct TNodeData{
	char data;// ֵ 
	int index;// �����±� ���ó����Ҫ�� 
}TNodeData;

typedef struct BiTNode{
	TNodeData *tdata; 		// ������ 
	struct BiTNode *lchild, *rchild;// ���Һ���ָ�� 
	struct BiTNode *parent;// ���׽�� 
}BiTNode, *BiTree;

// 0.�������� 
bool InsertRootNode(BiTree &btree, char e){
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
bool InsertTreeLeftNode(BiTree &c, char e){
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
		printf("%c\t", p->tdata->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
} 
// ������� 
void InOrder(BiTree p){// ������������ 
	if(p != NULL){
		InOrder(p->lchild);
		printf("%c\t", p->tdata->data);
		InOrder(p->rchild);
	}
} 
// ������� 
void PostOrder(BiTree p){// ������������ 
	if(p != NULL){
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%c\t", p->tdata->data);
	}
}
// ��α��� 
void CenCi(BiTree &root){// 
	queue<BiTNode*> que;
	que.push(root);
	BiTNode *p;
	while(!que.empty()){
		p = que.front();
		que.pop();
		printf("%c\t", p->tdata->data);
		if(p->lchild != NULL){
			que.push(p->lchild);	
		}
		if(p->rchild != NULL){
			que.push(p->rchild);	
		}
	}
	printf("\n");
}
// ���Ʊ���
// ǰ�� 
void PreOrderDiTui(BiTree &root){
	stack<BiTNode*> bistack;
	BiTNode *p = root;
	while(p != NULL || !bistack.empty()){
		if(p != NULL){
			printf("%c\t", p->tdata->data);
			bistack.push(p);
			p = p->lchild;
		}else{
			p = bistack.top();
			bistack.pop();
			p = p->rchild;
		}
	}
	printf("\n");
}
// ���� 
void InOrderDiTui(BiTree &root){
	stack<BiTNode*> bistack;
	BiTNode *p = root;
	while(p != NULL || !bistack.empty()){
		if(p != NULL){
			bistack.push(p);
			p = p->lchild;
		}else{
			p = bistack.top();
			bistack.pop();
			printf("%c\t", p->tdata->data);
			p = p->rchild;
		}
	}
	printf("\n");
}
// ���� 
void PostOrderDiTui(BiTree &root){
	stack<BiTNode*> bistack;
	BiTNode *p = root;
	BiTNode *lastp = NULL;// ��һ�����ʵĽ�� ,�ؼ��㣬�����ж��Ƿ����������� 
	while(p != NULL || !bistack.empty()){
		// ������������ջ 
		if(p != NULL){
			bistack.push(p);
			p = p->lchild;
		}else{
			// û·�ߣ���Ҫ��ջ
			// 1.������Ϊ�ճ�ջ
			// 2.�����������귵��Ҳ���Գ�ջ
			p = bistack.top();
			if(p->rchild == NULL || p->rchild == lastp){
				lastp = p; 
				bistack.pop();
				printf("%c\t", p->tdata->data);
				p = NULL; // ��ס��Ϊ�գ�д��������� 
			}else{
				// 1.1���������գ����������� 
				p = p->rchild;
			}
		}
	}
	printf("\n");
}

char ch;
// ���򹹽�
void CreateBiTree(BiTree &T){
	cin>>ch;
	if(ch == '#'){
		T = NULL;
	}else{
//		T = (BiTree)malloc(sizeof(BiTNode));// ���ɽڵ㣬��ָ��
//		TNodeData *td = (TNodeData*)malloc(sizeof(TNodeData));
		T = new BiTNode; 
		TNodeData *td = new TNodeData;
		td->data = ch;
		T->tdata = td;
		
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	
}
// ͳ�����
int Depth(BiTree &T) {
	if(T == NULL){
		return 0;
	}
	int n = Depth(T->lchild);
	int m = Depth(T->rchild);
	return n > m ? n + 1 : m + 1;
}
int main(){
//	BiTree root = NULL;
//	CreateBiTree(root);
	
	BiTree root = NULL;
	InsertRootNode(root, 'A');
	// root��ַ���� 
	BiTree cur = root; 
	InsertTreeLeftNode(cur, 'B');
	
	cur = root->lchild; 
	InsertTreeLeftNode(cur, 'C');
	InsertTreeRightNode(cur, 'D');
	
	cur = root->lchild->rchild;
	InsertTreeLeftNode(cur, 'E');
	InsertTreeRightNode(cur, 'F');
	
	cur = root->lchild->rchild->lchild;
	InsertTreeRightNode(cur, 'G');
	
	CenCi(root);
	
	// ǰ�����
	PreOrder(root);
	PreOrderDiTui(root);
	
	// ������� 
	InOrder(root);
	printf("\n"); 
	
	InOrderDiTui(root);
	printf("\n"); 
	
	// ����
	PostOrder(root);
	PostOrderDiTui(root) ;
	printf("\n");
	
	// ͳ�����
	printf("%d\t", Depth(root)); 
}
