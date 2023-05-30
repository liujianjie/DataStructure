#include <iostream>
#include <queue>
using namespace std;
#define MVNum 100
// 使用模板是因为6.32与6.33图的顶点值不同

typedef struct ArcNode {// 边表结点
	int adjvex;			// 所指向的顶点位置(序号）
	struct ArcNode* nextarc;
}ArcNode;
template <class T>
struct Vnode { // 顶点表结点
	T data;
	ArcNode* firstarc;
};
template <class T>
struct ALGraph {//	邻接表
	Vnode<T> vertices[MVNum];
	int vexnum, arcnum;
};
// 输入顶点值和初始化表头结点
template <class T>
void InputVertexValAndInit(ALGraph<T>& G) {
	cin >> G.vexnum >> G.arcnum;			// 输入顶点数、边数
	for (int i = 1; i <= G.vexnum; i++) {// 输入各点，构造表头结点表:注意这里从1开始，是因为这里认为顶点序号从1开始
		cin >> G.vertices[i].data;		// 输入顶点值 
		G.vertices[i].firstarc = NULL;  // 初始化表头结点的指针域为NULL
	}
}
// 构建6.32有向图
template <class T>
void CreateDirectedGraph(ALGraph<T>& G) {
	InputVertexValAndInit(G);
	int v1, v2;
	for (int k = 0; k < G.arcnum; k++) {
		cin >> v1 >> v2;					// 输入一条边的两个结点, v1 指向 v2
		ArcNode* p1 = new ArcNode;		// 生成新的边结点
		p1->adjvex = v2;					// 邻接点序号为v2
		p1->nextarc = G.vertices[v1].firstarc;
		G.vertices[v1].firstarc = p1;	// 将新结点*p1插入顶点v1的边表头部
	}
}
// 构建6.33无向图
template <class T>
void CreateUnDirectedGraph(ALGraph<T>& G) {
	InputVertexValAndInit(G);
	int v1, v2;
	for (int k = 0; k < G.arcnum; k++) {
		cin >> v1 >> v2;					// 输入一条边的两个结点, v1 指向 v2
		ArcNode* p1 = new ArcNode;		// 生成新的边结点
		p1->adjvex = v2;					// 邻接点序号为v2
		p1->nextarc = G.vertices[v1].firstarc;
		G.vertices[v1].firstarc = p1;	// 将新结点*p1插入顶点v1的边表头部
		ArcNode* p2 = new ArcNode;		// 生成一个对称的新的边结点
		p2->adjvex = v1;					// 邻接点序号为v2
		p2->nextarc = G.vertices[v2].firstarc;
		G.vertices[v2].firstarc = p2; // 将新结点*p2插入顶点v2的边表头部
	}
}
bool visited[MVNum];// 是否检查过了
template <class T>
// 深度优先遍历算法
void DFS(ALGraph<T>& G, int curi) {
	cout << G.vertices[curi].data << " "; // 输出当前遍历的结点
	visited[curi] = true;
	ArcNode* p = G.vertices[curi].firstarc;
	while (p != NULL) {
		int j = p->adjvex;			// j是curi的邻接点
		if (!visited[j]) {
			DFS(G, j);				// 以邻接点j为起始点继续遍历
		}
		p = p->nextarc;				// curi的下一个边结点
	}
}
bool visited2[MVNum];// 是否检查过了

// 广度优先遍历算法
template <class T>
void BFS(ALGraph<T>& G, int curi) {
	queue<int> que;
	cout << G.vertices[curi].data << " ";	// 输出开始顶点
	visited2[curi] = true;					// 标记开始顶点访问过
	que.push(curi);							// 添加开始顶点
	while (!que.empty()) {					// 不为空
		curi = que.front();					// 当前队头的顶点
		que.pop();							// 弹出队头
		ArcNode* p = G.vertices[curi].firstarc;// 得到当前顶点的顶点表结点，由顶点表结点再得到边表结点
		while (p != NULL) {					// 压入当前顶点的所有没有访问过的边表结点的顶点
			if (!visited2[p->adjvex]) {
				// 注意：BFS是在这里输出并且标记访问过的
				cout << G.vertices[p->adjvex].data << " ";// 输出访问到的邻接顶点
				visited2[p->adjvex] = true; // 标记邻接顶点访问过
				que.push(p->adjvex);			// 压入邻接顶点，作为下次的开始顶点
			}
			p = p->nextarc;					// curi的下一个边表结点
		}
	}
}
void main() {

	cout << "输入有向图(6.32)的数据：" << endl;
	ALGraph<int> G;
	CreateDirectedGraph(G);
	//cout << "有向图(6.32)的数据输入结束：" << endl;
	cout << "有向图(6.32)的深度优先遍历：" << endl;
	DFS(G, 3); // 从3号顶点3开始出发

	cout << endl << endl;

	cout << "输入无向图(6.33)的数据：" << endl;
	ALGraph<char> G2;
	CreateUnDirectedGraph(G2);
	cout << "无向图(6.33)的广度优先遍历：" << endl;
	BFS(G2, 1); // 从1号顶点a开始出发
}
/*
6.32有向图的数据
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

6.33无向图的数据
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