#include <stdio.h> 
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

typedef struct BiTNode{
	int data; 		// 数据域 
	struct BiTNode *lchild, *rchild;// 左右孩子指针 
	struct BiTNode *parent;// 父亲结点 
}BiTNode, *BiTree;

bool InsertRootNode(BiTree &btree, int e);
BiTNode* GetLeftC(BiTree &p);
BiTNode* GetRightC(BiTree &p);
BiTNode* GetParent(BiTree &p);
bool InsertTreeLeftNode(BiTree &c, int e);
bool InsertTreeRightNode(BiTree &c, int e);
bool DeleteTreeNode(BiTree &c);
bool Empty(BiTree &root);
void PreOrder(BiTree root);
void InOrder(BiTree p);
void PostOrder(BiTree p);
void PreOrderDiTui(BiTree &root);
void InOrderDiTui(BiTree &root);
void PostOrderDiTui(BiTree &root);
void CenciOrder(BiTree &root);

/*
统计树中结点为2的个数
思路
1.先序遍历
2.如果有右孩子和左孩子就返回 1
3.
*/
int twocount = 0;
void CountDegreeTwo(BiTree p){// p是当前的结点 
	// 1.如果为空直接返回
	if(p == NULL){
		return;
	} 
	// 2.进行先序
	if(p->lchild != NULL && p->rchild != NULL){
		twocount++;
	} 
	CountDegreeTwo(p->lchild);
	CountDegreeTwo(p->rchild);
} 

/*
统计树中结点为2的个数
思路
1.后序遍历
2.如果有右孩子和左孩子就返回1
3.
*/
int CountDegreeTwoOfPost(BiTree p){// p是当前的结点 
	// 1.如果为空直接返回
	if(p == NULL){
		return 0;
	} 
	// 2.进行后序
	int l = CountDegreeTwoOfPost(p->lchild);
	int r = CountDegreeTwoOfPost(p->rchild);
	if(p->lchild != NULL && p->rchild != NULL){
		return 1 + l + r;
	}
	return l + r;
} 

int main(){
	BiTree root = NULL;
	InsertRootNode(root, 1);
	// root地址不变 
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
	
	cur = root->rchild->rchild->lchild;
	InsertTreeLeftNode(cur, 16);
	InsertTreeRightNode(cur, 17);
	
	
	CountDegreeTwo(root);
	cout<< "树中结点为2的个数："<< twocount << "" << endl;
	
	int cous = CountDegreeTwoOfPost(root);
	cout<< "树中结点为2的个数："<< cous << "" << endl;
	
	PreOrder(root);
	cout<<endl;
	PreOrderDiTui(root);
	
	InOrder(root);
	printf("\n"); 
	InOrderDiTui(root);
	
	PostOrder(root);
	cout<<endl;
	PostOrderDiTui(root);
	
	CenciOrder(root);
}
// 递推遍历算法
// 前序 
void PreOrderDiTui(BiTree &root){
	stack<BiTNode*> sta;
	BiTNode *p = root;
	while(p != NULL || !sta.empty()){
		while(p != NULL){
			// 这里写错过，先访问，在入栈，在到左子树！！对应递归的时候！ 
			cout << p->data << " ";
			sta.push(p);
			p = p->lchild;
		}
		// p为空了，弹出栈
		p = sta.top();
		sta.pop();
		p = p->rchild; 
	}
	cout<<endl;
} 
// 中序
void InOrderDiTui(BiTree &root){
	stack<BiTNode*> sta;
	BiTNode *p = root;
	while(p != NULL || !sta.empty()){
		while(p != NULL){
			sta.push(p);
			p = p->lchild;
		}
		// 进入右子树访问的时候就访问 
		p = sta.top();
		sta.pop();
		cout << p->data << " ";
		p = p->rchild;
	}
	cout<<endl;
}
// 后序
void PostOrderDiTui(BiTree &root){
	stack<BiTNode*> sta;
	BiTNode *p = root;
	BiTNode *q = p;
	while(p != NULL || !sta.empty()){
		while(p != NULL){
			sta.push(p);
			p = p->lchild;
		} 
		// 获取栈顶 
		p = sta.top();
		// 分两种情况
		// 1.上一个出栈结点是自己的右孩子或者右孩子为空，就输出自己 
		if(p->rchild == NULL || p->rchild == q){
			cout << p->data << " ";// 输出 
			q = p;// 记录上一个出栈的结点 
			sta.pop();// 真正的出栈
			p = NULL;// 记为空 , 很重要，不然会一直循环 
		}
		// 2.上一个出栈结点是自己的左孩子，就转为右孩子 
		else{
			p = p->rchild;
		}
	}
	cout<<endl; 
} 

void CenciOrder(BiTree &root){
	queue<BiTNode*> que;
	BiTNode *p = root;
	que.push(p);
	while(!que.empty()){
		p = que.front();
		cout << p->data << " ";// 输出 
		que.pop();
		if(p->lchild != NULL){
			que.push(p->lchild);
		}
		if(p->rchild != NULL){
			que.push(p->rchild);
		}
	}
	cout<<endl;
}
// 0.插入根结点 
bool InsertRootNode(BiTree &btree, int e){
	btree = (BiTree)malloc(sizeof(BiTNode));
	btree->data = e;
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
// 当前结点插入一个左结点
bool InsertTreeLeftNode(BiTree &c, int e){
	BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = e;
	p->lchild = NULL;
	p->rchild = NULL;
	p->parent = c;
	
	c->lchild = p;
	return true;
} 
// 当前结点插入一个右结点
bool InsertTreeRightNode(BiTree &c, int e){
	BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = e;
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
		printf("%d\t", p->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
} 
// 中序遍历 
void InOrder(BiTree p){// 不能引用类型 
	if(p != NULL){
		InOrder(p->lchild);
		printf("%d\t", p->data);
		InOrder(p->rchild);
	}
} 
// 后序遍历 
void PostOrder(BiTree p){// 不能引用类型 
	if(p != NULL){
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%d\t", p->data);
	}
}
