#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#define MVNum 100

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
// 构建无向图
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
// 非递归的深度优先遍历
bool visited[MVNum];// 是否遍历过了
template <class T>
void DFSNoDiGui(ALGraph<T>& G, int curi) {		
	stack<int> sta;
	sta.push(curi);
	while (!sta.empty()) {
		curi = sta.top();
		sta.pop();
		if (!visited[curi]) {					  // 避免重复访问
			cout << G.vertices[curi].data << " "; // 输出当前遍历的结点
			visited[curi] = true;				  // 标记访问过
		}
		ArcNode* p = G.vertices[curi].firstarc;
		while (p != NULL) {
			int j = p->adjvex;			// j是curi的邻接点
			if (!visited[j]) {
				sta.push(j);
			}
			p = p->nextarc;				// curi的下一个边结点
		}
	}
}

void main() {
	cout << "输入无向图的数据：" << endl;
	ALGraph<int> G;
	CreateUnDirectedGraph(G);
	cout << "从顶点3开始的深度优先遍历：" << endl;
	DFSNoDiGui(G, 3); // 从3号顶点3开始出发
}
/*
图1
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

图2
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
