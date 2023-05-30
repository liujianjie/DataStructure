#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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
vector< BiTNode*> veccur;// ��ǰ���ʵ�·��
vector< BiTNode*> vecmax;// ������ķ��ʵ�·��
int maxh = -1;
void MaxLoad(BiTree& T, int height) {
	if(T == NULL){
		return;
	}
	veccur.push_back(T);	// ���뵱ǰ���
	if (height > maxh) {
		vecmax = veccur; // ��������ʵ�·��
		maxh = height;
	}
	MaxLoad(T->lchild, height + 1);
	MaxLoad(T->rchild, height + 1);
	veccur.pop_back();	// ������ǰ���
}

int main() {
	BiTNode* biTree;
	CreateBiTree(biTree); // ����������

	MaxLoad(biTree, 0);
	cout << "�·����" << endl;
	for (auto bi : vecmax) {
		cout << bi->data;
	}
	cout << endl;
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

