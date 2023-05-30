#include <stdio.h>
#define MaxSize 10 // ������󳤶� 

typedef struct {
	int data[MaxSize];
	int length;
}SqList;
// ��ʼ��
void InitList(SqList& L) {
	L.length = 0;
}
// ����λ��i����eԪ��
bool ListInsert(SqList& L, int i, int e) {
	if (i < 1 || i > L.length + 1) { // �Ƿ�Ϸ� 
		return false;
	}
	for (int j = L.length; j >= i; j--) {// ������ƶ�
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;// ��i-1λ�÷���e
	L.length++; // ����+1 
	return true;
}
// ����λ��iɾ��Ԫ�أ�����ɾ����Ԫ��ֵe
bool ListDelete(SqList& L, int i, int& e) {
	if (i < 1 || i > L.length) {
		return false;
	}
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++) {// ɾ����λ�ú��Ԫ����ǰ�ƶ�
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
		if (e == L.data[i]) {
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
	printf("����Ԫ��˳����Ԫ��Ϊ��\n");
	PrintList(L);
	printf("��λ��2��λ�ò���Ԫ�أ�\n");
	ListInsert(L, 2, 2);// ����2
	PrintList(L);
	if (ListDelete(L, 3, e)) {
		printf("ɾ��λ��3��Ԫ��%d�ɹ���\n", e);
		PrintList(L);
	}
	printf("λ��3�����ǣ�%d\n", GetElem(L, 3));
	printf("��ֵ��4��λ���ǣ�%d\n", LocateElem(L, 4));
}
