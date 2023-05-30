#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#define MVNum 100

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
// ��������ͼ
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
// �ǵݹ��������ȱ���
bool visited[MVNum];// �Ƿ��������
template <class T>
void DFSNoDiGui(ALGraph<T>& G, int curi) {		
	stack<int> sta;
	sta.push(curi);
	while (!sta.empty()) {
		curi = sta.top();
		sta.pop();
		if (!visited[curi]) {					  // �����ظ�����
			cout << G.vertices[curi].data << " "; // �����ǰ�����Ľ��
			visited[curi] = true;				  // ��Ƿ��ʹ�
		}
		ArcNode* p = G.vertices[curi].firstarc;
		while (p != NULL) {
			int j = p->adjvex;			// j��curi���ڽӵ�
			if (!visited[j]) {
				sta.push(j);
			}
			p = p->nextarc;				// curi����һ���߽��
		}
	}
}

void main() {
	cout << "��������ͼ�����ݣ�" << endl;
	ALGraph<int> G;
	CreateUnDirectedGraph(G);
	cout << "�Ӷ���3��ʼ��������ȱ�����" << endl;
	DFSNoDiGui(G, 3); // ��3�Ŷ���3��ʼ����
}
/*
ͼ1
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

ͼ2
6 8
1 2 3 4 5 6
1 2
1 3
2 6
3 5
3 4
3 6
4 5
4 6
*/
