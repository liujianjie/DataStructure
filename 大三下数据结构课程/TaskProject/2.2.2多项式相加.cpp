// 多项式相加
#include <iostream>
#define MAXSIZE 100
using namespace std;

typedef struct {
	double x;// 系数
	int y;// 指数
}P;
typedef struct {
	P* elem; 
	int length;
}SqList;

// 创建列表
int InitList(SqList& L)
{
	L.elem = new P[MAXSIZE];// 初始化内存空间
	if (!L.elem) {// 如果申请失败，返回0
		return 0;
	}
	L.length = 0;
	return 1;
}

// 插入元素
int ListInsert(SqList& L, int i, P &e)
{
	if (L.length == MAXSIZE || i < 1 || i > L.length + 1) {// 满了或者i值不正确
		return 0;
	}
	for (int j = L.length - 1; j >= i - 1; j--) {
		L.elem[j + 1] = L.elem[j];// 插入位置及之后的元素往后移动
	}
	L.elem[i - 1] = e;
	L.length++;
	return 1;
}

// 创建多项式
void CreateDuo(SqList& L, P a[], int n)
{
	for (int i = 0; i < n; i++) {
		ListInsert(L, i + 1, a[i]);
	}
}
// 遍历列表
void DisplaySqlist(SqList& L)
{
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i].x == 0)// 如果系数为0就跳过这个
			continue;
		if (i != 0)
			cout << " + ";
		cout << L.elem[i].x << "x^" << L.elem[i].y;
	}
	cout << endl;
}
// 辅助函数 排序的交换
void Swap(P& a, P& b) {
	P t = a;
	a = b;
	b = t;
}
// 对多项式排序， 指数大的排前，冒泡
void BubbleSort(SqList& L) {
	for (int i = L.length - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {// 从左向右边排序，右边的i是已经排好的
			if (L.elem[j].y < L.elem[j + 1].y) { 
				Swap(L.elem[j], L.elem[j + 1]);
			}
		}
	}
}
// 多项式相加，核心部分，重点看这里就行--------------------------------------
void Add(SqList& L1, SqList& L2, SqList& L3) {
	int i = 0, j = 0, z = 1;
	while (i < L1.length && j < L2.length) {
		if (L1.elem[i].y == L2.elem[j].y) {
			// 相等，相加，ij都前进
			P p = { L1.elem[i].x + L2.elem[j].x, L1.elem[i].y };
			ListInsert(L3, z++, p);
			i++;
			j++;
		}
		else if (L1.elem[i].y > L2.elem[j].y) {
			// 当i位置的指数大于j位置的指数，那么，i位置的元素添加到L3，并且i前进
			ListInsert(L3, z++, L1.elem[i]);
			i++;
		}
		else{
			// 当j位置的指数大于i位置的指数，那么，j位置的元素添加到L3，并且j前进
			ListInsert(L3, z++, L2.elem[j]);
			j++;
		}
	}
	// L1中剩余没有计算的元素直接添加
	while (i < L1.length) {
		ListInsert(L3, z++, L1.elem[i++]);
	}
	// L2中剩余没有计算的元素直接添加
	while (j < L2.length) {
		ListInsert(L3, z++, L2.elem[j++]);
	}
}

int main()
{
	SqList list1;// 多项式1
	SqList list2;// 多项式2
	SqList list3;// 多项式1和2相加后的多项式
	// 1.创建列表
	InitList(list1);
	InitList(list2);
	InitList(list3);

	// 2.插入元素 =》创建多项式
	P a[] = { {3.2, 0}, {2.5, 1},{2.2, 2},{-2.5, 3} };
	P b[] = { {-1.2, 0},{2.5, 1},{3.2, 2},{2.5, 3},{5.4, 4} };
	CreateDuo(list1, a, sizeof(a) / sizeof(P));
	CreateDuo(list2, b, sizeof(b) / sizeof(P));

	cout << "多项式1:\t";
	DisplaySqlist(list1);
	cout << "多项式2:\t";
	DisplaySqlist(list2);

	BubbleSort(list1);// 排序为了更好的计算
	BubbleSort(list2);
	cout << "有序多项式1:\t";
	DisplaySqlist(list1);
	cout << "有序多项式2:\t";
	DisplaySqlist(list2);
	
	// 3.进行多项式相加
	Add(list1, list2, list3);
	cout << "多项式相加:\t";
	DisplaySqlist(list3);

	return 0;
}