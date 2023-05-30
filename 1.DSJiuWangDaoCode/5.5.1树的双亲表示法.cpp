#include <stdio.h> 
#include <stdlib.h>
#define MAX_TREE_SIZE 100

using namespace std;
typedef struct {
	char data;// 值 
	int index;	// 自己在数组中的下标 
	int parent;// 双亲位置 ，在数组中的下标 
}PTNode;

typedef struct {							// 数的类型定义
	PTNode nodes[MAX_TREE_SIZE]; 		// 双亲表示 
	int n;								// 结点数					
}PTree;

// 0.初始化
void InitTree(PTree& pt) {
	pt.n = 0;
}
// 1.插入根结点 
bool InsertRootNode(PTree& ptree, char e) {
	PTNode ptn;
	ptn.data = e;			// 元素值 
	ptn.parent = -1;			// 没有父亲 
	ptn.index = 0;			// 自己在数组的位置为0 
	ptree.nodes[ptree.n] = ptn; 	// 根放入数组中第一个位置 下标为0 
	ptree.n++;				// 结点数加1 
	return true;
}
// 2.当前结点的父亲 
PTNode *GetParent(PTree &ptree, PTNode &ptn){
	if(ptn.parent == -1){
		return NULL;
	}
	return &ptree.nodes[ptn.parent];
} 
// 3.p结点插入一个叶子结点ptn
bool InsertPTNode(PTree& ptree, PTNode& p, char e) {
	if (ptree.n >= MAX_TREE_SIZE) {
		return false;
	}
	PTNode ptn;
	ptn.data = e;
	ptn.index = ptree.n;			//当前n结点数就是自己的下标 
	ptn.parent = p.index;	    // 父亲下标
	ptree.nodes[ptree.n] = ptn;// 放到末尾
	ptree.n++;				// 结点数加 
	return true;
}
// 4.根据下标删除结点：较难。 
bool DeleteTreeNode(PTree& ptree, int index) {
	// 方法一：将值置为'0'代表删除，并将parent置为--1。 并将这个结点的子节点都删除
	ptree.nodes[index].data = '0';
	ptree.nodes[index].parent = -1;
	for (int i = 0; i < ptree.n; i++) {
		if (ptree.nodes[i].parent == index) {
			ptree.nodes[i].data = '0';
			ptree.nodes[i].parent = -1;
		}
	}
 	return true;
}
// 5.判断为空
bool Empty(PTree& ptree) {
	if (ptree.n == 0) {
		return true;
	}
	return false;
}
// 辅助方法 
// 打印ptn结点的孩子们=实现查找一个结点的孩子 
void PrintPTNodeChildInfo(PTree& ptree, PTNode& ptn) {
	PTNode ptnchild;
	for (int i = 0; i < ptree.n; i++) {
		if (i == 0) {
			printf("%c的孩子有：", ptn.data);
		}
		ptnchild = ptree.nodes[i];
		if (ptnchild.parent == ptn.index) {
			printf("%c(%d) ", ptnchild.data, ptnchild.index);
		}
	}
}
// 依次打印结点
void PrintPTNodeInfo(PTree& ptree) {
	PTNode ptn;
	for (int i = 0; i < ptree.n; i++) {
		// 删除了的结点跳过
		if (ptree.nodes[i].parent == -1 && i != 0) {
			continue;
		}
		ptn = ptree.nodes[i];
		printf("第%d个下标的值是%c,", i, ptn.data);
		// 打印父亲 
		if (ptn.parent != -1) {
			printf("它的父结点的是%c(%d),",ptree.nodes[ptn.parent].data, ptn.parent);
		}
		// 打印孩子 
		//printf("\n");
		PrintPTNodeChildInfo(ptree, ptn);
		printf("\n");
	}
}
void PrintEmpty(PTree& ptree) {
	if (Empty(ptree)) {
		printf("树为空");
	}
	else {
		int ct = 1;
		for (int i = 1; i < ptree.n; i++) { 
			if (ptree.nodes[i].parent != -1) {
				ct++;
			}
		}
		printf("树不为空，有%d个结点", ct);
	}
	printf("\n");
}
int main() {
	PTree ptree;
	InitTree(ptree);// 初始化
	PrintEmpty(ptree);// 是否为空

	// 手动构造树
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

	PrintEmpty(ptree);// 是否为空

	printf("遍历各结点信息：\n");
	PrintPTNodeInfo(ptree);

	printf("\n删除下标为1的结点后，遍历各结点信息：\n");
	DeleteTreeNode(ptree, 1);// 删除节点
	PrintEmpty(ptree);// 是否为空

	PrintPTNodeInfo(ptree);
}
