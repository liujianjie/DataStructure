#include <stdio.h>
#include <stdlib.h>
#define InitSize 5 // ������󳤶� 
#define IncreaseSize 5// ���� 

typedef struct{
	int *data;
	int length;
	int MaxSize;
}SqList;

// ��ʼ�� 
void InitList(SqList &L){
	L.data = (int*)malloc(sizeof(int) * InitSize);// ��ʼ���ռ� 
	L.length = 0;
	L.MaxSize = InitSize;
}
// ��չ�ռ�
void IncreaseSpace(SqList &L, int len){
	printf("�����ı��С\n");
	int *p = L.data;// ������ 
	L.data = (int*)malloc(sizeof(int) * (L.MaxSize + len));// �¿ռ� 
	for(int i = 0; i < L.length; i++){// ��������
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + len;// ���� 
	free(p);// �ͷ�ԭ���ռ� 
} 

// i��λ��e��Ԫ�� 
bool ListInsert(SqList &L, int i, int e){
	if(i < 1 || i > L.length + 1){
		return false;
	}
	// ������ˣ�����ռ�
	
	if(L.length >= L.MaxSize){
		IncreaseSpace(L, IncreaseSize);
	}
	// �ȴ�ǰ�����ƶ��ٲ���
	for(int j = L.length; j >= i; j--){
		L.data[j] = L.data[j - 1];
	} 
	L.data[i - 1] = e;
	L.length++;
	return true;
}
// ����λ��ɾ��Ԫ�أ�����ɾ����Ԫ��ֵ 
bool ListDelete(SqList &L, int i, int &e){
	if(i < 1 || i > L.length){
		return false;
	}
	e = L.data[i - 1];
	// ֱ�ӴӺ���ǰ��ɾ�� 
	for(int j = i; j < L.length; j++){
		L.data[j - 1] = L.data[j];
	} 
	L.length--;
	return true;
} 
// ��λ����ң�����ֵ
int GetElem(SqList &L, int i){
	if(i < 1 || i > L.length){
		return 0;
	}
	return L.data[i - 1];
} 
// ��ֵ���ң�����λ�� 
int LocateElem(SqList &L, int e){
	for(int i = 0; i < L.length; i++){
		if(L.data[i] == e){
			return i + 1;
		}
	}
	return 0;
}
// ����������
void PrintList(SqList &L){
	for(int i = 0; i < L.length; i++){
		printf("%d\t", L.data[i]);
	}
	printf("\n"); 
} 
int main(){
	SqList L;
	InitList(L);
	ListInsert(L, 1, 1);// ����
	ListInsert(L, 2, 3);
	ListInsert(L, 3, 4);
	ListInsert(L, 4, 5);
	PrintList(L);
	ListInsert(L, 2, 2);// ����2
	PrintList(L);
	int e;
	if(ListDelete(L, 3, e)){
		printf("ɾ��Ԫ�سɹ���ֵ��%d\n", e);
		PrintList(L);
	}else{
		printf("ɾ��ʧ�ܣ�\n");
	}
	printf("����������%d\n", GetElem(L, 3));
	printf("��ֵ��4��λ����%d\n", LocateElem(L, 4)); 
	
	
	ListInsert(L, 2, 22);// ����2
	// �����ı��С
	ListInsert(L, 2, 222);// ����2
	PrintList(L);
	
	ListInsert(L, 2, 2222);// ����2
	ListInsert(L, 2, 2222);// ����2
	ListInsert(L, 2, 2222);// ����2
	ListInsert(L, 2, 2222);// ����2
	
	// �����ı��С
	ListInsert(L, 2, 232);// ����2
	PrintList(L);
}
