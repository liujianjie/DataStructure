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
#define MAXSIZE 100 	//�Թ����Χ 
#define ROW 10			//���� 
#define COL 10			//���� 

typedef int Status;

typedef struct {			//���� 
	int row;
	int col;
}PosType;
typedef struct {			//ջ��Ԫ������ 
	int stepnun;
	PosType seat;
	int di;
}Elem;
typedef struct {			//ջ 
	Elem* top;
	Elem* base;
	int stacksize;
}stack;
typedef struct {			//��ͼ���� 
	int m, n;
	int map[MAXSIZE][MAXSIZE];
}MazeType;

Status InitMaze(MazeType* maze, int a[][COL], int row, int col)	//������ͼ 
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
Status InitStack(stack* s)	//ջ��ʼ�� 
{
	s->base = (Elem*)malloc(STACK_INIT_SIZE * sizeof(Elem));
	if (!s->base) return ERROR;
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}
Status Pass(MazeType maze, PosType curpos)	//��֤�Ƿ�ͨ�� 
{
	return maze.map[curpos.row][curpos.col] == 0;
}
Status FootPrint(MazeType* maze, PosType curpos)		//���ͨ������ͼ�ϱ��Ϊ* 
{
	maze->map[curpos.row][curpos.col] = '*';
	return OK;
}
Elem CreatElem(int curstep, PosType curpos, int di)	//����ջ��Ԫ�� 
{
	Elem e;
	e.di = di;
	e.seat = curpos;
	e.stepnun = curstep;
	return e;
}
Status Push(stack* s, Elem e)	//��ջ 
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
Status Pop(stack* s, Elem* e)	//��ջ 
{
	if (s->base == s->top) return ERROR;
	s->top--;
	*e = *s->top;
	return OK;
}
PosType NextPos(PosType curpos, int di)	//��һ���ķ��� 
{
	switch (di) {
	case 1:
		curpos.col++;		//�� 
		break;
	case 2:
		curpos.row++;		//�� 
		break;
	case 3:
		curpos.col--;		//�� 
		break;
	case 4:
		curpos.row--;		//�� 
		break;
	}
	return curpos;
}
Status StackEmpty(stack s)	//�Ƿ�Ϊ��ջ 
{
	return s.base == s.top;
}
Status MarkPrint(MazeType* maze, PosType curpos)	//����ͨ���ĵط����Ϊ@ 
{
	maze->map[curpos.row][curpos.col] = '@';
	return OK;
}
Status PosEquare(PosType curpos, PosType end)	//��֤��ǰ�����Ƿ�Ϊ�յ����� 
{
	if (curpos.col == end.col && curpos.row == end.row) return OK;
	else return FALSE;
}
Status print_maze(MazeType maze, int row, int col)	//��ӡ��ͼ 
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			switch (maze.map[i][j]) {
			case 0:
				printf(" ");		//δ̽�� 
				break;
			case 1:
				printf("#");		//�Թ���ǽ 
				break;
			case '*':
				printf("*");		//ͨ����·�� 
				break;
			case '@':
				printf("@");		//̽������ͨ����·��

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
Status MazePath(MazeType maze, PosType start, PosType end)	//��maze��ͨ·�����ӡ����������ҷ���TURE�����޽��������FALSE 
{
	stack s;
	Elem e;
	InitStack(&s);
	PosType curpos = start;
	int curstep = 1;
	do {
		if (Pass(maze, curpos)) {			//�����ͨ�� 
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
		else {							//�������ͨ�� 
			if (!StackEmpty(s)) {
				Pop(&s, &e);
				while (e.di == 4 && !StackEmpty(s)) {
					MarkPrint(&maze, e.seat);	//����ͨ���ĵط����б�� 
					Pop(&s, &e);
				}
				if (e.di < 4) {				//����һ������̽�� 
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
	MazeType maze;			//������ͼ
	PosType start, end;		//�����ʼ����
	start.col = start.row = 1;	//�����������
	end.col = end.row = 8;
	InitMaze(&maze, a, ROW, COL);
	if (!MazePath(maze, start, end)) {
		printf("NO PASS");
	}
	return 0;
}
