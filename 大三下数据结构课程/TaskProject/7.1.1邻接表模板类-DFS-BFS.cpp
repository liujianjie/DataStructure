#include <iostream>
#include <queue>
using namespace std;
#define MVNum 100
// ʹ��ģ������Ϊ6.32��6.33ͼ�Ķ���ֵ��ͬ

typedef struct ArcNode {// �߱���
	int adjvex;			// ��ָ��Ķ���λ��(��ţ�
	struct ArcNode* nextarc;
}ArcNode;
template <class T>
struct Vnode { // �������
	T data;
	ArcNode* firstarc;
};
template <class T>
struct ALGraph {//	�ڽӱ�
	Vnode<T> vertices[MVNum];
	int vexnum, arcnum;
};
// ���붥��ֵ�ͳ�ʼ����ͷ���
template <class T>
void InputVertexValAndInit(ALGraph<T>& G) {
	cin >> G.vexnum >> G.arcnum;			// ���붥����������
	for (int i = 1; i <= G.vexnum; i++) {// ������㣬�����ͷ����:ע�������1��ʼ������Ϊ������Ϊ������Ŵ�1��ʼ
		cin >> G.vertices[i].data;		// ���붥��ֵ 
		G.vertices[i].firstarc = NULL;  // ��ʼ����ͷ����ָ����ΪNULL
	}
}
// ����6.32����ͼ
template <class T>
void CreateDirectedGraph(ALGraph<T>& G) {
	InputVertexValAndInit(G);
	int v1, v2;
	for (int k = 0; k < G.arcnum; k++) {
		cin >> v1 >> v2;					// ����һ���ߵ��������, v1 ָ�� v2
		ArcNode* p1 = new ArcNode;		// �����µı߽��
		p1->adjvex = v2;					// �ڽӵ����Ϊv2
		p1->nextarc = G.vertices[v1].firstarc;
		G.vertices[v1].firstarc = p1;	// ���½��*p1���붥��v1�ı߱�ͷ��
	}
}
// ����6.33����ͼ
template <class T>
void CreateUnDirectedGraph(ALGraph<T>& G) {
	InputVertexValAndInit(G);
	int v1, v2;
	for (int k = 0; k < G.arcnum; k++) {
		cin >> v1 >> v2;					// ����һ���ߵ��������, v1 ָ�� v2
		ArcNode* p1 = new ArcNode;		// �����µı߽��
		p1->adjvex = v2;					// �ڽӵ����Ϊv2
		p1->nextarc = G.vertices[v1].firstarc;
		G.vertices[v1].firstarc = p1;	// ���½��*p1���붥��v1�ı߱�ͷ��
		ArcNode* p2 = new ArcNode;		// ����һ���ԳƵ��µı߽��
		p2->adjvex = v1;					// �ڽӵ����Ϊv2
		p2->nextarc = G.vertices[v2].firstarc;
		G.vertices[v2].firstarc = p2; // ���½��*p2���붥��v2�ı߱�ͷ��
	}
}
bool visited[MVNum];// �Ƿ������
template <class T>
// ������ȱ����㷨
void DFS(ALGraph<T>& G, int curi) {
	cout << G.vertices[curi].data << " "; // �����ǰ�����Ľ��
	visited[curi] = true;
	ArcNode* p = G.vertices[curi].firstarc;
	while (p != NULL) {
		int j = p->adjvex;			// j��curi���ڽӵ�
		if (!visited[j]) {
			DFS(G, j);				// ���ڽӵ�jΪ��ʼ���������
		}
		p = p->nextarc;				// curi����һ���߽��
	}
}
bool visited2[MVNum];// �Ƿ������

// ������ȱ����㷨
template <class T>
void BFS(ALGraph<T>& G, int curi) {
	queue<int> que;
	cout << G.vertices[curi].data << " ";	// �����ʼ����
	visited2[curi] = true;					// ��ǿ�ʼ������ʹ�
	que.push(curi);							// ��ӿ�ʼ����
	while (!que.empty()) {					// ��Ϊ��
		curi = que.front();					// ��ǰ��ͷ�Ķ���
		que.pop();							// ������ͷ
		ArcNode* p = G.vertices[curi].firstarc;// �õ���ǰ����Ķ�����㣬�ɶ�������ٵõ��߱���
		while (p != NULL) {					// ѹ�뵱ǰ���������û�з��ʹ��ı߱���Ķ���
			if (!visited2[p->adjvex]) {
				// ע�⣺BFS��������������ұ�Ƿ��ʹ���
				cout << G.vertices[p->adjvex].data << " ";// ������ʵ����ڽӶ���
				visited2[p->adjvex] = true; // ����ڽӶ�����ʹ�
				que.push(p->adjvex);			// ѹ���ڽӶ��㣬��Ϊ�´εĿ�ʼ����
			}
			p = p->nextarc;					// curi����һ���߱���
		}
	}
}
void main() {

	cout << "��������ͼ(6.32)�����ݣ�" << endl;
	ALGraph<int> G;
	CreateDirectedGraph(G);
	//cout << "����ͼ(6.32)���������������" << endl;
	cout << "����ͼ(6.32)��������ȱ�����" << endl;
	DFS(G, 3); // ��3�Ŷ���3��ʼ����

	cout << endl << endl;

	cout << "��������ͼ(6.33)�����ݣ�" << endl;
	ALGraph<char> G2;
	CreateUnDirectedGraph(G2);
	cout << "����ͼ(6.33)�Ĺ�����ȱ�����" << endl;
	BFS(G2, 1); // ��1�Ŷ���a��ʼ����
}
/*
6.32����ͼ������
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

6.33����ͼ������
8 14
a b c d e f g h
1 2
1 3
2 3
2 4
2 5
3 4
3 8
4 5
4 6
4 7
4 8
5 6
6 7
7 8
*/