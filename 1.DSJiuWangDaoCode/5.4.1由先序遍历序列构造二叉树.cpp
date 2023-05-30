   #include <iostream>
#include <algorithm>
using namespace std;
// 实现二叉树的创建和销毁二叉树、三种遍历、求深度、叶子结点数、结点数等相关算法。

typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
}*BiTree;

int e;
// 根据先序输入创建二叉树
void CreateBiTree(BiTree& T) {
	cin >> e;
	if (e == 0) {
		T = NULL;
		return;
	}
	T = new BiTNode(); // 生成结点
	T->data = e;
	CreateBiTree(T->lchild);
	CreateBiTree(T->rchild);
}
// 额外补充----------------------------------------------
// 后序遍历销毁二叉树
void DeleteBiTree(BiTree& T) {
	if (T == NULL)
		return;
	DeleteBiTree(T->lchild);
	DeleteBiTree(T->rchild);
	cout << "元素为" << T->data << "的结点删除完成" << endl;
	delete T;
}
// 前序遍历
void PreOrder(BiTree& T) {
	if (T == NULL)
		return;
	cout << T->data << " ";
	PreOrder(T->lchild);
	PreOrder(T->rchild);
}
// 中序遍历
void InOrder(BiTree& T) {
	if (T == NULL)
		return;
	InOrder(T->lchild);
	cout << T->data << " ";
	InOrder(T->rchild);
}
// 后序遍历
void PostOrder(BiTree& T) {
	if (T == NULL)
		return;
	PostOrder(T->lchild);
	PostOrder(T->rchild);
	cout << T->data << " ";
}
// 深度
int GetHeight(BiTree& T) {
	if (T == NULL)
		return 0;
	return 1 + max(GetHeight(T->lchild), GetHeight(T->rchild)); // 自己的高度加上左右孩子谁更高就是这颗子树的高度，再往上递归就是整棵树的高度
}
// 求叶子结点数
int GetBiTreeLeafSize(BiTree& T) {
	if (T == NULL)
		return 0;
	// 只有左右孩子为空的结点才是叶子结点
	if (T->lchild == NULL && T->rchild == NULL) {
		return 1;
	}
	return 0 + GetBiTreeLeafSize(T->lchild) + GetBiTreeLeafSize(T->rchild);
}
// 求结点数
int GetBiTreeSize(BiTree& T) {
	if (T == NULL)
		return 0;
	return 1 + GetBiTreeSize(T->lchild) + GetBiTreeSize(T->rchild);
}
int main() {
	BiTNode* biTree;
	CreateBiTree(biTree); // 创建二叉树
	cout << "二叉树创建完成" << endl;

	cout << "前序遍历：" << endl;
	PreOrder(biTree);// 前序遍历
	cout << endl;

	cout << "中序遍历：" << endl;
	InOrder(biTree);// 中序遍历
	cout << endl;

	cout << "后序遍历：" << endl;
	PostOrder(biTree);// 后序遍历
	cout << endl;

	// 获取深度
	cout << "这颗二叉树的深度是:" << GetHeight(biTree) << endl;
	// 获取叶子结点数
	cout << "这颗二叉树的叶子结点数是:" << GetBiTreeLeafSize(biTree) << endl;
	// 获取树结点数
	cout << "这颗二叉树的结点数是:" << GetBiTreeSize(biTree) << endl;

	DeleteBiTree(biTree);// 删除二叉树
	cout << "二叉树销毁完成" << endl;
	return 0;
}
/*
1 2 3 0 0 4 5 0 6 0 0 7 0 0 8 0 0
构造的二叉树如：
		 1
	 2		        8
  3     4
	  5	  7
	   6

*/
