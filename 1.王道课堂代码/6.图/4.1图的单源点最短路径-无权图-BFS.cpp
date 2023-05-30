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


int path[MaxVertexNum];// 路径
bool isvisit[MaxVertexNum];// 是否访问过 
int dist[MaxVertexNum];// 单源点路径 dist[i]=j,源点到i点的最短路径j 
// BFS算法 
void BFS(MGraph &G, Vertex sourceu){ 
	// 初始化路径为-1，为了方便打印递归
	for(int i = 1; i < MaxVertexNum; i++){
		path[i] = -1;
	} 
	queue<Vertex> que;
	que.push(sourceu);
	isvisit[sourceu] = true;// 标记访问过 
	Vertex ver;
	while(!que.empty()){
		ver = que.front();
		que.pop();
		printf("%d\t", ver);// 访问这个顶点
		// 这个点的邻接点
		for(int i = 1; i < G.vexnum; i++){
			// 没有访问过 并且有路径 
			if(!isvisit[i] && G.edge[ver][i] != 0){
				// 记录路径。源点到i点的路径=源点到这个扩散点的路径 + 1 
				dist[i] = dist[ver] + 1;
				path[i] = ver;// 记录路径 
				// 标记访问过
				isvisit[i] = true;// 以免它点继续访问 这个点 
				// 入队列 ，先访问到这个点就入队，先来先进队列 
				que.push(i);
			}
		} 
	}
}
// 打印路径 
void PrintPath(int v){
	// 是否达到源点 ，看父亲是否-1 
	if(path[v] == -1){
		printf("%d->", v);
		return;
	}else{
		PrintPath(path[v]);// 往上找上一点过来
		printf("%d->", v);
	}
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
	Vertex v7 = {7};
	Vertex v8 = {8};
	
	InsertVertex(G, v0);
	InsertVertex(G, v1);
	InsertVertex(G, v2);
	InsertVertex(G, v3);
	InsertVertex(G, v4);
	InsertVertex(G, v5);
	InsertVertex(G, v6);
	InsertVertex(G, v7);
	InsertVertex(G, v8);
	
	AddEdgeAndValue(G, 1, 2, 1);
	AddEdgeAndValue(G, 1, 5, 1);
	AddEdgeAndValue(G, 2, 6, 1);
	AddEdgeAndValue(G, 3, 4, 1);
	AddEdgeAndValue(G, 3, 7, 1);
	AddEdgeAndValue(G, 4, 7, 1);
	AddEdgeAndValue(G, 4, 8, 1);
	AddEdgeAndValue(G, 6, 3, 1);
	AddEdgeAndValue(G, 6, 7, 1);
	AddEdgeAndValue(G, 7, 8, 1);
	
	PrintG(G);
	// Kruskal  
	BFS(G, v1);// 从1开始
	printf("\n");
	for(int i = 2; i < G.vexnum; i++){
		PrintPath(i);
		printf("\n");
	}
	printf("\n");
	// 每个点的路径
	for(int i = 1; i < G.vexnum; i++){
		printf("%d\t", dist[i]);
	} 
	
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
