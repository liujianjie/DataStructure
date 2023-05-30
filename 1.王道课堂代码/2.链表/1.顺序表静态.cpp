#include <stdio.h>
#define MaxSize 10 // ������󳤶� 

typedef struct{
	int data[MaxSize];
	int length;
}SqList;

void InitList(SqList &L){
	L.length = 0;
}

// i��λ��e��Ԫ�� 
bool ListInsert(SqList &L, int i, int e){
	if(i < 1 || i > L.length + 1){ // �Ƿ�Ϸ� 
		return false;
	}
	for(int j = L.length; j >= i; j--){// ������ƶ�
		L.data[j] = L.data[j - 1];
	} 
	L.data[i - 1] = e;// ��i-1λ�÷���e
	L.length++; // ����+1 
	return true;
}
// ����λ��ɾ��Ԫ�أ�����ɾ����Ԫ��ֵ 
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
		if(e == L.data[i]){
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
}
