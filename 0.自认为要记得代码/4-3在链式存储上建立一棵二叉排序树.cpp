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

void Init(BiTree &btree);
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
建立排序二叉树，利用引用
用先序 
*/
void BuildTree(BiTree &p, int e){// p是当前节点，e是插入值 
	if(p == NULL){
		// 说明空，得建立一个结点
		p = new BiTNode();
		p->data = e;
		p->lchild = p->rchild = NULL;
		return;
	}
	if(e < p->data){
		BuildTree(p->lchild, e);
	}else{
		BuildTree(p->rchild, e);
	}
} 
void BuildTree2(BiTNode *&p, int e){// p是当前节点，e是插入值 
	if(p == NULL){
		// 说明空，得建立一个结点
		p = new BiTNode();
		p->data = e;
		p->lchild = p->rchild = NULL;
		return;
	}
	if(e < p->data){
		BuildTree(p->lchild, e);
	}else{
		BuildTree(p->rchild, e);
	}
} 

int main(){
	int n = 6;
	int val[] = {12, 5, 7, 23, 17, 38};
	BiTree root = NULL;
	for(int i = 0; i < n; i++){
		BuildTree2(root, val[i]);
	}
	InOrder(root);

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
void Init(BiTree &btree){
	btree = (BiTree)malloc(sizeof(BiTNode));
	btree->lchild = NULL;
	btree->rchild = NULL;
	btree->parent = NULL; 
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


