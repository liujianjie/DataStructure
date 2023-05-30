#include <stdio.h> 
#include <iostream>
#define MaxVertexNum 10

using namespace std;
typedef struct{
	int data;		// ���� 
	bool isexist;	// ������㻹�ڲ��ڣ�Ĭ��true���� 
}Vertex; 

typedef struct{
	Vertex vex[MaxVertexNum]; 			  // �����
	int edge[MaxVertexNum][MaxVertexNum];// �ڽӾ��� 
	int vexnum, arcnum; // ͼ�ĵ�ǰ�������ͻ��� 
}MGraph;

// 0. ��ʼ��
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
		if(x.data == G.vex[i].data){
			G.vex[i].isexist = false;
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
// 8.��ͼ�ж���x�ĵ�һ���ڽӵ�y����һ���ڽӵ�(����y��x�ĵ�һ���ڽӵ㣩�����з��ض���ţ���ͼ��û��x�򶥵㲻����x����y��x�����һ���ڽӵ㣬����-1
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
// 9.��ȡͼG�б�(x,y)��Ӧ��Ȩֵ
int Get_edge_value(MGraph &G, int x, int y){
	return G.edge[x][y];
} 
// 10.����ͼG�б�(x,y)��Ӧ��Ȩֵ
bool Get_edge_value(MGraph &G, int x, int y, int v){
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
int main(){
	MGraph G;
	InitGraph(G);
	Vertex v0 = {0, false};// ����ڵ㲻ʹ�� 
	
	Vertex v1 = {1, true};
	Vertex v2 = {2, true};
	Vertex v3 = {3, true};
	Vertex v4 = {4, true};
	Vertex v5 = {5, true};
	
	InsertVertex(G, v0);
	InsertVertex(G, v1);
	InsertVertex(G, v2);
	InsertVertex(G, v3);
	InsertVertex(G, v4);
	InsertVertex(G, v5);
	
	AddEdge(G, 1, 2);
	AddEdge(G, 1, 4);
	AddEdge(G, 2, 3);
	AddEdge(G, 2, 5);
	AddEdge(G, 3, 5);
	AddEdge(G, 3, 4);
	
	// ��ӡͼ 
	PrintG(G);
	// ��ӡ ��x�ڽӵĵ�
	Neighbors(G, 1); 
	printf("\n");
	
	int f = FirstNeighbor(G, 1);
	printf("��һ���ڽӵ�Ķ�����ǣ�%d\n", f);
	f = NextNeighbor(G, 2, 5);
	printf("�ڶ����ڽӵ�Ķ�����ǣ�%d\n", f);
	// ɾ����
	RemoveEdge(G, 0, 1); 
	// ��ӡͼ 
	PrintG(G);
	// ɾ������ 
//	DeleteVertex(G, v3);
	// ��ӡͼ 
//	PrintG(G);
	return 0;
}
