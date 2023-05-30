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
 
// ��¼���� 
int path[MaxVertexNum][MaxVertexNum];// path[i][j] = v��i��j�����·����vΪ�м�� 
// Floyd�㷨 
void Floyd(MGraph G){// ����������������
	// ��ʼ��·��Ϊ-1
	for(int i = 0; i < G.vexnum; i++){
		for(int j = 0; j < G.vexnum; j++){
			path[i][j] = -1;
		}
	} 
	// ����ĵط�����Ҫ��ʼ��Ϊ��ֵ
	for(int i = 0; i < G.vexnum; i++){// ÿ�������ε���һ�ο�ʼ�� 
		for(int j = 0; j < G.vexnum; j++){
			if(i != j){
				if(G.edge[i][j] == 0){
					G.edge[i][j] = MaxValue; 
				}
			}
		}
	} 
	for(int k = 0; k < G.vexnum; k++){// ÿ�μ��붥��k�����м�� 
		for(int i = 0; i < G.vexnum; i++){// ÿ�������ε���һ�ο�ʼ�� 
			for(int j = 0; j < G.vexnum; j++){//  ÿ�������ε���һ�ν�����/���ʵ� 
				//��ǰ����k�㣬�Ƿ�i��k�ľ���+k��j�ľ���С��֮ǰһ�μ���k���·��(=G.edge[i][j])ҪС
				if(G.edge[i][k] + G.edge[k][j] < G.edge[i][j]){
					G.edge[i][j] = G.edge[i][k] + G.edge[k][j];
					// ��¼·�����м�¼�м��� 
					path[i][j] = k;
				}
			}
		}
	}
	// ��ӡ�ɹ�
	for(int i = 0; i < G.vexnum; i++){// ÿ�������ε���һ�ο�ʼ�� 
		for(int j = 0; j < G.vexnum; j++){//  ÿ�������ε���һ�ν�����/���ʵ� 
			printf("%d\t", G.edge[i][j]);
		} 
		printf("\n");
	} 
}
// ��ӡ·��  
void PrintPath(int u, int v){// u�ǿ�ʼ�㣬v���յ�=�м�� 
	// ��uv�Ƿ����м�� ��û�о�˵���������һ���м�㣬ֱ�Ӵ�ӡv���� 
	if(path[u][v] == -1){
		printf("%d->", v);// �м����ǽ����㡣 
		return;
	}else{
		printf("%d->", u);// ��ʼ�� 
		// ���м�㣬�ͼ�������һ���м�����ĸ� 
		PrintPath(u, path[u][v]);// u���м�� �Ƿ����м�� 
		PrintPath(path[u][v], v);// �м�㵽v�Ƿ����м�� 
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
	Floyd(G);// ��1��ʼ
	printf("\n");
	for(int i = 0; i < G.vexnum; i++){// ��� 
		for(int j = 0; j < G.vexnum; j++){// �յ� 
			printf("%d��%d��·��:", i, j);
			PrintPath(i, j);
			printf("\n");
		}
	}
	printf("\n");

	
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
