#include <stdio.h> 
#include <stdlib.h>
#define MAX_TREE_SIZE 100

using namespace std;
typedef struct {
	char data;// ֵ 
	int index;	// �Լ��������е��±� 
	int parent;// ˫��λ�� ���������е��±� 
}PTNode;

typedef struct {							// �������Ͷ���
	PTNode nodes[MAX_TREE_SIZE]; 		// ˫�ױ�ʾ 
	int n;								// �����					
}PTree;

// 0.��ʼ��
void InitTree(PTree& pt) {
	pt.n = 0;
}
// 1.�������� 
bool InsertRootNode(PTree& ptree, char e) {
	PTNode ptn;
	ptn.data = e;			// Ԫ��ֵ 
	ptn.parent = -1;			// û�и��� 
	ptn.index = 0;			// �Լ��������λ��Ϊ0 
	ptree.nodes[ptree.n] = ptn; 	// �����������е�һ��λ�� �±�Ϊ0 
	ptree.n++;				// �������1 
	return true;
}
// 2.��ǰ���ĸ��� 
PTNode *GetParent(PTree &ptree, PTNode &ptn){
	if(ptn.parent == -1){
		return NULL;
	}
	return &ptree.nodes[ptn.parent];
} 
// 3.p������һ��Ҷ�ӽ��ptn
bool InsertPTNode(PTree& ptree, PTNode& p, char e) {
	if (ptree.n >= MAX_TREE_SIZE) {
		return false;
	}
	PTNode ptn;
	ptn.data = e;
	ptn.index = ptree.n;			//��ǰn����������Լ����±� 
	ptn.parent = p.index;	    // �����±�
	ptree.nodes[ptree.n] = ptn;// �ŵ�ĩβ
	ptree.n++;				// ������� 
	return true;
}
// 4.�����±�ɾ����㣺���ѡ� 
bool DeleteTreeNode(PTree& ptree, int index) {
	// ����һ����ֵ��Ϊ'0'����ɾ��������parent��Ϊ--1�� ������������ӽڵ㶼ɾ��
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
// 5.�ж�Ϊ��
bool Empty(PTree& ptree) {
	if (ptree.n == 0) {
		return true;
	}
	return false;
}
// �������� 
// ��ӡptn���ĺ�����=ʵ�ֲ���һ�����ĺ��� 
void PrintPTNodeChildInfo(PTree& ptree, PTNode& ptn) {
	PTNode ptnchild;
	for (int i = 0; i < ptree.n; i++) {
		if (i == 0) {
			printf("%c�ĺ����У�", ptn.data);
		}
		ptnchild = ptree.nodes[i];
		if (ptnchild.parent == ptn.index) {
			printf("%c(%d) ", ptnchild.data, ptnchild.index);
		}
	}
}
// ���δ�ӡ���
void PrintPTNodeInfo(PTree& ptree) {
	PTNode ptn;
	for (int i = 0; i < ptree.n; i++) {
		// ɾ���˵Ľ������
		if (ptree.nodes[i].parent == -1 && i != 0) {
			continue;
		}
		ptn = ptree.nodes[i];
		printf("��%d���±��ֵ��%c,", i, ptn.data);
		// ��ӡ���� 
		if (ptn.parent != -1) {
			printf("���ĸ�������%c(%d),",ptree.nodes[ptn.parent].data, ptn.parent);
		}
		// ��ӡ���� 
		//printf("\n");
		PrintPTNodeChildInfo(ptree, ptn);
		printf("\n");
	}
}
void PrintEmpty(PTree& ptree) {
	if (Empty(ptree)) {
		printf("��Ϊ��");
	}
	else {
		int ct = 1;
		for (int i = 1; i < ptree.n; i++) { 
			if (ptree.nodes[i].parent != -1) {
				ct++;
			}
		}
		printf("����Ϊ�գ���%d�����", ct);
	}
	printf("\n");
}
int main() {
	PTree ptree;
	InitTree(ptree);// ��ʼ��
	PrintEmpty(ptree);// �Ƿ�Ϊ��

	// �ֶ�������
	InsertRootNode(ptree, 'R');
	// ������ 
	InsertPTNode(ptree, ptree.nodes[0], 'A');
	InsertPTNode(ptree, ptree.nodes[0], 'B');
	InsertPTNode(ptree, ptree.nodes[0], 'C');

	InsertPTNode(ptree, ptree.nodes[1], 'D');
	InsertPTNode(ptree, ptree.nodes[1], 'E');

	InsertPTNode(ptree, ptree.nodes[3], 'F');

	InsertPTNode(ptree, ptree.nodes[6], 'G');
	InsertPTNode(ptree, ptree.nodes[6], 'H');
	InsertPTNode(ptree, ptree.nodes[6], 'K');

	PrintEmpty(ptree);// �Ƿ�Ϊ��

	printf("�����������Ϣ��\n");
	PrintPTNodeInfo(ptree);

	printf("\nɾ���±�Ϊ1�Ľ��󣬱����������Ϣ��\n");
	DeleteTreeNode(ptree, 1);// ɾ���ڵ�
	PrintEmpty(ptree);// �Ƿ�Ϊ��

	PrintPTNodeInfo(ptree);
}
