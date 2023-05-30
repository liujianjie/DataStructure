#include <iostream>
#include <graphics.h>      // ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <stack>
#include <windows.h>
using namespace std;
// ��ͼֵ: 1��ǽ�ڣ�0��ͨ����2~5�����ǵķ����������ң���6�ǳ���
#define WALL 1
#define PASS 0
#define UP 2
#define DOWN 3
#define LEFT 4
#define RIGHT 5
#define EXITS 6

// ȫ�ֱ���
int m = 10, n = 10;		// �к��� Ĭ��Ϊ10
int map[100][100];		// ��ͼ���飬�ȿ���һ�㣬����m��n�޶���Χ
int vis[100][100];		// �Ƿ���ʹ���0��û���ʣ�-1�Ƿ��ʹ���
bool isFind = false;		// �Ƿ��ҵ�����
stack<int(*)> pathStack;// ��STLģ���ջ���¼·��

// ����ͼƬ
IMAGE imgs[10];
void LoadImags() {
	loadimage(&imgs[0], L"lu.png", 80, 80);
	loadimage(&imgs[1], L"qiang.png", 80, 80);
	loadimage(&imgs[2], L"u.png", 80, 80);
	loadimage(&imgs[3], L"d.png", 80, 80);
	loadimage(&imgs[4], L"l.png", 80, 80);
	loadimage(&imgs[5], L"r.png", 80, 80);
	loadimage(&imgs[6], L"qiang.png", 80, 80);
}

// ���Ƶ�ͼ
void DrawMap() {
	Sleep(300); // ����0.3�룬����ͼ
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			putimage(j * 80, i * 80, &imgs[map[i][j]]);
		}
	}
}
// ������������ǰ����Ķ�������
int GetAnotherDir(int dir) {
	if (dir == 2) {
		return 3;
	}
	if (dir == 3) {
		return 2;
	}
	if (dir == 4) {
		return 5;
	}
	if (dir == 5) {
		return 4;
	}
	return dir;
}
/*
˼·�����������������
�ݹ����Դ���ջ���ԡ����ڽ��뵱ǰ�ݹ麯���൱��ջ��push���˳���ǰ�ݹ麯���൱��ջ��pop
��ô����������ԣ�ʵ��������ͼ�з�����һ�����Ĺ��ܡ�
*/
void DFS(int cury, int curx, int dir, int lasty, int lastx, int ysval) {// cury curx ��ʾ��ǰ�㣬dir�ǵ�ǰλ�õķ��� lasty,lastx ��ʾ��һ���㣬ysval��ʾ��һ����ĵ�ͼֵ
	if (isFind) {// �ҵ��˳��ڣ��ݹ�ջ������
		return;
	}
	if (vis[cury][curx] == -1 || map[cury][curx] == 1 || cury >= m || cury < 0 || curx >= n || curx < 0) {// �ݹ鷵������:���λ�÷��ʹ���ǽ�ڣ�Խ�磬
		return;
	}
	if (map[cury][curx] == EXITS) {// �ݹ��˳��������ҵ��˳���
		// cout << "�ҵ��˳���" << endl;
		isFind = true;
		return;
	}

	// �ݹ麯��ִ��ʱ��ִ���൱��ջpushʱ�Ĳ���
	pathStack.push(new int[3]{ cury, curx, dir });// ��¼��ǰ·���ͷ���
	vis[cury][curx] = -1;				   // ��ʾ���ʹ���ǰ��
	int curysval = map[cury][curx];			// ���浱ǰ�ĵ�ͼֵ
	// ������������λ�á�
	map[lasty][lastx] = ysval;				// ��һ�����ڵ�λ�ñ�ص�ͼֵ
	map[cury][curx] = dir;					// �����������ڵ�λ�� = ����������ֵ
	DrawMap();								// �ݹ麯��ִ��ʱ����ǰ�ĵ�ͼֵ
	// ���������ĸ�����̽���������뵱ǰλ�ú͵�ǰ�ĵ�ͼֵ���Ա�����һ���ݹ麯���ѵ�ǰ������ռ��λ�ñ�ص�ͼֵ��
	DFS(cury + 1, curx, DOWN, cury, curx, curysval);// �����±�̽���������������������Ա�һ�������ұ�̽��
	DFS(cury, curx + 1, RIGHT, cury, curx, curysval);// ���ұ�̽��
	DFS(cury, curx - 1, LEFT, cury, curx, curysval);// �����̽��
	DFS(cury - 1, curx, UP, cury, curx, curysval);// ���ϱ�̽��

	if (isFind) {// �ҵ��˳��ڣ����ڵ�·��ջ��������ȷ�ķ���·�����˳����ɣ��������·�����ܲ�������·��
		return;
	}
	// 4�����������ˣ���·���ߣ���Ҫ������һ��λ��
	// �ݹ麯������ʱ���൱��ջpopʱ�Ĳ���
	// ��Ҫ�ѵݹ麯������ʱ�ı����ֵ�Ȳ����ع�ԭλ
	//vis[cury][curx] = 0;						// ��ǰ��û���ʹ���ȥ��ûӰ�죬���ָ�Ϊ0���ܿ����ҵ�����·��
	pathStack.pop();							// ��ȥ��¼��ǰλ��
	map[cury][curx] = curysval;				// �������ڵ�λ�ñ��һ��ʼ�ĵ�ͼֵ
	map[lasty][lastx] = GetAnotherDir(dir);	// ���Ƿ��ص���һ��λ�ã���һ��λ�õķ����ǵ�ǰ�����ķ�����ܻ�ͼ��ȷ
	DrawMap();								// ���Ƶ�ǰ�ĵ�ͼֵ
}

// ����ջ�����·��ֵ���޸ĵ�ͼֵ
void UpdateMapToPath() {
	while (!pathStack.empty()) {
		int* pos = pathStack.top();
		pathStack.pop();
		map[*pos][*(pos + 1)] = *(pos + 2); // ������ǵ�ʱ�ķ���ֵ
	}
}

int main()
{
	int val;
	cout << "�������ͼ������������" << endl;
	cin >> m >> n;
	cout << "�������ͼ���ݣ�" << endl;
	// 1.���������ʼ����ͼ
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			cin >> val;
			map[i][j] = val;
		}
	}
	int endy = m - 2, endx = n - 1; // �����к��У�����x��y����
	int curx = 1, cury = 1;			// ���ǿ�ʼ�к���
	map[endy][endx] = EXITS;			// ������λ�ñ��
	
	initgraph(n * 80, m * 80);		// ������ͼ���ڣ���СΪ n * 80,m * 80 ����
	LoadImags();
	
	// 2.��������������ҵ�·��
	DFS(cury, curx, DOWN, cury, curx, map[cury][curx]);

	// 3.����ջ�������Ϣ���޸ĵ�ͼ���ʵ�·��
	UpdateMapToPath();
	DrawMap();

	_getch();              // �����������
	closegraph();          // �رջ�ͼ����
}
/*
��ͼֵ
10 10 
1 1 1 1 1 1 1 1 1 1 
1 0 0 1 0 0 0 1 0 1 
1 0 0 1 0 0 0 1 0 1 
1 0 0 0 0 1 1 0 0 1 
1 0 1 1 1 0 0 0 0 1 
1 0 0 0 1 0 0 0 0 1 
1 0 1 0 0 0 1 0 0 1 
1 0 1 1 1 0 1 1 0 1 
1 0 0 0 0 1 0 0 0 1 
1 1 1 1 1 1 1 1 1 1 

11 10 
1 1 1 1 1 1 1 1 1 1 
1 0 0 1 0 0 0 1 0 1 
1 0 0 1 0 0 0 1 0 1 
1 0 0 0 0 1 1 0 0 1 
1 0 1 1 1 0 0 0 0 1 
1 0 0 0 1 0 1 0 0 1 
1 0 1 0 0 0 1 0 0 1 
1 0 1 1 1 0 1 1 0 1 
1 0 0 0 0 1 0 1 0 1 
1 0 1 0 0 0 0 1 0 1 
1 1 1 1 1 1 1 1 1 1
*/


//int map[10][10] = {
//	{1,1,1,1,1,1,1,1,1,1},
//	{1,0,0,1,0,0,0,1,0,1},
//	{1,0,0,1,0,0,0,1,0,1},
//	{1,0,0,0,0,1,1,0,0,1},
//	{1,0,1,1,1,0,0,0,0,1},
//	{1,0,0,0,1,0,0,0,0,1},
//	{1,0,1,0,0,0,1,0,0,1},
//	{1,0,1,1,1,0,1,1,0,1},
//	{1,0,0,0,0,1,0,0,0,1},
//	{1,1,1,1,1,1,1,1,1,1},
//};// ��ͼֵ, 1��ǽ�ڣ�0��ͨ����2 3 4 5�����ǵķ���6�ǳ���