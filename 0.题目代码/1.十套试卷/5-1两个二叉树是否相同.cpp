#include <stdio.h> 
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

typedef struct BiTNode{
	int data; 		// ������ 
	struct BiTNode *lchild, *rchild;// ���Һ���ָ�� 
	struct BiTNode *parent;// ���׽�� 
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
�ж��Ƿ���ͬ��ֱ��x���򣬲������������������� 
ǧ�����򣬺���������ͳ�ƺ�ֵ�ġ�
�����������ȣ�ֱ�ӷ��أ���������ݹ� 
 
*/
int count1 = 0;
int count2 = 0;
bool IsSame(BiTree p1, BiTree p2){// p�ǵ�ǰ�ڵ㣬e�ǲ���ֵ 
	count1++;
	if(p1 == NULL && p2 == NULL){
		return true;
	}
	if(p1 == NULL && p2 != NULL){
		return false;
	}
	if(p1 != NULL && p2 == NULL){
		return false;
	}
	if(p1->data != p2->data){
		return false;
	} 
	bool b1 = IsSame(p1->lchild, p2->lchild);
	bool b2 = IsSame(p1->rchild, p2->rchild);
//	if(p1->data != p2->data){
//		return false;
//	} 
	return b1 && b2;
} 

bool allargument = true;
void IsSame2(BiTree p1, BiTree p2){// p�ǵ�ǰ�ڵ㣬e�ǲ���ֵ 
	count2++;
	if(!allargument){
		return;
	}
	if(p1 == NULL && p2 == NULL){
		return;
	}
	if(p1 == NULL && p2 != NULL){
		allargument = false;
	}
	if(p1 != NULL && p2 == NULL){
		allargument = false;
	}
	if(p1->data != p2->data){
		allargument = false;
	} 
	IsSame2(p1->lchild, p2->lchild);
	IsSame2(p1->rchild, p2->rchild);
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
	
	InOrder(root);
	cout<<endl;
	
	BiTree root2 = NULL;
	InsertRootNode(root2, 1);
	// root��ַ���� 
	cur = root2; 
	InsertTreeLeftNode(cur, 2);
	InsertTreeRightNode(cur, 3);
	
	cur = root2->lchild; 
	InsertTreeLeftNode(cur, 4);
	InsertTreeRightNode(cur, 50);
	
	cur = root2->rchild;
	InsertTreeLeftNode(cur, 6);
	InsertTreeRightNode(cur, 7);
	
	InOrder(root2);
	
	cout<<endl;
	bool b = IsSame(root, root2);
	cout<<"�Ƿ����:"<<boolalpha <<b<<endl;
	cout<<count1<<endl;
	
	IsSame2(root, root2);	
	cout<<"�Ƿ����:"<<boolalpha <<allargument<<endl;
	cout<<count2<<endl;

}
// ���Ʊ����㷨
// ǰ�� 
void PreOrderDiTui(BiTree &root){
	stack<BiTNode*> sta;
	BiTNode *p = root;
	while(p != NULL || !sta.empty()){
		while(p != NULL){
			// ����д������ȷ��ʣ�����ջ���ڵ�������������Ӧ�ݹ��ʱ�� 
			cout << p->data << " ";
			sta.push(p);
			p = p->lchild;
		}
		// pΪ���ˣ�����ջ
		p = sta.top();
		sta.pop();
		p = p->rchild; 
	}
	cout<<endl;
} 
// ����
void InOrderDiTui(BiTree &root){
	stack<BiTNode*> sta;
	BiTNode *p = root;
	while(p != NULL || !sta.empty()){
		while(p != NULL){
			sta.push(p);
			p = p->lchild;
		}
		// �������������ʵ�ʱ��ͷ��� 
		p = sta.top();
		sta.pop();
		cout << p->data << " ";
		p = p->rchild;
	}
	cout<<endl;
}
// ����
void PostOrderDiTui(BiTree &root){
	stack<BiTNode*> sta;
	BiTNode *p = root;
	BiTNode *q = p;
	while(p != NULL || !sta.empty()){
		while(p != NULL){
			sta.push(p);
			p = p->lchild;
		} 
		// ��ȡջ�� 
		p = sta.top();
		// ���������
		// 1.��һ����ջ������Լ����Һ��ӻ����Һ���Ϊ�գ�������Լ� 
		if(p->rchild == NULL || p->rchild == q){
			cout << p->data << " ";// ��� 
			q = p;// ��¼��һ����ջ�Ľ�� 
			sta.pop();// �����ĳ�ջ
			p = NULL;// ��Ϊ�� , ����Ҫ����Ȼ��һֱѭ�� 
		}
		// 2.��һ����ջ������Լ������ӣ���תΪ�Һ��� 
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
		cout << p->data << " ";// ��� 
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
// 0.�������� 
bool InsertRootNode(BiTree &btree, int e){
	btree = (BiTree)malloc(sizeof(BiTNode));
	btree->data = e;
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
// ��ǰ������һ������
bool InsertTreeLeftNode(BiTree &c, int e){
	BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = e;
	p->lchild = NULL;
	p->rchild = NULL;
	p->parent = c;
	
	c->lchild = p;
	return true;
} 
// ��ǰ������һ���ҽ��
bool InsertTreeRightNode(BiTree &c, int e){
	BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
	p->data = e;
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
		printf("%d\t", p->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
} 
// ������� 
void InOrder(BiTree p){// ������������ 
	if(p != NULL){
		InOrder(p->lchild);
		printf("%d\t", p->data);
		InOrder(p->rchild);
	}
} 
// ������� 
void PostOrder(BiTree p){// ������������ 
	if(p != NULL){
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%d\t", p->data);
	}
}



