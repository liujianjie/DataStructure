#include <iostream>
using namespace std;
#define MAXSIZE 100

typedef struct {
	int *elem;  // �������ַ
	int length;// ��ǰ����
}SqList;

// �����б�
int InitList(SqList& L)
{
	L.elem = new int[MAXSIZE];// ��ʼ���ڴ�ռ�
	if (!L.elem) {// �������ʧ�ܣ�����0
		return 0;
	}
	L.length = 0;
	return 1;
}
// ����Ԫ��
int ListInsert(SqList& L, int i, int e)
{
	if (L.length == MAXSIZE || i < 1 || i > L.length + 1) {// ���˻���iֵ����ȷ
		return 0;
	}
	for (int j = L.length - 1; j >= i - 1; j--) {
		L.elem[j + 1] = L.elem[j];// ����λ�ü�֮���Ԫ�������ƶ�
	}
	L.elem[i - 1] = e;
	L.length++;
	return 1;
}
// ɾ��Ԫ��
int ListDelete(SqList& L, int i)
{
	if (i < 1 || i > L.length) {// iֵ����ȷ
		return 0;
	}
	for (int j = i; j <= L.length - 1; j++){
		L.elem[j - 1] = L.elem[j];// ɾ��λ��֮���Ԫ����ǰ�ƶ�
	}
	--L.length;
	return 1;
}
// ���±����Ԫ�أ�����Ԫ��ֵ
int GetElem(SqList& L, int i, int &e)
{
	if (i < 1 || i > L.length) {
		return 0;
	}
	return L.elem[i - 1];
}
// ��ֵ����Ԫ����������±꣬�����ǵڼ���λ��
int LocateElem(SqList& L, int e)
{
	for (int i = 0; i < L.length; i++){
		if (L.elem[i] == e) {
			return i + 1;
		}
	}
	return 0;
}

// �����б�
void DisplaySqlist(SqList& L) 
{
	if (L.length == 0) {
		cout << "�б���Ԫ��" << endl;
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
	// 1.�����б�
	int f = InitList(list);
	if (f != 0) {
		cout << "�����б�ɹ�" << endl;
	}
	DisplaySqlist(list);

	// 2.����Ԫ��
	ListInsert(list, 1, 2);
	ListInsert(list, 2, 3);
	ListInsert(list, 3, 5);
	ListInsert(list, 4, 7);
	ListInsert(list, 5, 13);
	DisplaySqlist(list);

	// 3.ɾ��Ԫ��
	ListDelete(list, 2); // ɾ����2��
	ListDelete(list, 3); // ɾ����3��
	DisplaySqlist(list);
	
	// 4.����Ԫ��
	int i = LocateElem(list, 5);
	cout << 5 << "���б�ĵ�" << i << "��λ��" << endl;

	// 5.�����б�
	DisplaySqlist(list);
	return 0;
}