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
	// ��ʼ��parentֵ
	// ��Ĭ��ÿ���ڵ�ĸ������Լ�
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	// ��edge�߼����Ա�ֵ������������ÿ��ȡ����С��
	//sort(edge.begin(), edge.end(), cmp);
	sort(edge.begin(), edge.end(), [&](Edge& a, Edge& b)->bool {
		return a.w < b.w;
	});
	int sumval = 0;
	// ���ȡ��m����
	for (int i = 0; i < m; i++) {
		// 1.ÿ������̵ı�
		int x = find(edge[i].u);
		int y = find(edge[i].v);
		// 2.�жϲ���ͬһ����ͨ�����ż���
		if (x != y) {
			// 3.��y�ĸ��ڵ�Ϊx
			parent[x] = y;
			sumval += edge[i].w;
			cout << ("��") + to_string(i + 1) + ("�����ҵ���u:") + to_string(edge[i].u) + (",v:") + to_string(edge[i].v) + ",w:" + to_string(edge[i].w) << endl;
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


