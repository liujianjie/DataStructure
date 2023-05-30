#include <iostream>
using namespace std;

typedef struct {
	int key;
	char info;
}ElemType;
typedef struct BSTNode{
	ElemType data;  // 数据域
	struct BSTNode* lchild, * rchild; // 左右孩子
}BSTNode, *BSTree;

// 查找
BSTree SearchBST(BSTree T, int key) {
	if (T == NULL || T->data.key == key) {// 两种结果，找到了和没找到
		return T;
	}
	else if (T->data.key > key) {
		return SearchBST(T->lchild, key); // 当前的key大于要搜索的key，就往左子树找
	}
	else {
		return SearchBST(T->rchild, key);// 当前的key小于等于要搜索的key，就往右子树找
	}
}
// 插入
void InsertBST(BSTree& T, ElemType e) {
	if (T == NULL) {
		BSTNode* s = new BSTNode;
		s->data = e;
		s->lchild = s->rchild = NULL;
		T = s;
	}else if (T->data.key > e.key) {
		InsertBST(T->lchild, e); // 当前的key大于要搜索的key，插入左子树
	}else {
		InsertBST(T->rchild, e);// 当前的key小于等于要搜索的key，插入右子树
	}
}
// 递归遍历
void InOrder(BSTree& T) {
	if (T == NULL)
		return;
	InOrder(T->lchild);
	cout << "(" << T->data.key << "," << T->data.info << ") ";
	InOrder(T->rchild);
}
// 创建二叉树
int key;
char info;
void CreateBST(BSTree &T) {
	T = NULL;
	cin >> key >> info;
	while (key != -1) {
		InsertBST(T, { key, info });
		cin >> key >> info;
	}
}
int main()
{
	BSTree T;
	cout << "请输入一组元素（key info):" << endl;
	CreateBST(T); // 创建二叉树
	
	cout << endl;

	cout << "创建完成，中序遍历为：" << endl;
	InOrder(T);
	cout << endl << endl;;

	int serkey = 45;
	BSTNode* bt = SearchBST(T, serkey);
	if (bt != NULL) {
		cout << "查找key为" << serkey << "的info是：" << bt->data.info << endl;
	} else {
		cout << "未查找到key为" << serkey <<"的结点" << endl;
	}

	cout << endl;
	cout << "请输入要插入的结点：" << endl;
	cin >> key >> info;
	InsertBST(T, { key, info });
	cout << "插入key为"<< key << "的结点后，中序遍历为：" << endl;
	InOrder(T);

	return 0;
}
/*
53 A 17 B 9 C 45 D 23 E 78 F 65 G 87 H -1 #
70 I
*/