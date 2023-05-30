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


bool isvisit[MaxVertexNum];// 是否访问过 
int dist[MaxVertexNum];// dist[i] = j; i代表顶点到生成树的j距离，初始化为最大。 

// Prim算法，从顶点1开始 
void Prim(MGraph &G, Vertex sourceu){ // 图和开始顶点 
	for(int i = 1; i < MaxVertexNum; i++){
		// 从源点开始的dist初值。有连通为边值，否则为大值 
		if(G.edge[sourceu][i] != 0){
			dist[i] = G.edge[sourceu][i];// 边值 
		} else{
			dist[i] = MaxValue;// 大值 
		}
	} 
	// 源点 为0
	dist[sourceu] = 0;
	int v = -1;// 找到的v点 
	int sumedgev = 0;// 边值共多少 
	for(int z = 1; z < G.vexnum; z++){// 找到n个点 
		int minedge = MaxValue;
		// 在dist数组中找上一个扩散u点找到最小边的v点 
		for(int i = 1; i < G.vexnum; i++){
			if(!isvisit[i]){// 这个点没访问过
				if(dist[i] < minedge){// 依次找到最小点 
					minedge = dist[i];
					v = i;
				}
			} 
			
		} 
		isvisit[v] = true;// 标记访问过了 ，找到最小点说明树到这个点的边访问过了 
		printf("%d\t", v);// 找到了，打印这个点 
		sumedgev += dist[v];
		// 更新这条边的信息 
		for(int i = 1; i < G.vexnum; i++){
			if(!isvisit[i] && G.edge[v][i] != 0){// 没有访问过，并且扩散点可以到这个点 
				if(G.edge[v][i] < dist[i]){// 当前扩散点到i的距离是否小于dist中源点到i点的距离 
					dist[i] = G.edge[v][i];
				}
			}
		}
	}
	printf("共花费%d\n", sumedgev);
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
	
	AddEdgeAndValue(G, 1, 2, 1);
	AddEdgeAndValue(G, 1, 3, 6);
	AddEdgeAndValue(G, 1, 4, 5);
	AddEdgeAndValue(G, 2, 3, 5);
	AddEdgeAndValue(G, 2, 5, 3);
	AddEdgeAndValue(G, 3, 4, 5);
	AddEdgeAndValue(G, 3, 5, 6);
	AddEdgeAndValue(G, 3, 6, 4);
	AddEdgeAndValue(G, 4, 6, 2);
	AddEdgeAndValue(G, 5, 6, 6);
	
	PrintG(G);
	
	// Prim  
	Prim(G, 1);// 从1开始
	
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
