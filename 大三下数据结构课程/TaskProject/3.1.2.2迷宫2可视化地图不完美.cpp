#include <iostream>
#include <graphics.h>      // ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <stack>
#include <windows.h>
using namespace std;

int m = 10, n = 10;// �к��� 
int map[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,0,0,0,0,1,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1},
};// ��ͼֵ, 1��ǽ�ڣ�0��ͨ����2 3 4 5�����ǵķ���6�ǳ���
int endx = m - 1, endy = n - 2; // �����к��У�����x��y����
int curx = 1, cury = 1; // �������ڵĿ�ʼ�к���
int vis[10][10]; // �Ƿ���ʹ���0��û���ʣ�-1�Ƿ��ʹ���
bool isFind = false; // �Ƿ��ҵ�����
stack<int(*)> pathStack;// ��STLģ���ջ���¼·����������

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
			//if (map[i][j] == 2) {
			//	putimage(j * 80, i * 80, &zjimg);
			//}
			//else if (map[i][j] == 0) {
			//	putimage(j * 80, i * 80, &luimg);
			//}
			//else if (map[i][j] == 1 || map[i][j] == 3) {
			//	putimage(j * 80, i * 80, &qiangimg);
			//}
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
	if (map[cury][curx] == 3) {// �ݹ��˳��������ҵ��˳���
		// cout << "�ҵ��˳���" << endl;
		isFind = true;
		return;
	}

	// �ݹ麯��ִ��ʱ��ִ���൱��ջpushʱ�Ĳ���
	pathStack.push(new int[2]{ cury, curx });// ��¼��ǰ·��
	vis[cury][curx] = -1;				   // ��ʾ���ʹ���ǰ��
	int curysval = map[cury][curx];			// ���浱ǰ�ĵ�ͼֵ
	// ������������λ�á�
	map[lasty][lastx] = ysval;				// ��һ�����ڵ�λ�ñ�ص�ͼֵ
	map[cury][curx] = dir;					// �����������ڵ�λ�� = ����������ֵ
	DrawMap();								// �ݹ麯��ִ��ʱ����ǰ�ĵ�ͼֵ
	// ���������ĸ�����̽���������뵱ǰλ�ú͵�ǰ�ĵ�ͼֵ���Ա�����һ���ݹ麯���ѵ�ǰ������ռ��λ�ñ�ص�ͼֵ��
	DFS(cury + 1, curx, 3, cury, curx, curysval);// �����±�̽��
	DFS(cury, curx + 1, 5, cury, curx, curysval);// ���ұ�̽��
	DFS(cury, curx - 1, 4, cury, curx, curysval);// �����̽��
	DFS(cury - 1, curx, 2, cury, curx, curysval);// ���ϱ�̽��

	if (isFind) {// �ҵ��˳��ڣ����ڵ�·��ջ��������ȷ�ķ���·�����˳����ɣ��������·�����ܲ�������·��
		return;
	}
	// 4�����������ˣ���·���ߣ���Ҫ������һ��λ��
	// �ݹ麯������ʱ���൱��ջpopʱ�Ĳ���
	// ��Ҫ�ѵݹ麯������ʱ�ı����ֵ�Ȳ����ع�ԭλ
	vis[cury][curx] = -1;				    // ��ǰ��û���ʹ���ȥ��ûӰ�죬�����ſ����ҵ�����·��
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
		map[*pos][*(pos + 1)] = 2;
	}
}

int main()
{
	int val;
	// 1.���������ʼ����ͼ
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			cin >> val;
			map[i][j] = val;
		}
	}
	map[endy][endx] = 6;// ������λ�ñ��

	initgraph(800, 800);   // ������ͼ���ڣ���СΪ 800x880 ����
	LoadImags();

	// 2.��������������ҵ�·��
	DFS(cury, curx, 3, cury, curx, map[cury][curx]);

	// 3.����ջ�������Ϣ���޸ĵ�ͼ���ʵ�·��
	UpdateMapToPath();
	DrawMap();

	//putimage(0, 0, &qiangimg);
	_getch();              // �����������
	closegraph();          // �رջ�ͼ����
}



/*
��ͼֵ
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

  0 1 2 3 4 5 6 7 8 9
0 1 1 1 1 1 1 1 1 1 1
1 1 0 0 1 0 0 0 1 0 1
2 1 0 0 1 0 0 0 1 0 1
3 1 0 0 0 0 1 1 0 0 1
4 1 0 1 1 1 0 0 0 0 1
5 1 0 0 0 1 0 0 0 0 1
6 1 0 1 0 0 0 1 0 0 1
7 1 0 1 1 1 0 1 1 0 1
8 1 1 0 0 0 1 0 0 0 1
9 1 1 1 1 1 1 1 1 1 1


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