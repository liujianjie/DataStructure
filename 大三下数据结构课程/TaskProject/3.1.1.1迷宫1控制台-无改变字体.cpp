#include <iostream>
#include <stack>
#include <windows.h>
using namespace std;
// ��ͼֵ: 1��ǽ�ڣ�0��ͨ����2����������λ�ã�3�ǳ��� 4�ǲ���ͨ���ı��
#define WALL 1
#define PASS 0
#define ZHUJUE 2
#define EXITS 3
#define NOPATH 4 

// ȫ�ֱ���
int m = 10, n = 10;		// �к��� Ĭ��Ϊ10
int map[100][100];		// ��ͼ���飬�ȿ���һ�㣬����m��n�޶���Χ
int vis[100][100];		// �Ƿ���ʹ���0��û���ʣ�-1�Ƿ��ʹ���
bool isFind = false;		// �Ƿ��ҵ�����
stack<int(*)> pathStack;// ��STLģ���ջ���¼·��

// ��ӡ��ͼֵ
void PrintMap(int flag) {// ����flag�Ƿ��������̨����
	if (flag == 0) {
		COORD position;
		position.X = 0;
		position.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		cout << "������ͼ��..............." << endl;
	}
	Sleep(250); // ����0.3�룬�����������
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == ZHUJUE) {// ���ǵ�ǰ����λ��
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);// ��ɫ
				cout << "��";
				continue;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);// ��ɫ����
			if (map[i][j] == WALL || map[i][j] == EXITS) {	// ǽ
				cout << "��";
			}
			if (map[i][j] == PASS) {	// ·
				cout << "  ";// Ҫ2���ո�
			}
			if (map[i][j] == NOPATH) {	// ����ͨ��
				cout << "��";
			}
		}
		cout << endl;
	}
	cout << endl;
}
/*
˼·�����������������
�ݹ����Դ���ջ���ԡ����ڽ��뵱ǰ�ݹ麯���൱��ջ��push���˳���ǰ�ݹ麯���൱��ջ��pop
��ô����������ԣ�ʵ��������ͼ�з�����һ�����Ĺ��ܡ�
*/
void DFS(int cury, int curx, int lasty, int lastx, int ysval) {// cury curx ��ʾ��ǰ�㣬 lasty,lastx ��ʾ��һ���㣬ysval��ʾ��һ����ĵ�ͼֵ
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
	pathStack.push(new int[2]{cury, curx});// ��¼��ǰ·��
	vis[cury][curx] = -1;				   // ��ʾ���ʹ���ǰ��
	int curysval = map[cury][curx];			// ���浱ǰ�ĵ�ͼֵ
	// ������������λ�á�
	map[lasty][lastx] = ysval;				// ��һ�����ڵ�λ�ñ�ص�ͼֵ
	map[cury][curx] = ZHUJUE;						// �������ڵ�λ��Ϊ2��
	PrintMap(0);								// �ݹ麯��ִ��ʱ����ǰ�ĵ�ͼֵ
	// ���������ĸ�����̽���������뵱ǰλ�ú͵�ǰ�ĵ�ͼֵ���Ա�����һ���ݹ麯���ѵ�ǰ������ռ��λ�ñ�ص�ͼֵ��
	DFS(cury, curx + 1, cury, curx, curysval);// �����ұ�̽����Ϊ�˷���PPT�ϵ�ͼչʾЧ��������Ӧ����������̽���ġ�
	DFS(cury + 1, curx, cury, curx, curysval);// ���±�̽��
	DFS(cury, curx - 1, cury, curx, curysval);// �����̽��
	DFS(cury - 1, curx, cury, curx, curysval);// ���ϱ�̽��

	if (isFind) {// �ҵ��˳��ڣ����ڵ�·��ջ��������ȷ�ķ���·�����˳����ɣ��������·�����ܲ�������·��
		return;
	}
	// 4�����������ˣ���·���ߣ�˵�����λ�ò���ͨ������Ҫ������һ��λ��
	// �ݹ麯������ʱ���൱��ջpopʱ�Ĳ���
	// ��Ҫ�ѵݹ麯������ʱ�ı����ֵ�Ȳ����ع�ԭλ
	//vis[cury][curx] = 0;						// ��ǰ��û���ʹ���ȥ��ûӰ�죬���ָ�Ϊ0���ܿ����ҵ�����·��
	pathStack.pop();							// ��ȥ��¼��ǰλ��
	map[cury][curx] = NOPATH;				// ���λ�õ�ֵΪ����ͨ��
	map[lasty][lastx] = ZHUJUE;				// ��һ�����ڵ�λ��Ϊ2
	PrintMap(0);								// ��ӡ��ǰ�ĵ�ͼֵ
}

// ����ջ�����·��ֵ���޸ĵ�ͼֵ
void UpdateMapToPath() {
	while (!pathStack.empty()) {
		int *pos = pathStack.top();
		pathStack.pop();
		map[*pos][*(pos + 1)] = 2;
	}
}

int main() {
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
	int curx = 1, cury = 1;			// �������ڵĿ�ʼ�к���
	map[endy][endx] = EXITS;// ������λ�ñ��
	system("cls");// �������

	// 2.��������������ҵ�·��
	DFS(cury, curx, cury, curx, map[cury][curx]);

	// 3.����ջ�������Ϣ���޸ĵ�ͼ���ʵ�·��
	cout << "�ɹ��ҵ����ڣ����ʳ���·������:" << endl;
	UpdateMapToPath();
	PrintMap(1); // ����ӡ���ʹ���·��ͼ

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





/*
���������¡�
1.���ݵ�ǰ���ǳ���λ��
	0)��¼��ǰλ�÷��ʹ�
	1)�ѵ�ǰλ�ô��뵽·��ջ��
	2)�ѵ�ǰ��λ�õĵ�ͼֵ��Ϊ�������ڵ�λ��ֵ
2.�����ǵ�ǰλ�������������ĸ����������������ǰλ�ø��ݲ�ͬ������ı�
3.�µ�λ�ü���ִ�в���1���������Ȱ���һ��������ռ��λ�ñ�ص�ͼֵ����˷���
4.
*/



