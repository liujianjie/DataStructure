#include <iostream>
#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include <stack>
#include <windows.h>
using namespace std;
// 地图值: 1是墙壁，0是通道，2~5是主角的方向（上下左右），6是出口
#define WALL 1
#define PASS 0
#define UP 2
#define DOWN 3
#define LEFT 4
#define RIGHT 5
#define EXITS 6

// 全局变量
int m = 10, n = 10;		// 行和列 默认为10
int map[100][100];		// 地图数组，先开大一点，根据m、n限定范围
int vis[100][100];		// 是否访问过，0是没访问，-1是访问过了
bool isFind = false;		// 是否找到出口
stack<int(*)> pathStack;// 用STL模板的栈类记录路径

// 加载图片
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

// 绘制地图
void DrawMap() {
	Sleep(300); // 休眠0.3秒，更新图
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			putimage(j * 80, i * 80, &imgs[map[i][j]]);
		}
	}
}
// 辅助函数，当前方向的对立方向
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
思路：采用深度优先搜索
递归中自带“栈特性”，在进入当前递归函数相当于栈的push，退出当前递归函数相当于栈的pop
那么根据这个特性，实现搜索地图中返回上一个结点的功能。
*/
void DFS(int cury, int curx, int dir, int lasty, int lastx, int ysval) {// cury curx 表示当前点，dir是当前位置的方向， lasty,lastx 表示上一个点，ysval表示上一个点的地图值
	if (isFind) {// 找到了出口，递归栈都返回
		return;
	}
	if (vis[cury][curx] == -1 || map[cury][curx] == 1 || cury >= m || cury < 0 || curx >= n || curx < 0) {// 递归返回条件:这个位置访问过，墙壁，越界，
		return;
	}
	if (map[cury][curx] == EXITS) {// 递归退出条件，找到了出口
		// cout << "找到了出口" << endl;
		isFind = true;
		return;
	}

	// 递归函数执行时，执行相当于栈push时的操作
	pathStack.push(new int[3]{ cury, curx, dir });// 记录当前路径和方向
	vis[cury][curx] = -1;				   // 表示访问过当前点
	int curysval = map[cury][curx];			// 保存当前的地图值
	// 更新主角所在位置。
	map[lasty][lastx] = ysval;				// 上一个所在的位置变回地图值
	map[cury][curx] = dir;					// 主角现在所在的位置 = 主角面向方向值
	DrawMap();								// 递归函数执行时，当前的地图值
	// 上下左右四个方向探索，并传入当前位置和当前的地图值（以便在下一个递归函数把当前主角所占的位置变回地图值）
	DFS(cury + 1, curx, DOWN, cury, curx, curysval);// 先向下边探索，这里先往下搜索，对比一下先向右边探索
	DFS(cury, curx + 1, RIGHT, cury, curx, curysval);// 向右边探索
	DFS(cury, curx - 1, LEFT, cury, curx, curysval);// 向左边探索
	DFS(cury - 1, curx, UP, cury, curx, curysval);// 向上边探索

	if (isFind) {// 找到了出口，现在的路径栈保存了正确的访问路径，退出即可，但是这个路径可能不是最优路径
		return;
	}
	// 4个方向都走完了，无路可走，需要返回上一个位置
	// 递归函数结束时，相当于栈pop时的操作
	// 需要把递归函数进入时改变的数值等操作回归原位
	//vis[cury][curx] = 0;						// 当前点没访问过，去掉没影响，但恢复为0可能可以找到最优路径
	pathStack.pop();							// 舍去记录当前位置
	map[cury][curx] = curysval;				// 现在所在的位置变回一开始的地图值
	map[lasty][lastx] = GetAnotherDir(dir);	// 主角返回到上一个位置，上一个位置的方向，是当前对立的方向才能绘图正确
	DrawMap();								// 绘制当前的地图值
}

// 根据栈保存的路径值，修改地图值
void UpdateMapToPath() {
	while (!pathStack.empty()) {
		int* pos = pathStack.top();
		pathStack.pop();
		map[*pos][*(pos + 1)] = *(pos + 2); // 变成主角当时的方向值
	}
}

int main()
{
	int val;
	cout << "请输入地图行数和列数：" << endl;
	cin >> m >> n;
	cout << "请输入地图数据：" << endl;
	// 1.根据输入初始化地图
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			cin >> val;
			map[i][j] = val;
		}
	}
	int endy = m - 2, endx = n - 1; // 出口列和行，列是x，y是行
	int curx = 1, cury = 1;			// 主角开始行和列
	map[endy][endx] = EXITS;			// 给出口位置标记
	
	initgraph(n * 80, m * 80);		// 创建绘图窗口，大小为 n * 80,m * 80 像素
	LoadImags();
	
	// 2.深度优先搜索，找到路径
	DFS(cury, curx, DOWN, cury, curx, map[cury][curx]);

	// 3.根据栈保存的信息，修改地图访问的路径
	UpdateMapToPath();
	DrawMap();

	_getch();              // 按任意键继续
	closegraph();          // 关闭绘图窗口
}
/*
地图值
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
//};// 地图值, 1是墙壁，0是通道，2 3 4 5是主角的方向，6是出口