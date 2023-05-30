#include <stdio.h> 
#include <stdlib.h>
#include <cmath>
#include <queue>
#define MAX_TREE_SIZE 100

using namespace std;

typedef struct CTNode{
	int child;		// 这个结点在数组中的下标 ,从而可以找到结点值data 
	struct CTNode* next;//  指向下一个 
}CTNode;

typedef struct{
	char data; 	// 数据 
	struct CTNode *firstChild;// 第一个孩子 
}CTBox;

typedef struct{
	CTBox nodes[MAX_TREE_SIZE]; 		// 双亲表示 
	int n;								// 结点数					
}CTree;

// 0.初始化
void InitTree(CTree &ctree){
	ctree.n = 0;
} 
// 1.插入根结点 
bool InsertRootNode(CTree &ctree, char e){
	CTBox ctb;
	ctb.data = e;			// 元素值 
	ctb.firstChild = NULL;	// 初始化为NULL;
	 
	ctree.nodes[ctree.n] = ctb;
	ctree.n++;				// 结点数加 
	return true;
}

// 2.当前p结点插入一个结点ctb
bool InsertCTB(CTree &ctree, CTBox &p, char e){
	if(ctree.n >= MAX_TREE_SIZE){
		return false;
	}
	CTBox ctb;
	ctb.data = e;			// 元素值 
	ctb.firstChild = NULL;	// 初始化为NULL;
	// 1.先在数组中放置
	ctree.nodes[ctree.n] = ctb;
	
	// 2.再建立一个链结点，这个链结点的下标为这结点在数组中的下标，将这个链结点插入到p结点中孩子节点链表末尾
	CTNode *ctn = (CTNode*)malloc(sizeof(CTNode));
	ctn->child = ctree.n;
	ctn->next = NULL;// 置位空 
	
	// 分情况，如果第一个为空，就直接加，如果不是就是得查
	if(p.firstChild == NULL){
		p.firstChild = ctn;
	}else{
		CTNode *q = p.firstChild;
		while(q->next != NULL){// 找到最后一个链结点 
			q = q->next;
		}
		q->next = ctn;// ctn放到末尾 
	}
	ctree.n++;				// 结点数加 
	return true;
} 

// 3.查找下标ci的父节点孩子结点链表中有ci的，返回下标, -1代表不存在 
int GetParentIndexByIndex(CTree &ctree, int ci){
	CTNode* p;
	for(int i = 0; i < ctree.n; i++){
		p = ctree.nodes[i].firstChild;
		if(p != NULL){
			while(p != NULL){
				if(p->child == ci){
					return i;
				}
				p = p->next;
			}
		}
	}
	return -1;
} 

// 4.从父节点的孩子链表中删除自己，通过自己的ci下标 
bool DeleteCTNodeFromParentByIndex(CTree &ctree, int ci){
	CTNode *p, *q;// p当前结点，q上一个结点为了方便删除p 
	for(int i = 0; i < ctree.n; i++){
		p = ctree.nodes[i].firstChild;
		if(p != NULL){
			q = p; // 
			while(p != NULL){
				if(p->child == ci){// 下标相等，代表找到待删除的结点 
					if(p == q){// 是否为首节点
						ctree.nodes[i].firstChild = NULL;// 置为空 
					}else{// 不是首节点需要用到q为前驱结点操作 
						q->next = p->next; // 将p删除 
						// 释放空间。
						free(p);
					}
					break;
				}
				q = p;	// 记录上一个结点 
				p = p->next;
			}
		}
	}
	return true;
} 

// 4.根据下标删除结点 ，不好实现。 
bool DeleteTreeNode(CTree &ctree, int index){
	// 在数组中下标是最后一个, 就需要它父节点孩子链表中删除自己 
	if(ctree.n == index + 1){
		ctree.n--;
	}else{
		// 不是数组中下标最后一个
		// 数组中下标最后一个移过来,它父节点孩子链表中删除自己 
		ctree.n--;
		ctree.nodes[index].data = ctree.nodes[ctree.n].data;
	}
	// 得处理移动过来的元素，将自己的父节点的孩子结点链表中删除自己 
	DeleteCTNodeFromParentByIndex(ctree, ctree.n);
	return true;
} 
 
// 5.判断为空
bool Empty(CTree &ptree){
	if(ptree.n == 0){
		return true;
	}
	return false;
} 

// 辅助方法 
// 打印一个结点的孩子们 ,通过一个结点 = 实现查找一个结点的孩子 
void PrintOneCTNodeChildInfo(CTree &ctree, CTBox& curctb){
	CTNode *ctn;
	ctn = curctb.firstChild;
	printf("它的孩子有:"); 
	while(ctn != NULL){
		printf("%c(%d)\t", ctree.nodes[ctn->child].data, ctn->child);
		ctn = ctn->next;
	}
	printf("\n");
}

// 依次打印树所有结点
void PrintCTreeInfo(CTree &ctree){
	CTBox ctb;
	int parenti;
	for(int i = 0; i < ctree.n; i++){
		ctb = ctree.nodes[i];
		printf("第%d个下标的值是%c\t", i, ctb.data);
		// 打印这个结点的父亲 
		parenti = GetParentIndexByIndex(ctree, i);
		if(parenti != -1){ // 不为空 
			printf("它的父结点的下标是%d，父结点的值是%c", parenti, ctree.nodes[parenti].data);
		}
		// 打印这个结点的孩子 
		printf("\n");
		PrintOneCTNodeChildInfo(ctree, ctb); 
	}
} 

void PrintEmpty(CTree &ptree){
	if(Empty(ptree)){
		printf("树为空");
	}else{
		printf("树不为空，有%d个结点", ptree.n);
	}
	printf("\n");
}
int main(){
	// 测试
	CTree ptree;
	InitTree(ptree);
	PrintEmpty(ptree);
	
	InsertRootNode(ptree, 'R');
	
	// 插入结点 
	InsertCTB(ptree, ptree.nodes[0], 'A');
	InsertCTB(ptree, ptree.nodes[0], 'B');
	InsertCTB(ptree, ptree.nodes[0], 'C');
	
	InsertCTB(ptree, ptree.nodes[1], 'D');
	InsertCTB(ptree, ptree.nodes[1], 'E');
	
	InsertCTB(ptree, ptree.nodes[3], 'F');
	
	InsertCTB(ptree, ptree.nodes[6], 'G');
	InsertCTB(ptree, ptree.nodes[6], 'H');
	InsertCTB(ptree, ptree.nodes[6], 'K');
	
	PrintEmpty(ptree);
	
	PrintCTreeInfo(ptree);
	
	// 删除节点 
	DeleteTreeNode(ptree, 3);
	
	printf("\n");
	PrintCTreeInfo(ptree);
}
