#include  <stdio.h>
#include  <stdlib.h>
#include  <malloc.h>
#include  <windows.h>

#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASINLE -1
#define OVERFLOW -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define MAXSIZE 100 	//迷宫最大范围 
#define ROW 10			//行数 
#define COL 10			//列数 

typedef int Status;

typedef struct {			//坐标 
	int row;
	int col;
}PosType;
typedef struct {			//栈的元素类型 
	int stepnun;
	PosType seat;
	int di;
}Elem;
typedef struct {			//栈 
	Elem* top;
	Elem* base;
	int stacksize;
}stack;
typedef struct {			//地图类型 
	int m, n;
	int map[MAXSIZE][MAXSIZE];
}MazeType;

Status InitMaze(MazeType* maze, int a[][COL], int row, int col)	//构建地图 
{
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			maze->map[i][j] = a[i][j];
		}
	}
	maze->m = ROW,
		maze->n = COL;
	return OK;
}
Status InitStack(stack* s)	//栈初始化 
{
	s->base = (Elem*)malloc(STACK_INIT_SIZE * sizeof(Elem));
	if (!s->base) return ERROR;
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}
Status Pass(MazeType maze, PosType curpos)	//验证是否通过 
{
	return maze.map[curpos.row][curpos.col] == 0;
}
Status FootPrint(MazeType* maze, PosType curpos)		//如果通过，地图上标记为* 
{
	maze->map[curpos.row][curpos.col] = '*';
	return OK;
}
Elem CreatElem(int curstep, PosType curpos, int di)	//创建栈的元素 
{
	Elem e;
	e.di = di;
	e.seat = curpos;
	e.stepnun = curstep;
	return e;
}
Status Push(stack* s, Elem e)	//入栈 
{
	if (s->top - s->base >= s->stacksize) {
		s->base = (Elem*)realloc(s->base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(Elem));
		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREMENT;
	}
	*s->top = e;
	s->top++;
	return OK;
}
Status Pop(stack* s, Elem* e)	//出栈 
{
	if (s->base == s->top) return ERROR;
	s->top--;
	*e = *s->top;
	return OK;
}
PosType NextPos(PosType curpos, int di)	//下一步的方向 
{
	switch (di) {
	case 1:
		curpos.col++;		//东 
		break;
	case 2:
		curpos.row++;		//南 
		break;
	case 3:
		curpos.col--;		//西 
		break;
	case 4:
		curpos.row--;		//北 
		break;
	}
	return curpos;
}
Status StackEmpty(stack s)	//是否为空栈 
{
	return s.base == s.top;
}
Status MarkPrint(MazeType* maze, PosType curpos)	//不能通过的地方标记为@ 
{
	maze->map[curpos.row][curpos.col] = '@';
	return OK;
}
Status PosEquare(PosType curpos, PosType end)	//验证当前坐标是否为终点坐标 
{
	if (curpos.col == end.col && curpos.row == end.row) return OK;
	else return FALSE;
}
Status print_maze(MazeType maze, int row, int col)	//打印地图 
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			switch (maze.map[i][j]) {
			case 0:
				printf(" ");		//未探索 
				break;
			case 1:
				printf("#");		//迷宫的墙 
				break;
			case '*':
				printf("*");		//通过的路径 
				break;
			case '@':
				printf("@");		//探索后不能通过的路径

			}
		}
		printf("\n");
	}
	printf("\n\nstart:");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (maze.map[i][j] == '*')
				printf("(%d,%d)->", i, j);
		}
	}
	printf("end");
	return OK;
}
Status MazePath(MazeType maze, PosType start, PosType end)	//若maze有通路，则打印出结果，并且返回TURE；若无结果，返回FALSE 
{
	stack s;
	Elem e;
	InitStack(&s);
	PosType curpos = start;
	int curstep = 1;
	do {
		if (Pass(maze, curpos)) {			//如果可通过 
			FootPrint(&maze, curpos);
			e = CreatElem(curstep, curpos, 1);
			Push(&s, e);
			if (PosEquare(curpos, end)) {
				system("CLS");
				print_maze(maze, ROW, COL);
				return TURE;
			}
			else {
				curpos = NextPos(curpos, 1);
				curstep++;
			}
		}
		else {							//如果不能通过 
			if (!StackEmpty(s)) {
				Pop(&s, &e);
				while (e.di == 4 && !StackEmpty(s)) {
					MarkPrint(&maze, e.seat);	//不能通过的地方进行标记 
					Pop(&s, &e);
				}
				if (e.di < 4) {				//换下一个方向探索 
					e.di++;
					Push(&s, e);
					curpos = NextPos(e.seat, e.di);
				}
			}
		}
		Sleep(100);
		system("CLS");
		print_maze(maze, ROW, COL);
	} while (!StackEmpty(s));
	return FALSE;
}
int main()
{
	int a[ROW][COL] =
	{ {1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1} };
	MazeType maze;			//构建地图
	PosType start, end;		//定义初始坐标
	start.col = start.row = 1;	//定义出口坐标
	end.col = end.row = 8;
	InitMaze(&maze, a, ROW, COL);
	if (!MazePath(maze, start, end)) {
		printf("NO PASS");
	}
	return 0;
}
