#include <iostream>
#include <stack>
#include <windows.h>
using namespace std;
// 地图值: 1是墙壁，0是通道，2是主角所在位置，3是出口 4是不能通过的标记
#define WALL 1
#define PASS 0
#define ZHUJUE 2
#define EXITS 3
#define NOPATH 4 

// 全局变量
int m = 10, n = 10;		// 行和列 默认为10
int map[100][100];		// 地图数组，先开大一点，根据m、n限定范围
int vis[100][100];		// 是否访问过，0是没访问，-1是访问过了
bool isFind = false;		// 是否找到出口
stack<int(*)> pathStack;// 用STL模板的栈类记录路径

// 打印地图值
void PrintMap(int flag) {// 根据flag是否清除控制台内容
	if (flag == 0) {
		COORD position;
		position.X = 0;
		position.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << "搜索地图中..............." << endl;
	}
	Sleep(250); // 休眠0.3秒，更新输出内容
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == ZHUJUE) {// 主角当前所在位置
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);// 红色
				cout << "☆";
				continue;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);// 白色字体
			if (map[i][j] == WALL || map[i][j] == EXITS) {	// 墙
				cout << "■";
			}
			if (map[i][j] == PASS) {	// 路
				cout << "  ";// 要2个空格
			}
			if (map[i][j] == NOPATH) {	// 不能通过
				cout << "×";
			}
		}
		cout << endl;
	}
	cout << endl;
}
/*
思路：采用深度优先搜索
递归中自带“栈特性”，在进入当前递归函数相当于栈的push，退出当前递归函数相当于栈的pop
那么根据这个特性，实现搜索地图中返回上一个结点的功能。
*/
void DFS(int cury, int curx, int lasty, int lastx, int ysval) {// cury curx 表示当前点， lasty,lastx 表示上一个点，ysval表示上一个点的地图值
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
	pathStack.push(new int[2]{cury, curx});// 记录当前路径
	vis[cury][curx] = -1;				   // 表示访问过当前点
	int curysval = map[cury][curx];			// 保存当前的地图值
	// 更新主角所在位置。
	map[lasty][lastx] = ysval;				// 上一个所在的位置变回地图值
	map[cury][curx] = ZHUJUE;						// 现在所在的位置为2，
	PrintMap(0);								// 递归函数执行时，当前的地图值
	// 上下左右四个方向探索，并传入当前位置和当前的地图值（以便在下一个递归函数把当前主角所占的位置变回地图值）
	DFS(cury, curx + 1, cury, curx, curysval);// 先向右边探索，为了符合PPT上的图展示效果，不过应该优先向下探索的。
	DFS(cury + 1, curx, cury, curx, curysval);// 向下边探索
	DFS(cury, curx - 1, cury, curx, curysval);// 向左边探索
	DFS(cury - 1, curx, cury, curx, curysval);// 向上边探索

	if (isFind) {// 找到了出口，现在的路径栈保存了正确的访问路径，退出即可，但是这个路径可能不是最优路径
		return;
	}
	// 4个方向都走完了，无路可走，说明这个位置不能通过，需要返回上一个位置
	// 递归函数结束时，相当于栈pop时的操作
	// 需要把递归函数进入时改变的数值等操作回归原位
	//vis[cury][curx] = 0;						// 当前点没访问过，去掉没影响，但恢复为0可能可以找到最优路径
	pathStack.pop();							// 舍去记录当前位置
	map[cury][curx] = NOPATH;				// 这个位置的值为不能通过
	map[lasty][lastx] = ZHUJUE;				// 上一个所在的位置为2
	PrintMap(0);								// 打印当前的地图值
}

// 根据栈保存的路径值，修改地图值
void UpdateMapToPath() {
	while (!pathStack.empty()) {
		int *pos = pathStack.top();
		pathStack.pop();
		map[*pos][*(pos + 1)] = 2;
	}
}

int main() {
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
	int curx = 1, cury = 1;			// 主角所在的开始行和列
	map[endy][endx] = EXITS;// 给出口位置标记
	system("cls");// 清空输入

	// 2.深度优先搜索，找到路径
	DFS(cury, curx, cury, curx, map[cury][curx]);

	// 3.根据栈保存的信息，修改地图访问的路径
	cout << "成功找到出口，访问出口路径如下:" << endl;
	UpdateMapToPath();
	PrintMap(1); // 最后打印访问过的路径图

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





/*
，具体如下。
1.根据当前主角出发位置
	0)记录当前位置访问过
	1)把当前位置存入到路径栈中
	2)把当前的位置的地图值变为主角所在的位置值
2.以主角当前位置向上下左右四个方向继续搜索，当前位置根据不同方向而改变
3.新的位置继续执行步骤1，并且需先把上一个主角所占的位置变回地图值，如此反复
4.
*/



