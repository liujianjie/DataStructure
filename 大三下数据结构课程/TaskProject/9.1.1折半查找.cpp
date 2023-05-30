#include <iostream>
using namespace std;
#define MAXSIZE 100

typedef struct {
	int key;
	char value;
}ElemType;

typedef struct {
	ElemType* elem;  // 数组基地址
	int length;// 当前长度
}SqList;
// 创建列表
int InitList(SqList& L)
{
	L.elem = new ElemType[MAXSIZE];// 初始化内存空间
	if (!L.elem) {// 如果申请失败，返回0
		return 0;
	}
	L.length = 0;
	return 1;
}
// 插入元素
int ListInsert(SqList& L, int i,int k, char e)
{
	if (L.length == MAXSIZE - 1 || i < 1 || i > L.length + 1) {// 满了或者i值不正确
		return 0;
	}
	for (int j = L.length; j >= i; j--) {
		L.elem[j + 1] = L.elem[j];// 插入位置及之后的元素往后移动
	}
	L.elem[i] = { k,e };
	L.length++;
	return 1;
}
// 遍历列表
void DisplaySqlist(SqList& L)
{
	if (L.length == 0) {
		cout << "列表无元素" << endl;
	}
	else {
		for (int i = 1; i <= L.length; i++) {
			cout << "(" << L.elem[i].key << "," << L.elem[i].value << ") ";
		}
		cout << endl;
	}
}
// 折半查找
// 递归
int Search_Bin_Digui(SqList& L, int low, int high, int searchkey) {
	if (low > high) return 0;
	int mid = (low + high) / 2;
	if (L.elem[mid].key == searchkey) {
		return mid;
	}else if (L.elem[mid].key < searchkey) {
		return Search_Bin_Digui(L, mid + 1, high, searchkey);
	}
	else{
		return Search_Bin_Digui(L, low, mid - 1, searchkey);
	}
}
// 非递归
int Search_Bin_FeiDigui(SqList& L, int low, int high, int searchkey) {
	int mid = 0;
	while (low <= high) {
		mid = (high + low) / 2;
		if (L.elem[mid].key == searchkey) {
			return mid;
		}
		else if (L.elem[mid].key < searchkey) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return 0;
}
int main()
{
	SqList list;
	InitList(list);// 1.创建列表
	// 2.插入元素
	ListInsert(list, 1, 2, 'A');
	ListInsert(list, 2, 3, 'B');
	ListInsert(list, 3, 5, 'C');
	ListInsert(list, 4, 7, 'D');
	ListInsert(list, 5, 15, 'E');
	ListInsert(list, 6, 17, 'F');
	ListInsert(list, 7, 19, 'G');
	ListInsert(list, 8, 21, 'H');
	ListInsert(list, 9, 23, 'I');
	ListInsert(list, 10, 25, 'J');
	cout << "列表的元素为：" << endl;
	DisplaySqlist(list);

	// 递归查找key为3的下标
	int key = 3;
	int index = Search_Bin_Digui(list, 1, list.length, key);
	cout << "key为3的值是：" << list.elem[index].value << endl;

	// 递归查找key为5的下标
	key = 5;
	index = Search_Bin_Digui(list, 1, list.length, key);
	cout << "key为5的值是：" << list.elem[index].value << endl;

	// 递推查找key为21的下标
	key = 21;
	index = Search_Bin_FeiDigui(list, 1, list.length, key);
	cout << "key为21的值是：" << list.elem[index].value << endl;

	// 递推查找不存在的key为30的下标
	key = 30;
	index = Search_Bin_FeiDigui(list, 1, list.length, key);
	if (index == 0) {
		cout << "key为30不存在" << endl;
	}
	return 0;
}