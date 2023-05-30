#include <iostream>
using namespace std;
#define MaxInt 32767
#define MVNum 100
typedef string VerTexType;
typedef int ArcType;
// 邻接矩阵
typedef struct {
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum, arcnum;
}AMGraph;

// 辅助函数，通过顶点值查找顶点在图G中的位置
int LocateVex(AMGraph& G, VerTexType v) {
	for (int i = 1; i <= G.vexnum; i++) {
		if (G.vexs[i] == v) {
			return i;
		}
	}
	return 0;
}
// 初始化邻接矩阵
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
		//G.arcs[j][i] = w; // 图6.10是有向图
	}
	return true;
}
// Prim-最小生成树
struct {
	VerTexType adjvex;
	ArcType lowcost;
}closedge[MVNum];
// 辅助函数，找出closeedge中最小的边，返回顶点下标
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
		if (k == -1) return; // 没找到最小的边的点下标，可以退出
		u0 = closedge[k].adjvex;
		v0 = G.vexs[k];
		cout << u0 << "->" << v0 << ":" << closedge[k].lowcost << " ";
		closedge[k].lowcost = -1;		// 访问过了，置为-1，
		for (int j = 1; j <= G.vexnum; j++) {
			if (G.arcs[k][j] < closedge[j].lowcost) {// 扩散点到新点的距离 < 新点到生成树的距离
				closedge[j] = { G.vexs[k], G.arcs[k][j] }; // 新点到生成树距离=扩散点到新点的距离
			}
		}
	}
}

int main() {
	AMGraph G;
	CreateUDN(G);
	Prim(G, "v1");	// 从v1顶点出发

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