#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Edge {
public:
	int u;
	int v;
	int w;
	Edge(){}
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
	vector<Edge> edge;
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
	edge.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
}
void KruskalCls::Kruskal() {
	// 初始化parent值
	// 先默认每个节点的父亲是自己
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	// 给edge边集合以边值排序，这样才能每次取出最小边
	//sort(edge.begin(), edge.end(), cmp);
	sort(edge.begin(), edge.end(), [&](Edge& a, Edge& b)->bool {
		return a.w < b.w;
	});
	int sumval = 0;
	// 最多取出m条边
	for (int i = 0; i < m; i++) {
		// 1.每次找最短的边
		int x = find(edge[i].u);
		int y = find(edge[i].v);
		// 2.判断不是同一个连通分量才继续
		if (x != y) {
			// 3.设y的父节点为x
			parent[x] = y;
			sumval += edge[i].w;
			cout << ("第") + to_string(i + 1) + ("条边找到：u:") + to_string(edge[i].u) + (",v:") + to_string(edge[i].v) + ",w:" + to_string(edge[i].w) << endl;
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


