#include <stdio.h> 
#include <cmath>

#define TreeSize 99
#define MaxSize 100

struct TreeNode{
	int value; 		// 节点中的数据元素 
	bool isEmpty; 	// 结点是否为空 
};

// 0.初始化
void InitTreeNode(TreeNode (&t)[MaxSize]){
	for(int i = 0; i < MaxSize; i++){
		t[i].isEmpty = true;
	}
} 
// 1.i的左孩子 
TreeNode GetLeftC(TreeNode (&t)[MaxSize], int i){
	TreeNode tn;
	tn.isEmpty = true;
	int j = i * 2;
	if(j <= TreeSize && !t[j].isEmpty && !t[i].isEmpty){// 是否越界 且有左孩子 且自己不是空 
		tn = t[j];
	}
	return tn;
} 
// 2.i的右孩子 
TreeNode GetRightC(TreeNode (&t)[MaxSize], int i){
	TreeNode tn;
	tn.isEmpty = true;
	int j = i * 2 + 1;
	if(j <= TreeSize && !t[j].isEmpty && !t[i].isEmpty){// 是否越界 且有右孩子 且自己不是空 
		tn = t[j];
	}
	return tn;
} 
// 3.i的父结点 
TreeNode GetParentC(TreeNode (&t)[MaxSize], int i){
	TreeNode tn;
	tn.isEmpty = true;
	int j = i / 2;
	if(j >= 1 && !t[j].isEmpty){// 是否越界 且有父亲 
		tn = t[j];
	}
	return tn;
} 
// 4.i的层次 
int GetDepth(TreeNode (&t)[MaxSize], int i){
	if(i >= 1 && i <= TreeSize){// 是否越界 
		return log(i) / log(2) + 1;
	}
	return 0;
} 
// i的位置插入一个结点
bool InsertTreeNode(TreeNode (&t)[MaxSize], int i, int e){
	if(i < 1 || i > TreeSize){// 是否越界 
		return false; 
	}
	TreeNode tn;
	tn.isEmpty = false;
	tn.value = e;
	t[i] = tn;
	return true;
} 

// i的位置删除一个结点 
bool DeleteTreeNode(TreeNode (&t)[MaxSize], int i, int &e){
	if(i < 1 || i > TreeSize){// 是否越界 
		return false; 
	}
	e = t[i].value;
	t[i].isEmpty = true;
	// 把它的孩子也删除
	int j = i * 2;
	while(j <= TreeSize){ 
		t[j].isEmpty = true;// 左孩子
		t[j+1].isEmpty = true;// 右孩子 
		j = j * 2;
	} 
	return true;
} 
// 顺序遍历 
void PrintTreeNodeOrder(TreeNode (&t)[MaxSize]){
	for(int i = 1; i < MaxSize; i++){
		if(!t[i].isEmpty){
			printf("%d\t", t[i]);
		}
	} 
} 
// 遍历详细信息
void PrintTreeNodeAll(TreeNode (&t)[MaxSize], int maxn){
	TreeNode tn1,tn2, tn3;
	int depth; 
	// 访问所有节点的左节点   
	for(int i = 1; i < maxn; i++){
		
		if(t[i].isEmpty){
			printf("%d结点为空\n", i);
			continue;
		}
		tn1 = GetLeftC(t, i);
		tn2 = GetRightC(t, i);
		tn3 = GetParentC(t, i); 
		if(!tn3.isEmpty){
			printf("%d结点的父结点是：%d\t", i, tn3.value);
		}else{ 
			printf("%d结点没有父结点\t", i);
		}
		if(!tn1.isEmpty){
			printf("%d结点的左结点是：%d\t", i, tn1.value);
		}else{
			printf("%d结点没有左结点\t", i);
		}
		if(!tn2.isEmpty){
			printf("%d结点的右结点是：%d\t", i, tn2.value);
		}else{
			printf("%d结点没有右结点\t", i);
		}
		depth = GetDepth(t, i);
		printf("%d结点的深度是%d\n",i, depth);
	} 
} 
int main(){
	TreeNode t[MaxSize];
	InitTreeNode(t);
	// 插入节点
	int maxn = 16;
	
	for(int i = 1; i < maxn; i++){
		InsertTreeNode(t, i, i);
	} 
	PrintTreeNodeOrder(t);
	PrintTreeNodeAll(t, maxn);
	// 删除节点
	int e;
	DeleteTreeNode(t, 2, e);
	PrintTreeNodeAll(t, maxn);
}
