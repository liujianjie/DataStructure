#include <stdio.h> 
#include <iostream>
#include <queue>
#define MaxVertexNum 15
#define MaxValue 1000000

using namespace std;
//typedef struct{
//	int data;		// 数据 
//}Vertex; 
typedef int Vertex;
typedef struct{
	Vertex vex[MaxVertexNum]; 			  // 顶点表
	int edge[MaxVertexNum][MaxVertexNum];// 邻接矩阵 
	int vexnum, arcnum; // 图的当前顶点数和弧数 
}MGraph;
// 保存每条边的信息
typedef struct Edge{
	Vertex u;// 源点
	Vertex v;// 终点
	int edge;// 边值
	// 重载运算符
	// 优先队列是从大到小排列。 
	// 原本若e0(5) < e1(8)时， 成立 e0 < e1则 队列： e1(8) e0(5) 从大到小 
	// 现在是e0(8) > e1(5),	   成立 e0 < e1则 队列： e1(5) e0(8) 从小到大成功 
	bool operator<(const Edge &e1) const{
		return edge > e1.edge;
	}
}Edge; 

void InitGraph(MGraph &G);
bool Adjacent(MGraph &G, int x, int y);
void Neighbors(MGraph &G, int x) ;
bool InsertVertex(MGraph &G, Vertex x);
bool DeleteVertex(MGraph &G, Vertex x);
bool AddEdge(MGraph &G, int x, int y);
bool AddEdgeAndValue(MGraph &G, int x, int y, int v);
bool RemoveEdge(MGraph &G, int x, int y);
int FirstNeighbor(MGraph &G, int x);
int NextNeighbor(MGraph &G, int x, int y);
int Get_edge_value(MGraph &G, int x, int y);
bool Set_edge_value(MGraph &G, int x, int y, int v);
void PrintG(MGraph &G);



int parent[MaxVertexNum];// parent[i] = j; 代表顶点i的父亲j，初始化为自己是自己父亲 
// 找父亲 
int GetParent(int v){// 参数是顶点 
	/*
	1.自己的父亲是自己的话，就返回自己
	2.自己的父亲不是自己的话，找到并返回自己的父亲的父亲，同时在找到的时候把自己的父亲也更新为父亲的父亲 
	*/ 
	return parent[v] == v ?v : (parent[v] = GetParent(parent[v]));
} 

// Kruskal算法
void Kruskal(MGraph &G, priority_queue<Edge> &pri){ 
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
}


int main(){
	MGraph G;
	InitGraph(G);
	Vertex v0 = {0};// 这个节点不使用 
	
	Vertex v1 = {1};
	Vertex v2 = {2};
	Vertex v3 = {3};
	Vertex v4 = {4};
	Vertex v5 = {5};
	Vertex v6 = {6};
	
	InsertVertex(G, v0);
	InsertVertex(G, v1);
	InsertVertex(G, v2);
	InsertVertex(G, v3);
	InsertVertex(G, v4);
	InsertVertex(G, v5);
	InsertVertex(G, v6);
	
	AddEdgeAndValue(G, 1, 2, 6);
	AddEdgeAndValue(G, 1, 3, 1);
	AddEdgeAndValue(G, 1, 4, 5);
	AddEdgeAndValue(G, 2, 3, 5);
	AddEdgeAndValue(G, 2, 5, 3);
	AddEdgeAndValue(G, 3, 4, 5);
	AddEdgeAndValue(G, 3, 5, 6);
	AddEdgeAndValue(G, 3, 6, 4);
	AddEdgeAndValue(G, 4, 6, 2);
	AddEdgeAndValue(G, 5, 6, 6);
	
	Edge e1 = {1, 2, 6};
	Edge e2 = {1, 3, 1};
	Edge e3 = {1, 4, 5};
	Edge e4 = {2, 3, 5};
	Edge e5 = {2, 5, 3};
	Edge e6 = {3, 4, 4};
	Edge e7 = {3, 5, 6};
	Edge e8 = {3, 6, 4};
	Edge e9 = {4, 6, 2};
	Edge e10 = {5, 6, 6};
	
	PrintG(G);
	
	priority_queue<Edge> pri;
	pri.push(e1);
	pri.push(e2);
	pri.push(e3);
	pri.push(e4);
	pri.push(e5);
	pri.push(e6);
	pri.push(e7);
	pri.push(e8);
	pri.push(e9);
	pri.push(e10);
	// Kruskal  
	Kruskal(G, pri);// 从1开始
	
	// 测试优先队列
//	Edge et1 = pri.top();
//	printf("%d%d%d",et1.u, et1.v, et1.edge);
	
	return 0;
}


// 0. 初始化
void InitGraph(MGraph &G){
	for(int i = 0; i < MaxVertexNum; i++){
		for(int j = 0; j < MaxVertexNum; j++){
			G.edge[i][j] = 0;
		}
	}
	G.vexnum = 0;
	G.arcnum = 0;
} 
// 1.判断图G是否存在边(x,y)
bool Adjacent(MGraph &G, int x, int y){
	if(G.edge[x][y] == 0){
		return false;
	}
	return true;// 存在 
}
// 2.列出图G中与结点x邻接的边
void Neighbors(MGraph &G, int x) {
	for(int i = 0; i < MaxVertexNum; i++){
		if(G.edge[x][i] != 0){
			printf("(%d, %d)\t", x, i);
		}
	}
}
// 3. 在图G中插入顶点x
bool InsertVertex(MGraph &G, Vertex x){
	// 顶点数是否满了
	if(G.vexnum >= MaxVertexNum){
		return false;
	} 
	// 放入到顶点数组中
	G.vex[G.vexnum] = x;
	// 图G开辟。。
	
	// 顶点数+1
	G.vexnum++;
	return true; 
} 
// 4.在图G中删除顶点x
bool DeleteVertex(MGraph &G, Vertex x){
	// 1.现在顶点数组中，置空 false 
	int pos;
	for(int i = 0; i < G.vexnum; i++){
		if(x == G.vex[i]){
			pos = i;
			break;
		}
	}
	// 2.在图中的i行和j列为0 
	for(int i = 0; i < G.vexnum; i++){
		G.edge[pos][i] = 0;
		G.edge[i][pos] = 0;
		G.arcnum--;
	}
	//G.vexnum--;// 顶点数 不用减不是真正的删除 
}
// 5.若无向边(x,y)不存在，再图中加入
bool AddEdge(MGraph &G, int x, int y){
	if(G.edge[x][y] == 0){
		G.edge[x][y] = 1;
		G.edge[y][x] = 1;
		G.arcnum++;
		return true;
	}
	return false;
} 
//  5.若无向边(x,y)不存在，再图中加入，并且设置边值 
bool AddEdgeAndValue(MGraph &G, int x, int y, int v){
	if(G.edge[x][y] == 0){
		G.edge[x][y] = v;
		G.edge[y][x] = v;
		G.arcnum++;
		return true;
	}
	return false;
} 
// 6.无向边(x,y)存在，在图中删除
bool RemoveEdge(MGraph &G, int x, int y){
	if(G.edge[x][y] != 0){
		G.edge[x][y] = 0;
		G.edge[y][x] = 0;
		G.arcnum--;
		return true;
	}
	return false;
}
// 7.求图中顶点x的第一个邻接点，若有返回顶点号，若图中没有x或顶点不存在x，返回-1
int FirstNeighbor(MGraph &G, int x){
	for(int i = 0; i < G.vexnum; i++){
		if(G.edge[x][i] != 0){
			return i;
		}
	}
	return -1;
} 
// 8.求图中顶点x的第一个邻接点y的下一个邻接点(假设y是x的第一个邻接点），若有返回顶点号，若图中没有x或顶点不存在x，或y是x的最后一个邻接点，返回-1
int NextNeighbor(MGraph &G, int x, int y){
	for(int i = 0; i < G.vexnum; i++){
		if(G.edge[x][i] != 0 && i > y){
			return i;
		}
	}
	return -1;
} 
// 9.获取图G中边(x,y)对应的权值
int Get_edge_value(MGraph &G, int x, int y){
	return G.edge[x][y];
} 
// 10.设置图G中边(x,y)对应的权值
bool Set_edge_value(MGraph &G, int x, int y, int v){
	return G.edge[x][y] = v;
} 


// 辅助
// 1.遍历图的边值
void PrintG(MGraph &G){
	printf("顶点数：%d\t边数:%d\n", G.vexnum, G.arcnum);
	for(int i = 0; i < G.vexnum; i++){
		for(int j = 0; j < G.vexnum; j++){
			printf("%d\t",G.edge[i][j]);
		}
		printf("\n");
	}
	printf("\n");
} 
