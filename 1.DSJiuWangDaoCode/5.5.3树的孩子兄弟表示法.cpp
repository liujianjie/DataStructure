#include <stdio.h> 
#include <stdlib.h>
#include <cmath>
#include <queue>
#define MAX_TREE_SIZE 100

using namespace std;

typedef struct CSNode {
	char data;								 //	数据域 
	struct CSNode* firstchild, * nextsibling, * parent; // 第一个孩子和右兄弟指针	,父亲结点 
}CSNode, * CSNTree;

// 1.插入根结点 
bool InsertRootNode(CSNTree& ctree, char e) {
	ctree = (CSNode*)malloc(sizeof(CSNode));
	ctree->data = e;
	ctree->firstchild = NULL;
	ctree->nextsibling = NULL;
	ctree->parent = NULL;

	return true;
}

// 2.树状情况下，当前ctree结点插入一个孩子结点
bool InsertNode(CSNTree& ctree, char e) {
	CSNode* csn = (CSNode*)malloc(sizeof(CSNode));
	csn->data = e;
	csn->firstchild = NULL;
	csn->nextsibling = NULL;
	csn->parent = ctree;

	// 插入节点这里是重点-------------------------------------------------
	// 有没有孩子，没有就first指向这个孩子结点，否则加到右边兄弟结点指针的最后
	if (ctree->firstchild == NULL) {
		ctree->firstchild = csn;
	}
	else {
		// 如果找到最后的兄弟结点，将新结点放到最后 
		CSNode* cs = ctree->firstchild;
		while (cs->nextsibling != NULL) {// 找到末尾 
			cs = cs->nextsibling;
		}
		cs->nextsibling = csn;
	}
	return true;
}

// 3.查找当前结点的父节点，应该不用。返回指针 
CSNode* GetParent(CSNTree& ctree) {
	if (ctree->parent == NULL) {
		return NULL;
	}
	return ctree->parent;
}

// 4.删除p结点，不好实现。难点 -------------- 
bool DeleteTreeNode(CSNTree& ctree, CSNode* p) {
	// 1.如果删除根节点，置空,懒得free 
	if (p == ctree) {
		ctree = NULL;
	}
	else {
		CSNode* parent = p->parent;
		// 2.删除最左边结点时候，代表只有一个结点。需要将父结点的第一个指针给p的兄弟
		if (parent->firstchild == p) {
			if (p->nextsibling != NULL) {
				parent->firstchild = p->nextsibling;
			}
			else {
				// 没有右兄弟，代表只有p，就将父结点的第一个指针置空
				parent->firstchild = NULL;
			}
		}
		// 3. 删除不是第一个结点的时候。需要将前一个结点的兄弟结点指向p下一个兄弟结点
		else {
			CSNode* q = parent->firstchild;// q是找到要删除的p前一个位置 
			while (q->nextsibling != p) { // 不要写成== 了 
				q = q->nextsibling;
			}
			q->nextsibling = p->nextsibling;// 将p删除 
		}
	}
	free(p);
	return true;
}

// 5.判断为空
bool Empty(CSNTree& ptree) {
	if (ptree == NULL || ptree->firstchild == NULL) {
		return true;
	}
	return false;
}

// 辅助方法 
// 打印一个结点的孩子们 ,通过一个结点 = 实现查找一个结点的孩子 
void PrintOneNodeChildInfo(CSNTree& ctree) {
	printf("它的孩子有：");
	CSNode* csn1 = ctree->firstchild;
	while (csn1 != NULL) {
		printf("%C\t", csn1->data);
		csn1 = csn1->nextsibling;// 转向兄弟结点 
	}
	printf("\n");
}

// 递归 遍历 

// 1.先序遍历, 树形式的先序遍历=二叉树形式的先序遍历 
void ShuPreOrder(CSNTree ctree) { // 树形式的先序遍历 
	if (ctree != NULL) {
		printf("%c\t", ctree->data);
		// 有结点就访问
		CSNode* p = ctree->firstchild;
		if (p != NULL) {
			ShuPreOrder(p);
			p = p->nextsibling;
			while (p != NULL) {
				ShuPreOrder(p);
				p = p->nextsibling;
			}
		}
	}
}
void PreOrder(CSNTree ctree) { // 二叉树的方式遍历 
	if (ctree != NULL) {
		printf("%c\t", ctree->data);
		PreOrder(ctree->firstchild);
		PreOrder(ctree->nextsibling);
	}
}
// 先序遍历打印详细信息
void PreOrderDetail(CSNTree ctree) {
	if (ctree != NULL) {
		printf("这个结点是:%c", ctree->data);
		if (ctree->parent != NULL) {
			printf(",它的父亲是:%c\t", ctree->parent->data);
		}
		PrintOneNodeChildInfo(ctree);//孩子 

		PreOrderDetail(ctree->firstchild);
		PreOrderDetail(ctree->nextsibling);
	}
}
// 2.树的后序遍历等于二叉树的中序遍历 输出
void ShuPostOrder(CSNTree ctree) { // 树形式的后序遍历 
	if (ctree != NULL) {
		// 有结点就访问
		CSNode* p = ctree->firstchild;
		if (p != NULL) {
			ShuPostOrder(p);
			p = p->nextsibling;
			while (p != NULL) {
				ShuPostOrder(p);
				p = p->nextsibling;
			}
		}
		printf("%c\t", ctree->data);
	}
}
void InOrder(CSNTree ctree) {// 二叉树形式的后序遍历 
	if (ctree != NULL) {
		InOrder(ctree->firstchild);
		printf("%c\t", ctree->data);
		InOrder(ctree->nextsibling);
	}
}

// 3.层次遍历
void CenciOrder(CSNTree& ctree) {
	CSNode* p, * sib;
	queue<CSNode*> que;
	que.push(ctree);
	while (!que.empty()) {
		p = que.front();
		printf("%c\t", p->data);// 输出 
		que.pop();
		if (p->firstchild != NULL) {
			que.push(p->firstchild);
			// 兄弟结点
			sib = p->firstchild;
			while (sib->nextsibling != NULL) {
				que.push(sib->nextsibling);
				sib = sib->nextsibling;
			}
		}
	}
}

void PrintEmpty(CSNTree& ctree) {
	if (Empty(ctree)) {
		printf("树为空");
	}
	else {
		printf("树不为空");
	}
	printf("\n");
}
int main() {
	// 测试
	CSNTree ptree = NULL;
	PrintEmpty(ptree);

	InsertRootNode(ptree, 'R');
	CSNTree root = ptree;
	// 插入结点 
	InsertNode(ptree, 'A');// R插入ABC 
	InsertNode(ptree, 'B');
	InsertNode(ptree, 'C');

	InsertNode(ptree->firstchild, 'D');// A插入DE 
	InsertNode(ptree->firstchild, 'E');

	InsertNode(ptree->firstchild->nextsibling->nextsibling, 'F');// C插入F 

	InsertNode(ptree->firstchild->nextsibling->nextsibling->firstchild, 'G');// F插入GHK 
	InsertNode(ptree->firstchild->nextsibling->nextsibling->firstchild, 'H');
	InsertNode(ptree->firstchild->nextsibling->nextsibling->firstchild, 'K');

	PrintEmpty(ptree);

	PreOrderDetail(ptree);
	printf("\n");

	// 树的先序
	printf("树的先序和二叉树的先序：\n");
	ShuPreOrder(ptree);
	printf("\n");

	PreOrder(ptree);
	printf("\n");

	printf("树的后序和二叉树的中序：\n");
	ShuPostOrder(ptree);
	printf("\n");

	InOrder(ptree);
	printf("\n");

	CenciOrder(ptree);
	printf("\n");

	// 测试删除
//	DeleteTreeNode(ptree, ptree->firstchild);// 删除A 
//	DeleteTreeNode(ptree, ptree->firstchild->nextsibling);// 删除B 
//	DeleteTreeNode(ptree, ptree->firstchild->nextsibling->nextsibling);// 删除C 
	DeleteTreeNode(ptree, ptree->firstchild->nextsibling->nextsibling->firstchild->firstchild->nextsibling);// 删除H 
	PreOrder(ptree);
	printf("\n");
}
