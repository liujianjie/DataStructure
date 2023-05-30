#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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
vector< BiTNode*> veccur;// 当前访问的路径
vector< BiTNode*> vecmax;// 保存最长的访问的路径
int maxh = -1;
void MaxLoad(BiTree& T, int height) {
	if(T == NULL){
		return;
	}
	veccur.push_back(T);	// 放入当前结点
	if (height > maxh) {
		vecmax = veccur; // 保存最长访问的路径
		maxh = height;
	}
	MaxLoad(T->lchild, height + 1);
	MaxLoad(T->rchild, height + 1);
	veccur.pop_back();	// 弹出当前结点
}

int main() {
	BiTNode* biTree;
	CreateBiTree(biTree); // 创建二叉树

	MaxLoad(biTree, 0);
	cout << "最长路径：" << endl;
	for (auto bi : vecmax) {
		cout << bi->data;
	}
	cout << endl;
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

