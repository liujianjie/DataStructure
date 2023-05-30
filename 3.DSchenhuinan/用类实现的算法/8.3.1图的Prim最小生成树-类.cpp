 #include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXVALUE = 2 << 29;
class Edge {
public:
	int u;
	int v;
	int w;
	Edge() {}
};
class PrimCls {
public:
	void Prim(int sourceu);
	void Input();
	void PrintPath(int u);
public:
	int n, m;
	vector<vector<int>> edge;
	vector<int> isvisit;
	vector<int> lowcost;
	vector<int> path;
};
bool cmp(Edge& a, Edge& b) {
	return a.w < b.w;
}
void PrimCls::Input() {
	cin >> n >> m;
	edge.resize(n + 1);
	for (int i = 0; i < edge.size(); i++) {
		edge[i].resize(n + 1);
	}
	isvisit.resize(n + 1);
	lowcost.resize(n + 1);
	path.resize(n + 1);
	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		edge[u][v] = w;
		edge[v][u] = w;
	}
}
void PrimCls::Prim(int sourceu) {
	for (int i = 1; i <= n; i++) {
		isvisit[i] = false;
		if (edge[sourceu][i] == 0) {
			lowcost[i] = MAXVALUE;
		}
		else {
			lowcost[i] = edge[sourceu][i];
		}
		//path[i] = -1;
		path[i] = sourceu; // 不记得为啥要设置为出发点？？，因为比如这，第一次更新后的lowcost数组中最小的没有初始化的1 3 1,并没有经过第一次更新lowcost设置了path！默认是从原点出发
	}
	lowcost[sourceu] = 0; 
	path[sourceu] = -1;
	int sum = 0;
	int minv, minval;
	for (int z = 1; z <= n; z++) {
		minv = -1, minval = MAXVALUE;
		for (int i = 1; i <= n; i++) {
			if (!isvisit[i]) {
				if (lowcost[i] < minval) {
					minval = lowcost[i];
					minv = i;
				}
			}
		}
		if (minv == -1) {
			cout << "失败" << endl;
			return;
		}
		cout << minv << endl;
		isvisit[minv] = true;
		sum += minval;
		for (int i = 1; i <= n; i++) {
			if (!isvisit[i] && edge[minv][i] != 0) {
				if (edge[minv][i] < lowcost[i]) {
					lowcost[i] = edge[minv][i];
					path[i] = minv;
				}
			}
		}
	}
	cout << "路径总和：" << sum << endl;
}
void PrimCls::PrintPath(int u) {
	if (path[u] == -1) {
		cout << "路径：" << u << "->";
	}
	else {
		PrintPath(path[u]);
		cout << u << "->";
	}
}
int main() {
	//cout << MAXVALUE << endl;
	PrimCls cls;
	cls.Input();
	int sourcePoint = 1;
	cls.Prim(sourcePoint);
	// 打印路径
	for (int i = 1; i <= cls.n; i++) {
		if (sourcePoint != i) {
			cout << "生成点：" << i << "的路径是：";
			cls.PrintPath(i);
			cout << endl;
		}
	}
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
*/


