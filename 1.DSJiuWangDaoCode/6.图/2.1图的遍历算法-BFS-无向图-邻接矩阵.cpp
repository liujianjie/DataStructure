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


// BFS算法 ,和视频保持一致，从顶点1开始 
void BFS(MGraph &G, Vertex cur);
void BFS2(MGraph &G, Vertex cur);

bool istraverse[MaxVertexNum];
void BFSTraverse(MGraph &G){
	for(int i = 1; i < G.vexnum; i++){
		if(!istraverse[i]){
			BFS2(G, G.vex[i]);
		}
	}
}
void BFS(MGraph &G, Vertex cur){ // 图和开始顶点 
	queue<Vertex> que;
	que.push(cur);
	printf("%d\t", cur);// 访问 
	istraverse[cur] = true;// 重点，自己标记自己访问过 
	while(!que.empty()){
		cur = que.front();
		que.pop();
		for(int w = FirstNeighbor(G, cur); w > 0; w = NextNeighbor(G, cur, w)){
			if(!istraverse[w]){// 未访问过 
				// 访问，标记访问， 入队。记住，找到一个就访问，和标记，不然后面会重复 
				printf("%d\t", w);// 访问 
				istraverse[w] = true;
				que.push(w);
			}
		}
	}
}
void BFS2(MGraph &G, Vertex cur){ // 图和开始顶点 
	queue<Vertex> que;
	que.push(cur);
	istraverse[cur] = true;// 重点，自己标记自己访问过 
	while(!que.empty()){
		cur = que.front();
		que.pop();
		printf("%d\t", cur);// 访问 标记 
		for(int i = 1; i < G.vexnum; i++){
			if(G.edge[cur][i] != 0 && !istraverse[i]){// 未访问过 
				// 访问，标记访问， 入队
				istraverse[i] = true;
				que.push(i);
			}
		}
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
	Vertex v9 = {9};
	Vertex v10 = {10};
	Vertex v11 = {11};
	
	InsertVertex(G, v0);
	InsertVertex(G, v1);
	InsertVertex(G, v2);
	InsertVertex(G, v3);
	InsertVertex(G, v4);
	InsertVertex(G, v5);
	InsertVertex(G, v6);
	InsertVertex(G, v7);
	InsertVertex(G, v8);
	InsertVertex(G, v9);
	InsertVertex(G, v10);
	InsertVertex(G, v11);
	
	AddEdge(G, 1, 2);
	AddEdge(G, 1, 5);
	AddEdge(G, 2, 6);
	AddEdge(G, 3, 4);
	AddEdge(G, 3, 6);
	AddEdge(G, 3, 7);
	AddEdge(G, 4, 7);
	AddEdge(G, 4, 8);
	AddEdge(G, 6, 7);
	AddEdge(G, 7, 8);
	
	
	AddEdge(G, 9, 10);
	AddEdge(G, 10, 11);
	AddEdge(G, 9, 11);
	PrintG(G);
	
	// BFS
	BFSTraverse(G);
	
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
