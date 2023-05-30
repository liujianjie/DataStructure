#include <iostream>
#include <queue>
using namespace std;
#define MVNum 100
typedef struct ArcNode {// 边表结点
	int adjvex;
	struct ArcNode* nextarc;
}ArcNode;

typedef struct Vnode { // 顶点表结点
	int data;
	ArcNode* firstarc;
}VNode, AdjList[MVNum];

typedef struct {//	邻接表
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;
// 构建6.32有向图
void CreateDirectedGraph(ALGraph& G) {
	cin >> G.vexnum >> G.arcnum;			// 输入顶点数、边数
	for (int i = 1; i <= G.vexnum; i++) {// 输入各点，构造表头结点表:注意这里从1开始，是因为这里认为顶点序号从1开始
		cin >> G.vertices[i].data;		// 输入顶点值 
		G.vertices[i].firstarc = NULL;  // 初始化表头结点的指针域为NULL
	}
	int v1, v2;
	for (int k = 0; k < G.arcnum; k++) {
		cin >> v1 >> v2;					// 输入一条边的两个结点, v1 指向 v2
		ArcNode* p1 = new ArcNode;		// 生成新的边结点
		p1->adjvex = v2;					// 邻接点序号为v2
		p1->nextarc = G.vertices[v1].firstarc;
		G.vertices[v1].firstarc = p1; // 将新结点*p1插入顶点v1的边表头部
	}
}
bool visited[MVNum];// 是否检查过了
// 深度优先遍历算法
void DFS(ALGraph& G, int curi) {
	cout << curi; // 输入当前遍历的结点
	visited[curi] = true;
	ArcNode* p = G.vertices[curi].firstarc;
	while (p != NULL) {
		int j = p->adjvex; // j是curi的邻接点
		if (!visited[j]) {
			DFS(G, j);	   // 以邻接点j为起始点继续遍历
		}
		p = p->nextarc;    // curi的下一个边表结点
	}
}
bool visited2[MVNum];// 是否检查过了
// 广度优先遍历算法
void BFS(ALGraph& G, int curi) {
	queue<int> que;
	cout << curi;							// 输出开始顶点
	visited2[curi] = true;					// 标记开始顶点访问过
	que.push(curi);							// 添加开始顶点
	while (!que.empty()) {					// 不为空
		curi = que.front();					// 当前队头的顶点
		que.pop();							// 弹出队头
		ArcNode* p = G.vertices[curi].firstarc;// 得到当前顶点的顶点表结点，由顶点表结点再得到边表结点
		while (p != NULL) {					// 压入当前顶点的所有没有访问过的边表结点的顶点
			if (!visited2[p->adjvex]) {
				// 注意：BFS是在这里输出并且标记访问过的
				cout << p->adjvex;			// 输出访问到的邻接顶点
				visited2[p->adjvex] = true; // 标记邻接顶点访问过
				que.push(p->adjvex);			// 压入邻接顶点，作为下次的开始顶点
			}
			p = p->nextarc;					// curi的下一个边表结点
		}
	}
}
void main() {
	ALGraph G;
	CreateDirectedGraph(G);
	DFS(G, 3); // 从3开始出发
	cout << endl;
	BFS(G, 3); // 从3开始出发
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