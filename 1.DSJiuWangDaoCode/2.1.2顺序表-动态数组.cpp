#include <stdio.h>
#include <stdlib.h>
#define InitSize 5 // 定义最大长度 
#define IncreaseSize 5// 每次改变的步长 

typedef struct {
	int* data;
	int length;
	int MaxSize;
}SqList;
// 初始化 
void InitList(SqList& L) {
	L.data = (int*)malloc(sizeof(int) * InitSize);// 初始化空间 
	L.length = 0;
	L.MaxSize = InitSize;
}
// 扩展空间，实现改变数组大小
void IncreaseSpace(SqList& L, int len) {
	printf("增加空间\n");
	int* p = L.data;// 旧数据 
	L.data = (int*)malloc(sizeof(int) * (L.MaxSize + len));// 新空间 
	for (int i = 0; i < L.length; i++) {// 拷贝旧的数据
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + len;// 增加 
	free(p);// 释放原来空间 
}
// 根据位序i插入e元素
bool ListInsert(SqList& L, int i, int e) {
	if (i < 1 || i > L.length + 1) {
		return false;
	}
	// 如果满了，扩大空间
	if (L.length >= L.MaxSize) {
		IncreaseSpace(L, IncreaseSize);
	}
	// 先从前往后移动再插入
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}
// 根据位序i删除元素，返回删除的元素值e
bool ListDelete(SqList& L, int i, int& e) {
	if (i < 1 || i > L.length) {
		return false;
	}
	e = L.data[i - 1];
	// 直接从后往前移删除 
	for (int j = i; j < L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}
// 按位序i查找元素，返回值
int GetElem(SqList& L, int i) {
	if (i < 1 || i > L.length) {
		return 0;
	}
	return L.data[i - 1];
}
// 按值e查找元素，返回位序 
int LocateElem(SqList& L, int e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i + 1;
		}
	}
	return 0;
}
// 遍历顺序表元素
void PrintList(SqList& L) {
	for (int i = 0; i < L.length; i++) {
		printf("%d\t", L.data[i]);
	}
	printf("\n");
}
int main() {
	int e;
	SqList L;
	InitList(L);
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 3);
	ListInsert(L, 3, 4);
	ListInsert(L, 4, 5);
	ListInsert(L, 2, 2);// 插入
	PrintList(L);
	// 此前已经插入了5个，再插入会增加空间
	printf("此前已经插入了5个\n");
	ListInsert(L, 2, 22);// 插入
	PrintList(L);
}
