#include <stdio.h> 
#include <stdlib.h>
#include <cmath>
#include <queue>
#define MAX_TREE_SIZE 100

using namespace std;

typedef struct CSNode {
	char data;								 //	������ 
	struct CSNode* firstchild, * nextsibling, * parent; // ��һ�����Ӻ����ֵ�ָ��	,���׽�� 
}CSNode, * CSNTree;

// 1.�������� 
bool InsertRootNode(CSNTree& ctree, char e) {
	ctree = (CSNode*)malloc(sizeof(CSNode));
	ctree->data = e;
	ctree->firstchild = NULL;
	ctree->nextsibling = NULL;
	ctree->parent = NULL;

	return true;
}

// 2.��״����£���ǰctree������һ�����ӽ��
bool InsertNode(CSNTree& ctree, char e) {
	CSNode* csn = (CSNode*)malloc(sizeof(CSNode));
	csn->data = e;
	csn->firstchild = NULL;
	csn->nextsibling = NULL;
	csn->parent = ctree;

	// ����ڵ��������ص�-------------------------------------------------
	// ��û�к��ӣ�û�о�firstָ��������ӽ�㣬����ӵ��ұ��ֵܽ��ָ������
	if (ctree->firstchild == NULL) {
		ctree->firstchild = csn;
	}
	else {
		// ����ҵ������ֵܽ�㣬���½��ŵ���� 
		CSNode* cs = ctree->firstchild;
		while (cs->nextsibling != NULL) {// �ҵ�ĩβ 
			cs = cs->nextsibling;
		}
		cs->nextsibling = csn;
	}
	return true;
}

// 3.���ҵ�ǰ���ĸ��ڵ㣬Ӧ�ò��á�����ָ�� 
CSNode* GetParent(CSNTree& ctree) {
	if (ctree->parent == NULL) {
		return NULL;
	}
	return ctree->parent;
}

// 4.ɾ��p��㣬����ʵ�֡��ѵ� -------------- 
bool DeleteTreeNode(CSNTree& ctree, CSNode* p) {
	// 1.���ɾ�����ڵ㣬�ÿ�,����free 
	if (p == ctree) {
		ctree = NULL;
	}
	else {
		CSNode* parent = p->parent;
		// 2.ɾ������߽��ʱ�򣬴���ֻ��һ����㡣��Ҫ�������ĵ�һ��ָ���p���ֵ�
		if (parent->firstchild == p) {
			if (p->nextsibling != NULL) {
				parent->firstchild = p->nextsibling;
			}
			else {
				// û�����ֵܣ�����ֻ��p���ͽ������ĵ�һ��ָ���ÿ�
				parent->firstchild = NULL;
			}
		}
		// 3. ɾ�����ǵ�һ������ʱ����Ҫ��ǰһ�������ֵܽ��ָ��p��һ���ֵܽ��
		else {
			CSNode* q = parent->firstchild;// q���ҵ�Ҫɾ����pǰһ��λ�� 
			while (q->nextsibling != p) { // ��Ҫд��== �� 
				q = q->nextsibling;
			}
			q->nextsibling = p->nextsibling;// ��pɾ�� 
		}
	}
	free(p);
	return true;
}

// 5.�ж�Ϊ��
bool Empty(CSNTree& ptree) {
	if (ptree == NULL || ptree->firstchild == NULL) {
		return true;
	}
	return false;
}

// �������� 
// ��ӡһ�����ĺ����� ,ͨ��һ����� = ʵ�ֲ���һ�����ĺ��� 
void PrintOneNodeChildInfo(CSNTree& ctree) {
	printf("���ĺ����У�");
	CSNode* csn1 = ctree->firstchild;
	while (csn1 != NULL) {
		printf("%C\t", csn1->data);
		csn1 = csn1->nextsibling;// ת���ֵܽ�� 
	}
	printf("\n");
}

// �ݹ� ���� 

// 1.�������, ����ʽ���������=��������ʽ��������� 
void ShuPreOrder(CSNTree ctree) { // ����ʽ��������� 
	if (ctree != NULL) {
		printf("%c\t", ctree->data);
		// �н��ͷ���
		CSNode* p = ctree->firstchild;
		if (p != NULL) {
			ShuPreOrder(p);
			p = p->nextsibling;
			while (p != NULL) {
				ShuPreOrder(p);
				p = p->nextsibling;
			}
		}
	}
}
void PreOrder(CSNTree ctree) { // �������ķ�ʽ���� 
	if (ctree != NULL) {
		printf("%c\t", ctree->data);
		PreOrder(ctree->firstchild);
		PreOrder(ctree->nextsibling);
	}
}
// ���������ӡ��ϸ��Ϣ
void PreOrderDetail(CSNTree ctree) {
	if (ctree != NULL) {
		printf("��������:%c", ctree->data);
		if (ctree->parent != NULL) {
			printf(",���ĸ�����:%c\t", ctree->parent->data);
		}
		PrintOneNodeChildInfo(ctree);//���� 

		PreOrderDetail(ctree->firstchild);
		PreOrderDetail(ctree->nextsibling);
	}
}
// 2.���ĺ���������ڶ�������������� ���
void ShuPostOrder(CSNTree ctree) { // ����ʽ�ĺ������ 
	if (ctree != NULL) {
		// �н��ͷ���
		CSNode* p = ctree->firstchild;
		if (p != NULL) {
			ShuPostOrder(p);
			p = p->nextsibling;
			while (p != NULL) {
				ShuPostOrder(p);
				p = p->nextsibling;
			}
		}
		printf("%c\t", ctree->data);
	}
}
void InOrder(CSNTree ctree) {// ��������ʽ�ĺ������ 
	if (ctree != NULL) {
		InOrder(ctree->firstchild);
		printf("%c\t", ctree->data);
		InOrder(ctree->nextsibling);
	}
}

// 3.��α���
void CenciOrder(CSNTree& ctree) {
	CSNode* p, * sib;
	queue<CSNode*> que;
	que.push(ctree);
	while (!que.empty()) {
		p = que.front();
		printf("%c\t", p->data);// ��� 
		que.pop();
		if (p->firstchild != NULL) {
			que.push(p->firstchild);
			// �ֵܽ��
			sib = p->firstchild;
			while (sib->nextsibling != NULL) {
				que.push(sib->nextsibling);
				sib = sib->nextsibling;
			}
		}
	}
}

void PrintEmpty(CSNTree& ctree) {
	if (Empty(ctree)) {
		printf("��Ϊ��");
	}
	else {
		printf("����Ϊ��");
	}
	printf("\n");
}
int main() {
	// ����
	CSNTree ptree = NULL;
	PrintEmpty(ptree);

	InsertRootNode(ptree, 'R');
	CSNTree root = ptree;
	// ������ 
	InsertNode(ptree, 'A');// R����ABC 
	InsertNode(ptree, 'B');
	InsertNode(ptree, 'C');

	InsertNode(ptree->firstchild, 'D');// A����DE 
	InsertNode(ptree->firstchild, 'E');

	InsertNode(ptree->firstchild->nextsibling->nextsibling, 'F');// C����F 

	InsertNode(ptree->firstchild->nextsibling->nextsibling->firstchild, 'G');// F����GHK 
	InsertNode(ptree->firstchild->nextsibling->nextsibling->firstchild, 'H');
	InsertNode(ptree->firstchild->nextsibling->nextsibling->firstchild, 'K');

	PrintEmpty(ptree);

	PreOrderDetail(ptree);
	printf("\n");

	// ��������
	printf("��������Ͷ�����������\n");
	ShuPreOrder(ptree);
	printf("\n");

	PreOrder(ptree);
	printf("\n");

	printf("���ĺ���Ͷ�����������\n");
	ShuPostOrder(ptree);
	printf("\n");

	InOrder(ptree);
	printf("\n");

	CenciOrder(ptree);
	printf("\n");

	// ����ɾ��
//	DeleteTreeNode(ptree, ptree->firstchild);// ɾ��A 
//	DeleteTreeNode(ptree, ptree->firstchild->nextsibling);// ɾ��B 
//	DeleteTreeNode(ptree, ptree->firstchild->nextsibling->nextsibling);// ɾ��C 
	DeleteTreeNode(ptree, ptree->firstchild->nextsibling->nextsibling->firstchild->firstchild->nextsibling);// ɾ��H 
	PreOrder(ptree);
	printf("\n");
}
