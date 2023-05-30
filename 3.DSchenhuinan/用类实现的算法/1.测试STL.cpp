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
	Edge(int a, int b, int c) :u(a), v(b), w(c) {}
	// ���������
	// ���ȶ����ǴӴ�С���С� 
	// ԭ����e0(5) < e1(8)ʱ�� ���� e0 < e1�� ���У� e1(8) e0(5) �Ӵ�С 
	// ������e0(8) > e1(5),	   ���� e0 < e1�� ���У� e1(5) e0(8) ��С����ɹ� 
	bool operator<(const Edge& b)const {
		return this->w > b.w;
	}
};

int main() {
	//stack<int>::size_type size = stk.size();
	cout << "stack" << endl;
	stack<int> stk;
	stk.push(2);
	int size = stk.size();
	cout << size << endl;

	cout << "vector" << endl;
	vector<Edge> edges;
	edges.push_back(Edge(1, 2, 10));
	edges.push_back(Edge(1, 2, 20));
	edges.push_back(Edge(1, 2, 15));
	size = edges.size();

	sort(edges.rbegin(), edges.rend());

	cout << size << endl;
	for (int i = 0; i < size; i++) {
		cout << edges[i].w << endl;
	}

	cout << "queue" << endl;
	queue<Edge> que;
	que.push(Edge(1, 2, 10));
	que.push(Edge(2, 3, 20));
	que.push(Edge(4, 5, 15));
	size = que.size();
	for (int i = 0; i < size; i++) {
		cout << ((Edge)que.front()).w << endl;
		que.pop();
	}

	cout << "priority_queue" << endl;
	priority_queue<Edge> priEdge;
	priEdge.push(Edge(1, 2, 10));
	priEdge.push(Edge(1, 2, 20));
	priEdge.push(Edge(1, 2, 15));
	size = priEdge.size();
	for (int i = 0; i < size; i++) {
		cout << ((Edge)priEdge.top()).w << endl;
		priEdge.pop();
	}
	return 0;
}

