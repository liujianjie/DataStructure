#include <stdio.h>
#include <stdlib.h>
#define InitSize 5 // ������󳤶� 
#define IncreaseSize 5// ÿ�θı�Ĳ��� 

typedef struct {
	int* data;
	int length;
	int MaxSize;
}SqList;
// ��ʼ�� 
void InitList(SqList& L) {
	L.data = (int*)malloc(sizeof(int) * InitSize);// ��ʼ���ռ� 
	L.length = 0;
	L.MaxSize = InitSize;
}
// ��չ�ռ䣬ʵ�ָı������С
void IncreaseSpace(SqList& L, int len) {
	printf("���ӿռ�\n");
	int* p = L.data;// ������ 
	L.data = (int*)malloc(sizeof(int) * (L.MaxSize + len));// �¿ռ� 
	for (int i = 0; i < L.length; i++) {// �����ɵ�����
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + len;// ���� 
	free(p);// �ͷ�ԭ���ռ� 
}
// ����λ��i����eԪ��
bool ListInsert(SqList& L, int i, int e) {
	if (i < 1 || i > L.length + 1) {
		return false;
	}
	// ������ˣ�����ռ�
	if (L.length >= L.MaxSize) {
		IncreaseSpace(L, IncreaseSize);
	}
	// �ȴ�ǰ�����ƶ��ٲ���
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}
// ����λ��iɾ��Ԫ�أ�����ɾ����Ԫ��ֵe
bool ListDelete(SqList& L, int i, int& e) {
	if (i < 1 || i > L.length) {
		return false;
	}
	e = L.data[i - 1];
	// ֱ�ӴӺ���ǰ��ɾ�� 
	for (int j = i; j < L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}
// ��λ��i����Ԫ�أ�����ֵ
int GetElem(SqList& L, int i) {
	if (i < 1 || i > L.length) {
		return 0;
	}
	return L.data[i - 1];
}
// ��ֵe����Ԫ�أ�����λ�� 
int LocateElem(SqList& L, int e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i + 1;
		}
	}
	return 0;
}
// ����˳���Ԫ��
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
	ListInsert(L, 2, 2);// ����
	PrintList(L);
	// ��ǰ�Ѿ�������5�����ٲ�������ӿռ�
	printf("��ǰ�Ѿ�������5��\n");
	ListInsert(L, 2, 22);// ����
	PrintList(L);
}
