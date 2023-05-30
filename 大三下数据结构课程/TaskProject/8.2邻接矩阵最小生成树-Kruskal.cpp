#include <iostream>
#include <algorithm>
using namespace std;
#define MaxInt 32767
#define MVNum 100
typedef string VerTexType;
typedef int ArcType;

// �ڽӾ���
typedef struct {
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum, arcnum;
}AMGraph;

// Krusal �㷨�Ľṹ
struct  Edge {
	VerTexType Head;
	VerTexType Tail;
	ArcType lowcost;
}Edges[MVNum];

// ����������ͨ������ֵ���Ҷ�����ͼG�е�λ��
int LocateVex(AMGraph& G, VerTexType v) {
	for (int i = 1; i <= G.vexnum; i++) {
		if (G.vexs[i] == v) {
			return i;
		}
	}
	return 0;
}
// ��ʼ���ڽӾ���
bool CreateUDN(AMGraph& G) {
	cin >> G.vexnum >> G.arcnum;
	for (int i = 1; i <= G.vexnum; i++) {
		cin >> G.vexs[i];
	}
	for (int i = 1; i <= G.vexnum; i++) {
		for (int j = 0; j <= G.vexnum; j++) {
			G.arcs[i][j] = MaxInt;
		}
	}
	VerTexType v1, v2;
	ArcType	w;
	int i, j;
	for (int k = 1; k <= G.arcnum; k++) {
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = w;
		//G.arcs[j][i] = w; // ͼ6.10������ͼ
		Edges[k] = { v1, v2, w}; // �����
	}
	return true;
}
// ������ ��С����
bool cmp(Edge &a, Edge& b) {
	return a.lowcost < b.lowcost;
}
// Kruskal-��С������
int Vexset[MVNum];
void Kruskal(AMGraph& G) {
	// ��algorithm��sort������������飬1~arnum+1
	sort(Edges, Edges + G.arcnum + 1, cmp);
	// ��ʼ����ͨ��������
	for (int i = 1; i <= G.vexnum; i++) {
		Vexset[i] = i;
	}
	int v1, v2;
	for (int i = 1; i <= G.arcnum; i++) {
		v1 = LocateVex(G, Edges[i].Head);
		v2 = LocateVex(G, Edges[i].Tail);
		if (Vexset[v1] != Vexset[v2]) { // ��������Ķ����Ƿ���ͬһ����ͨ����
			cout << Edges[i].Head << "->" << Edges[i].Tail << ":" << Edges[i].lowcost << " ";
			// �ϲ�������������v2����ͨ����������������v1����ͨ�����ϣ�
			for (int j = 1; j <= G.vexnum; j++) {
				if (Vexset[j] == Vexset[v2]) {
					Vexset[j] = Vexset[v1];
				}
			}
		}
	}
}
int main() {
	AMGraph G;
	CreateUDN(G);
	//const int edgesize = G.arcnum;
	Kruskal(G);

	return 0;
}
/*
6 10
v1 v2 v3 v4 v5 v6
v1 v2 5
v1 v4 7
v2 v3 4
v3 v1 8
v3 v6 9
v4 v6 6
v4 v3 5
v5 v4 5
v6 v1 3
v6 v5 1

*/