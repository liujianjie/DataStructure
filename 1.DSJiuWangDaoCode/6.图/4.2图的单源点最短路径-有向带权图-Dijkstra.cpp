#include <stdio.h> 
#include <iostream>
#include <queue>
#define MaxVertexNum 15
#define MaxValue 1000000

using namespace std;
//typedef struct{
//	int data;		// ���� 
//}Vertex; 
typedef int Vertex;
typedef struct{
	Vertex vex[MaxVertexNum]; 			  // �����
	int edge[MaxVertexNum][MaxVertexNum];// �ڽӾ��� 
	int vexnum, arcnum; // ͼ�ĵ�ǰ�������ͻ��� 
}MGraph;
// ����ÿ���ߵ���Ϣ
typedef struct Edge{
	Vertex u;// Դ��
	Vertex v;// �յ�
	int edge;// ��ֵ
	// ���������
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


int path[MaxVertexNum];// ·��
bool isvisit[MaxVertexNum];// �Ƿ���ʹ� 
int dist[MaxVertexNum];// ��Դ��·�� dist[i]=j,Դ�㵽i������·��j 

// Dijkstra�㷨 
void Dijkstra(MGraph &G, Vertex sourceu){ 
	// ��ʼ��·��Ϊ-1��Ϊ�˷����ӡ�ݹ�
	for(int i = 1; i < MaxVertexNum; i++){
		path[i] = -1;
	} 
	// Դ�������dist 0,������һ�ξ����ҵ�Դ��Ӷ���ɢ 
	// �����ĵ�ҪΪ���ֵ�źø���
	for(int i = 1; i < G.vexnum; i++){
		
		if(G.edge[sourceu][i] != 0){
			dist[i] = G.edge[sourceu][i];
		}else{
			dist[i] = MaxValue;
		}
	} 
	dist[sourceu] = 0;
	int minv;// ÿ���ҵ�����С�ߵĵ� 
	int sumv = 0;// ��¼��������·�� 
	// ѭ��n�Σ��ҵ����е��� 
	for(int z = 1; z < G.vexnum; z++){
		// 1.�ҵ���С���ϵĵ㡣��������ж����ͼ�Ƿ���ͨͼ��û�ҵ���С�ߵĵ�Ͳ���ͨ�����������ͨ�� 
		int minvalue = MaxValue;
		for(int i = 1; i < G.vexnum; i++){
			if(!isvisit[i] && dist[i] < minvalue){// û�з��ʹ���������С 
				minvalue = dist[i];
				minv = i;
			}
		}
		isvisit[minv] = true;// �ҵ���С���ϵĵ㣬��Ƿ��ʹ�
		printf("%d\t", minv);
		sumv += minvalue;
		// 2. �����������ɢ��ˢ��dist
		for(int i = 1; i < G.vexnum; i++){
			if(!isvisit[i] && G.edge[minv][i] != 0){//  û�з��ʹ� ������ɢ�㵽���i����·��  
				if(dist[minv] + G.edge[minv][i] < dist[i]){// �������dist��Դ�㵽��ɢ���ֵ+��ɢ�㵽i���ֵС�ڵ���dist��Դ�㵽i���ֵ�� �͸��� 
					dist[i] = dist[minv] + G.edge[minv][i];
					// ��¼·�� 
					path[i] = minv;
				}
			}
		} 
	}
}
// ��ӡ·�� 
void PrintPath(int v){
	// �Ƿ�ﵽԴ�� ���������Ƿ�-1 
	if(path[v] == -1){
		printf("%d->", v);
		return;
	}else{
		PrintPath(path[v]);// ��������һ�����
		printf("%d->", v);
	}
}

int main(){
	MGraph G;
	InitGraph(G);
	Vertex v0 = {0};// ����ڵ㲻ʹ�� 
	
//	Vertex v1 = {1};
//	Vertex v2 = {2};
//	Vertex v3 = {3};
//	Vertex v4 = {4};
//	Vertex v5 = {5};
//	
//	InsertVertex(G, v0);
//	InsertVertex(G, v1);
//	InsertVertex(G, v2);
//	InsertVertex(G, v3);
//	InsertVertex(G, v4);
//	InsertVertex(G, v5);
//	
//	AddEdgeAndValueWithDir(G, 1, 2, 10);
//	AddEdgeAndValueWithDir(G, 1, 5, 5);
//	AddEdgeAndValueWithDir(G, 2, 3, 1);
//	AddEdgeAndValueWithDir(G, 2, 5, 2);
//	AddEdgeAndValueWithDir(G, 3, 4, 4);
//	AddEdgeAndValueWithDir(G, 4, 3, 6);
//	AddEdgeAndValueWithDir(G, 4, 1, 7);
//	AddEdgeAndValueWithDir(G, 5, 2, 3);
//	AddEdgeAndValueWithDir(G, 5, 3, 9);
//	AddEdgeAndValueWithDir(G, 5, 4, 2);
	
	
	
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
	// Kruskal  
	Dijkstra(G, v1);// ��1��ʼ
	printf("\n");
	for(int i = 2; i < G.vexnum; i++){
		PrintPath(i);
		printf("\n");
	}
	printf("\n");
	// ÿ�����·��
	for(int i = 1; i < G.vexnum; i++){
		printf("%d\t", dist[i]);
	} 
	
	return 0;
}

// 0. ��ʼ��
void InitGraph(MGraph &G){
	for(int i = 0; i < MaxVertexNum; i++){
		for(int j = 0; j < MaxVertexNum; j++){
			G.edge[i][j] = 0;
		}
	}
	G.vexnum = 0;
	G.arcnum = 0;
} 
// 1.�ж�ͼG�Ƿ���ڱ�(x,y)
bool Adjacent(MGraph &G, int x, int y){
	if(G.edge[x][y] == 0){
		return false;
	}
	return true;// ���� 
}
// 2.�г�ͼG������x�ڽӵı�
void Neighbors(MGraph &G, int x) {
	for(int i = 0; i < MaxVertexNum; i++){
		if(G.edge[x][i] != 0){
			printf("(%d, %d)\t", x, i);
		}
	}
}
// 3. ��ͼG�в��붥��x
bool InsertVertex(MGraph &G, Vertex x){
	// �������Ƿ�����
	if(G.vexnum >= MaxVertexNum){
		return false;
	} 
	// ���뵽����������
	G.vex[G.vexnum] = x;
	// ͼG���١���
	
	// ������+1
	G.vexnum++;
	return true; 
} 
// 4.��ͼG��ɾ������x
bool DeleteVertex(MGraph &G, Vertex x){
	// 1.���ڶ��������У��ÿ� false 
	int pos;
	for(int i = 0; i < G.vexnum; i++){
		if(x == G.vex[i]){
			pos = i;
			break;
		}
	}
	// 2.��ͼ�е�i�к�j��Ϊ0 
	for(int i = 0; i < G.vexnum; i++){
		G.edge[pos][i] = 0;
		G.edge[i][pos] = 0;
		G.arcnum--;
	}
	//G.vexnum--;// ������ ���ü�����������ɾ�� 
}
// 5.�������(x,y)�����ڣ���ͼ�м���
bool AddEdge(MGraph &G, int x, int y){
	if(G.edge[x][y] == 0){
		G.edge[x][y] = 1;
		G.edge[y][x] = 1;
		G.arcnum++;
		return true;
	}
	return false;
} 
//  5.�������(x,y)�����ڣ���ͼ�м��룬�������ñ�ֵ 
bool AddEdgeAndValue(MGraph &G, int x, int y, int v){
	if(G.edge[x][y] == 0){
		G.edge[x][y] = v;
		G.edge[y][x] = v;
		G.arcnum++;
		return true;
	}
	return false;
} 
// 5.����ߴ�Ȩͼ����ӱ� 
bool AddEdgeAndValueWithDir(MGraph &G, int x, int y, int v){
	if(G.edge[x][y] == 0){
		G.edge[x][y] = v;
		G.arcnum++;
		return true;
	}
	return false;
} 
// 6.�����(x,y)���ڣ���ͼ��ɾ��
bool RemoveEdge(MGraph &G, int x, int y){
	if(G.edge[x][y] != 0){
		G.edge[x][y] = 0;
		G.edge[y][x] = 0;
		G.arcnum--;
		return true;
	}
	return false;
}
// 7.��ͼ�ж���x�ĵ�һ���ڽӵ㣬���з��ض���ţ���ͼ��û��x�򶥵㲻����x������-1
int FirstNeighbor(MGraph &G, int x){
	for(int i = 0; i < G.vexnum; i++){
		if(G.edge[x][i] != 0){
			return i;
		}
	}
	return -1;
} 
// 8.��ͼ�ж���x�ĵ�һ���ڽӵ�y����һ���ڽӵ�(����y��x�ĵ�һ���ڽӵ㣩�����з��ض���ţ���ͼ��û��x�򶥵㲻����x����y��x�����һ���ڽӵ㣬����-1
int NextNeighbor(MGraph &G, int x, int y){
	for(int i = 0; i < G.vexnum; i++){
		if(G.edge[x][i] != 0 && i > y){
			return i;
		}
	}
	return -1;
} 
// 9.��ȡͼG�б�(x,y)��Ӧ��Ȩֵ
int Get_edge_value(MGraph &G, int x, int y){
	return G.edge[x][y];
} 
// 10.����ͼG�б�(x,y)��Ӧ��Ȩֵ
bool Set_edge_value(MGraph &G, int x, int y, int v){
	return G.edge[x][y] = v;
} 


// ����
// 1.����ͼ�ı�ֵ
void PrintG(MGraph &G){
	printf("��������%d\t����:%d\n", G.vexnum, G.arcnum);
	for(int i = 0; i < G.vexnum; i++){
		for(int j = 0; j < G.vexnum; j++){
			printf("%d\t",G.edge[i][j]);
		}
		printf("\n");
	}
	printf("\n");
} 
