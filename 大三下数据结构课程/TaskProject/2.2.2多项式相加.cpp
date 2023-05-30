// ����ʽ���
#include <iostream>
#define MAXSIZE 100
using namespace std;

typedef struct {
	double x;// ϵ��
	int y;// ָ��
}P;
typedef struct {
	P* elem; 
	int length;
}SqList;

// �����б�
int InitList(SqList& L)
{
	L.elem = new P[MAXSIZE];// ��ʼ���ڴ�ռ�
	if (!L.elem) {// �������ʧ�ܣ�����0
		return 0;
	}
	L.length = 0;
	return 1;
}

// ����Ԫ��
int ListInsert(SqList& L, int i, P &e)
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

// ��������ʽ
void CreateDuo(SqList& L, P a[], int n)
{
	for (int i = 0; i < n; i++) {
		ListInsert(L, i + 1, a[i]);
	}
}
// �����б�
void DisplaySqlist(SqList& L)
{
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i].x == 0)// ���ϵ��Ϊ0���������
			continue;
		if (i != 0)
			cout << " + ";
		cout << L.elem[i].x << "x^" << L.elem[i].y;
	}
	cout << endl;
}
// �������� ����Ľ���
void Swap(P& a, P& b) {
	P t = a;
	a = b;
	b = t;
}
// �Զ���ʽ���� ָ�������ǰ��ð��
void BubbleSort(SqList& L) {
	for (int i = L.length - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {// �������ұ������ұߵ�i���Ѿ��źõ�
			if (L.elem[j].y < L.elem[j + 1].y) { 
				Swap(L.elem[j], L.elem[j + 1]);
			}
		}
	}
}
// ����ʽ��ӣ����Ĳ��֣��ص㿴�������--------------------------------------
void Add(SqList& L1, SqList& L2, SqList& L3) {
	int i = 0, j = 0, z = 1;
	while (i < L1.length && j < L2.length) {
		if (L1.elem[i].y == L2.elem[j].y) {
			// ��ȣ���ӣ�ij��ǰ��
			P p = { L1.elem[i].x + L2.elem[j].x, L1.elem[i].y };
			ListInsert(L3, z++, p);
			i++;
			j++;
		}
		else if (L1.elem[i].y > L2.elem[j].y) {
			// ��iλ�õ�ָ������jλ�õ�ָ������ô��iλ�õ�Ԫ����ӵ�L3������iǰ��
			ListInsert(L3, z++, L1.elem[i]);
			i++;
		}
		else{
			// ��jλ�õ�ָ������iλ�õ�ָ������ô��jλ�õ�Ԫ����ӵ�L3������jǰ��
			ListInsert(L3, z++, L2.elem[j]);
			j++;
		}
	}
	// L1��ʣ��û�м����Ԫ��ֱ�����
	while (i < L1.length) {
		ListInsert(L3, z++, L1.elem[i++]);
	}
	// L2��ʣ��û�м����Ԫ��ֱ�����
	while (j < L2.length) {
		ListInsert(L3, z++, L2.elem[j++]);
	}
}

int main()
{
	SqList list1;// ����ʽ1
	SqList list2;// ����ʽ2
	SqList list3;// ����ʽ1��2��Ӻ�Ķ���ʽ
	// 1.�����б�
	InitList(list1);
	InitList(list2);
	InitList(list3);

	// 2.����Ԫ�� =����������ʽ
	P a[] = { {3.2, 0}, {2.5, 1},{2.2, 2},{-2.5, 3} };
	P b[] = { {-1.2, 0},{2.5, 1},{3.2, 2},{2.5, 3},{5.4, 4} };
	CreateDuo(list1, a, sizeof(a) / sizeof(P));
	CreateDuo(list2, b, sizeof(b) / sizeof(P));

	cout << "����ʽ1:\t";
	DisplaySqlist(list1);
	cout << "����ʽ2:\t";
	DisplaySqlist(list2);

	BubbleSort(list1);// ����Ϊ�˸��õļ���
	BubbleSort(list2);
	cout << "�������ʽ1:\t";
	DisplaySqlist(list1);
	cout << "�������ʽ2:\t";
	DisplaySqlist(list2);
	
	// 3.���ж���ʽ���
	Add(list1, list2, list3);
	cout << "����ʽ���:\t";
	DisplaySqlist(list3);

	return 0;
}