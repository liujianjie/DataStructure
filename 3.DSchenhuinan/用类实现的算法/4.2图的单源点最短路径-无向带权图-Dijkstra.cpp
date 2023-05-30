#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXVALUE = 2 << 28;
class Edge {
public:
	int u;
	int v;
	int w;
	Edge() {}
};
class DijkstraCls {
public:
	void Dijkstra(int sourceu);
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
void DijkstraCls::Input() {
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
		//edge[v][u] = w;
	}
}
void DijkstraCls::Dijkstra(int sourceu) {
	for (int i = 1; i <= n; i++) {
		isvisit[i] = false;
		path[i] = sourceu; // ����Ĭ��Ϊ�Լ��������Ĭ��Ϊԭ��
		if (edge[sourceu][i] == 0) {
			lowcost[i] = MAXVALUE;
		}
		else {
			lowcost[i] = edge[sourceu][i];
		}
	}
	lowcost[sourceu] = 0;
	path[sourceu] = -1; // ԭ�㿪ʼ
	int sum = 0;
	int minv, minval;
	for (int z = 1; z < n; z++) {// n - 1�� ����,��Ϊn-1ʱ�Ѿ���¼��lowcost��primҪn�Σ���ΪҪͳ��·��
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
			cout << "ʧ��" << endl;
			break;
		}
		//cout << minv << endl;
		isvisit[minv] = true;
		sum += minval;
		for (int i = 1; i <= n; i++) {
			if (!isvisit[i] && edge[minv][i] != 0) {
				if (lowcost[minv] + edge[minv][i] < lowcost[i]) { // ��lowcost[minv] д���lowcost[i]
					lowcost[i] = lowcost[minv] + edge[minv][i];
					path[i] = minv;
				}
			}
		}
	}
	cout << "·���ܺͣ�" << sum << endl;
}
void DijkstraCls::PrintPath(int u) {
	if (path[u] == -1) {
		cout << "·����" << u << "->";
	}
	else {
		PrintPath(path[u]);
		cout << u << "->";
	}
}
int main() {
	//cout << MAXVALUE << endl;
	DijkstraCls cls;
	cls.Input();
	int sourcePoint = 1;
	cls.Dijkstra(sourcePoint);
	// ��ӡ·��
	for (int i = 1; i <= cls.n; i++) {
		if (sourcePoint != i) {
			cout << "���ɵ㣺" << i << "����:"<< cls.lowcost[i] << ",·���ǣ�";
			cls.PrintPath(i);
			cout << endl;
		}
	}
	return 0;
}
/*
6 8
1 2 2
1 3 1
2 6 6
3 4 2
3 5 10
3 6 2
4 5 3
4 6 1

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


