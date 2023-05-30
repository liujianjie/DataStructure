#include <stdio.h> 
#include <cmath>

#define TreeSize 99
#define MaxSize 100

struct TreeNode{
	int value; 		// �ڵ��е�����Ԫ�� 
	bool isEmpty; 	// ����Ƿ�Ϊ�� 
};

// 0.��ʼ��
void InitTreeNode(TreeNode (&t)[MaxSize]){
	for(int i = 0; i < MaxSize; i++){
		t[i].isEmpty = true;
	}
} 
// 1.i������ 
TreeNode GetLeftC(TreeNode (&t)[MaxSize], int i){
	TreeNode tn;
	tn.isEmpty = true;
	int j = i * 2;
	if(j <= TreeSize && !t[j].isEmpty && !t[i].isEmpty){// �Ƿ�Խ�� �������� ���Լ����ǿ� 
		tn = t[j];
	}
	return tn;
} 
// 2.i���Һ��� 
TreeNode GetRightC(TreeNode (&t)[MaxSize], int i){
	TreeNode tn;
	tn.isEmpty = true;
	int j = i * 2 + 1;
	if(j <= TreeSize && !t[j].isEmpty && !t[i].isEmpty){// �Ƿ�Խ�� �����Һ��� ���Լ����ǿ� 
		tn = t[j];
	}
	return tn;
} 
// 3.i�ĸ���� 
TreeNode GetParentC(TreeNode (&t)[MaxSize], int i){
	TreeNode tn;
	tn.isEmpty = true;
	int j = i / 2;
	if(j >= 1 && !t[j].isEmpty){// �Ƿ�Խ�� ���и��� 
		tn = t[j];
	}
	return tn;
} 
// 4.i�Ĳ�� 
int GetDepth(TreeNode (&t)[MaxSize], int i){
	if(i >= 1 && i <= TreeSize){// �Ƿ�Խ�� 
		return log(i) / log(2) + 1;
	}
	return 0;
} 
// i��λ�ò���һ�����
bool InsertTreeNode(TreeNode (&t)[MaxSize], int i, int e){
	if(i < 1 || i > TreeSize){// �Ƿ�Խ�� 
		return false; 
	}
	TreeNode tn;
	tn.isEmpty = false;
	tn.value = e;
	t[i] = tn;
	return true;
} 

// i��λ��ɾ��һ����� 
bool DeleteTreeNode(TreeNode (&t)[MaxSize], int i, int &e){
	if(i < 1 || i > TreeSize){// �Ƿ�Խ�� 
		return false; 
	}
	e = t[i].value;
	t[i].isEmpty = true;
	// �����ĺ���Ҳɾ��
	int j = i * 2;
	while(j <= TreeSize){ 
		t[j].isEmpty = true;// ����
		t[j+1].isEmpty = true;// �Һ��� 
		j = j * 2;
	} 
	return true;
} 
// ˳����� 
void PrintTreeNodeOrder(TreeNode (&t)[MaxSize]){
	for(int i = 1; i < MaxSize; i++){
		if(!t[i].isEmpty){
			printf("%d\t", t[i]);
		}
	} 
} 
// ������ϸ��Ϣ
void PrintTreeNodeAll(TreeNode (&t)[MaxSize], int maxn){
	TreeNode tn1,tn2, tn3;
	int depth; 
	// �������нڵ����ڵ�   
	for(int i = 1; i < maxn; i++){
		
		if(t[i].isEmpty){
			printf("%d���Ϊ��\n", i);
			continue;
		}
		tn1 = GetLeftC(t, i);
		tn2 = GetRightC(t, i);
		tn3 = GetParentC(t, i); 
		if(!tn3.isEmpty){
			printf("%d���ĸ�����ǣ�%d\t", i, tn3.value);
		}else{ 
			printf("%d���û�и����\t", i);
		}
		if(!tn1.isEmpty){
			printf("%d���������ǣ�%d\t", i, tn1.value);
		}else{
			printf("%d���û������\t", i);
		}
		if(!tn2.isEmpty){
			printf("%d�����ҽ���ǣ�%d\t", i, tn2.value);
		}else{
			printf("%d���û���ҽ��\t", i);
		}
		depth = GetDepth(t, i);
		printf("%d���������%d\n",i, depth);
	} 
} 
int main(){
	TreeNode t[MaxSize];
	InitTreeNode(t);
	// ����ڵ�
	int maxn = 16;
	
	for(int i = 1; i < maxn; i++){
		InsertTreeNode(t, i, i);
	} 
	PrintTreeNodeOrder(t);
	PrintTreeNodeAll(t, maxn);
	// ɾ���ڵ�
	int e;
	DeleteTreeNode(t, 2, e);
	PrintTreeNodeAll(t, maxn);
}
