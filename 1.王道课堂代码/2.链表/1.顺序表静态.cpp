#include <stdio.h>
#define MaxSize 10 // 定义最大长度 

typedef struct{
	int data[MaxSize];
	int length;
}SqList;

void InitList(SqList &L){
	L.length = 0;
}

// i是位序，e是元素 
bool ListInsert(SqList &L, int i, int e){
	if(i < 1 || i > L.length + 1){ // 是否合法 
		return false;
	}
	for(int j = L.length; j >= i; j--){// 先向后移动
		L.data[j] = L.data[j - 1];
	} 
	L.data[i - 1] = e;// 再i-1位置放置e
	L.length++; // 长度+1 
	return true;
}
// 根据位序删除元素，返回删除的元素值 
bool ListDelete(SqList &L, int i, int &e){
	if(i < 1 || i > L.length){
		return false;
	}
	e = L.data[i - 1];
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
		if(e == L.data[i]){
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
}
