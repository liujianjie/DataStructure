#include <iostream>
#include <queue>
using namespace std;
#define MVNum 100
typedef struct ArcNode {// �߱���
	int adjvex;
	struct ArcNode* nextarc;
}ArcNode;

typedef struct Vnode { // �������
	int data;
	ArcNode* firstarc;
}VNode, AdjList[MVNum];

typedef struct {//	�ڽӱ�
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;
// ����6.32����ͼ
void CreateDirectedGraph(ALGraph& G) {
	cin >> G.vexnum >> G.arcnum;			// ���붥����������
	for (int i = 1; i <= G.vexnum; i++) {// ������㣬�����ͷ����:ע�������1��ʼ������Ϊ������Ϊ������Ŵ�1��ʼ
		cin >> G.vertices[i].data;		// ���붥��ֵ 
		G.vertices[i].firstarc = NULL;  // ��ʼ����ͷ����ָ����ΪNULL
	}
	int v1, v2;
	for (int k = 0; k < G.arcnum; k++) {
		cin >> v1 >> v2;					// ����һ���ߵ��������, v1 ָ�� v2
		ArcNode* p1 = new ArcNode;		// �����µı߽��
		p1->adjvex = v2;					// �ڽӵ����Ϊv2
		p1->nextarc = G.vertices[v1].firstarc;
		G.vertices[v1].firstarc = p1; // ���½��*p1���붥��v1�ı߱�ͷ��
	}
}
bool visited[MVNum];// �Ƿ������
// ������ȱ����㷨
void DFS(ALGraph& G, int curi) {
	cout << curi; // ���뵱ǰ�����Ľ��
	visited[curi] = true;
	ArcNode* p = G.vertices[curi].firstarc;
	while (p != NULL) {
		int j = p->adjvex; // j��curi���ڽӵ�
		if (!visited[j]) {
			DFS(G, j);	   // ���ڽӵ�jΪ��ʼ���������
		}
		p = p->nextarc;    // curi����һ���߱���
	}
}
bool visited2[MVNum];// �Ƿ������
// ������ȱ����㷨
void BFS(ALGraph& G, int curi) {
	queue<int> que;
	cout << curi;							// �����ʼ����
	visited2[curi] = true;					// ��ǿ�ʼ������ʹ�
	que.push(curi);							// ��ӿ�ʼ����
	while (!que.empty()) {					// ��Ϊ��
		curi = que.front();					// ��ǰ��ͷ�Ķ���
		que.pop();							// ������ͷ
		ArcNode* p = G.vertices[curi].firstarc;// �õ���ǰ����Ķ�����㣬�ɶ�������ٵõ��߱���
		while (p != NULL) {					// ѹ�뵱ǰ���������û�з��ʹ��ı߱���Ķ���
			if (!visited2[p->adjvex]) {
				// ע�⣺BFS��������������ұ�Ƿ��ʹ���
				cout << p->adjvex;			// ������ʵ����ڽӶ���
				visited2[p->adjvex] = true; // ����ڽӶ�����ʹ�
				que.push(p->adjvex);			// ѹ���ڽӶ��㣬��Ϊ�´εĿ�ʼ����
			}
			p = p->nextarc;					// curi����һ���߱���
		}
	}
}
void main() {
	ALGraph G;
	CreateDirectedGraph(G);
	DFS(G, 3); // ��3��ʼ����
	cout << endl;
	BFS(G, 3); // ��3��ʼ����
}
/*
6 11
1 2 3 4 5 6
2 1
2 4
3 2
3 6
4 3
4 6
4 6
5 1
6 1
6 2
6 5

*/