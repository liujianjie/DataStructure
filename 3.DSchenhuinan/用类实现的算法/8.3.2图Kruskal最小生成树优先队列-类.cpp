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
	// ���������
	// ���ȶ����ǴӴ�С���С� 
	// ԭ����e0(5) < e1(8)ʱ�� ���� e0 < e1�� ���У� e1(8) e0(5) �Ӵ�С 
	// ������e0(8) > e1(5),	   ���� e0 < e1�� ���У� e1(5) e0(8) ��С����ɹ� 
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
	// ��ʼ��parentֵ
	// ��Ĭ��ÿ���ڵ�ĸ������Լ�
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int sumval = 0;
	// ���ȡ��m����
	for (int i = 0; i < m; i++) {
		// 1.ÿ������̵ı�
		Edge curEdge = edgeque.top();
		edgeque.pop();
		int x = find(curEdge.u);
		int y = find(curEdge.v);
		// 2.�жϲ���ͬһ����ͨ�����ż���
		if (x != y) {
			// 3.��y�ĸ��ڵ�Ϊx
			parent[x] = y;
			sumval += curEdge.w;
			cout << ("��") + to_string(i + 1) + ("�����ҵ���u:") + to_string(curEdge.u) + (",v:") + to_string(curEdge.v) + ",w:" + to_string(curEdge.w) << endl;
		}
	}
	cout << "·����:" + to_string(sumval) << endl;
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
	// ��ʼ��
	for(int i = 1; i < G.vexnum; i++){
		parent[i] = i;
	} 
	int sumedge = 0; 
	Edge edge;
	int u, v;
	// ��Ҫѭ��n-1�Σ���Ϊ�ҵ�n-1���ߣ��͹�����С�������� 
	for(int i = 1; i < G.vexnum - 1; ){
		edge = pri.top();
		pri.pop();
		u = edge.u;
		v = edge.v;
		if(GetParent(u) != GetParent(v)){// �Ƿ�ͬ��һ����ͨ���� 
			// ���Ǿ������ǹ���ͬһ����ͨ��������u�ĸ��ױ�Ϊv. ������ 
			parent[u] = v;
//			parent[v] = u;
			// ����ҵ��� 
			printf("�ҵ�%d->%d,��ֵ��%d\n", u, v, edge.edge);
			sumedge += edge.edge;
			i++; 
		}else{
			printf("%d�ĸ�����%d,%d�ĸ�����%d\n", u, GetParent(u), v, GetParent(v));
		}
	}
	printf("������%d\n", sumedge);

const int n = 6, m = 10;// ����ͱ�
int parent[n + 1];// ���׽ڵ㣬Ϊ�˲��鼯
class Edge {
public:
	int u;
	int v;
	int w;
};
Edge edge[m];// �߼��ϣ���Ӿ���
// ������ ��С����
bool cmp(Edge& a, Edge& b) {
	return a.w < b.w;
}
// �������������Ҹ��ף�Ϊ�������ڵ��ڲ���ͬһ����ͨ����
int find(int x) {
	// ���ص�ʱ����¸��ڵ㣬���ٸ߶�
	return parent[x] == x ? x : (parent[x] = find(parent[x]));
}
// ��Ҫ�㷨
void Kural() {
	// ��ʼ��parentֵ
	// ��Ĭ��ÿ���ڵ�ĸ������Լ�
	for (int i = 1; i < n + 1; i++) {
		parent[i] = i;
	}
	// ��edge�߼����Ա�ֵ������������ÿ��ȡ����С��
	sort(edge, edge + m, cmp);
	// ��ʼ
	int x, y;
	int sum = 0;// �ۼ�·��
	// ���ȡ��m����
	for (int i = 0; i < m; i++) {
		// 1.ÿ������̵ı�
		x = find(edge[i].u);
		y = find(edge[i].v);
		// 2.�жϲ���ͬһ����ͨ�����ż���
		//cout << i << endl;
		if (x != y) {
			sum += edge[i].w;
			cout << ("��") + to_string(i + 1) + ("�����ҵ���u:") + to_string(edge[i].u) + (",v:") + to_string(edge[i].v) + ",w:" + to_string(edge[i].w) << endl;
			// 3.��y�ĸ��ڵ�Ϊx
			parent[x] = y;//
			cout << endl;
		}
	}
	cout << "·����:" + to_string(sum) << endl;
}
*/


