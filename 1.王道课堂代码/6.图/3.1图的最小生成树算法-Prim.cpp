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


bool isvisit[MaxVertexNum];// �Ƿ���ʹ� 
int dist[MaxVertexNum];// dist[i] = j; i�����㵽��������j���룬��ʼ��Ϊ��� 

// Prim�㷨���Ӷ���1��ʼ 
void Prim(MGraph &G, Vertex sourceu){ // ͼ�Ϳ�ʼ���� 
	for(int i = 1; i < MaxVertexNum; i++){
		// ��Դ�㿪ʼ��dist��ֵ������ͨΪ��ֵ������Ϊ��ֵ 
		if(G.edge[sourceu][i] != 0){
			dist[i] = G.edge[sourceu][i];// ��ֵ 
		} else{
			dist[i] = MaxValue;// ��ֵ 
		}
	} 
	// Դ�� Ϊ0
	dist[sourceu] = 0;
	int v = -1;// �ҵ���v�� 
	int sumedgev = 0;// ��ֵ������ 
	for(int z = 1; z < G.vexnum; z++){// �ҵ�n���� 
		int minedge = MaxValue;
		// ��dist����������һ����ɢu���ҵ���С�ߵ�v�� 
		for(int i = 1; i < G.vexnum; i++){
			if(!isvisit[i]){// �����û���ʹ�
				if(dist[i] < minedge){// �����ҵ���С�� 
					minedge = dist[i];
					v = i;
				}
			} 
			
		} 
		isvisit[v] = true;// ��Ƿ��ʹ��� ���ҵ���С��˵�����������ı߷��ʹ��� 
		printf("%d\t", v);// �ҵ��ˣ���ӡ����� 
		sumedgev += dist[v];
		// ���������ߵ���Ϣ 
		for(int i = 1; i < G.vexnum; i++){
			if(!isvisit[i] && G.edge[v][i] != 0){// û�з��ʹ���������ɢ����Ե������ 
				if(G.edge[v][i] < dist[i]){// ��ǰ��ɢ�㵽i�ľ����Ƿ�С��dist��Դ�㵽i��ľ��� 
					dist[i] = G.edge[v][i];
				}
			}
		}
	}
	printf("������%d\n", sumedgev);
}

int main(){
	MGraph G;
	InitGraph(G);
	Vertex v0 = {0};// ����ڵ㲻ʹ�� 
	
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
	Prim(G, 1);// ��1��ʼ
	
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
