#include <iostream>
using namespace std;
#define MAXSIZE 100

typedef struct {
	int key;
	char value;
}ElemType;

typedef struct {
	ElemType* elem;  // �������ַ
	int length;// ��ǰ����
}SqList;
// �����б�
int InitList(SqList& L)
{
	L.elem = new ElemType[MAXSIZE];// ��ʼ���ڴ�ռ�
	if (!L.elem) {// �������ʧ�ܣ�����0
		return 0;
	}
	L.length = 0;
	return 1;
}
// ����Ԫ��
int ListInsert(SqList& L, int i,int k, char e)
{
	if (L.length == MAXSIZE - 1 || i < 1 || i > L.length + 1) {// ���˻���iֵ����ȷ
		return 0;
	}
	for (int j = L.length; j >= i; j--) {
		L.elem[j + 1] = L.elem[j];// ����λ�ü�֮���Ԫ�������ƶ�
	}
	L.elem[i] = { k,e };
	L.length++;
	return 1;
}
// �����б�
void DisplaySqlist(SqList& L)
{
	if (L.length == 0) {
		cout << "�б���Ԫ��" << endl;
	}
	else {
		for (int i = 1; i <= L.length; i++) {
			cout << "(" << L.elem[i].key << "," << L.elem[i].value << ") ";
		}
		cout << endl;
	}
}
// �۰����
// �ݹ�
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
// �ǵݹ�
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
	InitList(list);// 1.�����б�
	// 2.����Ԫ��
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
	cout << "�б��Ԫ��Ϊ��" << endl;
	DisplaySqlist(list);

	// �ݹ����keyΪ3���±�
	int key = 3;
	int index = Search_Bin_Digui(list, 1, list.length, key);
	cout << "keyΪ3��ֵ�ǣ�" << list.elem[index].value << endl;

	// �ݹ����keyΪ5���±�
	key = 5;
	index = Search_Bin_Digui(list, 1, list.length, key);
	cout << "keyΪ5��ֵ�ǣ�" << list.elem[index].value << endl;

	// ���Ʋ���keyΪ21���±�
	key = 21;
	index = Search_Bin_FeiDigui(list, 1, list.length, key);
	cout << "keyΪ21��ֵ�ǣ�" << list.elem[index].value << endl;

	// ���Ʋ��Ҳ����ڵ�keyΪ30���±�
	key = 30;
	index = Search_Bin_FeiDigui(list, 1, list.length, key);
	if (index == 0) {
		cout << "keyΪ30������" << endl;
	}
	return 0;
}