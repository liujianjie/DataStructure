#include <iostream>
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
	}
	return true;
}
// Prim-��С������
struct {
	VerTexType adjvex;
	ArcType lowcost;
}closedge[MVNum];
// �����������ҳ�closeedge����С�ıߣ����ض����±�
int Min(AMGraph& G) {
	int max = MaxInt, idx = -1;
	for (int i = 1; i <= G.vexnum; i++) {
		if (closedge[i].lowcost != -1 && closedge[i].lowcost < max) {
			max = closedge[i].lowcost;
			idx = i;
		}
	}
	return idx;
}

void Prim(AMGraph& G, VerTexType u) {
	int k = LocateVex(G, u);
	for (int j = 1; j <= G.vexnum; j++) {
		if (j != k) {
			closedge[j] = { u, G.arcs[k][j] };
		}
	}
	VerTexType u0, v0;
	closedge[k].lowcost = 0;
	for (int i = 1; i <= G.vexnum; i++) {
		k = Min(G);
		if (k == -1) return; // û�ҵ���С�ıߵĵ��±꣬�����˳�
		u0 = closedge[k].adjvex;
		v0 = G.vexs[k];
		cout << u0 << "->" << v0 << ":" << closedge[k].lowcost << " ";
		closedge[k].lowcost = -1;		// ���ʹ��ˣ���Ϊ-1��
		for (int j = 1; j <= G.vexnum; j++) {
			if (G.arcs[k][j] < closedge[j].lowcost) {// ��ɢ�㵽�µ�ľ��� < �µ㵽�������ľ���
				closedge[j] = { G.vexs[k], G.arcs[k][j] }; // �µ㵽����������=��ɢ�㵽�µ�ľ���
			}
		}
	}
}

int main() {
	AMGraph G;
	CreateUDN(G);
	Prim(G, "v1");	// ��v1�������

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