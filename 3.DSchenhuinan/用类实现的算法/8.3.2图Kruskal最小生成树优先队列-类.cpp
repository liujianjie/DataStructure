#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Edge {
public:
	int u;
	int v;
	int w;
	Edge() {}
	Edge(int a, int b, int c):u(a),v(b),w(c) {}
	// 重载运算符
	// 优先队列是从大到小排列。 
	// 原本若e0(5) < e1(8)时， 成立 e0 < e1则 队列： e1(8) e0(5) 从大到小 
	// 现在是e0(8) > e1(5),	   成立 e0 < e1则 队列： e1(5) e0(8) 从小到大成功 
	bool operator<(const Edge& b)const {
		return this->w > b.w;
	}
};
class KruskalCls {
public:
	KruskalCls(int a, int b) :n(a), m(b) {
		
	};
	void Kruskal();
	void Input();
	int find(int x);
public:
	int n, m;
	vector<int> parent;
	priority_queue<Edge> edgeque;
};
bool cmp(Edge& a, Edge& b) {
	return a.w < b.w;
}
int KruskalCls::find(int x) {
	return parent[x] == x ? x : (parent[x] = find(parent[x]));
}
void KruskalCls::Input() {
	cin >> n >> m;
	parent.resize(n + 1);
	for (int i = 0; i < m; i++) {
		Edge ed;
		cin >> ed.u >> ed.v >> ed.w;
		edgeque.push(ed);
	}
}
void KruskalCls::Kruskal() {
	// 初始化parent值
	// 先默认每个节点的父亲是自己
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int sumval = 0;
	// 最多取出m条边
	for (int i = 0; i < m; i++) {
		// 1.每次找最短的边
		Edge curEdge = edgeque.top();
		edgeque.pop();
		int x = find(curEdge.u);
		int y = find(curEdge.v);
		// 2.判断不是同一个连通分量才继续
		if (x != y) {
			// 3.设y的父节点为x
			parent[x] = y;
			sumval += curEdge.w;
			cout << ("第") + to_string(i + 1) + ("条边找到：u:") + to_string(curEdge.u) + (",v:") + to_string(curEdge.v) + ",w:" + to_string(curEdge.w) << endl;
		}
	}
	cout << "路径和:" + to_string(sumval) << endl;
}
int main() {
	KruskalCls cls(6, 10);
	cls.Input();
	cls.Kruskal();
	return 0;
}
/*
6 10
1 2 6
3 1 1
1 4 5
2 3 5
2 5 3
3 4 5
3 5 6
3 6 4
4 6 2
5 6 6
	// 初始化
	for(int i = 1; i < G.vexnum; i++){
		parent[i] = i;
	} 
	int sumedge = 0; 
	Edge edge;
	int u, v;
	// 共要循环n-1次，因为找到n-1个边，就构成最小生成树了 
	for(int i = 1; i < G.vexnum - 1; ){
		edge = pri.top();
		pri.pop();
		u = edge.u;
		v = edge.v;
		if(GetParent(u) != GetParent(v)){// 是否同属一个连通分量 
			// 不是就让他们归属同一个连通分量，让u的父亲变为v. 都可以 
			parent[u] = v;
//			parent[v] = u;
			// 输出找到边 
			printf("找到%d->%d,边值是%d\n", u, v, edge.edge);
			sumedge += edge.edge;
			i++; 
		}else{
			printf("%d的父亲是%d,%d的父亲是%d\n", u, GetParent(u), v, GetParent(v));
		}
	}
	printf("共花费%d\n", sumedge);

const int n = 6, m = 10;// 顶点和边
int parent[n + 1];// 父亲节点，为了并查集
class Edge {
public:
	int u;
	int v;
	int w;
};
Edge edge[m];// 边集合，领接矩阵
// 排序函数 从小到大
bool cmp(Edge& a, Edge& b) {
	return a.w < b.w;
}
// 辅助方法，是找父亲，为了两个节点在不在同一个连通分量
int find(int x) {
	// 返回的时候更新父节点，减少高度
	return parent[x] == x ? x : (parent[x] = find(parent[x]));
}
// 主要算法
void Kural() {
	// 初始化parent值
	// 先默认每个节点的父亲是自己
	for (int i = 1; i < n + 1; i++) {
		parent[i] = i;
	}
	// 给edge边集合以边值排序，这样才能每次取出最小边
	sort(edge, edge + m, cmp);
	// 开始
	int x, y;
	int sum = 0;// 累加路径
	// 最多取出m条边
	for (int i = 0; i < m; i++) {
		// 1.每次找最短的边
		x = find(edge[i].u);
		y = find(edge[i].v);
		// 2.判断不是同一个连通分量才继续
		//cout << i << endl;
		if (x != y) {
			sum += edge[i].w;
			cout << ("第") + to_string(i + 1) + ("条边找到：u:") + to_string(edge[i].u) + (",v:") + to_string(edge[i].v) + ",w:" + to_string(edge[i].w) << endl;
			// 3.设y的父节点为x
			parent[x] = y;//
			cout << endl;
		}
	}
	cout << "路径和:" + to_string(sum) << endl;
}
*/


