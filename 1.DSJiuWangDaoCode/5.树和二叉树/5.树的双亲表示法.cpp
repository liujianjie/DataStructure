#include <stdio.h> 
#include <stdlib.h>
#include <cmath>
#include <queue>
#define MAX_TREE_SIZE 100

using namespace std;
typedef struct{
	char data;// 值 
	int index;	// 自己在数组中的下标 
	int parent;// 双亲位置 ，在数组中的下标 
}PTNode;

typedef struct{							// 数的类型定义
	PTNode nodes[MAX_TREE_SIZE]; 		// 双亲表示 
	int n;								// 结点数					
}PTree;

// 0.初始化
void InitTree(PTree &pt){
	pt.n = 0;
} 
// 1.插入根结点 
bool InsertRootNode(PTree &ptree, char e){
	PTNode ptn;
	ptn.data = e;			// 元素值 
	ptn.parent = -1;		// 没有父亲 
	ptn.index = 0;			// 自己在数组的位置为0 
	ptree.nodes[ptree.n] = ptn; 	// 放入数组中第一个位置 下标为0 
	ptree.n++;				// 结点数加 
	return true;
}

// 2.当前结点的父亲  ，没必要 
//PTNode *GetParent(PTree &ptree, PTNode &ptn){
//	if(ptn.parent == -1){
//		return NULL;
//	}
//	return &ptree.nodes[ptn.parent];
//} 

// 3.当前p结点插入一个结点ptn
bool InsertPTNode(PTree &ptree, PTNode &p, char e){
	if(ptree.n >= MAX_TREE_SIZE){
		return false;
	}
	PTNode ptn;
	ptn.data = e;
	ptn.index = ptree.n;			//当前n结点数就是自己的下标 
	ptn.parent = p.index; 
	ptree.nodes[ptree.n] = ptn;
	
	ptree.n++;				// 结点数加 
	return true;
} 

// 4.根据下标删除结点 ，不好实现。 
bool DeleteTreeNode(PTree &ptree, int index){
	// 最后一个结点移过来。它的子结点还存在，是个问题,并且最后一个结点变为父结点了 
	ptree.n--;
	ptree.nodes[index].data = ptree.nodes[ptree.n].data;
	return true;
} 
// 5.判断为空
bool Empty(PTree &ptree){
	if(ptree.n == 0){
		return true;
	}
	return false;
} 

// 辅助方法 
// 打印一个结点的孩子们  = 实现查找一个结点的孩子 
void PrintPTNodeChildInfo(PTree &ptree, PTNode& ptn){
	PTNode ptnchild;
	printf("%c的孩子有：", ptn.data);
	for(int i = 0; i < ptree.n; i++){
		ptnchild = ptree.nodes[i];
		if(ptnchild.parent == ptn.index){
			printf("%c(%d)\t", ptnchild.data, ptnchild.index);
		}
	}
} 

// 依次打印结点
void PrintPTNodeInfo(PTree &ptree){
	PTNode ptn;
	for(int i = 0; i < ptree.n; i++){
		ptn = ptree.nodes[i];
		printf("第%d个下标的值是%c\t", i, ptn.data);
		// 打印父亲 
		if(ptn.parent != -1){
			printf("它的父结点的下标是%d，父结点的值是%c", ptn.parent, ptree.nodes[ptn.parent].data);
		}
		// 打印孩子 
		printf("\n");
		PrintPTNodeChildInfo(ptree, ptn); 
		printf("\n");
	}
} 

void PrintEmpty(PTree &ptree){
	if(Empty(ptree)){
		printf("树为空");
	}else{
		printf("树不为空，有%d个结点", ptree.n);
	}
	printf("\n");
}
int main(){
	// 测试
	PTree ptree;
	InitTree(ptree);
	PrintEmpty(ptree);
	
	InsertRootNode(ptree, 'R');
	
	// 插入结点 
	InsertPTNode(ptree, ptree.nodes[0], 'A');
	InsertPTNode(ptree, ptree.nodes[0], 'B');
	InsertPTNode(ptree, ptree.nodes[0], 'C');
	
	InsertPTNode(ptree, ptree.nodes[1], 'D');
	InsertPTNode(ptree, ptree.nodes[1], 'E');
	
	InsertPTNode(ptree, ptree.nodes[3], 'F');
	
	InsertPTNode(ptree, ptree.nodes[6], 'G');
	InsertPTNode(ptree, ptree.nodes[6], 'H');
	InsertPTNode(ptree, ptree.nodes[6], 'K');
	
	PrintEmpty(ptree);
	
	PrintPTNodeInfo(ptree);
	
	// 删除节点 
	DeleteTreeNode(ptree, 1);
	
	PrintPTNodeInfo(ptree);
}
