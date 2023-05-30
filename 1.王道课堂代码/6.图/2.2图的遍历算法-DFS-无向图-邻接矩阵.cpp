#include <stdio.h> 
#include <iostream>
#include <queue>
#define MaxVertexNum 15

using namespace std;
typedef struct{
	int data;		// 数据 
	bool isexist;	// 这个顶点还在不在，默认true存在 
}Vertex; 

typedef struct{
	Vertex vex[MaxVertexNum]; 			  // 顶点表
	int edge[MaxVertexNum][MaxVertexNum];// 邻接矩阵 
	int vexnum, arcnum; // 图的当前顶点数和弧数 
}MGraph;

// 0. 初始化
void InitGraph(MGraph &G){
	for(int i = 0; i < MaxVertexNum; i++){
		G.vex[i].isexist = true;
	}
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
		if(x.data == G.vex[i].data){
			G.vex[i].isexist = false;
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
	if(G.vex[x].isexist == false){
		return -1;
	}
	for(int i = 0; i < G.vexnum; i++){
		if(G.edge[x][i] != 0){
			return i;
		}
	}
	return -1;
} 
// 8.求图中顶点x的第一个邻接点y的下一个邻接点(假设y是x的第一个邻接点），若有返回顶点号，若图中没有x或顶点不存在x，或y是x的最后一个邻接点，返回-1
int NextNeighbor(MGraph &G, int x, int y){
	if(G.vex[x].isexist == false || G.vex[y].isexist == false){
		return -1;
	}
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
bool Get_edge_value(MGraph &G, int x, int y, int v){
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


// DFS算法 ,和视频保持一致，从顶点1开始 。实则是递归的过程 
void DFS(MGraph &G, Vertex cur);

bool istraverse[MaxVertexNum];
void DFSTraverse(MGraph &G){
	for(int i = 1; i < G.vexnum; i++){
		if(!istraverse[i]){
			DFS(G, G.vex[i]);
		}
	}
}
void DFS(MGraph &G, Vertex cur){ // 图和开始顶点 
	// 访问，标记访问，访问其邻接点
	printf("%d\t", cur.data);// 访问 
	istraverse[cur.data] = true;
//	for(int w = FirstNeighbor(G, cur.data); w > 0; w = NextNeighbor(G, cur.data, w)){
//		if(!istraverse[w]){// 未访问过 
//			DFS(G, G.vex[w]);
//		}
//	}
	for(int i = 1; i < G.vexnum; i++){
		if(G.edge[cur.data][i] != 0){
			if(!istraverse[i]){// 未访问过 
				DFS(G, G.vex[i]);
			}
		}
		
	}
}

int main(){
	MGraph G;
	InitGraph(G);
	Vertex v0 = {0, false};// 这个节点不使用 
	
	Vertex v1 = {1, true};
	Vertex v2 = {2, true};
	Vertex v3 = {3, true};
	Vertex v4 = {4, true};
	Vertex v5 = {5, true};
	Vertex v6 = {6, true};
	Vertex v7 = {7, true};
	Vertex v8 = {8, true};
	Vertex v9 = {9, true};
	Vertex v10 = {10, true};
	Vertex v11 = {11, true};
	
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
	
	// DFS
	DFSTraverse(G);
	
	return 0;
}
