#include <stdio.h>
#include <stdlib.h>
#define InitSize 5 // 定义最大长度 
#define IncreaseSize 5// 步长 

typedef struct{
	int *data;
	int length;
	int MaxSize;
}SqList;

// 初始化 
void InitList(SqList &L){
	L.data = (int*)malloc(sizeof(int) * InitSize);// 初始化空间 
	L.length = 0;
	L.MaxSize = InitSize;
}
// 扩展空间
void IncreaseSpace(SqList &L, int len){
	printf("发生改变大小\n");
	int *p = L.data;// 旧数据 
	L.data = (int*)malloc(sizeof(int) * (L.MaxSize + len));// 新空间 
	for(int i = 0; i < L.length; i++){// 拷贝数据
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + len;// 增加 
	free(p);// 释放原来空间 
} 

// i是位序，e是元素 
bool ListInsert(SqList &L, int i, int e){
	if(i < 1 || i > L.length + 1){
		return false;
	}
	// 如果满了，扩大空间
	
	if(L.length >= L.MaxSize){
		IncreaseSpace(L, IncreaseSize);
	}
	// 先从前往后移动再插入
	for(int j = L.length; j >= i; j--){
		L.data[j] = L.data[j - 1];
	} 
	L.data[i - 1] = e;
	L.length++;
	return true;
}
// 根据位序删除元素，返回删除的元素值 
bool ListDelete(SqList &L, int i, int &e){
	if(i < 1 || i > L.length){
		return false;
	}
	e = L.data[i - 1];
	// 直接从后往前移删除 
	for(int j = i; j < L.length; j++){
		L.data[j - 1] = L.data[j];
	} 
	L.length--;
	return true;
} 
// 按位序查找，返回值
int GetElem(SqList &L, int i){
	if(i < 1 || i > L.length){
		return 0;
	}
	return L.data[i - 1];
} 
// 按值查找，返回位序 
int LocateElem(SqList &L, int e){
	for(int i = 0; i < L.length; i++){
		if(L.data[i] == e){
			return i + 1;
		}
	}
	return 0;
}
// 辅助，遍历
void PrintList(SqList &L){
	for(int i = 0; i < L.length; i++){
		printf("%d\t", L.data[i]);
	}
	printf("\n"); 
} 
int main(){
	SqList L;
	InitList(L);
	ListInsert(L, 1, 1);// 插入
	ListInsert(L, 2, 3);
	ListInsert(L, 3, 4);
	ListInsert(L, 4, 5);
	PrintList(L);
	ListInsert(L, 2, 2);// 插入2
	PrintList(L);
	int e;
	if(ListDelete(L, 3, e)){
		printf("删除元素成功，值是%d\n", e);
		PrintList(L);
	}else{
		printf("删除失败！\n");
	}
	printf("第三个数是%d\n", GetElem(L, 3));
	printf("数值是4的位序是%d\n", LocateElem(L, 4)); 
	
	
	ListInsert(L, 2, 22);// 插入2
	// 发生改变大小
	ListInsert(L, 2, 222);// 插入2
	PrintList(L);
	
	ListInsert(L, 2, 2222);// 插入2
	ListInsert(L, 2, 2222);// 插入2
	ListInsert(L, 2, 2222);// 插入2
	ListInsert(L, 2, 2222);// 插入2
	
	// 发生改变大小
	ListInsert(L, 2, 232);// 插入2
	PrintList(L);
}
