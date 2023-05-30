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


// BFS�㷨 ,����Ƶ����һ�£��Ӷ���1��ʼ 
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
void BFS(MGraph &G, Vertex cur){ // ͼ�Ϳ�ʼ���� 
	queue<Vertex> que;
	que.push(cur);
	printf("%d\t", cur);// ���� 
	istraverse[cur] = true;// �ص㣬�Լ�����Լ����ʹ� 
	while(!que.empty()){
		cur = que.front();
		que.pop();
		for(int w = FirstNeighbor(G, cur); w > 0; w = NextNeighbor(G, cur, w)){
			if(!istraverse[w]){// δ���ʹ� 
				// ���ʣ���Ƿ��ʣ� ��ӡ���ס���ҵ�һ���ͷ��ʣ��ͱ�ǣ���Ȼ������ظ� 
				printf("%d\t", w);// ���� 
				istraverse[w] = true;
				que.push(w);
			}
		}
	}
}
void BFS2(MGraph &G, Vertex cur){ // ͼ�Ϳ�ʼ���� 
	queue<Vertex> que;
	que.push(cur);
	istraverse[cur] = true;// �ص㣬�Լ�����Լ����ʹ� 
	while(!que.empty()){
		cur = que.front();
		que.pop();
		printf("%d\t", cur);// ���� ��� 
		for(int i = 1; i < G.vexnum; i++){
			if(G.edge[cur][i] != 0 && !istraverse[i]){// δ���ʹ� 
				// ���ʣ���Ƿ��ʣ� ���
				istraverse[i] = true;
				que.push(i);
			}
		}
	}
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
