#include <iostream>
using namespace std;

typedef struct {
	int key;
	char info;
}ElemType;
typedef struct BSTNode{
	ElemType data;  // ������
	struct BSTNode* lchild, * rchild; // ���Һ���
}BSTNode, *BSTree;

// ����
BSTree SearchBST(BSTree T, int key) {
	if (T == NULL || T->data.key == key) {// ���ֽ�����ҵ��˺�û�ҵ�
		return T;
	}
	else if (T->data.key > key) {
		return SearchBST(T->lchild, key); // ��ǰ��key����Ҫ������key��������������
	}
	else {
		return SearchBST(T->rchild, key);// ��ǰ��keyС�ڵ���Ҫ������key��������������
	}
}
// ����
void InsertBST(BSTree& T, ElemType e) {
	if (T == NULL) {
		BSTNode* s = new BSTNode;
		s->data = e;
		s->lchild = s->rchild = NULL;
		T = s;
	}else if (T->data.key > e.key) {
		InsertBST(T->lchild, e); // ��ǰ��key����Ҫ������key������������
	}else {
		InsertBST(T->rchild, e);// ��ǰ��keyС�ڵ���Ҫ������key������������
	}
}
// �ݹ����
void InOrder(BSTree& T) {
	if (T == NULL)
		return;
	InOrder(T->lchild);
	cout << "(" << T->data.key << "," << T->data.info << ") ";
	InOrder(T->rchild);
}
// ����������
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
	cout << "������һ��Ԫ�أ�key info):" << endl;
	CreateBST(T); // ����������
	
	cout << endl;

	cout << "������ɣ��������Ϊ��" << endl;
	InOrder(T);
	cout << endl << endl;;

	int serkey = 45;
	BSTNode* bt = SearchBST(T, serkey);
	if (bt != NULL) {
		cout << "����keyΪ" << serkey << "��info�ǣ�" << bt->data.info << endl;
	} else {
		cout << "δ���ҵ�keyΪ" << serkey <<"�Ľ��" << endl;
	}

	cout << endl;
	cout << "������Ҫ����Ľ�㣺" << endl;
	cin >> key >> info;
	InsertBST(T, { key, info });
	cout << "����keyΪ"<< key << "�Ľ����������Ϊ��" << endl;
	InOrder(T);

	return 0;
}
/*
53 A 17 B 9 C 45 D 23 E 78 F 65 G 87 H -1 #
70 I
*/