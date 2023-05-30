#include <stdio.h> 
#include <stdlib.h>
#include <cmath>
#include <queue>
#define MAX_TREE_SIZE 100

using namespace std;
typedef struct{
	char data;// ֵ 
	int index;	// �Լ��������е��±� 
	int parent;// ˫��λ�� ���������е��±� 
}PTNode;

typedef struct{							// �������Ͷ���
	PTNode nodes[MAX_TREE_SIZE]; 		// ˫�ױ�ʾ 
	int n;								// �����					
}PTree;

// 0.��ʼ��
void InitTree(PTree &pt){
	pt.n = 0;
} 
// 1.�������� 
bool InsertRootNode(PTree &ptree, char e){
	PTNode ptn;
	ptn.data = e;			// Ԫ��ֵ 
	ptn.parent = -1;		// û�и��� 
	ptn.index = 0;			// �Լ��������λ��Ϊ0 
	ptree.nodes[ptree.n] = ptn; 	// ���������е�һ��λ�� �±�Ϊ0 
	ptree.n++;				// ������� 
	return true;
}

// 2.��ǰ���ĸ���  ��û��Ҫ 
//PTNode *GetParent(PTree &ptree, PTNode &ptn){
//	if(ptn.parent == -1){
//		return NULL;
//	}
//	return &ptree.nodes[ptn.parent];
//} 

// 3.��ǰp������һ�����ptn
bool InsertPTNode(PTree &ptree, PTNode &p, char e){
	if(ptree.n >= MAX_TREE_SIZE){
		return false;
	}
	PTNode ptn;
	ptn.data = e;
	ptn.index = ptree.n;			//��ǰn����������Լ����±� 
	ptn.parent = p.index; 
	ptree.nodes[ptree.n] = ptn;
	
	ptree.n++;				// ������� 
	return true;
} 

// 4.�����±�ɾ����� ������ʵ�֡� 
bool DeleteTreeNode(PTree &ptree, int index){
	// ���һ������ƹ����������ӽ�㻹���ڣ��Ǹ�����,�������һ������Ϊ������� 
	ptree.n--;
	ptree.nodes[index].data = ptree.nodes[ptree.n].data;
	return true;
} 
// 5.�ж�Ϊ��
bool Empty(PTree &ptree){
	if(ptree.n == 0){
		return true;
	}
	return false;
} 

// �������� 
// ��ӡһ�����ĺ�����  = ʵ�ֲ���һ�����ĺ��� 
void PrintPTNodeChildInfo(PTree &ptree, PTNode& ptn){
	PTNode ptnchild;
	printf("%c�ĺ����У�", ptn.data);
	for(int i = 0; i < ptree.n; i++){
		ptnchild = ptree.nodes[i];
		if(ptnchild.parent == ptn.index){
			printf("%c(%d)\t", ptnchild.data, ptnchild.index);
		}
	}
} 

// ���δ�ӡ���
void PrintPTNodeInfo(PTree &ptree){
	PTNode ptn;
	for(int i = 0; i < ptree.n; i++){
		ptn = ptree.nodes[i];
		printf("��%d���±��ֵ��%c\t", i, ptn.data);
		// ��ӡ���� 
		if(ptn.parent != -1){
			printf("���ĸ������±���%d��������ֵ��%c", ptn.parent, ptree.nodes[ptn.parent].data);
		}
		// ��ӡ���� 
		printf("\n");
		PrintPTNodeChildInfo(ptree, ptn); 
		printf("\n");
	}
} 

void PrintEmpty(PTree &ptree){
	if(Empty(ptree)){
		printf("��Ϊ��");
	}else{
		printf("����Ϊ�գ���%d�����", ptree.n);
	}
	printf("\n");
}
int main(){
	// ����
	PTree ptree;
	InitTree(ptree);
	PrintEmpty(ptree);
	
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
	
	PrintEmpty(ptree);
	
	PrintPTNodeInfo(ptree);
	
	// ɾ���ڵ� 
	DeleteTreeNode(ptree, 1);
	
	PrintPTNodeInfo(ptree);
}
