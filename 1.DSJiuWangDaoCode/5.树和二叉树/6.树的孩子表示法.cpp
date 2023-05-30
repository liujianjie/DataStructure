#include <stdio.h> 
#include <stdlib.h>
#include <cmath>
#include <queue>
#define MAX_TREE_SIZE 100

using namespace std;

typedef struct CTNode{
	int child;		// �������������е��±� ,�Ӷ������ҵ����ֵdata 
	struct CTNode* next;//  ָ����һ�� 
}CTNode;

typedef struct{
	char data; 	// ���� 
	struct CTNode *firstChild;// ��һ������ 
}CTBox;

typedef struct{
	CTBox nodes[MAX_TREE_SIZE]; 		// ˫�ױ�ʾ 
	int n;								// �����					
}CTree;

// 0.��ʼ��
void InitTree(CTree &ctree){
	ctree.n = 0;
} 
// 1.�������� 
bool InsertRootNode(CTree &ctree, char e){
	CTBox ctb;
	ctb.data = e;			// Ԫ��ֵ 
	ctb.firstChild = NULL;	// ��ʼ��ΪNULL;
	 
	ctree.nodes[ctree.n] = ctb;
	ctree.n++;				// ������� 
	return true;
}

// 2.��ǰp������һ�����ctb
bool InsertCTB(CTree &ctree, CTBox &p, char e){
	if(ctree.n >= MAX_TREE_SIZE){
		return false;
	}
	CTBox ctb;
	ctb.data = e;			// Ԫ��ֵ 
	ctb.firstChild = NULL;	// ��ʼ��ΪNULL;
	// 1.���������з���
	ctree.nodes[ctree.n] = ctb;
	
	// 2.�ٽ���һ������㣬����������±�Ϊ�����������е��±꣬������������뵽p����к��ӽڵ�����ĩβ
	CTNode *ctn = (CTNode*)malloc(sizeof(CTNode));
	ctn->child = ctree.n;
	ctn->next = NULL;// ��λ�� 
	
	// ������������һ��Ϊ�գ���ֱ�Ӽӣ�������Ǿ��ǵò�
	if(p.firstChild == NULL){
		p.firstChild = ctn;
	}else{
		CTNode *q = p.firstChild;
		while(q->next != NULL){// �ҵ����һ������� 
			q = q->next;
		}
		q->next = ctn;// ctn�ŵ�ĩβ 
	}
	ctree.n++;				// ������� 
	return true;
} 

// 3.�����±�ci�ĸ��ڵ㺢�ӽ����������ci�ģ������±�, -1�������� 
int GetParentIndexByIndex(CTree &ctree, int ci){
	CTNode* p;
	for(int i = 0; i < ctree.n; i++){
		p = ctree.nodes[i].firstChild;
		if(p != NULL){
			while(p != NULL){
				if(p->child == ci){
					return i;
				}
				p = p->next;
			}
		}
	}
	return -1;
} 

// 4.�Ӹ��ڵ�ĺ���������ɾ���Լ���ͨ���Լ���ci�±� 
bool DeleteCTNodeFromParentByIndex(CTree &ctree, int ci){
	CTNode *p, *q;// p��ǰ��㣬q��һ�����Ϊ�˷���ɾ��p 
	for(int i = 0; i < ctree.n; i++){
		p = ctree.nodes[i].firstChild;
		if(p != NULL){
			q = p; // 
			while(p != NULL){
				if(p->child == ci){// �±���ȣ������ҵ���ɾ���Ľ�� 
					if(p == q){// �Ƿ�Ϊ�׽ڵ�
						ctree.nodes[i].firstChild = NULL;// ��Ϊ�� 
					}else{// �����׽ڵ���Ҫ�õ�qΪǰ�������� 
						q->next = p->next; // ��pɾ�� 
						// �ͷſռ䡣
						free(p);
					}
					break;
				}
				q = p;	// ��¼��һ����� 
				p = p->next;
			}
		}
	}
	return true;
} 

// 4.�����±�ɾ����� ������ʵ�֡� 
bool DeleteTreeNode(CTree &ctree, int index){
	// ���������±������һ��, ����Ҫ�����ڵ㺢��������ɾ���Լ� 
	if(ctree.n == index + 1){
		ctree.n--;
	}else{
		// �����������±����һ��
		// �������±����һ���ƹ���,�����ڵ㺢��������ɾ���Լ� 
		ctree.n--;
		ctree.nodes[index].data = ctree.nodes[ctree.n].data;
	}
	// �ô����ƶ�������Ԫ�أ����Լ��ĸ��ڵ�ĺ��ӽ��������ɾ���Լ� 
	DeleteCTNodeFromParentByIndex(ctree, ctree.n);
	return true;
} 
 
// 5.�ж�Ϊ��
bool Empty(CTree &ptree){
	if(ptree.n == 0){
		return true;
	}
	return false;
} 

// �������� 
// ��ӡһ�����ĺ����� ,ͨ��һ����� = ʵ�ֲ���һ�����ĺ��� 
void PrintOneCTNodeChildInfo(CTree &ctree, CTBox& curctb){
	CTNode *ctn;
	ctn = curctb.firstChild;
	printf("���ĺ�����:"); 
	while(ctn != NULL){
		printf("%c(%d)\t", ctree.nodes[ctn->child].data, ctn->child);
		ctn = ctn->next;
	}
	printf("\n");
}

// ���δ�ӡ�����н��
void PrintCTreeInfo(CTree &ctree){
	CTBox ctb;
	int parenti;
	for(int i = 0; i < ctree.n; i++){
		ctb = ctree.nodes[i];
		printf("��%d���±��ֵ��%c\t", i, ctb.data);
		// ��ӡ������ĸ��� 
		parenti = GetParentIndexByIndex(ctree, i);
		if(parenti != -1){ // ��Ϊ�� 
			printf("���ĸ������±���%d��������ֵ��%c", parenti, ctree.nodes[parenti].data);
		}
		// ��ӡ������ĺ��� 
		printf("\n");
		PrintOneCTNodeChildInfo(ctree, ctb); 
	}
} 

void PrintEmpty(CTree &ptree){
	if(Empty(ptree)){
		printf("��Ϊ��");
	}else{
		printf("����Ϊ�գ���%d�����", ptree.n);
	}
	printf("\n");
}
int main(){
	// ����
	CTree ptree;
	InitTree(ptree);
	PrintEmpty(ptree);
	
	InsertRootNode(ptree, 'R');
	
	// ������ 
	InsertCTB(ptree, ptree.nodes[0], 'A');
	InsertCTB(ptree, ptree.nodes[0], 'B');
	InsertCTB(ptree, ptree.nodes[0], 'C');
	
	InsertCTB(ptree, ptree.nodes[1], 'D');
	InsertCTB(ptree, ptree.nodes[1], 'E');
	
	InsertCTB(ptree, ptree.nodes[3], 'F');
	
	InsertCTB(ptree, ptree.nodes[6], 'G');
	InsertCTB(ptree, ptree.nodes[6], 'H');
	InsertCTB(ptree, ptree.nodes[6], 'K');
	
	PrintEmpty(ptree);
	
	PrintCTreeInfo(ptree);
	
	// ɾ���ڵ� 
	DeleteTreeNode(ptree, 3);
	
	printf("\n");
	PrintCTreeInfo(ptree);
}
