#include <stdio.h> 
#include <cmath>

#define TreeSize 99 
#define MaxSize 100
/* 
����ȫ��������ʽ�洢���
i�����ӣ�2i
i���Һ��ӣ�2i+1
i�ĸ��ڵ㣺i/2 ����ȡ��
i���ڵĲ�Σ���ȣ���log2 (n) + 1
*/
struct TreeNode {
	int value; 		// �ڵ��е�����Ԫ�� 
	bool isEmpty; 	// ����Ƿ�Ϊ�� 
};
// ��ʼ��
void InitTreeNode(TreeNode(&t)[MaxSize]) {
	for (int i = 0; i < MaxSize; i++) {
		t[i].isEmpty = true; // ��Ϊ��
	}
}
// λ��i�������� 
TreeNode GetLeftC(TreeNode(&t)[MaxSize], int i) {
	TreeNode tn;
	tn.isEmpty = true;
	int j = i * 2;
	if (j <= TreeSize && !t[j].isEmpty && !t[i].isEmpty) {// ûԽ�� �������� ���Լ����ǿ� 
		tn = t[j];
	}
	return tn;
}
// λ��i�����Һ��� 
TreeNode GetRightC(TreeNode(&t)[MaxSize], int i) {
	TreeNode tn;
	tn.isEmpty = true;
	int j = i * 2 + 1;
	if (j <= TreeSize && !t[j].isEmpty && !t[i].isEmpty) {// ûԽ�� �����Һ��� ���Լ����ǿ� 
		tn = t[j];
	}
	return tn;
}
// λ��i���ĸ���� 
TreeNode GetParentC(TreeNode(&t)[MaxSize], int i) {
	TreeNode tn;
	tn.isEmpty = true;
	int j = i / 2;
	if (j >= 1 && !t[j].isEmpty) {// ûԽ�� ���и��� 
		tn = t[j];
	}
	return tn;
}
// λ��i����Σ���ȣ� 
int GetDepth(TreeNode(&t)[MaxSize], int i) {
	if (i >= 1 && i <= TreeSize) {// �Ƿ�Խ�� 
		return log(i) / log(2) + 1;
	}
	return 0;
}
// ��λ��i��λ�ò���һ�����
bool InsertTreeNode(TreeNode(&t)[MaxSize], int i, int e) {
	if (i < 1 || i > TreeSize) {// �Ƿ�Խ�� 
		return false;
	}
	TreeNode tn;
	tn.isEmpty = false;
	tn.value = e;
	t[i] = tn;
	return true;
}
// ɾ����λ��i��λ���ϵĽ�� - Ҫע����������Һ���Ҳɾ��
bool DeleteTreeNode(TreeNode(&t)[MaxSize], int i, int& e) {
	if (i < 1 || i > TreeSize) {// �Ƿ�Խ�� 
		return false;
	}
	// �ݹ���������Һ���Ҳɾ��
	DeleteTreeNode(t, i * 2, e);
	DeleteTreeNode(t, i * 2 + 1, e);

	e = t[i].value;
	t[i].isEmpty = true;
	return true;
}
// ˳����� 
void PrintTreeNodeOrder(TreeNode(&t)[MaxSize]) {
	for (int i = 1; i < MaxSize; i++) {
		if (!t[i].isEmpty) {
			printf("%d  ", t[i]);
		}
	}
}
// �������������ϸ��Ϣ
void PrintTreeNodeAll(TreeNode(&t)[MaxSize], int maxn) {
	TreeNode tn1, tn2, tn3;
	int depth;
	for (int i = 1; i < maxn; i++) {
		if (t[i].isEmpty) {
			printf("%d���Ϊ��\n", i);
			continue;
		}
		tn1 = GetLeftC(t, i);	// ����
		tn2 = GetRightC(t, i);  // �н��
		tn3 = GetParentC(t, i); // ���׽��
		if (!tn3.isEmpty) {
			printf("%d���ĸ�����ǣ�%d\t", i, tn3.value);
		}
		else {
			printf("%d���û�и���� \t", i);
		}
		if (!tn1.isEmpty) {
			printf("%d���������ǣ�%d\t", i, tn1.value);
		}
		else {
			printf("%d���û������ \t", i);
		}
		if (!tn2.isEmpty) {
			printf("%d�����ҽ���ǣ�%d\t", i, tn2.value);
		}
		else {
			printf("%d���û���ҽ�� \t", i);
		}
		depth = GetDepth(t, i);
		printf("%d���������%d\n", i, depth);
	}
}
int main() {
	TreeNode t[MaxSize];
	InitTreeNode(t);
	// ����ڵ�
	int maxn = 16;
	for (int i = 1; i < maxn; i++) {
		InsertTreeNode(t, i, i);
	}
	printf("��������������:\n");
	PrintTreeNodeOrder(t);
	printf("\n");
	printf("�������ÿ��������ϸ��Ϣ�����Һ��ӡ����ס����:\n");
	PrintTreeNodeAll(t, maxn);
	printf("\n");
	// ɾ���ڵ�
	int e;
	DeleteTreeNode(t, 2, e);
	printf("ɾ�����2����������������:\n");
	PrintTreeNodeOrder(t);
	printf("\n");
	printf("ɾ�����2�󣬸��������ϸ��Ϣ:\n");
	PrintTreeNodeAll(t, maxn);
}
