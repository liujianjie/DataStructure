   #include <iostream>
#include <algorithm>
using namespace std;
// ʵ�ֶ������Ĵ��������ٶ����������ֱ���������ȡ�Ҷ�ӽ�����������������㷨��

typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
}*BiTree;

int e;
// �����������봴��������
void CreateBiTree(BiTree& T) {
	cin >> e;
	if (e == 0) {
		T = NULL;
		return;
	}
	T = new BiTNode(); // ���ɽ��
	T->data = e;
	CreateBiTree(T->lchild);
	CreateBiTree(T->rchild);
}
// ���ⲹ��----------------------------------------------
// ����������ٶ�����
void DeleteBiTree(BiTree& T) {
	if (T == NULL)
		return;
	DeleteBiTree(T->lchild);
	DeleteBiTree(T->rchild);
	cout << "Ԫ��Ϊ" << T->data << "�Ľ��ɾ�����" << endl;
	delete T;
}
// ǰ�����
void PreOrder(BiTree& T) {
	if (T == NULL)
		return;
	cout << T->data << " ";
	PreOrder(T->lchild);
	PreOrder(T->rchild);
}
// �������
void InOrder(BiTree& T) {
	if (T == NULL)
		return;
	InOrder(T->lchild);
	cout << T->data << " ";
	InOrder(T->rchild);
}
// �������
void PostOrder(BiTree& T) {
	if (T == NULL)
		return;
	PostOrder(T->lchild);
	PostOrder(T->rchild);
	cout << T->data << " ";
}
// ���
int GetHeight(BiTree& T) {
	if (T == NULL)
		return 0;
	return 1 + max(GetHeight(T->lchild), GetHeight(T->rchild)); // �Լ��ĸ߶ȼ������Һ���˭���߾�����������ĸ߶ȣ������ϵݹ�����������ĸ߶�
}
// ��Ҷ�ӽ����
int GetBiTreeLeafSize(BiTree& T) {
	if (T == NULL)
		return 0;
	// ֻ�����Һ���Ϊ�յĽ�����Ҷ�ӽ��
	if (T->lchild == NULL && T->rchild == NULL) {
		return 1;
	}
	return 0 + GetBiTreeLeafSize(T->lchild) + GetBiTreeLeafSize(T->rchild);
}
// ������
int GetBiTreeSize(BiTree& T) {
	if (T == NULL)
		return 0;
	return 1 + GetBiTreeSize(T->lchild) + GetBiTreeSize(T->rchild);
}
int main() {
	BiTNode* biTree;
	CreateBiTree(biTree); // ����������
	cout << "�������������" << endl;

	cout << "ǰ�������" << endl;
	PreOrder(biTree);// ǰ�����
	cout << endl;

	cout << "���������" << endl;
	InOrder(biTree);// �������
	cout << endl;

	cout << "���������" << endl;
	PostOrder(biTree);// �������
	cout << endl;

	// ��ȡ���
	cout << "��Ŷ������������:" << GetHeight(biTree) << endl;
	// ��ȡҶ�ӽ����
	cout << "��Ŷ�������Ҷ�ӽ������:" << GetBiTreeLeafSize(biTree) << endl;
	// ��ȡ�������
	cout << "��Ŷ������Ľ������:" << GetBiTreeSize(biTree) << endl;

	DeleteBiTree(biTree);// ɾ��������
	cout << "�������������" << endl;
	return 0;
}
/*
1 2 3 0 0 4 5 0 6 0 0 7 0 0 8 0 0
����Ķ������磺
		 1
	 2		        8
  3     4
	  5	  7
	   6

*/
