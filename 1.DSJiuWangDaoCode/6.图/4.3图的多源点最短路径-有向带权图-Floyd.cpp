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
bool AddEdgeAndValueWithDir(MGraph &G, int x, int y, int v); 
bool RemoveEdge(MGraph &G, int x, int y);
int FirstNeighbor(MGraph &G, int x);
int NextNeighbor(MGraph &G, int x, int y);
int Get_edge_value(MGraph &G, int x, int y);
bool Set_edge_value(MGraph &G, int x, int y, int v);
void PrintG(MGraph &G);
 
// 记录拓扑 
int path[MaxVertexNum][MaxVertexNum];// path[i][j] = v；i到j的最短路径以v为中间点 
// Floyd算法 
void Floyd(MGraph G){// 参数不是引用类型
	// 初始化路径为-1
	for(int i = 0; i < G.vexnum; i++){
		for(int j = 0; j < G.vexnum; j++){
			path[i][j] = -1;
		}
	} 
	// 特殊的地方，需要初始化为大值
	for(int i = 0; i < G.vexnum; i++){// 每个点依次当做一次开始点 
		for(int j = 0; j < G.vexnum; j++){
			if(i != j){
				if(G.edge[i][j] == 0){
					G.edge[i][j] = MaxValue; 
				}
			}
		}
	} 
	for(int k = 0; k < G.vexnum; k++){// 每次加入顶点k当做中间点 
		for(int i = 0; i < G.vexnum; i++){// 每个点依次当做一次开始点 
			for(int j = 0; j < G.vexnum; j++){//  每个点依次当做一次结束点/访问点 
				//当前加入k点，是否i到k的距离+k到j的距离小于之前一次加入k点的路径(=G.edge[i][j])要小
				if(G.edge[i][k] + G.edge[k][j] < G.edge[i][j]){
					G.edge[i][j] = G.edge[i][k] + G.edge[k][j];
					// 记录路径中有记录中间结点 
					path[i][j] = k;
				}
			}
		}
	}
	// 打印成果
	for(int i = 0; i < G.vexnum; i++){// 每个点依次当做一次开始点 
		for(int j = 0; j < G.vexnum; j++){//  每个点依次当做一次结束点/访问点 
			printf("%d\t", G.edge[i][j]);
		} 
		printf("\n");
	} 
}
// 打印路径  
void PrintPath(int u, int v){// u是开始点，v是终点=中间点 
	// 看uv是否有中间点 ，没有就说明这是最后一个中间点，直接打印v即可 
	if(path[u][v] == -1){
		printf("%d->", v);// 中间点就是结束点。 
		return;
	}else{
		printf("%d->", u);// 开始点 
		// 有中间点，就继续找上一个中间点是哪个 
		PrintPath(u, path[u][v]);// u到中间点 是否有中间点 
		PrintPath(path[u][v], v);// 中间点到v是否有中间点 
	}
}

int main(){
	MGraph G;
	InitGraph(G);
	Vertex v0 = {0};
	Vertex v1 = {1};
	Vertex v2 = {2};
	Vertex v3 = {3};
	Vertex v4 = {4};
	
	InsertVertex(G, v0);
	InsertVertex(G, v1);
	InsertVertex(G, v2);
	InsertVertex(G, v3);
	InsertVertex(G, v4);
	
	AddEdgeAndValueWithDir(G, 0, 2, 1);
	AddEdgeAndValueWithDir(G, 0, 4, 10);
	AddEdgeAndValueWithDir(G, 1, 4, 5);
	AddEdgeAndValueWithDir(G, 1, 3, 1);
	AddEdgeAndValueWithDir(G, 2, 1, 1);
	AddEdgeAndValueWithDir(G, 2, 4, 7);
	AddEdgeAndValueWithDir(G, 3, 4, 1);
	
	PrintG(G);
	// Kruskal  
	Floyd(G);// 从1开始
	printf("\n");
	for(int i = 0; i < G.vexnum; i++){// 起点 
		for(int j = 0; j < G.vexnum; j++){// 终点 
			printf("%d到%d的路径:", i, j);
			PrintPath(i, j);
			printf("\n");
		}
	}
	printf("\n");

	
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
// 5.有向边带权图的添加边 
bool AddEdgeAndValueWithDir(MGraph &G, int x, int y, int v){
	if(G.edge[x][y] == 0){
		G.edge[x][y] = v;
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
