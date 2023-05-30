#include <stdio.h> 
#include <stdlib.h>
#include <cmath>

typedef struct TNodeData{
	int data;// 值 
	int index;// 索引下标 ，得出深度要用 
}TNodeData;

typedef struct BiTNode{
	TNodeData *tdata; 		// 数据域 
	struct BiTNode *lchild, *rchild;// 左右孩子指针 
	struct BiTNode *parent;// 父亲结点 
}BiTNode, *BiTree;

// 0.插入根结点 
bool InsertRootNode(BiTree &btree, int e){
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
bool InsertTreeLeftNode(BiTree &c, int e){
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
		printf("%d\t", p->tdata->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
} 
// 中序遍历 
void InOrder(BiTree p){// 不能引用类型 
	if(p != NULL){
		InOrder(p->lchild);
		printf("%d\t", p->tdata->data);
		InOrder(p->rchild);
	}
} 
// 后序遍历 
void PostOrder(BiTree p){// 不能引用类型 
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
	InsertTreeRightNode(cur, 15);
	
	// 中序遍历 
	InOrder(root);
	printf("\n"); 
	
	// 测试获取左右结点 父结点方法
	cur = GetLeftC(root->lchild->lchild);
	if(cur != NULL){
		printf("结点%d的左结点是%d\n", root->lchild->lchild->tdata->data, cur->tdata->data);
	}
	cur = GetRightC(root->rchild->rchild);
	if(cur != NULL){
		printf("结点%d的右结点是%d\n", root->rchild->rchild->tdata->data, cur->tdata->data);
	}
	cur = GetParent(root->lchild->rchild);
	if(cur != NULL){
		printf("结点%d的父亲结点是%d\n", root->lchild->rchild->tdata->data, cur->tdata->data);
	}
	
	// 测试高度
	int hight = GetDepth(root->lchild->rchild);
	printf("结点%d的深度是%d\n", root->lchild->rchild->tdata->data, hight); 
	
	hight = GetDepth(root->rchild->rchild);
	printf("结点%d的深度是%d\n", root->rchild->rchild->tdata->data, hight); 
	
	hight = GetDepth(root->rchild->rchild->rchild);
	printf("结点%d的深度是%d\n", root->rchild->rchild->rchild->tdata->data, hight); 
	
	// 删除节点
	DeleteTreeNode(root->lchild->lchild);
	InOrder(root);
	printf("\n"); 
	
	DeleteTreeNode(root->rchild->rchild);
	InOrder(root);
	printf("\n"); 

}
