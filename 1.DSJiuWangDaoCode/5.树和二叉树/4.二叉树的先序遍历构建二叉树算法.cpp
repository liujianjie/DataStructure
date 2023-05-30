#include <stdio.h> 
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack> 
using namespace std;
typedef struct TNodeData{
	char data;// 值 
	int index;// 索引下标 ，得出深度要用 
}TNodeData;

typedef struct BiTNode{
	TNodeData *tdata; 		// 数据域 
	struct BiTNode *lchild, *rchild;// 左右孩子指针 
	struct BiTNode *parent;// 父亲结点 
}BiTNode, *BiTree;

// 0.插入根结点 
bool InsertRootNode(BiTree &btree, char e){
	btree = (BiTree)malloc(sizeof(BiTNode));
	TNodeData *td = (TNodeData*)malloc(sizeof(TNodeData));
	td->data = e;
	td->index = 1;// 根结点的索引为1 
	
	btree->tdata = td;
	btree->lchild = NULL;
	btree->rchild = NULL;
	btree->parent = NULL; 
	return true;
}

// 1.当前结点的左孩子 
BiTNode* GetLeftC(BiTree &p){
	if(p == NULL || p->lchild == NULL){
		return NULL;
	}
	return p->lchild;
} 
// 2.当前结点的右孩子  
BiTNode* GetRightC(BiTree &p){
	if(p == NULL || p->rchild == NULL){
		return NULL;
	}
	return p->rchild;
} 
// 3.当前结点的父亲  
BiTNode* GetParent(BiTree &p){
	if(p == NULL || p->parent == NULL){
		return NULL;
	}
	return p->parent;
} 
// 4.获取当前结点的深度
int GetDepth(BiTree &p){
	if(p == NULL){
		return 0;
	}
	return (log(p->tdata->index) / log(2) + 1) ;
} 
// 当前结点插入一个左结点
bool InsertTreeLeftNode(BiTree &c, char e){
	BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
	TNodeData *td = (TNodeData*)malloc(sizeof(TNodeData));
	td->data = e;
	td->index = c->tdata->index * 2;// 根据c结点得出索引 
	
	p->tdata = td;
	p->lchild = NULL;
	p->rchild = NULL;
	p->parent = c;
	
	c->lchild = p;
	return true;
} 
// 当前结点插入一个右结点
bool InsertTreeRightNode(BiTree &c, int e){
	BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
	TNodeData *td = (TNodeData*)malloc(sizeof(TNodeData));
	td->data = e;
	td->index = c->tdata->index * 2 + 1;// 根据c结点得出索引 
	
	p->tdata = td;
	p->lchild = NULL;
	p->rchild = NULL;
	p->parent = c;
	
	c->rchild = p;
	return true;
} 

// 删除c节点 
bool DeleteTreeNode(BiTree &c){
	// 释放空间,它的左右结点
	BiTNode *curp = c;
	BiTNode *p;
	while(curp != NULL){// 释放左节点空间 
		p = curp->lchild;
		if(p != NULL){
			curp = p->lchild;
		}else{
			curp = NULL;
		}
		free(p);
	} 
	curp = c;// 当前节点开始扫描右节点 
	while(curp != NULL){
		p = curp->rchild;
		if(p != NULL){
			curp = p->rchild;
		}else{
			curp = NULL;
		}
		free(p);
	}  
	// 注意此结点的父节点的左右结点置空。 
	if(c->parent->lchild == c){
		c->parent->lchild = NULL; 		
	}else{
		c->parent->rchild = NULL; 
	}
	free(c);// 释放自己 
	return true;
} 
// 判断为空
bool Empty(BiTree &root){
	if(root->lchild == root->rchild){
		return true;
	}
	return false;
} 
// 前序遍历 
void PreOrder(BiTree p){// 不能引用类型 
	if(p != NULL){
		printf("%c\t", p->tdata->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
} 
// 中序遍历 
void InOrder(BiTree p){// 不能引用类型 
	if(p != NULL){
		InOrder(p->lchild);
		printf("%c\t", p->tdata->data);
		InOrder(p->rchild);
	}
} 
// 后序遍历 
void PostOrder(BiTree p){// 不能引用类型 
	if(p != NULL){
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%c\t", p->tdata->data);
	}
}
// 层次遍历 
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
// 递推遍历
// 前序 
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
// 中序 
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
// 后序 
void PostOrderDiTui(BiTree &root){
	stack<BiTNode*> bistack;
	BiTNode *p = root;
	BiTNode *lastp = NULL;// 上一个访问的结点 ,关键点，用来判断是否右子树返回 
	while(p != NULL || !bistack.empty()){
		// 左子树依次入栈 
		if(p != NULL){
			bistack.push(p);
			p = p->lchild;
		}else{
			// 没路走，需要出栈
			// 1.右子树为空出栈
			// 2.右子树访问完返回也可以出栈
			p = bistack.top();
			if(p->rchild == NULL || p->rchild == lastp){
				lastp = p; 
				bistack.pop();
				printf("%c\t", p->tdata->data);
				p = NULL; // 记住置为空，写错过！！！ 
			}else{
				// 1.1右子树不空，往右子树走 
				p = p->rchild;
			}
		}
	}
	printf("\n");
}

char ch;
// 先序构建
void CreateBiTree(BiTree &T){
	cin>>ch;
	if(ch == '#'){
		T = NULL;
	}else{
//		T = (BiTree)malloc(sizeof(BiTNode));// 生成节点，是指针
//		TNodeData *td = (TNodeData*)malloc(sizeof(TNodeData));
		T = new BiTNode; 
		TNodeData *td = new TNodeData;
		td->data = ch;
		T->tdata = td;
		
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	
}
// 统计深度
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
	// root地址不变 
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
	
	// 前序遍历
	PreOrder(root);
	PreOrderDiTui(root);
	
	// 中序遍历 
	InOrder(root);
	printf("\n"); 
	
	InOrderDiTui(root);
	printf("\n"); 
	
	// 后续
	PostOrder(root);
	PostOrderDiTui(root) ;
	printf("\n");
	
	// 统计深度
	printf("%d\t", Depth(root)); 
}
