#include <iostream>
using namespace std;
#define MAXSIZE 100

typedef struct {
	int *elem;  // 数组基地址
	int length;// 当前长度
}SqList;

// 创建列表
int InitList(SqList& L)
{
	L.elem = new int[MAXSIZE];// 初始化内存空间
	if (!L.elem) {// 如果申请失败，返回0
		return 0;
	}
	L.length = 0;
	return 1;
}
// 插入元素
int ListInsert(SqList& L, int i, int e)
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
// 删除元素
int ListDelete(SqList& L, int i)
{
	if (i < 1 || i > L.length) {// i值不正确
		return 0;
	}
	for (int j = i; j <= L.length - 1; j++){
		L.elem[j - 1] = L.elem[j];// 删除位置之后的元素向前移动
	}
	--L.length;
	return 1;
}
// 按下标查找元素，返回元素值
int GetElem(SqList& L, int i, int &e)
{
	if (i < 1 || i > L.length) {
		return 0;
	}
	return L.elem[i - 1];
}
// 按值查找元素在数组的下标，返回是第几个位置
int LocateElem(SqList& L, int e)
{
	for (int i = 0; i < L.length; i++){
		if (L.elem[i] == e) {
			return i + 1;
		}
	}
	return 0;
}

// 遍历列表
void DisplaySqlist(SqList& L) 
{
	if (L.length == 0) {
		cout << "列表无元素" << endl;
	}
	else {
		for (int i = 0; i < L.length; i++) {
			cout << L.elem[i] << " ";
		}
		cout << endl;
	}
}
typedef int ElemType;
int main()
{

	SqList list;
	// 1.创建列表
	int f = InitList(list);
	if (f != 0) {
		cout << "创建列表成功" << endl;
	}
	DisplaySqlist(list);

	// 2.插入元素
	ListInsert(list, 1, 2);
	ListInsert(list, 2, 3);
	ListInsert(list, 3, 5);
	ListInsert(list, 4, 7);
	ListInsert(list, 5, 13);
	DisplaySqlist(list);

	// 3.删除元素
	ListDelete(list, 2); // 删除第2个
	ListDelete(list, 3); // 删除第3个
	DisplaySqlist(list);
	
	// 4.查找元素
	int i = LocateElem(list, 5);
	cout << 5 << "在列表的第" << i << "个位置" << endl;

	// 5.遍历列表
	DisplaySqlist(list);
	return 0;
}