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
bool RemoveEdge(MGraph &G, int x, int y);
int FirstNeighbor(MGraph &G, int x);
int NextNeighbor(MGraph &G, int x, int y);
int Get_edge_value(MGraph &G, int x, int y);
bool Set_edge_value(MGraph &G, int x, int y, int v);
void PrintG(MGraph &G);


int path[MaxVertexNum];// ·��
bool isvisit[MaxVertexNum];// �Ƿ���ʹ� 
int dist[MaxVertexNum];// ��Դ��·�� dist[i]=j,Դ�㵽i������·��j 
// BFS�㷨 
void BFS(MGraph &G, Vertex sourceu){ 
	// ��ʼ��·��Ϊ-1��Ϊ�˷����ӡ�ݹ�
	for(int i = 1; i < MaxVertexNum; i++){
		path[i] = -1;
	} 
	queue<Vertex> que;
	que.push(sourceu);
	isvisit[sourceu] = true;// ��Ƿ��ʹ� 
	Vertex ver;
	while(!que.empty()){
		ver = que.front();
		que.pop();
		printf("%d\t", ver);// �����������
		// �������ڽӵ�
		for(int i = 1; i < G.vexnum; i++){
			// û�з��ʹ� ������·�� 
			if(!isvisit[i] && G.edge[ver][i] != 0){
				// ��¼·����Դ�㵽i���·��=Դ�㵽�����ɢ���·�� + 1 
				dist[i] = dist[ver] + 1;
				path[i] = ver;// ��¼·�� 
				// ��Ƿ��ʹ�
				isvisit[i] = true;// ��������������� ����� 
				// ����� ���ȷ��ʵ���������ӣ������Ƚ����� 
				que.push(i);
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
	BFS(G, v1);// ��1��ʼ
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
